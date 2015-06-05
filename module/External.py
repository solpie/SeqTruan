__author__ = 'toramisu'
from PyQt5.Qt import QTimer
import os
from utils import Watcher
import queue


class External():
    def __init__(self):
        self.watchTimer = QTimer()
        self.watchTimer.setInterval(800)
        self.watchTimer.timerEvent = self.onWatch
        self.files_changed = queue.Queue()
        pass

    def onWatch(self,e):
        try:
            file_type, filename, action = self.files_changed.get_nowait()
            print(file_type, filename, action)
        except queue.Empty:
            pass
        pass

    def onFileChanged(self, path=None):
        print('file changed', path)
        pass

    def load(self, path):
        print('load', path)
        Watcher(path, self.files_changed)
        if not self.watchTimer.isActive():
            self.watchTimer.start()
            pass
        pass

    def update(self, path):
        pass

    def create(self, tmppath=None):
        if not tmppath:
            tmppath = 'tmp'
        if not os.path.exists(tmppath):
            os.mkdir(tmppath)
            pass
        pass
