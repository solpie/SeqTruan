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
        self.thumbs.mousePressEvent = ignoreEvent
        # self.thumbs.move(0, 25)

        # self.thumbHbox = QHBoxLayout(self.thumbs)
        # self.thumbs.move(335, 5)]
        # self.thumbHbox.setSpacing(0)
        self.thumbs.resize(1280, 75)
        self.resize(1280, TIMELINE_TRACK_DEF_HEIGHT)
        # self.frameBar.resize(self.width(), 25)
        self.setStyleSheet(
            'QWidget{'
            # 'background-color:red;'
            'border-style: outset;'
            'border-width: 1px;'
            'border-color: beige;}')

    def relayout(self):
        pass

    def load(self, imgs):
        for i in range(0, len(imgs)):
            img = imgs[i]
            tf = TrackFrame(self.thumbs)
            tf.setPixmap(QPixmap.fromImage(img))
            tf.setIdx(i+1)
            tf.move(i * tf.width(), 0)
            # self.thumbHbox.addWidget(ql)
        pass

    def collapse(self):
        # todo
        pass

    def expand(self):
        # todo
        pass
