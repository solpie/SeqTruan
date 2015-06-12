__author__ = 'toramisu'
import os

from ui import *
from ui.Canvas import Canvas

from module.C import *
from module.Events import *
from .Transport import Transport

class Viewport(QScrollArea):
    def __init__(self, parent):
        super(Viewport, self).__init__(parent)
        self.imageLabel = QLabel()
        self.imageLabel.setBackgroundRole(QPalette.Base)
        self.imageLabel.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Ignored)
        self.imageLabel.setScaledContents(True)
        self.scaleFactor = 0.0
        # self.canvas = Canvas(self)
        self.setWidget(self.imageLabel)
        self.imageSequence = []
        Event.add(SequencePlaybackEvent.RENDER, self.onRender)
        self.transport = Transport(self)
        # self.resizeEvent(None)
        self.resize(1280, 720)
        pass

    def resizeEvent(self, QResizeEvent):
        self.transport.move(self.transport.x(), self.height() - self.transport.height())
        pass

    # def onResize(self, w, h):
    #     self.transport.move(10, h - 40)
    #     pass

    def onRender(self, img):
        # self.canvas.load(img)

        self.imageLabel.setPixmap(QPixmap.fromImage(img))
        self.imageLabel.adjustSize()
        pass

    def load(self, imagesPath=None):
        if imagesPath:
            for root, dirs, files in os.walk(imagesPath):
                for filespath in files:
                    filename = os.path.join(root, filespath).replace('\\', '/')
                    img = QImage(filename)
                    self.imageSequence.append(img)
                    print('[load img]: ', filename)
            pass
        else:
            fileName, _ = QFileDialog.getOpenFileName(self, "Open File", QDir.currentPath())
            if fileName:
                image = QImage(fileName)
                if image.isNull():
                    QMessageBox.information(self, "Image Viewer",
                                            "Cannot load %s." % fileName)
                    return

                self.imageLabel.setPixmap(QPixmap.fromImage(image))
                self.scaleFactor = 1.0
                # self.printAct.setEnabled(True)
                # self.fitToWindowAct.setEnabled(True)
                # self.updateActions()

                # if not self.fitToWindowAct.isChecked():
                #     self.imageLabel.adjustSize()
                self.imageLabel.adjustSize()
        pass

    def zoomIn(self):
        self.scaleImage(1 / VIEWPORT_ZOOM_FACTOR)
        pass

    def zoomOut(self):
        self.scaleImage(VIEWPORT_ZOOM_FACTOR)
        pass

    def scaleImage(self, factor):
        self.scaleFactor *= factor
        self.imageLabel.resize(self.scaleFactor * self.imageLabel.pixmap().size())

        # self.adjustScrollBar(self.horizontalScrollBar(), factor)
        # self.adjustScrollBar(self.verticalScrollBar(), factor)

        # self.zoomInAct.setEnabled(self.scaleFactor < 3.0)
        # self.zoomOutAct.setEnabled(self.scaleFactor > 0.333)

    def adjustScrollBar(self, scrollBar, factor):
        scrollBar.setValue(int(factor * scrollBar.value()
                               + ((factor - 1) * scrollBar.pageStep() / 2)))

    def normalSize(self):
        self.imageLabel.adjustSize()
        self.scaleFactor = 1.0
