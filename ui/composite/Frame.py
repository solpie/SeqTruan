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
        self.thumb = img
        self.thumbWidth  = img.width()
        self.thumbHeight = self.thumb.height() / self.width() * self.width()
        pass

    def paintEvent(self, QPaintEvent):
        B.drawPixmap(self, self.thumb.scaled(self.width(), self.thumbHeight), 5, 5)
        pass
