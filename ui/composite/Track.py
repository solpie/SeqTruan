__author__ = 'toramisu'
from ui import *


class Track(QWidget):
    def __init__(self, parent):
        super(Track, self).__init__(parent)
        self.hbox = QHBoxLayout(self)


    def load(self, imgs):
        for i in range(0,len(imgs)):
            img = imgs[i]
            ql = QLabel()
            ql.setPixmap(QPixmap.fromImage(img))
            self.hbox.addWidget(ql)
        pass
