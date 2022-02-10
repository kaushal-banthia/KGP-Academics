from library_odd import Base

class Derived(Base):
    def bar(self):
        return self.foo()

if __name__ == '__main__':

    assert hasattr(Base, 'foo')

    d1 = Derived()
    d1.bar()