def createNode(data):
    return {'data': data, 'next': None}
def addAtHead(CLL, data):
    newNode = createNode(data)
    if CLL is None:
        newNode['next'] = newNode  
        return newNode
    current = CLL
    while current['next'] != CLL:  
        current = current['next']
    current['next'] = newNode
    newNode['next'] = CLL  
    return newNode
CLL = None  
CLL = addAtHead(CLL, 1)
CLL = addAtHead(CLL, 6)
CLL = addAtHead(CLL, 3)
CLL = addAtHead(CLL, 2)
CLL = addAtHead(CLL, 5)
print(CLL)

