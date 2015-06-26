#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_TRACKFRAME_H
#define SEQTRUAN_TRACKFRAME_H

#include "view/UI.hpp"
#include "utils/Linker.hpp"
#include "model/ImageLoader.hpp"

class TrackFrame : public QWidget, public OneLinker<TrackFrame> {
Q_OBJECT
public:
    int idx() {
        return trackFrameInfo->getIdx();
    }

    QLabel *holdFrameCountLabel = nullptr;
    bool isPressLeftButton = false;
    bool isPressRightButton = false;
    int changeWidth = 0;
    int changeDir = 0;
    //拖拽方向
    TrackFrameInfo *trackFrameInfo;
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
        leftButton->add(mousePressEvent_, [this](void *e) { isPressLeftButton = true; });
        leftButton->add(mouseMoveEvent_, [this](void *e) { this->pressAndMoveEvent(); });
        leftButton->add(mouseReleaseEvent_, [this](void *e) {
            isPressLeftButton = false;
            this->onRelLeftButton(this);
        });
        UI::setQss(leftButton, ":/qss_button", "frameButton");

        rightButton = new OverWidget<QPushButton>(this);
        rightButton->resize(8, 8);
        rightButton->move(33, 32);
        rightButton->isCustomQss = true;
        rightButton->add(mousePressEvent_, [this](void *e) { isPressRightButton = true; });
        rightButton->add(mouseMoveEvent_, [this](void *e) { this->pressAndMoveEvent(); });
        rightButton->add(mouseReleaseEvent_, [this](void *e) { isPressRightButton = false; });
        UI::setQss(rightButton, ":/qss_button", "frameButton");
        setMouseTracking(true);
    }

    void setPixmap(QImage *qImage) {
        if (qImage) {
            int thumbHeight = int(float(qImage->height()) / qImage->width() * (this->width() - 2));
            thumbPixmap = new QPixmap(
                    QPixmap::fromImage(qImage->scaled(this->width() - 2, thumbHeight, Qt::KeepAspectRatio)));
        }
    }


    void setIdx(int trackFrameIdx) {
        trackFrameInfo->setIdx(trackFrameIdx);
        QString s = QString::number(trackFrameIdx + 1);
        frameIdx->setText(s);
    }

    //dir 方向 -1 向左
    void setHoldFrameCount(int count, int dir = 1) {
        int frameWidth = _app.trackModel->frameWidth;
        changeWidth = (count - trackFrameInfo->getHoldFrame()) * frameWidth * dir;
        trackFrameInfo->setHoldFrame(count);

        if (dir < 0) {
            trackFrameInfo->setStartFrame(trackFrameInfo->getStartFrame() + count);
        }
        UI::setWidth(this, count * frameWidth);
        UI::setWidth(thumb, width());
        UI::setX(rightButton, width() - rightButton->width() + 1);
        qDebug() << this << "setHoldFrameCount" << this->frameIdx->text() << "width" << width();
        updateFrameCountLabel();
    }

    void updateFrameCountLabel() {
        int idx = trackFrameInfo->getIdx();
        setIdx(idx);

        int count = trackFrameInfo->getHoldFrame();
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
            holdFrameCountLabel->move(_app.trackModel->frameWidth * count - 20, 10);
        }
    }

    void resizeFrame(TrackFrame *tf, int w) {
        UI::setWidth(tf, w);
        UI::setWidth(tf->thumb, tf->width());
        UI::setX(tf->rightButton, tf->width() - tf->rightButton->width() + 1);
        int fCount = tf->width() / _app.trackModel->frameWidth;
        tf->setHoldFrameCount(fCount, 0);
    }

    void updateFrameWidth() {
        int w = trackFrameInfo->getHoldFrame() * _app.trackModel->frameWidth;
        UI::setWidth(this, w);
        UI::setWidth(this->thumb, w);
        UI::setX(this->rightButton, w - this->rightButton->width() + 1);
    }

    void setTrackFrameInfo(TrackFrameInfo *tfi) {
        trackFrameInfo = tfi;
        connect(trackFrameInfo->imageLoader, tfi->imageLoader->imageLoaded, [this](QImage *q) { this->onLoaded(q); });
        tfi->imageLoader->start();
    }

    void onLoaded(QImage *q) {
        qDebug() << this << "update()";
        setPixmap(q);
        update();
    }

    OverWidget<QWidget> *thumb;
    OverWidget<QPushButton> *leftButton;
    OverWidget<QPushButton> *rightButton;
signals:

    void resizeTail();

