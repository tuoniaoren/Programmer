class MyStack3:
    def __init__(self):
        self.stackData = []
        self.stackMin = []

    def Push(self, newData):
        self.stackData.append(newData)
        if len(self.stackMin) == 0:
            self.stackMin.append(newData)
        elif newData > self.stackMin[-1]:
            self.stackMin.append(self.stackMin[-1])
        else:
            self.stackMin.append(newData)
    
    def Pop(self):
        self.stackMin.pop()
    
    def getMin(self):
        minData = self.stackMin[-1]
        print(minData)


if __name__ == "__main__":
    s = MyStack3()
    s.Push(2)
    s.Push(3)
    s.Push(4)
    s.Push(1)
    s.getMin()
    s.Pop()
    s.getMin()