__author__ = 'toramisu'

from PyQt5.QtGui import QImage, QPixmap


class SImage():
    def __init__(self, path):
        self.frameIdx = 0  # frame数组内idx
        self.__holdFrameCount = 1  # 持续帧数
        self.__imageForRender = QImage(path)
        self.__startFrameIdx = 0

    def getImage(self):
        return self.__imageForRender

    def getPixmap(self):
        return QPixmap.fromImage(self.__imageForRender)

    @property
    def holdFrameCount(self):
        return self.__holdFrameCount

    @holdFrameCount.setter
    def holdFrameCount(self, value):
        self.__holdFrameCount = value

    @property
    def endFrameIdx(self):
        return self.__startFrameIdx + self.holdFrameCount - 1

    @property
    def startFrameIdx(self):
        return self.__startFrameIdx

    @startFrameIdx.setter
    def startFrameIdx(self, value):
        self.__startFrameIdx = value
