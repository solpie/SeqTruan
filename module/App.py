__author__ = 'toramisu'
from utils import Singleton
from module.AudioPlayBack import AudioPlayBack
from module.SequencePlayback import SequencePlayback
from module.External import External
from module.Events import *
from model import *
from ui.SeqTruanWindow import SeqTruanWindow
from module.Shortcut import Shortcut


class App(Singleton):
    def init(self):
        self.trackModel = TrackModel()
        self.audioPlayback = AudioPlayBack()
        self.sequencePlayback = SequencePlayback()
        self.ext = External()
        pass

    def initUI(self):
        self.mainWin = SeqTruanWindow()
        # self.shortcut = \
        Shortcut(self.mainWin)
        self.mainWin.show()
        pass

    def start(self):
        self.init()
        self.initUI()

        self.test()
        pass

    def test(self):
        self.trackModel.newTrack(name='curry', imagesPath='test/test10')
        # Event.dis(ActionEvent.NEW_TRACK, 'test track0')
        # Event.dis(ActionEvent.NEW_TRACK, 'test track1')
        # Event.dis(ActionEvent.NEW_TRACK, 'test track2')
        # Event.dis(ActionEvent.NEW_TRACK, 'test track3')
        # self.sequencePlayback.load('test/test10')
        # self.sequencePlayback.load('test')
        self.sequencePlayback.endFrameIdx = 30
        # Event.dis(PlaybackEvent.STATE, PlayStateType.PLAY)
        # App().audioPlayback.load("test/test1.mp3")
        # App().audioPlayback.setVolume(0)

        # self.__audioPlayback.load("test/test.mp3")
        # self.__audioPlayback.setVolume(0)
        # self.sequencePlayback.load('test')

        # self.ext.load('test/')

        pass