protected:
    ImageLoader *loader = nullptr;

    void onRelLeftButton(TrackFrame *relTrackFrame) {
//        qDebug() << this << "onRelLeftButton() idx:" << relTrackFrame->pre->idx() << "changeDir:" <<
//        relTrackFrame->changeDir;
//        if (relTrackFrame->changeDir < 0) {
//            //fixme 删除两个
//            relink(relTrackFrame);
////                    //fixme idx bug
////                    TrackFrame *deleteMe = relTrackFrame->pre->remove();//todo 释放资源 保存历史操作
////                    TrackFrameInfo *deleteMeInfo = trackFrameInfo->pre->remove();//todo 释放资源 保存历史操作
//        }
//        relTrackFrame->changeDir = 0;
        TrackFrame::reLink2(relTrackFrame);
    }


    void reIdxBackward(TrackFrame *cur, int idx) {
        cur->setIdx(idx);
        if (cur->next) {
            reIdxBackward(cur->next, ++idx);
        }
    }

    //右拉rightbutton
    void handleR(TrackFrame *cur) {
        if (cur->next) {
            UI::setX(cur->next, cur->x() + cur->width());
            handleR(cur->next);
        }
        else {
            UI::setWidth(cur->parentWidget(), cur->x() + cur->width());
            emit resizeTail();
        }
    }

    void handleL(TrackFrame *cur) {
        UI::setX(cur, cur->x() + cur->changeWidth);
        if (cur->pre) {
            resizeFrame(cur->pre, cur->x() - cur->pre->x());
        }
        qDebug() << "handleL" << cur->pre->idx() << cur->pre->frameIdx->text();
        cur->changeWidth = 0;
    }


    void pressAndMoveEvent() {
        int drag = 30;
        if (isPressLeftButton || isPressRightButton) {
            int posX = mapFromGlobal(QCursor::pos()).x();
            if (isPressRightButton) {
                if (posX > width() + drag) {
                    this->changeDir += 1;
                    setHoldFrameCount(trackFrameInfo->getHoldFrame() + 1, 1);
                    handleR(this);
                }
                else if (posX < width() - drag and trackFrameInfo->getHoldFrame() > 1) {
                    this->changeDir -= 1;
                    setHoldFrameCount(trackFrameInfo->getHoldFrame() - 1, 1);
                    handleR(this);
                }
            }
            else if (isPressLeftButton) {
                if (posX < -drag) {//向左拖拽
                    this->changeDir -= 1;
                    TrackFrame::resizeFrame2(this, -1, 1, true);
//                    setHoldFrameCount(trackFrameInfo->getHoldFrame() + 1, -1);
//                    handleL(this);
                }
                else if (posX > drag && trackFrameInfo->getHoldFrame() > 1) {
                    this->changeDir += 1;
                    setHoldFrameCount(trackFrameInfo->getHoldFrame() - 1, -1);
                    handleL(this);
                }
            }
        }
    }


    void paintThumb(void *e) {
        QPainter pg(this->thumb);
        QLinearGradient lg(0, 0, 0, 38);
        lg.setColorAt(0.0, QColor(0x343434));
        lg.setColorAt(0.5, QColor(0x606060));
        lg.setColorAt(1.0, QColor(0x343434));
        pg.setBrush(QBrush(lg));
        pg.drawRect(0, 2, width(), 36);
        int frameWidth = _app.trackModel->frameWidth;
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


        if (this->thumbPixmap) {
            QPainter pm(this->thumb);
            pm.drawPixmap(int((frameWidth - 2 - this->thumbPixmap->width()) * .5),
                          int((22 - this->thumbPixmap->height()) * .5 + 9),
                          *this->thumbPixmap);
        }
    }

    QPixmap *thumbPixmap = nullptr;
    QLabel *frameIdx;
    ////////////////////////////////////      VM           //////////////////////////////
private:
    static void resizeFrame2(TrackFrame *cur, int dtStartFrame, int dtCount, bool isLeftButton) {
        int frameWidth = _app.trackModel->frameWidth;
        int startFrame = cur->trackFrameInfo->getStartFrame();
        cur->trackFrameInfo->setStartFrame(startFrame + dtStartFrame);


        cur->trackFrameInfo->setHoldFrame(cur->trackFrameInfo->getHoldFrame() + dtCount);
        cur->updateFrameWidth();
        if (isLeftButton) {
            UI::setX(cur, cur->x() + dtStartFrame * frameWidth);

            if (cur->pre) {
                resizeFrameByWidth(cur->pre, cur->x() - cur->pre->x());
            }
            cur->changeWidth = 0;
        }
        cur->updateFrameCountLabel();
    }

    static void resizeFrameByWidth(TrackFrame *tf, int w) {
        UI::setWidth(tf, w);
        UI::setWidth(tf->thumb, tf->width());
        UI::setX(tf->rightButton, tf->width() - tf->rightButton->width() + 1);
        int fCount = tf->width() / _app.trackModel->frameWidth;
        tf->setHoldFrameCount(fCount, 0);
        tf->updateFrameCountLabel();
    }

    static void reLink2(TrackFrame *tf) {
        relink(tf);
    }


    static void relink(TrackFrame *cur) {
        TrackFrame *preFrame = cur->pre;
        if (preFrame) {
            vector<TrackFrame *> toRemoves;
            while (preFrame->x() >= cur->x()) {
                toRemoves.push_back(preFrame);
                preFrame->hide();
                preFrame = preFrame->pre;
            }
            if (preFrame != cur->pre) {
                cur->setPre(preFrame);
                updateBackward(cur, cur->pre->idx() + 1);
            }
        }
        else {
            updateBackward(cur, 1);
        }
        qDebug() << "relink pre idx:" << cur->pre->idx();
    }

    static void updateBackward(TrackFrame *tf, int idx) {
        tf->trackFrameInfo->setIdx(idx);
        tf->updateFrameCountLabel();
        if (tf->next)
            updateBackward(tf->next, ++idx);
    }
};


#endif //SEQTRUAN_TRACKFRAME_H
