__author__ = 'toramisu'
from ui import *


class TimestampBar(QWidget):
    def __init__(self, parent=None):
        super(TimestampBar, self).__init__(parent)
        self.setZoomLevel(ZOOM_LEVEL_NORMAL)
        fillColor(self,0x3e3e3e)

    def setZoomLevel(self, zoomLevel):
        if zoomLevel == ZOOM_LEVEL_NORMAL:
            self.paintEvent = self.paintNormal
        pass

    def paintNormal(self, e):
        p = QPainter(self)
        pen = QPen(QColor(0x343434))
        p.setPen(pen)
        for i in range(0, self.width(), TIMELINE_TRACK_FRAME_MAX_WIDTH):
            p.drawLine(i, 15, i, self.height())
            pass
        pass
