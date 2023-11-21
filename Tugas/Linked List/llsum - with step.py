def createNode(data):                                                  # baris 1
    print(f'1 def createNode({data})')
    print(f'2    return {{"data": {data}, "next": None}}')
    return {'data': data, 'next': None}                                # baris 2
def insertAtTail(linkedList, data):                                    # baris 3
    print(f'3 def insertAtTail({linkedList}, {data})')
    newNode = createNode(data)                                         # baris 4
    print(f'4    newNode = {newNode}')
    if linkedList is None:                                             # baris 5
        print(f'5    if {linkedList} is None:         # True')
        print(f'6       return {newNode}')
        return newNode                                                 # baris 6
    print(f'5    if {linkedList} is None:         # False')
    current = linkedList                                               # baris 7
    print(f'7    current = {current}')
    while current['next'] is not None:                                 # baris 8
        print(f'8    while {current["next"]} is not None:   # True')
        current = current['next']                                      # baris 9
        print(f'9       current = {current}')
    print(f'8    while {current["next"]} is not None:   # False')
    current['next'] = newNode                                          # baris 10
    print(f'10    current["next"] = {newNode}')
    print(f'11    return {linkedList}')
    return linkedList                                                  # baris 11
def print_list_and_sum(linkedList):                                    # baris 12
    print(f'12 def print_list_and_sum({linkedList})')
    current = linkedList                                               # baris 13
    print(f'13    current = {current}')
    total = 0                                                          # baris 14
    print(f'14    total = {total}')
    while current is not None:                                         # baris 15
        print(f'15 while {current} is not None:      # True')
        print(f'16     print(Nilai {current["data"]}² = {current["data"]**2})')   # baris 16
        total += current["data"]**2                                    # baris 17
        print(f'17     total += {current["data"]}**2        # total = {total}')
        current = current["next"]                                      # baris 18
        print(f'18     current = {current}')
    print(f'15    while {current} is not None:      # False')
    print(f'19    Total/jumlah = {total}')                                   # baris 19
linkedlist = None                                                      # baris 20
print(f'20 linkedlist = {linkedlist}')
for i in range(1, 6):                                                  # baris 21
    print(f'21 for {i} in range(1, 6):         # True')
    linkedlist = insertAtTail(linkedlist, i)                           # baris 22
    print(f'22 linkedlist = {linkedlist}')
print(f'21 for {i+1} in range(1, 6):         # False')
print(f'23 print_list_and_sum({linkedlist})')
print_list_and_sum(linkedlist)                                         # baris 23