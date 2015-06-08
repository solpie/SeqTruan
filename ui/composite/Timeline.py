__author__ = 'toramisu'
from ui import *
from utils import B
from module.Events import *
from .Track import Track
from .Cursor import Cursor


class Timeline(QWidget):
    def __init__(self, parent):
        super(Timeline, self).__init__(parent)
        height = 280
        vSlider = QSlider(self)
        vSlider.move(285, 0)
        vSlider.resize(15, height)
        Qss.setStyle(vSlider, ':qss_slider')

        self.tracks = [Track(self)]
        self.resize(1280, height)
        # self.setStyleSheet('QWidget { background: red; }')
        B.fillColor(self, TIMELINE_COL_BG)
        Event.add(ActionEvent.LOAD_SEQ, self.onLoadImg)

        self.frameCursor = Cursor(self)
        self.frameCursor.move(305, 0)

        self.mouseMoveEvent = self.onMove
        self.mousePressEvent = self.onPress
        self.mouseReleaseEvent = self.onRelease

        self.isPress = False
        self.lastX = 0
        self.setMouseTracking(True)

    def onPress(self, e):
        self.isPress = True
        self.lastX = e.x()
        pass

    def onRelease(self, e):
        self.isPress = False
        self.lastX = 0
        pass

    def onMove(self, e):
        px = int(e.localPos().x() / 40) * 40
        if self.isPress:
            self.frameCursor.move(px, self.frameCursor.y())
        pass

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
