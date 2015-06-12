__author__ = 'toramisu'

from PyQt5.QtGui import QImage, QPixmap


class SImage():
    def __init__(self, path):
        self.frameIdx = 0
        self.holdFrameCount = 1#³ÖÐøÖ¡Êý
        self.__imageForRender = QImage(path)

    def getImage(self):
        return self.__imageForRender

    def getPixmap(self):
        return QPixmap.fromImage(self.__imageForRender)
