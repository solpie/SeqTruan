__author__ = 'toramisu'
from ui import *
from utils import B
from module.Events import *


class TrackFrame(QWidget):
    def __init__(self, parent):
        super(TrackFrame, self).__init__(parent)
        self.thumbPixmap = None
        self.relayout = None
        self.changeWidth = 0
        self.resize(40, 60)

        self.thumb = QWidget(self)
        self.thumb.resize(40, 50)
        self.thumb.move(0, 0)
        setMouseTransparent(self.thumb)
        self.thumb.setStyleSheet(
            'border:none'
        )
        self.thumb.paintEvent = self.thumbPaintEvent
        self.holdFrameCount = 1
        self.holdFrameCountLabel = None
        self.frameIdx = QLabel(self)
        self.frameIdx.setStyleSheet('color:#b6b6b6;border:none;')
        setMouseTransparent(self.frameIdx)
        self.frameIdx.move(4, 45)
        self.frameIdx.setText('0')
        self.leftButton = QPushButton(self)
        self.isPressLeftButton = False
        self.leftButton.resize(8, 8)
        setStyle(self.leftButton, ':qss_button', 'frameButton')
        self.leftButton.mousePressEvent = self.onPressLeftButton
        self.leftButton.mouseReleaseEvent = self.onRels

        self.rightButton = QPushButton(self)
        self.isPressRightButton = False
        setStyle(self.rightButton, ':qss_button', 'frameButton')
        self.rightButton.resize(8, 8)
        self.rightButton.move(33, 32)
        self.rightButton.mousePressEvent = self.onPressRightButton
        self.rightButton.mouseReleaseEvent = self.onRels
        self.mousePressEvent = self.onPress
        self.mouseMoveEvent = self.onMove
        self.mouseReleaseEvent = self.onRels
        self.isPress = False
        self.__refSImage = None

    @property
    def refSImage(self):
        return self.__refSImage

    @refSImage.setter
    def refSImage(self, value):
        self.__refSImage = value

    def onRels(self, e):
        self.isPress = False
        self.isPressRightButton = False
        if self.isPressLeftButton:
            Event.dis(ActionEvent.RELEASE_TRACK_FRAME_LEFT_BUTTON)
            self.isPressLeftButton = False
        pass

    def onMove(self, e):
        if self.isPress:
            posX = e.pos().x()
            if self.isPressRightButton:
                if posX > self.width() + 30:
                    self.setHoldFrameCount(self.holdFrameCount + 1)
                    self.relayout(self)
                    print(self, self.width(), e.pos().x())
                elif posX < self.width() - 30 and self.holdFrameCount > 1:
                    self.setHoldFrameCount(self.holdFrameCount - 1)
                    self.relayout(self)
            elif self.isPressLeftButton:
                if posX < -30:
                    self.setHoldFrameCount(self.holdFrameCount + 1, -1)
                    self.relayout(self)
                    pass
                elif posX > 30 and self.holdFrameCount > 1:
                    self.setHoldFrameCount(self.holdFrameCount - 1, -1)
                    self.relayout(self)
                    pass
            else:
                self.parent().mouseMoveEvent(e)
            pass
        pass

    def onPress(self, e):
        self.isPress = True
        self.parent().mousePressEvent(e)

    def onPressRightButton(self, e):
        self.isPress = True
        self.isPressRightButton = True

    def onPressLeftButton(self, e):
        self.isPress = True
        self.isPressLeftButton = True

    def getIdx(self):
        return int(self.frameIdx.text().replace('.', ''))

    def setIdx(self, idx):
        self.frameIdx.setText(str(idx) + '.')

    def setPixmap(self, img):
        self.thumbWidth = img.width()
        self.thumbHeight = img.height() / img.width() * (self.width() - 3)
        self.thumbPixmap = img.scaled(self.width(), self.thumbHeight)
        pass

    def thumbPaintEvent(self, QPaintEvent):
        pg = QPainter(self.thumb)
        linearGradient = QLinearGradient(0, 0, 0, 38)
        linearGradient.setColorAt(0.0, QColor(0x343434))
        linearGradient.setColorAt(0.5, QColor(0x606060))
        linearGradient.setColorAt(1.0, QColor(0x343434))
        pg.setBrush(QBrush(linearGradient))
        pg.drawRect(0, 2, self.thumb.width(), 36)

        p = QPainter(self.thumb)
        pen = QPen()
        col = QColor(0xc8c8c8)
        pen.setColor(col)
        p.setPen(pen)
        p.drawLine(0, 1, self.thumb.width(), 1)
        p.drawLine(0, self.thumb.height() - 2 - 10, self.thumb.width(), self.thumb.height() - 2 - 10)
        p.fillRect(0, 9, TIMELINE_TRACK_FRAME_MAX_WIDTH, 22, QColor(0xffffff))
        pen.setColor(QColor(0x343434))
        p.setPen(pen)
        p.drawLine(0, self.thumb.height() - 1 - 10, self.thumb.width(), self.thumb.height() - 1 - 10)
        p.drawLine(0, 0, 0, self.thumb.height())
        p.drawLine(0, 0, self.thumb.width(), 0)

        if self.thumbPixmap:
            B.drawPixmap(self.thumb, self.thumbPixmap, 1, (22 - self.thumbPixmap.height()) * .5 + 9)
        if self.getIdx() == 1:
            pass

    def setHoldFrameCount(self, count, dx=1):
        self.changeWidth = (count - self.holdFrameCount) * TIMELINE_TRACK_FRAME_MAX_WIDTH * dx
        self.resize(count * TIMELINE_TRACK_FRAME_MAX_WIDTH, self.height())
        self.thumb.resize(self.width(), self.thumb.height())
        self.rightButton.move(self.width() - self.rightButton.width() + 1, self.rightButton.y())
        self.holdFrameCount = count
        self.refSImage.holdFrameCount = count
        if count > 1:
            if not self.holdFrameCountLabel:
                self.holdFrameCountLabel = QLabel(self)
                self.holdFrameCountLabel.setAlignment(Qt.AlignRight)
                self.holdFrameCountLabel.setWordWrap(True)
                self.holdFrameCountLabel.setStyleSheet('color:#b6b6b6;border:none;')
                self.holdFrameCountLabel.setMinimumWidth(15)
                # self.holdFrameCountLabel.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Ignored)
                self.holdFrameCountLabel.show()
            self.holdFrameCountLabel.setText(str(count))
            self.holdFrameCountLabel.move(40 * count - 20, 10)
            print('holdFrameCountLabel', self.holdFrameCountLabel.text(), self.holdFrameCountLabel.rect(),
                  self.holdFrameCountLabel.x())
