__author__ = 'toramisu'
from ui import *
from .TrackPanel import TrackPanel


class TrackPanelArea(QScrollArea):
    def __init__(self, parent):
        super(TrackPanelArea, self).__init__(parent)
        self.trackPanelStack = QWidget(self)
        self.trackPanelStack.resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, 10)
        self.vbox = QVBoxLayout(self.trackPanelStack)
        self.trackPanels = []

    def addTrackPanel(self, trackInfo):
        tp = TrackPanel()
        tp.setTrackName(trackInfo.name)
        self.trackPanelStack.resize(self.trackPanelStack.width(), self.trackPanelStack.height() + tp.height())
        self.vbox.addWidget(tp)
        self.trackPanels.append(tp)
        pass
