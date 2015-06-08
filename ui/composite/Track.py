__author__ = 'toramisu'
from ui import *
from .Frame import Frame


class Track(QWidget):
    def __init__(self, parent):
        super(Track, self).__init__(parent)
        self.opacitySlider = QSlider(0x1, self)
        self.opacitySlider.move(200, 37)
        self.opacitySlider.resize(80, 15)
        self.opacitySlider.setRange(0, 100)
        self.opacitySlider.setValue(100)
        connect(self.opacitySlider.valueChanged, self.onOpacityChanged)

        self.thumbs = QWidget(self)
        self.thumbHbox = QHBoxLayout(self.thumbs)
        self.thumbs.move(335, 5)
        self.thumbs.resize(1280, 50)
        self.resize(1280, 80)
        self.setStyleSheet(
            'QWidget{background-color:red;'
            'border-style: outset;'
            'border-width: 1px;'
            'border-color: beige;}')

    def onOpacityChanged(self, value):
        # value 0~100
        pass

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
