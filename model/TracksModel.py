__author__ = 'toramisu'

import os
from module.Events import *
from PyQt5.QtGui import QImage


class TrackInfo():
    def __init__(self):
        self.id = 0  # from 1
        self.name = ''
        self.frames = []


class TrackModel():
    def __init__(self):
        self.tracks = []

        Event.add(ActionEvent.NEW_TRACK, self.onActNewTrack)
        pass

    def onActNewTrack(self, name):
        self.newTrack(name=name)
        pass

    def newTrack(self, name=None, imagesPath=None):
        trackInfo = TrackInfo()
        if imagesPath:
            for root, dirs, files in os.walk(imagesPath):
                for filespath in files:
                    filename = os.path.join(root, filespath).replace('\\', '/')
                    # todo support image ext
                    if filename.find('.png') < 0:
                        continue
                    img = QImage(filename)
                    trackInfo.frames.append(img)
                    print('[load img]: ', filename)
            pass

        trackInfo.name = name
        self.tracks.append(trackInfo)
        trackInfo.id = len(self.tracks)

        Event.dis(TracksModelEvent.NEW_TRACK, trackInfo)
        pass

    def delTrack(self, id):
        pass
