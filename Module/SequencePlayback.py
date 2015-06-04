__author__ = 'toramisu'
import os
from PyQt5.QtGui import QImage
from PyQt5.Qt import QTimer
from Module.Events import *


class SequencePlayback():
    def __init__(self):
        self.imageSequence = []
        self.framerate = 0
        self.currentFrame = -1

        self.timer = QTimer()
        self.timer.timerEvent = self.onTick
        Event().add(AudioPlaybackEvent.TICK, self.onTick)

        self.setFramerate(24)
        pass

    def onTick(self, time):
        self.render()
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

    def play(self):
        pass

    def render(self):
        if len(self.imageSequence):
            self.currentFrame = (self.currentFrame + 1) % len(self.imageSequence)
            img = self.imageSequence[self.currentFrame]
            Event().dispatch(SequencePlaybackEvent.RENDER, img)
        pass

    def setFramerate(self, framerate):
        self.framerate = framerate
        self.timer.start(1000 / self.framerate)
        pass
