__author__ = 'toramisu'
from ui import *
from ui.composite import Timeline


class SeqTruanWindow(QMainWindow):
    def __init__(self):
        super(SeqTruanWindow, self).__init__()
        self.resize(1440, 1056)
        self.mainWidget = QWidget()
        self.vSplitter = QSplitter(Qt.Vertical, self.mainWidget)
        self.vSplitter.resize(self.width(), self.height())
        self.vSplitter.setOpaqueResize(False)

        self.__viewport = Viewport(self.vSplitter)
        self.__timeline = Timeline(self.vSplitter)
        self.__timeline.move(0, 720)
        self.setCentralWidget(self.mainWidget)
        self.mouseDoubleClickEvent = self.onDoubleClk
        self.wheelEvent = self.onWheel
        pass

    def resizeEvent(self, e):
        print(e)
        pass

    def test(self):
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
