__author__ = 'toramisu'
from PyQt5.QtWidgets import (QOpenGLWidget, QWidget, QPushButton,
                             QLabel, QFileDialog, QMessageBox, QScrollArea, QSizePolicy,
                             QSlider,
                             QVBoxLayout,
QScrollBar,
                             QCheckBox,
                             QHBoxLayout, QComboBox, QMainWindow)
from PyQt5 import Qt
from PyQt5.QtCore import QDir, QRectF
from PyQt5.QtGui import (QImage, QPalette, QPixmap, QPainter, QBrush,
                         QMouseEvent,
                         QColor, QPen, QPainterPath, QLinearGradient)

from utils.Qss import Qss


def connect(signal, func):
    signal.connect(func)


def ignoreEvent(e):
    e.ignore()


from .Transport import Transport
from .Viewport import Viewport
from .Theme import *
