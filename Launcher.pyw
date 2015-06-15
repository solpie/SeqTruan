# -*- coding: utf-8 -*-
from PyQt5.QtCore import QTextCodec
from PyQt5.QtWidgets import QApplication
from module import App
import sys
from PyQt5.Qt import QStyleFactory



app = QApplication(sys.argv)
app.setApplicationName("SeqTruan")
app.setStyle(QStyleFactory.create('Fusion'))
app.setQuitOnLastWindowClosed(True)
app.installEventFilter(app)
codec = QTextCodec.codecForName('UTF-8')
# QTextCodec.setCodecForTr(codec)
QTextCodec.setCodecForLocale(codec)
# QTextCodec.setCodecForCStrings(codec)


# fmt = QSurfaceFormat()
# fmt.setSamples(4)
# QSurfaceFormat.setDefaultFormat(fmt)
App.start()
# window = SeqTruanWindow()
# window.show()
sys.exit(app.exec_())
