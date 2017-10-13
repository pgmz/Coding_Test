'''
Created on 12/10/2017

@author: Patricio Gomez
'''

minval = 0
lmin = []

def pushToStack(l, data):

    global minval
    global lmin

    if (len(l) != 0):
        if (minval > data):
            lmin.append(minval)
            minval = data
        elif (lmin[-1:] < data):
            lmin.append(data)
    else:
        minval = data

    l.append(data)

def popFromStack(l):

    global minval
    global lmin

    a = l.pop()

    if(a == minval):
        minval = lmin.pop()

    return a

def getMin():

    global minval
    global lmin

    return minval

l = []

pushToStack(l, 10)
print("%d" %getMin())
pushToStack(l, 15)
print(getMin())
pushToStack(l, 5)
print(getMin())
pushToStack(l, 3)
print(getMin())
pushToStack(l, 6)
print(getMin())
pushToStack(l, 2)
print(getMin())
pushToStack(l, 4)
print(getMin())
pushToStack(l, 7)
print(getMin())
pushToStack(l, 23)
print(getMin())

print(lmin)
print(l)

popFromStack(l)
print(getMin())
popFromStack(l)
print(getMin())
popFromStack(l)
print(getMin())
popFromStack(l)
print(getMin())
popFromStack(l)
print(getMin())
popFromStack(l)
print(getMin())
popFromStack(l)
print(getMin())
popFromStack(l)
print(getMin())
