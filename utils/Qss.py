from qss.qrc import *
from PyQt5.QtCore import QFile, QTextStream,QByteArray


class Qss():
    @staticmethod
    def setStyle(widget, aliasPath):
        file_qss = QFile(aliasPath)
        file_qss.open(QFile.ReadOnly)
        ba = file_qss.readAll()
        s = str(ba)
        widget.setStyleSheet(s)
        file_qss.close()
