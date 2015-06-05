__author__ = 'toramisu'
from PyQt5.QtOpenGL import QGLWidget, QGL,QGLContext
from PyQt5.QtGui import QColor
from PyQt5.Qt import QPointF


class Canvas(QGLWidget):
    def __init__(self, parent):
        super(Canvas, self).__init__(parent)
        # self.resize(640,300)
        self.rect = QPointF(0,0)
        pass

    def paintGL(self):
        self.drawTexture(self.rect, 0)
        # self.renderPixmap(10,10)
        # self.qglColor(QColor(255, 255, 255, 255))
        pass

    def load(self, img):

        self.makeCurrent()
        self.bindTexture(img)
        self.doneCurrent()
        pass
