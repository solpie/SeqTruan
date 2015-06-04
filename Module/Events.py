__author__ = 'toramisu'
from Module import Singleton


class Event(Singleton):
    def init(self):
        self.handles = {}
        pass

    def add_event_handle(self, event, func):
        if event not in self.handles:
            self.handles[event] = []
        self.handles[event].append(func)

    def dispatch_event(self, event, *args):
        if event in self.handles:
            fs = self.handles[event]
            for func in fs:
                func(*args)


class SequencePlaybackEvent():
    RENDER = 'render'


class AudioPlaybackEvent():
    TICK = 'tick'

class MainWindowEvent():
    INITED = 'inited'

