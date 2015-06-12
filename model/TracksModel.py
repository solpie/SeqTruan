__author__ = 'toramisu'

import os

from module.Events import *
from model.SImage import *


class TrackInfo():
    def __init__(self):
        self.id = 0  # from 1
        self.name = ''
        self.frames = []
        self.startFrameIdx = 1
        self.track = None


class TrackModel():
    def __init__(self):
        self.tracks = []
        Event.add(ActionEvent.NEW_TRACK, self.onActNewTrack)
        Event.add(SequencePlaybackEvent.RENDER_FRAME, self.onRenderFrame)
        pass

    def onRenderFrame(self, SequencePlaybackEvent):
        renderFrameIdx = SequencePlaybackEvent.frameIdx
        for trackInfo in self.tracks:
            if renderFrameIdx >= trackInfo.startFrameIdx:
                i = renderFrameIdx - trackInfo.startFrameIdx
                print('render frame', trackInfo.name, i)
                if i < len(trackInfo.frames):
                    simage = trackInfo.frames[i]
                    Event.dis(SequencePlaybackEvent.RENDER, simage)

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
                    img = SImage(filename)
                    trackInfo.frames.append(img)
                    img.frameIdx = len(trackInfo.frames)
                    print('[load img]:', filename)
            pass

        trackInfo.name = name
        self.tracks.append(trackInfo)
        trackInfo.id = len(self.tracks)

        Event.dis(TracksModelEvent.NEW_TRACK, trackInfo)
        pass

    def delTrack(self, id):
        pass
