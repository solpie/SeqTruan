#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_TRACKFRAME_H
#define SEQTRUAN_TRACKFRAME_H

#include "view/UI.hpp"
#include "utils/Linker.hpp"

class TrackFrame : public OneLinker<TrackFrame>, public QWidget {
public:
    TrackFrame(QWidget *parent) : QWidget(parent) {
        resize(40, 60);

        thumb = new OverWidget<QWidget>(this);
        thumb->resize(40, 50);
        over(thumb, paintEvent_, paintThumb);
        _setMouseTransparent(thumb);

        frameIdx = new QLabel(this);
        frameIdx->setStyleSheet("color:#b6b6b6;border:none;");
        _setMouseTransparent(frameIdx);
        frameIdx->move(4, 45);
        frameIdx->setText("0");

        leftButton = new OverWidget<QPushButton>(this);
        leftButton->resize(8, 8);
        leftButton->isCustomQss = true;
        leftButton->add(mousePressEvent_, [this] { isPressLeftButton = true; });
        leftButton->add(mouseMoveEvent_, [this] { this->pressAndMoveEvent(); });
        leftButton->add(mouseReleaseEvent_, [this] {
            isPressLeftButton = false;
            this->onRelLeftButton(this);
        });
        UI::setQss(leftButton, ":/qss_button", "frameButton");

        rightButton = new OverWidget<QPushButton>(this);
        rightButton->resize(8, 8);
        rightButton->move(33, 32);
        rightButton->isCustomQss = true;
        rightButton->add(mousePressEvent_, [this] { isPressRightButton = true; });
        rightButton->add(mouseMoveEvent_, [this] { this->pressAndMoveEvent(); });
        rightButton->add(mouseReleaseEvent_, [this] { isPressRightButton = false; });
        UI::setQss(rightButton, ":/qss_button", "frameButton");
        setMouseTracking(true);
    }

    void setPixmap(QImage *qImage) {
        int thumbHeight = int(float(qImage->height()) / qImage->width() * (this->width() - 2));
        thumbPixmap = new QPixmap(
                QPixmap::fromImage(qImage->scaled(this->width() - 2, thumbHeight, Qt::KeepAspectRatio)));
    }

    int idx = 0;
    QLabel *holdFrameCountLabel = nullptr;
    bool isPressLeftButton = false;
    bool isPressRightButton = false;
    int changeWidth = 0;

    void setIdx(int trackFrameIdx) {
        idx = trackFrameIdx;
        QString s = QString::number(idx + 1);
        frameIdx->setText(s);
    }

    void setHoldFrameCount(int count, int dx = 1) {
        int frameWidth = app.trackModel->frameWidth;
        changeWidth = (count - _trackFrameInfo->getHoldFrame()) * frameWidth * dx;
        _trackFrameInfo->setHoldFrame( count);
        _setWidth(this, count * frameWidth);
        _setWidth(thumb, width());
        _setX(rightButton, width() - rightButton->width() + 1);
        qDebug() << this << "setHoldFrameCount" << this->frameIdx->text() << "width" << width();
        if (count > 1) {
            if (!holdFrameCountLabel) {
                holdFrameCountLabel = new QLabel(this);
                holdFrameCountLabel->setAlignment(Qt::AlignRight);
                holdFrameCountLabel->setWordWrap(true);
                holdFrameCountLabel->setStyleSheet("color:#b6b6b6;border:none;");
                holdFrameCountLabel->setMinimumWidth(15);
                holdFrameCountLabel->show();
            }
            holdFrameCountLabel->setText(QString::number(count));
            holdFrameCountLabel->move(app.trackModel->frameWidth * count - 20, 10);
        }
    }

    void resizeFrame(int endPosX) {
        _setWidth(this, endPosX - this->x());
        _setWidth(thumb, width());
        _setX(rightButton, width() - rightButton->width() + 1);
        _trackFrameInfo->setHoldFrame( width() / app.trackModel->frameWidth);
    }

    void setTrackFrameInfo(TrackFrameInfo *tfi) {
        _trackFrameInfo = tfi;
    }

    void updateTrackFrameInfo() {
        int frameWidth = app.trackModel->frameWidth;
        _trackFrameInfo->setStartFrame(this->x() / frameWidth + 1);
        _trackFrameInfo->setHoldFrame((this->x() + this->width()) / frameWidth);
    }

protected:
    OverWidget<QWidget> *thumb;
    TrackFrameInfo *_trackFrameInfo;

