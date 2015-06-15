__author__ = 'toramisu'

import os

from module.Events import *
from model.SImage import *


class TrackInfo(object):
    def __init__(self):
        self.id = 0  # from 1 todo deleteme
        self.name = ''
        self.frames = []
        self.__refTrack = None
        self.__currentFrameIdx = -1
        self.__sImageIdx = -1
        self.__startFrameIdx = 1
        self.__trackIdx = -1

    @property
    def trackIdx(self):
        return self.__trackIdx

    @trackIdx.setter
    def trackIdx(self, value):
        self.__trackIdx = value

    @property
    def startFrameIdx(self):
        return self.__startFrameIdx

    @startFrameIdx.setter
    def startFrameIdx(self, value):
        self.__startFrameIdx = value

    @property
    def refTrack(self):
        return self.__refTrack

    @refTrack.setter
    def refTrack(self, value):
        self.__refTrack = value

    @property
    def currentFrameIdx(self):
        return self.__currentFrameIdx

    @currentFrameIdx.setter
    def currentFrameIdx(self, value):
        self.__currentFrameIdx = value

    @property
    def sImageIdx(self):
        return self.__sImageIdx

    @sImageIdx.setter
    def sImageIdx(self, value):
        self.__sImageIdx = value


class TrackModel():
    def __init__(self):
        self.tracks = []
        Event.add(ActionEvent.NEW_TRACK, self.onActNewTrack)
        Event.add(ActionEvent.MOVE_CURSOR, self.onMoveCursor)
        Event.add(SequencePlaybackEvent.RENDER_FRAME, self.onRenderFrame)
        pass

    def onMoveCursor(self, frameIdx):
        print('Move Cursor', frameIdx)
        self.seekFrame(frameIdx)
        pass

    def renderFrame(self, trackInfo, frameIdx):
        if frameIdx > 0 and frameIdx < len(trackInfo.frames)+1:
            simage = trackInfo.frames[frameIdx - 1]
            trackInfo.sImageIdx = frameIdx
            trackInfo.holdFrame = simage.holdFrameCount
            # print('render frame', trackInfo.name, frameIdx)
            Event.dis(SequencePlaybackEvent.RENDER, simage)

    def seekFrame(self, frameIdx):
        for trackInfo in self.tracks:
            if frameIdx > len(trackInfo.frames):
                continue
            for simage in trackInfo.frames:
                if simage.startFrameIdx <= frameIdx and simage.endFrameIdx >= frameIdx:
                    self.renderFrame(trackInfo, simage.frameIdx)
                    break
                    pass
                pass
        pass

    def renderFrameByFrameIdx(self, renderFrameIdx):
        for trackInfo in self.tracks:
            if renderFrameIdx < trackInfo.currentFrameIdx:
                # 循环重置
                trackInfo.sImageIdx = 0
            trackInfo.currentFrameIdx = renderFrameIdx
            if trackInfo.sImageIdx > 0:
                if trackInfo.holdFrame > 1:
                    trackInfo.holdFrame -= 1
                else:
                    nextSImageIdx = trackInfo.sImageIdx + 1
                    self.renderFrame(trackInfo, nextSImageIdx)
            elif renderFrameIdx >= trackInfo.startFrameIdx:
                i = renderFrameIdx - trackInfo.startFrameIdx
                self.renderFrame(trackInfo, i)
        pass

    def onRenderFrame(self, SequencePlaybackEvent):
        renderFrameIdx = SequencePlaybackEvent.frameIdx
        self.renderFrameByFrameIdx(renderFrameIdx)
        # for trackInfo in self.tracks:
        #     if renderFrameIdx < trackInfo.currentFrameIdx:
        #         # 循环重置
        #         trackInfo.sImageIdx = 0
        #     trackInfo.currentFrameIdx = renderFrameIdx
        #     if trackInfo.sImageIdx > 0:
        #         if trackInfo.holdFrame > 1:
        #             trackInfo.holdFrame -= 1
        #         else:
        #             nextSImageIdx = trackInfo.sImageIdx + 1
        #             self.renderFrame(trackInfo, nextSImageIdx)
        #     elif renderFrameIdx >= trackInfo.startFrameIdx:
        #         i = renderFrameIdx - trackInfo.startFrameIdx
        #         self.renderFrame(trackInfo, i)
        # print('onRenderFrame', trackInfo.currentFrameIdx, trackInfo.sImageIdx)

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
        trackInfo.trackIdx = len(self.tracks)
        Event.dis(TracksModelEvent.NEW_TRACK, trackInfo)
        pass

    def delTrack(self, id):
        pass

    def setTrackSImage(self, trackIdx, simageIdx, holdFrame):
        pass
