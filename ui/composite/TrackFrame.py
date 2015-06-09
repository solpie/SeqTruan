__author__ = 'toramisu'
from ui import *
from utils import B


class TrackFrame(QWidget):
    def __init__(self, parent):
        super(TrackFrame, self).__init__(parent)
        # B.fillColor(self, TIMELINE_TRACK_FRAME_BG)
        self.thumb = None
        self.resize(40, 60)

        self.frameIdx = QLabel(self)
        self.frameIdx.move(2, 40)
        self.frameIdx.setText('0')

        self.leftButton = QPushButton(self)
        self.leftButton.resize(8, 8)
        self.leftButton.setStyleSheet(
            'QPushButton{'
            # 'background-color:red;'
            'border-width: 1px;'
            'border-color: beige;}')

        self.rightButton = QPushButton(self)
        self.rightButton.resize(8, 8)
        self.rightButton.move(32, 32)
        self.rightButton.mousePressEvent = self.onPressRightButton
        self.rightButton.setStyleSheet(
            'QPushButton{'
            # 'background-color:red;'
            'border-width: 1px;'
            'border-color: beige;}')
        pass

    def onPressRightButton(self, e):
        self.resize(self.width() + 40, self.height())
        pass

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
