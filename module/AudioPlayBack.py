__author__ = 'toramisu'
from PyQt5.QtMultimedia import QMediaPlayer, QMediaContent
from PyQt5.QtCore import QUrl
from module.Events import *


class AudioPlayBack():
    def __init__(self):
        self.__audioPlayback = QMediaPlayer()
        self.__audioPlayback.setVolume(50)
        self.__audioPlayback.positionChanged.connect(self.onTick)

        pass

    def onTick(self, e=None):
        print(self.__audioPlayback.position(), self.__audioPlayback.state())
        Event.dis(AudioPlaybackEvent.TICK, self.__audioPlayback.position())
        pass

    def load(self, path):
        content = QMediaContent(QUrl(path))
        self.__audioPlayback.setMedia(content)
        self.__audioPlayback.play()
        pass

    def seek(self, position):
        self.__audioPlayback.setPosition(position)
        pass

    def play(self):
        if self.__audioPlayback.state() == QMediaPlayer.PausedState:
            self.__audioPlayback.play()
            pass
        pass

    def pause(self):
        if self.__audioPlayback.state() == QMediaPlayer.PlayingState:
            self.__audioPlayback.pause()
            pass
        pass

    # 0~100
    def setVolume(self, vol):
        self.__audioPlayback.setVolume(vol)
        pass
