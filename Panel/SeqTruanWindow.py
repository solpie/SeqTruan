__author__ = 'toramisu'
from PyQt5.QtGui import QWindow, QPixmap, QIcon, QPainter, QBrush, QColor, QFont
from Module.App import App
from Module.Events import Event
from PyQt5.QtWidgets import QMainWindow, QLabel, QWidget
from Panel.Viewport import Viewport
from PyQt5.QtOpenGL import QGLWidget

# class SeqTruanWindow(QGLWidget):
#     def __init__(self, parent=None):
#         super(SeqTruanWindow, self).__init__( parent)
class SeqTruanWindow(QMainWindow):
    def __init__(self):
        super(SeqTruanWindow, self).__init__()
        self.initModule()
        # app = App()
        self.resize(1440, 900)
        # self.paintEvent = self.onPaint
        self.mainWidget = QWidget()
        self.__viewport = Viewport(self.mainWidget)
        self.setCentralWidget(self.mainWidget)
        self.mouseDoubleClickEvent = self.onDoubleClk
        self.wheelEvent = self.onWheel

        self.test()
        pass

    def initModule(self):
        Event().init()
        App().init()
        pass

    def onDoubleClk(self, e):
        self.__viewport.load()
        pass

    def onWheel(self, e):
        dy = e.angleDelta().y()
        if dy > 0:
            self.__viewport.zoomIn()
        else:
            self.__viewport.zoomOut()
        print('wheel', e.pixelDelta().y(), e.angleDelta())
        pass

    def onPaint(self, e):
        print('paint event')
        pass

    def test(self):
        App().sequencePlayback.load('test')
        # App().audioPlayback.load("test/test1.mp3")
        # App().audioPlayback.setVolume(0)
        pass
