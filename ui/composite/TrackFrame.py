__author__ = 'toramisu'
from ui import *
from utils import B
from module.Events import *

class TrackFrame(QWidget):
    def __init__(self, parent):
        super(TrackFrame, self).__init__(parent)
        # B.fillColor(self, TIMELINE_TRACK_FRAME_BG)
        self.thumb = None
        self.relayout = None
        self.changeWidth = 0
        self.resize(40, 60)
        self.holdFrameCount = 1
        self.holdFrameCountLabel = None
        self.frameIdx = QLabel(self)
        self.frameIdx.move(2, 40)
        self.frameIdx.setText('0')

        self.leftButton = QPushButton(self)
        self.isPressLeftButton = False
        self.leftButton.resize(8, 8)
        self.leftButton.setStyleSheet(
            'QPushButton{'
            # 'background-color:red;'
            'border-width: 1px;'
            'border-color: beige;}')
        self.leftButton.mousePressEvent = self.onPressLeftButton
        self.leftButton.mouseReleaseEvent = self.onRels

        self.rightButton = QPushButton(self)
        self.isPressRightButton = False
        self.rightButton.resize(8, 8)
        self.rightButton.move(32, 32)
        self.rightButton.mousePressEvent = self.onPressRightButton
        self.rightButton.mouseReleaseEvent = self.onRels

        self.rightButton.setStyleSheet(
            'QPushButton{'
            # 'background-color:red;'
            'border-width: 1px;'
            'border-color: beige;}')
        self.mousePressEvent = self.onPress
        self.mouseMoveEvent = self.onMove
        self.mouseReleaseEvent = self.onRels
        self.isPress = False

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
            pass
        pass

    def onPress(self, e):
        self.isPress = True

    def onPressRightButton(self, e):
        self.isPress = True
        self.isPressRightButton = True

    def onPressLeftButton(self, e):
        self.isPress = True
        self.isPressLeftButton = True

    def getIdx(self):
        return int(self.frameIdx.text())

    def setPixmap(self, img):
        self.thumbWidth = img.width()
        self.thumbHeight = img.height() / img.width() * (self.width() - 2)
        self.thumb = img.scaled(self.width(), self.thumbHeight)
        pass

    def setIdx(self, idx):
        self.frameIdx.setText(str(idx))

    def paintEvent(self, QPaintEvent):
        B.drawPixmap(self, self.thumb, 1, 9)
        pass

    def setHoldFrameCount(self, count, dx=1):
        self.changeWidth = (count - self.holdFrameCount) * TIMELINE_TRACK_FRAME_MAX_WIDTH * dx
        self.resize(count * TIMELINE_TRACK_FRAME_MAX_WIDTH, self.height())
        self.rightButton.move(self.width() - self.rightButton.width(), self.rightButton.y())
        self.holdFrameCount = count
        if count > 1:
            if not self.holdFrameCountLabel:
                self.holdFrameCountLabel = QLabel(self)
                self.holdFrameCountLabel.setAlignment(Qt.AlignRight)
                self.holdFrameCountLabel.setWordWrap(True)
                self.holdFrameCountLabel.setMinimumWidth(15)
                # self.holdFrameCountLabel.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Ignored)
                self.holdFrameCountLabel.show()
            self.holdFrameCountLabel.setText(str(count))
            self.holdFrameCountLabel.move(40 * count - 20, 10)
            print('holdFrameCountLabel', self.holdFrameCountLabel.text(), self.holdFrameCountLabel.rect(),
                  self.holdFrameCountLabel.x())
