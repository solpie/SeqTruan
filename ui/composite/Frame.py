__author__ = 'toramisu'
from ui import *
from utils import B


class Frame(QWidget):
    def __init__(self, parent):
        super(Frame, self).__init__(parent)
        B.fillColor(self, TIMELINE_TRACK_FRAME_BG)
        self.thumb = None
        self.resize(45, 75)
        pass

    def setPixmap(self, img):
        self.thumbWidth = img.width()
        self.thumbHeight = img.height() / img.width() * self.width()
        self.thumb = img.scaled(self.width(), self.thumbHeight)
        pass

    def paintEvent(self, QPaintEvent):
        B.drawPixmap(self, self.thumb, 5, 5)
        pass
