__author__ = 'toramisu'
from ui import *


class Cursor(QWidget):
    def __init__(self, parent):
        super(Cursor, self).__init__(parent)
        self.resize(42, 200)
        # self.mouseMoveEvent = self.onMove
        # self.mousePressEvent = self.onPress
        # self.mouseReleaseEvent = self.onRelease
        # self.isPress = False
        # self.lastX = 0
        # self.setMouseTracking(True)
        self.timeLabel = QLabel(self)
        self.timeLabel.move(2, 10)
        self.timeLabel.setText('00:00:24')
        pass

    # def onPress(self, e):
    #     self.isPress = True
    #     self.lastX = e.x()
    #     pass
    #
    # def onRelease(self, e):
    #     self.isPress = False
    #     self.lastX = 0
    #     pass
    #
    # def onMove(self, e):
    #     px = int(e.localPos().x() / 40) * 40
    #     if self.isPress:
    #         self.move(px, self.y())
    #     pass

    def paintEvent(self, QPaintEvent):
        p = QPainter(self)
        pen = QPen()
        pen.setColor(QColor(TIMELINE_CURSOR_EDGE_COL))
        p.setPen(pen)
        p.drawLine(0, 0, 0, self.height())
        p.drawLine(self.width() - 1, 0, self.width() - 1, self.height())
        pass
