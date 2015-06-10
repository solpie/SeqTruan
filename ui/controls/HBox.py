__author__ = 'toramisu'
from PyQt5 import QtWidgets as _w


class HBox(_w.QWidget):
    def __init__(self, parent=None):
        super(HBox, self).__init__(parent)
        pass

    def refresh(self):
        self.children()

    # def addWidget(self,obj):
    #     self.
