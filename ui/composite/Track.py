__author__ = 'toramisu'
from ui import *
from .TrackFrame import TrackFrame
from module.Events import *
from utils.B import B


class Track(QWidget):
    def __init__(self, parent=None):
        self.trackInfo = None
        super(Track, self).__init__(parent)
        self.deleteTrackFrame = None
        # self.frameBar = QWidget(self)
        # self.frameBar.setStyleSheet('QWidget{background-color:yellow}')
        self.currentFrameWidth = TIMELINE_TRACK_FRAME_MAX_WIDTH

        setupDrag(self, moveFunc=self.onMove)

        self.thumbs = QWidget(self)
        self.thumbArr = []
        self.thumbs.mousePressEvent = ignoreEvent
        self.thumbs.move(TIMELINE_TRACK_FRAME_MAX_WIDTH, 0)

        self.thumbs.resize(80, 75)
        self.resize(1280, TIMELINE_TRACK_DEF_HEIGHT)
        # self.frameBar.resize(self.width(), 25)
        self.setStyleSheet(
            'border-style: solid;'
            'border-width: 1px;'
            'border-top-color: #343434;'
            'border-bottom-color: #343434;'
        )
        self.headButton = QWidget(self)
        self.headButton.move(30, 0)
        self.headButton.setStyleSheet('boder:none')
        self.headButton.resize(10, 40)
        self.headButton.paintEvent = self.headButtonPaintEvent
    def onMove(self, e):
        if e.dragObject.dx > 30:
            self.move(self.x() + self.currentFrameWidth, self.y())
        elif e.dragObject.dx < -30:
            self.move(self.x() - self.currentFrameWidth, self.y())
        pass

    def deletePreTrackFrame(self):
        if self.deleteTrackFrame:
            # todo ɾ��ǰһ֡
            self.deleteTrackFrame.hide()
            print('deletePreTrackFrame frame idx:', self.deleteTrackFrame.getIdx())
        pass

    def relayout(self, trackFrame):
        changeWidth = trackFrame.changeWidth
        trackFrame.changeWidth = 0
        if trackFrame.isPressRightButton:  # ����֡�����֡�����ƶ�
            for idx in range(trackFrame.getIdx(), len(self.thumbArr)):
                tf = self.thumbArr[idx]
                tf.move(tf.x() + changeWidth, tf.y())
                self.thumbs.resize(self.thumbs.width() + changeWidth, self.thumbs.height())
                self.resize(self.thumbs.x() + self.thumbs.width(), self.height())
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
                    if preTrackFrame.holdFrameCount > 1:  # ����ǰһ֡ ���ӵ�ǰ֡
                        preTrackFrame.setHoldFrameCount(preTrackFrame.holdFrameCount - 1)
                    else:  # ����ǰһ֡
                        print('to delete preTrackFrame')
                        Event.add(ActionEvent.RELEASE_TRACK_FRAME_LEFT_BUTTON, self.deletePreTrackFrame)
                        self.deleteTrackFrame = preTrackFrame

    def load(self, imgs):
        for i in range(0, len(imgs)):
            img = imgs[i]
            tf = TrackFrame(self.thumbs)
            tf.setPixmap(QPixmap.fromImage(img))
            tf.setIdx(i + 1)
            tf.relayout = self.relayout
            tf.move(i * tf.width(), 0)
            # tf.startDrag = self.enableTracking
            self.thumbArr.append(tf)
            self.thumbs.resize(self.thumbs.width() + 40, self.thumbs.height())
            # self.thumbHbox.addWidget(tf)
        pass

    def headButtonPaintEvent(self, e):
        path = QPainterPath()
        y = 17
        path.moveTo(10, 0 + y)
        path.lineTo(0, 10 + y)
        path.lineTo(0, 22 + y)
        path.lineTo(10, 22 + y)
        path.lineTo(10, 0 + y)
        path.moveTo(4, 11 + y)
        path.lineTo(4, 11 + y + 6)
        path.moveTo(6, 11 + y)
        path.lineTo(6, 11 + y + 6)
        p = QPainter(self.headButton)
        # p.setRenderHint(QPainter.Antialiasing)
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
