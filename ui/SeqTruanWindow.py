__author__ = 'toramisu'
from ui import *
from ui.composite import Timeline


class SeqTruanWindow(QMainWindow):
    def __init__(self):
        super(SeqTruanWindow, self).__init__()
        self.resize(1440, 900)
        self.mainWidget = QWidget()
        self.__viewport = Viewport(self.mainWidget)
        self.__timeline = Timeline(self.mainWidget)
        self.__timeline.move(0, 720)
        self.setCentralWidget(self.mainWidget)
        self.mouseDoubleClickEvent = self.onDoubleClk
        self.wheelEvent = self.onWheel

        pass

    def test(self):
        self.__timeline.tracks
        pass

    # def initModule(self):
    #     # Event().init()
    #     # App().init()
    #     pass

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
