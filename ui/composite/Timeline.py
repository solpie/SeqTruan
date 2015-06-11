__author__ = 'toramisu'
from ui import *
from utils import B
from module.Events import *
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

        self.trackArea = TrackArea(self)
        self.trackArea.move(TIMELINE_TRACK_PANEL_DEF_WIDTH, 0)
        self.trackArea.resize(1280, height)
        Event.add(TracksModelEvent.NEW_TRACK, self.onNewTrack)

        vScrollBar = QScrollBar(2, self)
        self.lastVScrollValue = 0
        vScrollBar.setPageStep(100)
        vScrollBar.move(TIMELINE_TRACK_PANEL_DEF_WIDTH - 15, self.trackToolBar.height())
        vScrollBar.resize(15, 235)
        connect(vScrollBar.valueChanged, self.onVScrollBar)
        self.vScrollBar = vScrollBar

        hScrollBar = QScrollBar(1, self)
        self.lastHScrollValue = 0
        hScrollBar.move(vScrollBar.x() + vScrollBar.width() + 1, vScrollBar.y() + vScrollBar.height() + 1)
        hScrollBar.resize(500, 15)
        hScrollBar.setPageStep(200)
        setStyle(hScrollBar, ':qss_scrollBar')
        setStyle(vScrollBar, ':qss_scrollBar')
        connect(hScrollBar.valueChanged, self.onHScrollBar)
        self.hScrollBar = hScrollBar
        self.resize(1280, height)

        B.fillColor(self, TIMELINE_COL_BG)
        # self.setObjectName('timeline')
        # self.setStyleSheet('QWidget{background:#484848;}')
        Event.add(ActionEvent.LOAD_SEQ, self.onLoadImg)

    def onHScrollBar(self, e):
        dx = self.lastHScrollValue - self.hScrollBar.value()
        self.lastHScrollValue = self.hScrollBar.value()
        self.trackArea.scroll(dx, 0)
        pass

    def onVScrollBar(self, e):
        dy = self.lastVScrollValue - self.vScrollBar.value()
        self.lastVScrollValue = self.vScrollBar.value()
        self.trackPanelArea.scroll(0, dy)
        self.trackArea.trackStack.scroll(0, dy)
        pass

    def onNewTrack(self, trackInfo):
        self.trackArea.addTrack(trackInfo)
        self.trackPanelArea.addTrackPanel(trackInfo)
        self.vScrollBar.setRange(0, self.trackArea.trackStack.height() - self.vScrollBar.height())
        print('vSlider range', self.vScrollBar.minimum(), self.vScrollBar.maximum())
        pass

    def onLoadImg(self, images):
        self.trackArea.tracks[0].load(images)
        pass

    def paintEvent(self, QPaintEvent):
        # B.drawRoundRect(self,TIMELINE_COL_BG,0,0, self.width(),self.height(),5)
        # B.drawRect(self, TIMELINE_COL_BG, 0, 0, self.width(), self.height())
        # B.drawRect(self, TIMELINE_COL_BG, 0, 0, self.width(), self.height())
        pass

    def newTrack(self):
        pass
