__author__ = 'toramisu'
from  ui import *


class TrackPanel(QWidget):
    def __init__(self, parent=None):
        super(TrackPanel, self).__init__(parent)
        self.opacitySlider = QSlider(0x1, self)
        self.opacitySlider.move(200, 37)
        self.opacitySlider.resize(80, 15)
        self.opacitySlider.setRange(0, 100)
        self.opacitySlider.setValue(100)
        setStyle(self.opacitySlider, ':qss_slider')
        connect(self.opacitySlider.valueChanged, self.onOpacityChanged)

        self.trackNameLabel = QLabel(self)
        self.trackNameLabel.move(5, 5)

        self.visibleButton = QCheckBox(self)
        self.visibleButton.move(200, 5)

        self.resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, TIMELINE_TRACK_DEF_HEIGHT)
        pass

    def onOpacityChanged(self, value):
        # value 0~100
        pass

    def setTrackName(self, name):
        self.trackNameLabel.setText(name)
        pass
