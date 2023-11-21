def createNode(data):                                   # baris 1
    return {'data': data, 'next': None}                 # baris 2
def addAtTail(linkedList, data):                        # baris 3
    print (f'3 def addAtTail({linkedList}, {data})')
    newNode = createNode(data)                          # baris 4
    print (f'4    newNode = {newNode}')
    if linkedList is None:                              # baris 5
        print (f'5    if {linkedList} is None:         # True')
        print (f'6       return {newNode}')
        return newNode                                  # baris 6
    print (f'5    if {linkedList} is None:         # False')
    current = linkedList                                # baris 7
    while current['next'] is not None:                  # baris 8
        print (f'8    while {current["next"]} is not None:   # True')
        current = current['next']                       # baris 9
        print (f'9       current = {current}')
    print (f'8    while {current["next"]} is not None:   # False')
    current['next'] = newNode                           # baris 10
    print (f'10    current["next"] = {newNode}')
    print (f'11    return {linkedList}')
    return linkedList                                   # baris 11
def productOfSquares(linkedList):                       # baris 12
    print (f'12 def productOfSquares({linkedList})')
    current = linkedList                                # baris 13
    print (f'13    current = {current}')
    total = 1                                           # baris 14
    print (f'14    total = {total}')
    while current is not None:                          # baris 15
        print (f'15 while {current} is not None:      # True')
        total *= current["data"]**2                     # baris 16
        print (f'16     total *= {current["data"]}**2        # total = {total}')
        current = current["next"]                       # baris 17
        print (f'17     current = {current}')
    print (f'15    while {current} is not None:      # False')
    return total                                        # baris 18
def removeEvenNodesAfterHead(linkedList):               # baris 19
    print (f'19 def removeEvenNodesAfterHead({linkedList})')
    if linkedList is None:                              # baris 20
        print (f'20    if {linkedList} is None:         # True')
        print (f'21       return None')
        return None                                     # baris 21
    current = linkedList                                # baris 22
    print (f'22    current = {current}')
    while current['next'] is not None:                  # baris 23
        print (f'23 while {current["next"]} is not None:   # True')
        if current['next']["data"] % 2 == 0:            # baris 24
            print (f'24    if {current["next"]["data"]} % 2 == 0:   # True')
            current['next'] = current['next']['next']   # baris 25
            print (f'25       current["next"] = {current["next"]["next"]}')
            print (f'26       break')
            break                                       # baris 26
        else:                                           # baris 27
            print (f'24    if {current["next"]["data"]} % 2 == 0:   # False')
            print (f'27    else:')
            current = current['next']                   # baris 28
            print (f'28       current = {current}')
    print (f'23 while {current["next"]} is not None:   # False')
    return linkedList                                   # baris 29
linkedlist = None                           #5->2->3->6->1
linkedlist = addAtTail(linkedlist, 5)
linkedlist = addAtTail(linkedlist, 2)
linkedlist = addAtTail(linkedlist, 3)
linkedlist = addAtTail(linkedlist, 6)
linkedlist = addAtTail(linkedlist, 1)

print(productOfSquares(linkedlist))
print(linkedlist)
linkedlist = removeEvenNodesAfterHead(linkedlist)
print(linkedlist)
