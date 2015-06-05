__author__ = 'toramisu'
def singleton(cls):
    instances = {}

    def get_instance():
        if cls not in instances:
            instances[cls] = cls()
        return instances[cls]

    return get_instance


class Singleton(object):
    instances = {}

    def __new__(cls, *args, **kwargs):
        if cls not in cls.instances:
            cls.instances[cls] = object.__new__(cls)
        return cls.instances[cls]


from .Watcher import Watcher
from .B import B