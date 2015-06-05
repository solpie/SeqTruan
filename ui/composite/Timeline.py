__author__ = 'toramisu'
from ui import *
from utils import B
from module.Events import *
from .Track import Track


class Timeline(QWidget):
    def __init__(self, parent):
        super(Timeline, self).__init__(parent)
        height = 280
        vSlider = QSlider(self)
        vSlider.move(285, 0)
        vSlider.resize(15, height)

        self.tracks = [Track(self)]
        self.resize(1280, height)
        B.fillColor(self, TIMELINE_COL_BG)
        Event.add(ActionEvent.LOAD_SEQ, self.onLoadImg)

    def onLoadImg(self, images):
        self.tracks[0].load(images)
        pass

    def paintEvent(self, QPaintEvent):
        # B.drawRoundRect(self,TIMELINE_COL_BG,0,0, self.width(),self.height(),5)
        # B.drawRect(self, TIMELINE_COL_BG, 0, 0, self.width(), self.height())
        # B.drawRect(self, TIMELINE_COL_BG, 0, 0, self.width(), self.height())
        pass

    def newTrack(self):
        pass
