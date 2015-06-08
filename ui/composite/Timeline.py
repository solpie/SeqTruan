__author__ = 'toramisu'
from ui import *
from utils import B
from module.Events import *
from .Track import Track
from .TrackArea import TrackArea
from .TrackToolBar import TrackToolBar
from .TrackPanelArea import TrackPanelArea

class Timeline(QWidget):
    def __init__(self, parent):
        super(Timeline, self).__init__(parent)
        self.trackToolBar = TrackToolBar(self)
        height = 280

        self.trackPanelArea = TrackPanelArea(self)
        self.trackPanelArea.move(0, self.trackToolBar.height())
        self.trackPanelArea.resize(1280, height)
        # self.trackPanels = [TrackPanel(self.vScroll)]

        vSlider = QSlider(self)
        vSlider.move(285, self.trackToolBar.height())
        vSlider.resize(15, height)
        Qss.setStyle(vSlider, ':qss_slider')

        self.trackArea = TrackArea(self)
        self.trackArea.move(300, 0)
        self.trackArea.resize(1280, height)
        Event.add(TracksModelEvent.NEW_TRACK, self.onNewTrack)

        self.tracks = [Track()]
        self.trackArea.addTrack(self.tracks[0])
        # self.trackArea.addTrack(self.tracks[1])

        self.resize(1280, height)
        # self.setStyleSheet('QWidget { background: red; }')
        B.fillColor(self, TIMELINE_COL_BG)
        Event.add(ActionEvent.LOAD_SEQ, self.onLoadImg)

    def onNewTrack(self, trackInfo):
        track = Track()
        track.trackInfo = trackInfo
        self.tracks.append(track)
        self.trackArea.addTrack(track)

        self.trackPanelArea.addTrackPanel(trackInfo)
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
