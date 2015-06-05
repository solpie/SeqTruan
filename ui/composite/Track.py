__author__ = 'toramisu'
from ui import *
from .Frame import Frame


class Track(QWidget):
    def __init__(self, parent):
        super(Track, self).__init__(parent)
        self.thumbs = QWidget(self)
        self.thumbHbox = QHBoxLayout(self.thumbs)
        self.thumbs.move(335, 5)
        self.thumbs.resize(1280, 75)
        self.resize(1280, 200)

    def load(self, imgs):
        for i in range(0, len(imgs)):
            img = imgs[i]
            ql = Frame(self)
            ql.setPixmap(QPixmap.fromImage(img))
            self.thumbHbox.addWidget(ql)
        pass
