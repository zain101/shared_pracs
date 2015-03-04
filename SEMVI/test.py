#check scope...
s = "sayed"
def func():
    s = "zain"
    print s
    golbal.s = ''

def display():
    print s


if __name__ == "__main__":
    func()
    display()
    func()
    display()
