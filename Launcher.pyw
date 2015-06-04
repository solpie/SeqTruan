# -*- coding: utf-8 -*-
from PyQt5.QtCore import QTextCodec
from PyQt5.QtWidgets import QApplication
from Panel.SeqTruanWindow import SeqTruanWindow
import sys


app = QApplication(sys.argv)
app.setApplicationName("SeqTruan")
app.setQuitOnLastWindowClosed(True)
codec = QTextCodec.codecForName('UTF-8')
# QTextCodec.setCodecForTr(codec)
QTextCodec.setCodecForLocale(codec)
# QTextCodec.setCodecForCStrings(codec)
window = SeqTruanWindow()
window.show()
sys.exit(app.exec_())
