__author__ = 'toramisu'

from PyQt5.QtWidgets import QOpenGLWidget, QWidget, QPushButton, QHBoxLayout, QComboBox
from Module.App import *
from Module.Events import *


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
            Event().dispatch(PlaybackEvent.STATE, PlayStateType.PAUSE)
        else:
            Event().dispatch(PlaybackEvent.STATE, PlayStateType.PLAY)
        pass
