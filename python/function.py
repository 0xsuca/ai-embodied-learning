class Test:

    classAddr = 0

    def __init__(self, addr):
        self.addr = addr
        print(self)

    def __str__(self):
        return self.addr

class SingleTon:
    _instance = None
    _initialied = False
    def __new__(cls,*args, **kwargs):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance

    def __init__(self, addr):
        if not self._initialied :
            self.addr = addr
            print(self._instance.addr)
            self._initialied = True

print(type(SingleTon))
print(SingleTon._instance)
s1 = SingleTon("hello")
s2 = SingleTon("world")

print(s1 == s2)
