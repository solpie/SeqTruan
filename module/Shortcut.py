__author__ = 'toramisu'
from module.Events import *
from ui import *


class Shortcut():
    def __init__(self, widget):
        widget.keyPressEvent = self.onKeyPress
        print('[init]: setup shortcut')
        pass

    def onKeyPress(self, e):
        print(e.key())
        key = e.key()
        if Qt.Key_Space:
            Event.dis(ActionEvent.TOGGLE_PLAY)
            pass
        pass
