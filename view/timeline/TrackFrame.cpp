//
// Created by manoyuria on 2015/6/19.
//

#include <model/App.h>
#include "TrackFrame.h"

TrackFrame::TrackFrame(QWidget *parent) : QWidget(parent) {
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
    leftButton->add(mouseReleaseEvent_, [this] { isPressLeftButton = false; });
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

void TrackFrame::paintThumb() {
    QPainter pg(this->thumb);
    QLinearGradient lg(0, 0, 0, 38);
    lg.setColorAt(0.0, QColor(0x343434));
    lg.setColorAt(0.5, QColor(0x606060));
    lg.setColorAt(1.0, QColor(0x343434));
    pg.setBrush(QBrush(lg));
    pg.drawRect(0, 2, width(), 36);

    QPainter p(this->thumb);
    QPen pen(QColor(0xc8c8c8));
    p.setPen(pen);
    p.drawLine(0, 1, this->thumb->width(), 1);
    p.drawLine(0, this->thumb->height() - 2 - 10, this->thumb->width(), this->thumb->height() - 2 - 10);
    p.fillRect(0, 9, TIMELINE_TRACK_FRAME_MAX_WIDTH, 22, QColor(0xffffff));
    pen.setColor(QColor(0x343434));
    p.setPen(pen);
    p.drawLine(0, this->thumb->height() - 1 - 10, this->thumb->width(), this->thumb->height() - 1 - 10);
    p.drawLine(0, 0, 0, this->thumb->height());
    p.drawLine(0, 0, this->thumb->width(), 0);

    QPainter pm(this->thumb);
    if (this->thumbPixmap != NULL) {
        pm.drawPixmap(int((TIMELINE_TRACK_FRAME_MAX_WIDTH- 2 - this->thumbPixmap->width() ) * .5),
                      int((22 - this->thumbPixmap->height()) * .5 + 9),
                      *this->thumbPixmap);
    }

}

void TrackFrame::setPixmap(QImage *qImage) {
    int thumbHeight = int(float(qImage->height()) / qImage->width() * (this->width() - 2));
    thumbPixmap = new QPixmap(QPixmap::fromImage(qImage->scaled(this->width() - 2, thumbHeight, Qt::KeepAspectRatio)));
}

void TrackFrame::pressAndMoveEvent() {
    if (isPressLeftButton || isPressRightButton) {
        int posX = mapFromGlobal(QCursor::pos()).x();
        if (isPressRightButton) {
            if (posX > width() + 30) {
                setHoldFrameCount(holdFrameCount + 1, 1);
                App()._().trackModel->relayout(trackInfoIdx,trackFrameInfoIdx);
            }
            else if (posX < width() - 30 and holdFrameCount > 1) {
                setHoldFrameCount(holdFrameCount - 1, 1);
                App()._().trackModel->relayout(trackInfoIdx,trackFrameInfoIdx);
            }
        }
        else if (isPressLeftButton) {
            if (posX < -30) {
                setHoldFrameCount(holdFrameCount + 1, -1);
                App()._().trackModel->relayout(trackInfoIdx,trackFrameInfoIdx);
            }
            else if (posX > 30 && holdFrameCount > 1) {
                setHoldFrameCount(holdFrameCount - 1, -1);
                App()._().trackModel->relayout(trackInfoIdx,trackFrameInfoIdx);
            }
        }
    }
}

void TrackFrame::setHoldFrameCount(int count, int dx = 1) {
    changeWidth = (count - holdFrameCount) * TIMELINE_TRACK_FRAME_MAX_WIDTH * dx;
    _setWidth(this, count * TIMELINE_TRACK_FRAME_MAX_WIDTH);
    _setWidth(thumb,width());
    _setX(rightButton, width() - rightButton->width() + 1);
    holdFrameCount = count;
}

void TrackFrame::setIdx(int trackFrameIdx) {
    idx = trackFrameIdx;
    QString s = QString::number(idx + 1, 10);
    frameIdx->setText(s);
}
