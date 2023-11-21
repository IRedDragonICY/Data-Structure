def createNode(data):
    return {'data': data, 'next': None}
def addAtTail(LL, data):
    newNode = createNode(data)
    if LL is None:
        return newNode
    current = LL
    while current['next'] is not None:
        current = current['next']
    current['next'] = newNode
    return LL
def productOfSquares(LL):
    current = LL
    total = 1
    while current is not None:
        total *= current["data"]**2
        current = current["next"]
    return total
def removeEvenNodesAfterHead(LL):
    if LL is None:
        return None
    current = LL
    while current['next'] is not None:
        if current['next']["data"] % 2 == 0:
            current['next'] = current['next']['next']
            break
        else:
            current = current['next']
    return LL
LL = None                           #5->2->3->6->1
LL = addAtTail(LL, 5)
LL = addAtTail(LL, 2)
LL = addAtTail(LL, 3)
LL = addAtTail(LL, 6)
LL = addAtTail(LL, 1)

print(productOfSquares(LL))
print(LL)
LL = removeEvenNodesAfterHead(LL)
print(LL)
