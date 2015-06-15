__author__ = 'toramisu'
from ui import *
from OpenGL.GL import *

class TimestampBar(QWidget):
    def __init__(self, parent=None):
        super(TimestampBar, self).__init__(parent)
        self.setZoomLevel(ZOOM_LEVEL_NORMAL)
        fillColor(self,0x3e3e3e)

    def setZoomLevel(self, zoomLevel):
        if zoomLevel == ZOOM_LEVEL_NORMAL:
            self.paintEvent = self.paintNormal
            pass
        pass

    def paintNormal(self, e):
        p = QPainter(self)
        pen = QPen(QColor(0x343434))
        p.setPen(pen)
        for i in range(0, self.width(), TIMELINE_TRACK_FRAME_MAX_WIDTH):
            p.drawLine(i, 15, i, self.height())
            pass
        pass

    def initializeGL(self):
        # OpenGL state
        glClearColor(1.0, 1.0, 1.0, 1.0)
        glEnable(GL_DEPTH_TEST)

    # def paintGL(self):
    #     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    #     glLoadIdentity()
    #     glTranslated(0.0,0.0,-5.0)
    #     glRotated(self.xRot/16.0,1.0,0.0,0.0)
    #     glRotated(self.yRot/16.0,0.0,1.0,0.0)
    #     glRotated(self.zRot/16.0,0.0,0.0,1.0)
    #     glCallList(self.object)