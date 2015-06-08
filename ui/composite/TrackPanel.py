__author__ = 'toramisu'
from  ui import *


class TrackPanel(QWidget):
    def __init__(self, parent):
        super(TrackPanel,self).__init__(parent)
        self.opacitySlider = QSlider(0x1, self)
        self.opacitySlider.move(200, 37)
        self.opacitySlider.resize(80, 15)
        self.opacitySlider.setRange(0, 100)
        self.opacitySlider.setValue(100)
        connect(self.opacitySlider.valueChanged, self.onOpacityChanged)

        pass

    def onOpacityChanged(self, value):
        # value 0~100
        pass