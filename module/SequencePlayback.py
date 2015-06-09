__author__ = 'toramisu'
import os
from PyQt5.QtGui import QImage
from PyQt5.Qt import QTimer
from module.Events import *


class SequencePlayback():
    def __init__(self):
        self.imageSequence = []
        self.framerate = 0
        self.currentFrame = -1
        self.state = ''

        self.timer = QTimer()
        self.timer.timerEvent = self.onTick
        Event.add(AudioPlaybackEvent.TICK, self.onTick)
        Event.add(PlaybackEvent.STATE, self.onState)
        self.setFramerate(24)
        pass

    def onState(self, state):
        self.state = state
        if state == PlayStateType.PLAY:
            self.play()
        elif state == PlayStateType.PAUSE:
            self.pause()
            pass
        pass

    def onTick(self, time):
        self.render()
        pass

    def load(self, imagesPath=None):
        if imagesPath:
            for root, dirs, files in os.walk(imagesPath):
                for filespath in files:
                    filename = os.path.join(root, filespath).replace('\\', '/')
                    #todo support image ext
                    if filename.find('.png') < 0:
                        continue
                    img = QImage(filename)
                    self.imageSequence.append(img)
                    print('[load img]: ', filename)
            Event.dis(ActionEvent.LOAD_SEQ, self.imageSequence)
            pass

    def play(self):
        if not self.timer.isActive():
            self.timer.start()
            pass
        pass

    def pause(self):
        if self.timer.isActive():
            self.timer.stop()
            pass
        pass

    def render(self):
        if len(self.imageSequence):
            self.currentFrame = (self.currentFrame + 1) % len(self.imageSequence)
            img = self.imageSequence[self.currentFrame]
            Event.dis(SequencePlaybackEvent.RENDER, img)
        pass

    def setFramerate(self, framerate):
        self.framerate = framerate
        self.timer.setInterval(1000 / self.framerate)
        pass