__author__ = 'toramisu'
from ui import *
from .TrackFrame import TrackFrame
from module.Events import *


class Track(QWidget):
    def __init__(self, parent=None):
        super(Track, self).__init__(parent)
        self.deleteTrackFrame = None
        self.currentFrameWidth = TIMELINE_TRACK_FRAME_MAX_WIDTH
        self.trackInfo = None
        self.__trackIdx = -1
        setupDrag(self, moveFunc=self.onMove)

        self.trackFrameArea = QWidget(self)
        self.thumbArr = []
        self.trackFrameArea.move(TIMELINE_TRACK_FRAME_MAX_WIDTH - 9, 0)
        self.trackFrameArea.resize(80, 75)
        self.resize(1280, TIMELINE_TRACK_DEF_HEIGHT)
        # self.frameBar.resize(self.width(), 25)
        self.setStyleSheet(
            'border-style: solid;'
            'border-width: 1px;'
            'border-top-color: #343434;'
            'border-bottom-color: #343434;'
        )
        self.headButton = QWidget(self)
        self.headButton.move(31 - 9, 0)
        self.headButton.setStyleSheet('boder:none')
        self.headButton.resize(10, 40)
        self.headButton.paintEvent = self.headButtonPaintEvent

        self.tailButton = QWidget(self)
        self.tailButton.resize(10, 40)
        self.tailButton.paintEvent = self.tailButtonPaintEvent
        self.tailButton.move(80, 0)

    @property
    def trackIdx(self):
        return self.__trackIdx

    @trackIdx.setter
    def trackIdx(self, value):
        self.__trackIdx = value

    def onMove(self, e):
        from module import App

        if e.dragObject.dx > 30:
            App.trackModel.setTrackInfoStartFrameIdxByDelta(self.trackIdx, 1)
            setX(self, self.x() + self.currentFrameWidth)
        elif e.dragObject.dx < -30:
            moveX = self.x() - self.currentFrameWidth
            if moveX > 0:
                App.trackModel.setTrackInfoStartFrameIdxByDelta(self.trackIdx, -1)
                setX(self, moveX)

    def deletePreTrackFrame(self):
        if self.deleteTrackFrame:
            # todo 删除前一帧
            self.deleteTrackFrame.hide()
            print('deletePreTrackFrame frame idx:', self.deleteTrackFrame.getIdx())
        pass

    def relayout(self, trackFrame):
        from module import App

        changeWidth = trackFrame.changeWidth
        trackFrame.changeWidth = 0
        if trackFrame.isPressRightButton:  # 操作帧后面的帧往后移动 todo 修改model
            for idx in range(trackFrame.getIdx(), len(self.thumbArr)):
                tf = self.thumbArr[idx]
                tf.move(tf.x() + changeWidth, tf.y())
                self.resize(self.trackFrameArea.x() + self.trackFrameArea.width(), self.height())
                App.trackModel.setTrackFrameInfo(tf.trackIdx, tf.getIdx(),
                                                   frameIdx=tf.getFramePos(self.currentFrameWidth))
        elif trackFrame.isPressLeftButton:
            trackFrame.isPressLeftButton = False
            trackFrame.move(trackFrame.x() + changeWidth, trackFrame.y())
            trackFrame.isPressLeftButton = True
            if trackFrame.getIdx() > 1:
                if self.deleteTrackFrame:
                    self.deleteTrackFrame = None
                    Event.delete(ActionEvent.RELEASE_TRACK_FRAME_LEFT_BUTTON, self.deletePreTrackFrame)
                preTrackFrame = self.thumbArr[trackFrame.getIdx() - 2]
                if changeWidth > 0:
                    print(self, 'preTrackFrame', preTrackFrame.getIdx())
                    preTrackFrame.setHoldFrameCount(preTrackFrame.holdFrameCount + 1)
                else:
                    if preTrackFrame.holdFrameCount > 1:  # 缩短前一帧 增加当前帧
                        preTrackFrame.setHoldFrameCount(preTrackFrame.holdFrameCount - 1)
                    else:  # 覆盖前一帧
                        print('to delete preTrackFrame')
                        Event.add(ActionEvent.RELEASE_TRACK_FRAME_LEFT_BUTTON, self.deletePreTrackFrame)
                        self.deleteTrackFrame = preTrackFrame
        pass
        lastTrackFrame = self.thumbArr[len(self.thumbArr) - 1]
        lastTrackFrameEndPos = lastTrackFrame.x() + lastTrackFrame.width()
        self.trackFrameArea.resize(lastTrackFrameEndPos + TIMELINE_TRACK_FRAME_MAX_WIDTH,
                                   self.trackFrameArea.height())
        self.resize(self.trackFrameArea.width() + TIMELINE_TRACK_FRAME_MAX_WIDTH, self.height())
        self.tailButton.move(
            self.trackFrameArea.x() + lastTrackFrameEndPos, 0)

    def load(self, trackInfo):
        imgs = trackInfo.frames
        self.trackIdx = trackInfo.trackIdx
        for i in range(0, len(imgs)):
            sImage = imgs[i]
            sImage.startFrameIdx = i + 1
            trackFrame = TrackFrame(self.trackFrameArea)
            trackFrame.setPixmap(sImage.getPixmap())
            trackFrame.setIdx(i + 1)
            trackFrame.trackIdx = self.trackIdx
            trackFrame.relayout = self.relayout
            trackFrame.move(i * trackFrame.width(), 0)
            trackFrame.refSImage = sImage
            self.thumbArr.append(trackFrame)
            self.trackFrameArea.resize((len(self.thumbArr) + 1) * TIMELINE_TRACK_FRAME_MAX_WIDTH,
                                       self.trackFrameArea.height())
            self.tailButton.move(self.trackFrameArea.x() + self.trackFrameArea.width() - TIMELINE_TRACK_FRAME_MAX_WIDTH,
                                 0)
            # self.thumbHbox.addWidget(tf)
        pass

    def headButtonPaintEvent(self, e):
        path = QPainterPath()
        y = 17
        path.moveTo(9, 0 + y)
        path.lineTo(0, 9 + y)
        path.lineTo(0, 22 + y)
        path.lineTo(9, 22 + y)
        path.lineTo(9, 0 + y)
        path.moveTo(4, 11 + y)
        path.lineTo(4, 11 + y + 6)
        path.moveTo(6, 11 + y)
        path.lineTo(6, 11 + y + 6)
        p = QPainter(self.headButton)
        qColor = QColor(0x343434)
        pen = QPen(qColor)
        p.setPen(pen)
        p.drawPath(path)

        pass

    def tailButtonPaintEvent(self, e):
        path = QPainterPath()
        path.moveTo(0, 22)
        path.lineTo(9, 22 - 9)
        path.lineTo(9, 0)
        path.lineTo(0, 0)
        path.lineTo(0, 22)

        path.moveTo(4, 4)
        path.lineTo(4, 4 + 6)
        path.moveTo(6, 4)
        path.lineTo(6, 4 + 6)
        p = QPainter(self.tailButton)
        qColor = QColor(0x343434)
        pen = QPen(qColor)
        p.setPen(pen)
        p.drawPath(path)

        pass

    def collapse(self):
        # todo
        pass

    def expand(self):
        # todo
        pass
