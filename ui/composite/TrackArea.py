__author__ = 'toramisu'
from ui import *
from .Cursor import Cursor


class TrackArea(QScrollArea):
    def __init__(self, parent):
        super(TrackArea, self).__init__(parent)
        self.trackStack = QWidget(self)
        self.trackStack.mousePressEvent = ignoreEvent
        self.vbox = QVBoxLayout(self.trackStack)
        self.trackStack.move(20, 0)
        self.trackStack.resize(1280, 10)
        self.eventFilter = self.onEventFilter
        self.frameCursor = Cursor(self)

        self.mouseMoveEvent = self.onMove
        self.mousePressEvent = self.onPress
        self.mouseReleaseEvent = self.onRelease
        self.setMouseTracking(True)

        self.isPress = False
        self.lastX = 0

    def onEventFilter(self, obj, e):
        print(e)
        pass

    def addTrack(self, track):
        self.trackStack.resize(self.trackStack.width(), self.trackStack.height() + track.height())
        self.vbox.addWidget(track)
        pass

    def onPress(self, e):
        self.isPress = True
        pass

    def onRelease(self, e):
        self.isPress = False
        pass

    def onMove(self, e):
        if self.isPress:
            px = int(e.localPos().x() / 40) * 40
            if px >= 0:
                self.frameCursor.move(px, self.frameCursor.y())
        pass
