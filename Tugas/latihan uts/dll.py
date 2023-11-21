def createNode(data):
    return {"data": data, "next": None, "prev": None}
def insertAtHead(DLL, data):
    newNode = createNode(data)
    if DLL is None:
        return newNode
    newNode["next"] = DLL
    DLL["prev"] = newNode
    return newNode
def insertAtTail(DLL, data):
    newNode = createNode(data)
    if DLL is None:
        return newNode
    current = DLL
    while current["next"] is not None:
        current = current["next"]
    current["next"] = newNode
    newNode["prev"] = current
    return DLL
def printAtHead(DLL):
    current = DLL
    while current["next"] is not None:
        print(current["data"], end="->")
        current = current["next"]
    print(current["data"])
def printAtTail(DLL):
    current = DLL
    while current["next"] is not None:
        current = current["next"]
    while current["prev"] is not None:
        print(current["data"], end="<-")
        current = current["prev"]
    print(current["data"])
def printRange(DLL, start, end):
    current = DLL
    for i in range(start):
        current = current["next"]
    for i in range(start, end):
        print(current["data"], end="->")
        current = current["next"]
    print(current["data"])

# contoh
DLL = None
DLL = insertAtHead(DLL, 1)
DLL = insertAtHead(DLL, 2)
printAtHead(DLL)