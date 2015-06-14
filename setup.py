# -*- coding: utf-8 -*-
import sys
from cx_Freeze import setup, Executable

base = None
if sys.platform == 'win32':
    base = 'Win32GUI'
includes = ["atexit", "PyQt5.QtCore", "PyQt5.QtGui", "PyQt5.QtWidgets"]
options = {
    'build_exe': {
        "includes": includes
    }
}

executables = [
    Executable('Launcher.pyw', base=base)
]

setup(name='SeqTruan',
      version='0.1',
      description='SeqTruan. image sequence view',
      options=options,
      executables=executables
      )
