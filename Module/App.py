__author__ = 'toramisu'
from Module import Singleton
from Module.AudioPlayBack import AudioPlayBack
from Module.SequencePlayback import SequencePlayback


class App(Singleton):
    def init(self):
        self.audioPlayback = AudioPlayBack()
        self.sequencePlayback = SequencePlayback()
        pass

    def test(self):
        # self.__audioPlayback.load("test/test.mp3")
        # self.__audioPlayback.setVolume(0)

        self.sequencePlayback.load('test')
        pass


def connect(signal, func):
    signal.connect(func)
