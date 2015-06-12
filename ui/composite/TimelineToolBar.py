__author__ = 'toramisu'
from ui import *


class TimelineToolBar(QWidget):
    def __init__(self, parent):
        super(TimelineToolBar, self).__init__(parent)
        hbox = QHBoxLayout(self)
        self.startFrameButton = QPushButton()
        hbox.addWidget(self.startFrameButton)
        self.startFrameButton.setText('startFrame')
        self.startFrameLabel = QLineEdit()
        self.startFrameLabel.setText('1')
        hbox.addWidget(self.startFrameLabel)
        hbox.setSpacing(0)
        hbox.setContentsMargins(0, 0, 0, 0)
        self.resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, 15)
        pass
