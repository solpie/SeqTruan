__author__ = 'toramisu'
from ui import *
from .Cursor import Cursor
from .Track import Track

from module.Events import *


class TrackArea(QWidget):
    def __init__(self, parent):
        super(TrackArea, self).__init__(parent)
        self.startFrameIdx = 1
        self.timestampBar = QWidget(self)
        self.timestampBar.resize(1280, 25)
        self.timestampBar.setStyleSheet(
            'background-color:rgb(62,62,62)'
        )

        self.trackStack = QWidget(self)
        # self.trackStack.mousePressEvent = ignoreEvent
        self.vbox = QVBoxLayout(self.trackStack)
        self.vbox.setSpacing(0)
        self.trackStack.move(0, self.timestampBar.height())
        self.trackStack.resize(1280, 10)

        self.setMouseTracking(True)
        self.timestampBar.setMouseTracking(True)

        self.frameCursor = Cursor(self)
        self.frameCursor.attach(self.timestampBar)
        self.frameCursor.move(40, 0)
        self.tracks = []
        Event.add(SequencePlaybackEvent.RENDER_FRAME, self.onRenderFrame)

    def onRenderFrame(self, SequencePlaybackEvent):
        setX(self.frameCursor, SequencePlaybackEvent.frameIdx * 40)

    def resizeEvent(self, QResizeEvent):
        setHeight(self.frameCursor, self.height())

    def addTrack(self, trackInfo):
        track = Track()
        track.trackInfo = trackInfo
        # if len(trackInfo.frames):
        track.load(trackInfo.frames)
        self.trackStack.resize(self.trackStack.width(), self.trackStack.height() + track.height())
        self.vbox.addWidget(track)
        self.tracks.append(track)
        pass
