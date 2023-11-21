def createNode(data):                                   # baris 1
    print (f'1 def createNode({data})')
    print (f'2    return {{"data": {data}, "next": None}}')
    return {'data': data, 'next': None}                 # baris 2
def addAtTail(LL, data):                        # baris 3
    print (f'3 def addAtTail({LL}, {data})')
    newNode = createNode(data)                          # baris 4
    print (f'4    newNode = {newNode}')
    if LL is None:                              # baris 5
        print (f'5    if {LL} is None:         # True')
        print (f'6       return {newNode}')
        return newNode                                  # baris 6
    print (f'5    if {LL} is None:         # False')
    current = LL                                # baris 7
    while current['next'] is not None:                  # baris 8
        print (f'8    while {current["next"]} is not None:   # True')
        current = current['next']                       # baris 9
        print (f'9       current = {current}')
    print (f'8    while {current["next"]} is not None:   # False')
    current['next'] = newNode                           # baris 10
    print (f'10    current["next"] = {newNode}')
    print (f'11    return {LL}')
    return LL                                   # baris 11
def productOfSquares(LL):                       # baris 12
    print (f'12 def productOfSquares({LL})')
    current = LL                                # baris 13
    print (f'13    current = {current}')
    total = 1                                           # baris 14
    print (f'14    total = {total}')
    while current is not None:                          # baris 15
        print (f'15    while {current} is not None:      # True')
        total *= current["data"]**2                     # baris 16
        print (f'16        total *= {current["data"]}²        # total = {total//current["data"]**2}*{current["data"]}²={total}')
        current = current["next"]                       # baris 17
        print (f'17        current = {current}')
    print (f'15       while {current} is not None:      # False')
    print (f'18    return {total}')
    return total                                        # baris 18
def removeEvenNodesAfterHead(LL):               # baris 19
    print (f'19 def removeEvenNodesAfterHead({LL})')
    if LL is None:                              # baris 20
        print (f'20    if {LL} is None:         # True')
        print (f'21       return None')
        return None                                     # baris 21
    print (f'20    if {LL} is None:         # False')
    current = LL                                # baris 22
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
    print (f'29 return {LL}')
    return LL                                   # baris 29
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
