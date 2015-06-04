__author__ = 'toramisu'
import os
from PyQt5.QtGui import QImage
from Module.Events import *


class SequencePlayback():
    def __init__(self):
        self.imageSequence = []
        self.framerate = 24
        self.currentFrame = -1
        Event().add_event_handle(AudioPlaybackEvent.TICK, self.onTick)
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
        print(self, 'render')
        self.currentFrame = (self.currentFrame + 1) % len(self.imageSequence)
        img = self.imageSequence[self.currentFrame]
        Event().dispatch_event(SequencePlaybackEvent.RENDER, img)
        pass

    def setFramerate(self, framerate):
        self.framerate = framerate
        pass
