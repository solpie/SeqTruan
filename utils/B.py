__author__ = 'toramisu'

from ui import *


class B():
    @staticmethod
    def drawRoundRect(obj, col, x, y, width, height, r=0):
        rp = QPainterPath()
        rp.addRoundedRect(x, y, width, height, r, r)
        rp.closeSubpath()

        p = QPainter(obj)
        p.setRenderHint(QPainter.Antialiasing)
        qColor = QColor(col)

        # gradient = QLinearGradient(0, 0, 0, 100)
        # gradient.setColorAt(0, col)
        # gradient.setColorAt(1, col)
        b = QBrush()
        b.setColor(qColor)
        p.drawPath(rp)
        # p.fillPath(rp,b)
        # p.drawPath(rp)
        pass

    @staticmethod
    def drawRect(obj, col, x, y, width, height):
        p = QPainter(obj)
        qColor = QColor(col)
        p.fillRect(x, y, width, height, qColor)
        pass

    @staticmethod
    def drawPixmap(obj, pixmap, x, y, width=0, height=0):
        p = QPainter(obj)
        if width == 0:
            width = pixmap.width()
            pass
        if height == 0:
            height = pixmap.height()
            pass
        p.drawPixmap(x, y, width, height, pixmap)
        pass

    @staticmethod
    def fillColor(qwidget, color):
        qwidget.setAutoFillBackground(True)
        p = qwidget.palette()
        p.setColor(qwidget.backgroundRole(), QColor(color))
        qwidget.setPalette(p)
        pass
