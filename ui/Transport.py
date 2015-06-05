__author__ = 'toramisu'

# from PyQt5.QtWidgets import QOpenGLWidget, QWidget, QPushButton, QHBoxLayout, QComboBox
from ui import *

from module.App import *
from module.Events import *


class Transport(QWidget):
    def __init__(self, parent):
        super(Transport, self).__init__(parent)
        self.hbox = QHBoxLayout(self)
        self.frameRate = QComboBox()
        self.frameRate.addItems(['24', '30', '60'])
        connect(self.frameRate.currentTextChanged, self.onFrameRateChanged)
        self.hbox.addWidget(self.frameRate)

        self.playButton = QPushButton()
        self.playButton.setText('play')
        connect(self.playButton.clicked, self.togglePlay)
        self.hbox.addWidget(self.playButton)

        self.pauseButton = QPushButton()
        self.pauseButton.setText('stop')
        self.hbox.addWidget(self.pauseButton)
        pass

    def onFrameRateChanged(self, e):
        fr = int(self.frameRate.currentText())
        App().sequencePlayback.setFramerate(fr)
        pass

    def togglePlay(self):
        state = App().sequencePlayback.state
        if state == PlayStateType.PLAY:
            self.playButton.setText('play')
            Event.dis(PlaybackEvent.STATE, PlayStateType.PAUSE)
        else:
            self.playButton.setText('pause')
            Event.dis(PlaybackEvent.STATE, PlayStateType.PLAY)
        pass
