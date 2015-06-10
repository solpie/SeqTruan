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

    @staticmethod
    def delete(event, func):
        self = Event()
        if event in self.handles:
            newFuncs = []
            for f in self.handles[event]:
                if f != func:
                    newFuncs.append(f)
                else:
                    print('delete func', func)
            self.handles[event] = newFuncs


class TracksModelEvent():
    NEW_TRACK = 'new track'


class ActionEvent():
    LOAD_SEQ = 'load seq'
    NEW_TRACK = '[action]:new track'
    RELEASE_TRACK_FRAME_LEFT_BUTTON = 'RELEASE_TRACK_FRAME_LEFT_BUTTON'


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
