# -*- coding: utf-8 -*-
from PyQt5.QtCore import QTextCodec
from PyQt5.QtWidgets import QApplication
from PyQt5.QtGui import QSurfaceFormat
# from Panel.SeqTruanWindow import SeqTruanWindow
from module.App import App
import sys


app = QApplication(sys.argv)
app.setApplicationName("SeqTruan")
app.setQuitOnLastWindowClosed(True)
codec = QTextCodec.codecForName('UTF-8')
# QTextCodec.setCodecForTr(codec)
QTextCodec.setCodecForLocale(codec)
# QTextCodec.setCodecForCStrings(codec)


# fmt = QSurfaceFormat()
# fmt.setSamples(4)
# QSurfaceFormat.setDefaultFormat(fmt)
App().start()
# window = SeqTruanWindow()
# window.show()
sys.exit(app.exec_())
