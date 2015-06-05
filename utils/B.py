__author__ = 'toramisu'

from ui import *
class B():
    @staticmethod
    def drawRect(obj, col, x, y, width, height):
        p = QPainter(obj)
        qColor = QColor(col)
        p.fillRect(x,y,width,height,qColor)
        pass
