
class MyQueue():

    def __init__(self):
        self.s_order = []
        self.s_norder = []

    def pushToQueue(self, data):

        while len(self.s_norder)!=0:
            self.s_order.append(self.s_norder.pop())

        self.s_order.append(data)


    def popFromQueue(self):

        while len(self.s_order)!=0:
            self.s_norder.append(self.s_order.pop())

        return self.s_norder.pop()


newQueue = MyQueue()

newQueue.pushToQueue(5)
print(newQueue.popFromQueue())

newQueue.pushToQueue(1)
newQueue.pushToQueue(2)
newQueue.pushToQueue(3)
print(newQueue.popFromQueue())
print(newQueue.popFromQueue())
print(newQueue.popFromQueue())
