__author__ = 'toramisu'

from ui import *
from module.Events import *


class Transport(QWidget):
    def __init__(self, parent):
        super(Transport, self).__init__(parent)
        self.hbox = QHBoxLayout(self)
        self.hbox.setSpacing(0)
        self.frameRate = QComboBox()
        self.frameRate.addItems(['24', '30', '60'])
        connect(self.frameRate.currentTextChanged, self.onFrameRateChanged)
        self.hbox.addWidget(self.frameRate)

        self.playButton = QPushButton()
        self.playButton.setText('play')
        Event.add(ActionEvent.TOGGLE_PLAY, self.togglePlay)
        connect(self.playButton.clicked, self.togglePlay)
        self.hbox.addWidget(self.playButton)

        self.pauseButton = QPushButton()
        self.pauseButton.setText('stop')
        self.hbox.addWidget(self.pauseButton)
        # self.setStyleSheet('QWidget { background: red; }')
        pass

    def onFrameRateChanged(self, e):
        from module import App

        fr = int(self.frameRate.currentText())
        App().sequencePlayback.setFramerate(fr)
        pass

    def togglePlay(self):
        from module import App
        state = App().sequencePlayback.state
        if state == PlayStateType.PLAY:
            self.playButton.setText('play')
            Event.dis(PlaybackEvent.STATE, PlayStateType.PAUSE)
        else:
            self.playButton.setText('pause')
            Event.dis(PlaybackEvent.STATE, PlayStateType.PLAY)
        pass
