__author__ = 'toramisu'
from ui import *
from .Frame import Frame


class Track(QWidget):
    def __init__(self, parent=None):
        self.trackInfo = None
        super(Track, self).__init__(parent)
        self.frameBar = QWidget(self)
        self.frameBar.setStyleSheet('QWidget{background-color:yellow}')
        self.mousePressEvent = ignoreEvent
        self.thumbs = QWidget(self)
        self.thumbs.mousePressEvent = ignoreEvent
        self.thumbs.move(0, 25)

        self.thumbHbox = QHBoxLayout(self.thumbs)
        # self.thumbs.move(335, 5)
        self.thumbs.resize(1280, 50)
        self.resize(1280, TIMELINE_TRACK_DEF_HEIGHT)
        self.frameBar.resize(self.width(), 25)
        self.setStyleSheet(
            'QWidget{background-color:red;'
            'border-style: outset;'
            'border-width: 1px;'
            'border-color: beige;}')

    def load(self, imgs):
        for i in range(0, len(imgs)):
            img = imgs[i]
            ql = Frame(self)
            ql.setPixmap(QPixmap.fromImage(img))
            self.thumbHbox.addWidget(ql)
        pass

    def collapse(self):
        # todo
        pass

    def expand(self):
        # todo
        pass
