def createNode(data):                              # baris 1
    print (f'1 def createNode({data})')
    print (f'2    return {{"data": {data}, "next": None}}')
    return {'data': data, 'next': None}            # baris 2
def addAtHead(CLL, data):                          # baris 3
    print (f'3 def addAtHead({CLL}, {data})')
    newNode = createNode(data)                     # baris 4
    print (f'4    newNode = {newNode}')
    if CLL is None:                                # baris 5
        print (f'5    if {CLL}:               # True')
        newNode['next'] = newNode                  # baris 6
        print (f'6       newNode["next"] = {newNode}')
        print (f'7       return {newNode}')
        return newNode                             # baris 7
    print (f'5    if {CLL} is None:         # False')
    current = CLL                                  # baris 8
    print (f'8    current = {current}')
    while current['next'] != CLL:                  # baris 9
        print (f'9    while {current["next"]} != {CLL}:   # True')
        current = current['next']                  # baris 10 
        print (f'10       current = {current}')
    print (f'9    while {current["next"]} != {CLL}:   # False')
    current['next'] = newNode                      # baris 11
    print (f'11    current["next"] = {newNode}')
    newNode['next'] = CLL                          # baris 12
    print (f'12    newNode["next"] = {CLL}')
    print (f'13    return {newNode}')
    return newNode                                 # baris 13
CLL = None  
CLL = addAtHead(CLL, 1)
CLL = addAtHead(CLL, 6)
CLL = addAtHead(CLL, 3)
CLL = addAtHead(CLL, 2)
CLL = addAtHead(CLL, 5)