    void onRelLeftButton(TrackFrame *relTrackFrame) {
        if (relTrackFrame->pre) {
            if (relTrackFrame->pre->x() <= relTrackFrame->x()) {
                qDebug() << this << "onRelLeftButton" << relTrackFrame->pre->idx;
                TrackFrame *deleteMe = relTrackFrame->pre->remove();//todo 释放资源 保存历史操作
                TrackFrameInfo *deleteMeInfo = _trackFrameInfo->pre->remove();//todo 释放资源 保存历史操作
                renameBackward(this);
//                relTrackFrame->updateTrackFrameInfo();
                //todo 验证idx
                qDebug() << this << "onRelLeftButton remove():" << relTrackFrame->pre->idx;
//                onRelLeftButton(relTrackFrame);
            }
        }
    }

    void renameBackward(TrackFrame *cur) {
        cur->setIdx(cur->idx - 1);
        if (cur->next) {
            renameBackward(cur->next);
        }
    }

    //右拉rightbutton
    void handleR(TrackFrame *cur) {
        if (cur->next) {
            _setX(cur->next, cur->x() + cur->width());
            handleR(cur->next);
        }
        else {
            _setWidth(cur->parentWidget(), cur->x() + cur->width() + 40);
        }
    }

    void handleL(TrackFrame *cur) {
        _setX(cur, cur->x() + cur->changeWidth);
        cur->changeWidth = 0;
        if (cur->pre) {
            qDebug() << "handleL" << cur->pre->idx << cur->pre->frameIdx->text();
            cur->pre->resizeFrame(cur->x());
        }
    }

    void pressAndMoveEvent() {
        if (isPressLeftButton || isPressRightButton) {
            int posX = mapFromGlobal(QCursor::pos()).x();
            if (isPressRightButton) {
                if (posX > width() + 30) {
                    setHoldFrameCount(_trackFrameInfo->getHoldFrame() + 1, 1);
                    handleR(this);
                }
                else if (posX < width() - 30 and _trackFrameInfo->getHoldFrame() > 1) {
                    setHoldFrameCount(_trackFrameInfo->getHoldFrame() - 1, 1);
                    handleR(this);
                }
            }
            else if (isPressLeftButton) {
                if (posX < -30) {
                    setHoldFrameCount(_trackFrameInfo->getHoldFrame() + 1, -1);
                    handleL(this);
                }
                else if (posX > 30 && _trackFrameInfo->getHoldFrame() > 1) {
                    setHoldFrameCount(_trackFrameInfo->getHoldFrame() - 1, -1);
                    handleL(this);
                }
            }
        }
    }


    void paintThumb() {
        QPainter pg(this->thumb);
        QLinearGradient lg(0, 0, 0, 38);
        lg.setColorAt(0.0, QColor(0x343434));
        lg.setColorAt(0.5, QColor(0x606060));
        lg.setColorAt(1.0, QColor(0x343434));
        pg.setBrush(QBrush(lg));
        pg.drawRect(0, 2, width(), 36);
        int frameWidth = app.trackModel->frameWidth;
        QPainter p(this->thumb);
        QPen pen(QColor(0xc8c8c8));
        p.setPen(pen);
        p.drawLine(0, 1, this->thumb->width(), 1);
        p.drawLine(0, this->thumb->height() - 2 - 10, this->thumb->width(), this->thumb->height() - 2 - 10);
        p.fillRect(0, 9, frameWidth, 22, QColor(0xffffff));
        pen.setColor(QColor(0x343434));
        p.setPen(pen);
        p.drawLine(0, this->thumb->height() - 1 - 10, this->thumb->width(), this->thumb->height() - 1 - 10);
        p.drawLine(0, 0, 0, this->thumb->height());
        p.drawLine(0, 0, this->thumb->width(), 0);

        QPainter pm(this->thumb);
        if (this->thumbPixmap != NULL) {
            pm.drawPixmap(int((frameWidth - 2 - this->thumbPixmap->width()) * .5),
                          int((22 - this->thumbPixmap->height()) * .5 + 9),
                          *this->thumbPixmap);
        }
    }

    QPixmap *thumbPixmap;
    QLabel *frameIdx;
    OverWidget<QPushButton> *leftButton;
    OverWidget<QPushButton> *rightButton;
};


#endif //SEQTRUAN_TRACKFRAME_H
