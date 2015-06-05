__author__ = 'toramisu'
from utils import Singleton


class Event(Singleton):
    handles = None

    def __init__(self):
        if not self.handles:
            self.init()

    def init(self):
        self.handles = {}
        pass

    @staticmethod
    def add(event, func):
        self = Event()
        if event not in self.handles:
            self.handles[event] = []
        self.handles[event].append(func)

    @staticmethod
    def dis(event, *args):
        self = Event()
        if event in self.handles:
            fs = self.handles[event]
            for func in fs:
                func(*args)


def connect(signal, func):
    signal.connect(func)



class PlaybackEvent():
    STATE = 'state'


class PlayStateType():
    PLAY = 'play'
    PAUSE = 'pause'
    STOP = 'stop'


class SequencePlaybackEvent():
    RENDER = 'render'


class AudioPlaybackEvent():
    TICK = 'tick'


class MainWindowEvent():
    INITED = 'inited'
