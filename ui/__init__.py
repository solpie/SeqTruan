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
from PyQt5.QtGui import (QImage, QPalette, QPixmap, QPainter, QBrush, QCursor,
                         QMouseEvent,
                         QColor, QPen, QPainterPath, QLinearGradient)


def connect(signal, func):
    signal.connect(func)


def ignoreEvent(e):
    e.ignore()


def setMouseTransparent(obj):
    obj.setAttribute(Qt.WA_TransparentForMouseEvents, True)


from qss.qrc import *
from PyQt5.QtCore import QFile


def setStyle(widget, aliasPath, objName=None):
    file_qss = QFile(aliasPath)
    file_qss.open(QFile.ReadOnly)
    ba = file_qss.readAll()
    s = bytes(ba.data()).decode()
    if objName:
        widget.setObjectName(objName)
    widget.setStyleSheet(s)
    file_qss.close()


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
        self.__lastX = self.widget.mapFromGlobal(QCursor.pos()).x()
        self.__lastY = self.widget.mapFromGlobal(QCursor.pos()).y()
        # print(self.widget.mapFromGlobal(QCursor.pos()).x(), QCursor.pos().x(), e.pos().x())
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
    do.widget = obj
    obj.mousePressEvent = do.onPress
    obj.mouseMoveEvent = do.onMove
    obj.mouseReleaseEvent = do.onRels
    pass


from .Transport import Transport
from .Viewport import Viewport
from .Theme import *
