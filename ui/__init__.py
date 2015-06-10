__author__ = 'toramisu'
from PyQt5.QtWidgets import (QOpenGLWidget,
                             QWidget,
                             QPushButton,
                             QLabel,
                             QFileDialog,
                             QMessageBox,
                             QScrollArea,
                             QSizePolicy,
                             QSlider,
                             QVBoxLayout,
                             QScrollBar,
                             QCheckBox,
                             QLayout,
                             QHBoxLayout,
                             QComboBox,
                             QMainWindow)
# from PyQt5 import Qt
from PyQt5.QtCore import QDir, QRectF, Qt, QSize
from PyQt5.QtGui import (QImage, QPalette, QPixmap, QPainter, QBrush,
                         QMouseEvent,
                         QColor, QPen, QPainterPath, QLinearGradient)

from utils.Qss import Qss


def connect(signal, func):
    signal.connect(func)


def ignoreEvent(e):
    e.ignore()


class DragObject():
    def __init__(self, pressFunc=None, releaseFunc=None, moveFunc=None):
        self.isPress = False
        self.dx = 0
        self.dy = 0
        self.__lastX = 0
        self.__lastY = 0
        self.exPressFunc = pressFunc
        self.exReleaseFunc = releaseFunc
        self.exMoveFunc = moveFunc
        pass

    def onPress(self, e):
        self.isPress = True
        self.__lastX = e.pos().x()
        self.__lastY = e.pos().y()
        if self.exPressFunc:
            e.dragObject = self
            self.exPressFunc(e)
        pass

    def onMove(self, e):
        if self.isPress:
            if self.exMoveFunc:
                e.dragObject = self
                self.dx = e.pos().x() - self.__lastX
                self.dy = e.pos().y() - self.__lastY
                self.exMoveFunc(e)
            pass
        pass

    def onRels(self, e):
        self.isPress = False
        self.__lastX = 0
        self.__lastY = 0
        if self.exReleaseFunc:
            e.dragObject = self
            self.exReleaseFunc(e)
        pass


def setupDrag(obj, pressFunc=None, releaseFunc=None, moveFunc=None):
    do = DragObject(pressFunc, releaseFunc, moveFunc)
    obj.mousePressEvent = do.onPress
    obj.mouseMoveEvent = do.onMove
    obj.mouseReleaseEvent = do.onRels
    pass


from .Transport import Transport
from .Viewport import Viewport
from .Theme import *
