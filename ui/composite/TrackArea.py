__author__ = 'toramisu'
from ui import *
from .Cursor import Cursor


class TrackArea(QScrollArea):
    def __init__(self, parent):
        super(TrackArea, self).__init__(parent)


        self.timestampBar = QWidget()
        self.timestampBar.resize(1280, 25)

        self.trackStack = QWidget(self)
        self.trackStack.mousePressEvent = ignoreEvent
        self.vbox = QVBoxLayout(self.trackStack)
        self.trackStack.move(20, self.timestampBar.height())
        self.trackStack.resize(1280, 10)

        # self.eventFilter = self.onEventFilter

        # self.mouseMoveEvent = self.onMove
        # self.mousePressEvent = self.onPress
        # self.mouseReleaseEvent = self.onRelease
        self.setMouseTracking(True)
        self.timestampBar.setMouseTracking(True)

        self.frameCursor = Cursor(self)
        self.frameCursor.attach(self)
        # self.frameCursor.installEventFilter(self)



    def onEventFilter(self, obj, e):
        if isinstance(obj, Cursor):
            if isinstance(e, QMouseEvent):
                e.ignore()
            pass
        pass

    def addTrack(self, track):
        self.trackStack.resize(self.trackStack.width(), self.trackStack.height() + track.height())
        self.vbox.addWidget(track)
        pass

    # def onPress(self, e):
    #     self.frameCursor.isPress = True
    #     pass
    #
    # def onRelease(self, e):
    #     self.frameCursor.isPress = False
    #     pass
    #
    # def onMove(self, e):
    #     print(self.frameCursor.isPress)
    #     if self.frameCursor.isPress:
    #         px = int(e.localPos().x() / 40) * 40
    #         if px >= 0:
    #             self.frameCursor.move(px, self.frameCursor.y())
    #     pass
