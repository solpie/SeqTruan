__author__ = 'toramisu'
from ui import *
from .TrackFrame import TrackFrame


class Track(QWidget):
    def __init__(self, parent=None):
        self.trackInfo = None
        super(Track, self).__init__(parent)
        # self.frameBar = QWidget(self)
        # self.frameBar.setStyleSheet('QWidget{background-color:yellow}')

        self.mousePressEvent = ignoreEvent
        self.thumbs = QWidget(self)
        self.thumbArr = []
        self.thumbs.mousePressEvent = ignoreEvent
        # self.thumbs.move(0, 25)

        # self.thumbHbox = QHBoxLayout(self.thumbs)
        # self.thumbHbox.setSizeConstraint()
        # self.thumbs.move(335, 5)
        # self.thumbHbox.setSpacing(0)
        # self.thumbHbox.setContentsMargins(0, 0, 0, 0)

        self.thumbs.resize(80, 75)
        self.resize(1280, TIMELINE_TRACK_DEF_HEIGHT)
        # self.frameBar.resize(self.width(), 25)
        self.setStyleSheet(
            'QWidget{'
            # 'background-color:red;'
            'border-style: outset;'
            'border-width: 1px;'
            'border-color: beige;}')

    def relayout(self, trackFrame):
        self.thumbs.resize(self.thumbs.width() + 40, self.thumbs.height())
        changeWidth = trackFrame.changeWidth
        trackFrame.changeWidth = 0
        if trackFrame.isPressRightButton:
            for idx in range(trackFrame.getIdx(), len(self.thumbArr)):
                tf = self.thumbArr[idx]
                tf.move(tf.x() + changeWidth, tf.y())
        elif trackFrame.isPressLeftButton:
            trackFrame.isPressLeftButton = False
            trackFrame.move(trackFrame.x() + changeWidth, trackFrame.y())
            trackFrame.isPressLeftButton = True
            if trackFrame.getIdx() > 1:
                preTrackFrame = self.thumbArr[trackFrame.getIdx() - 2]
                if changeWidth > 0:
                    print(self, 'preTrackFrame', preTrackFrame.getIdx())
                    preTrackFrame.setHoldFrameCount(preTrackFrame.holdFrameCount + 1)
                elif preTrackFrame.holdFrameCount > 1:
                    #todo ɾ��ǰһ֡
                    preTrackFrame.setHoldFrameCount(preTrackFrame.holdFrameCount - 1)

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

    def collapse(self):
        # todo
        pass

    def expand(self):
        # todo
        pass
