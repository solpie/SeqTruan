__author__ = 'toramisu'
from  ui import *
from module.Events import *


class TrackToolBar(QWidget):
    def __init__(self, parent):
        super(TrackToolBar, self).__init__(parent)
        self.resize(250, 25)
        self.newTrackButton = QPushButton(self)
        self.newTrackButton.setText('new Track')
        self.newTrackButton.mousePressEvent = self.onPressNewTrack

    def onPressNewTrack(self, e):
        Event.dis(ActionEvent.NEW_TRACK, 'new layer')
        pass
