__author__ = 'toramisu'
from ui import *
from utils import B
from module.C import *

class Timeline(QWidget):
    def __init__(self, parent):
        super(Timeline, self).__init__(parent)
        self.layers = None
        self.tracks = None
        self.resize(1280, 315)

    def paintEvent(self, QPaintEvent):
        B.drawRect(self, TIMELINE_COL_BG, 0, 0, self.width(), self.height())
        pass
