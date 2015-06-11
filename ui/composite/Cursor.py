__author__ = 'toramisu'
from ui import *


class Cursor(QWidget):
    def __init__(self, parent):
        super(Cursor, self).__init__(parent)
        self.resize(60, 200)

        self.isPress = False
        # self.mousePressEvent = self.onPress
        # self.mouseReleaseEvent = self.onRelease

        self.timeLabel = QLabel(self)
        self.timeLabel.move(2, 10)
        self.timeLabel.setText('00:00:24')
        self.setAttribute(Qt.WA_TransparentForMouseEvents,True)

    def attach(self, obj):
        obj.mouseMoveEvent = self.onMove
        obj.mousePressEvent = self.onPress
        obj.mouseReleaseEvent = self.onRelease
        obj.setMouseTracking(True)

    def onPress(self, e):
        self.isPress = True
        e.ignore()
        pass

    def onRelease(self, e):
        self.moveByFrame(e)
        self.isPress = False
        pass

    def moveByFrame(self, e):
        px = int(e.localPos().x() / 40) * 40
        if px >= 0:
            self.move(px, self.y())
        pass

    def onMove(self, e):
        if self.isPress:
            self.moveByFrame(e)
            # px = int(e.localPos().x() / 40) * 40
            # if px >= 0:
            #     self.move(px, self.y())
        pass

    def paintEvent(self, QPaintEvent):
        p = QPainter(self)
        pen = QPen()
        pen.setColor(QColor(TIMELINE_CURSOR_EDGE_COL))
        p.setPen(pen)
        p.drawLine(0, 0, 0, self.height())
        p.drawLine(TIMELINE_TRACK_FRAME_MAX_WIDTH, 0, TIMELINE_TRACK_FRAME_MAX_WIDTH, self.height())
        pass
