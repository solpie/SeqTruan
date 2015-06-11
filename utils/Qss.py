from qss.qrc import *
from PyQt5.QtCore import QFile

class Qss():
    @staticmethod
    def setStyle(widget, aliasPath):
        file_qss = QFile(aliasPath)
        file_qss.open(QFile.ReadOnly)
        ba = file_qss.readAll()
        s = bytes(ba.data()).decode()
        widget.setStyleSheet(s)
        file_qss.close()
