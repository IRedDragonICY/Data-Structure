def createNode(data):
    return {'data': data, 'next': None}
def insertAtTail(linkedList, data):
    newNode = createNode(data)
    if linkedList is None:
        return newNode
    current = linkedList
    while current['next'] is not None:
        current = current['next']
    current['next'] = newNode
    return linkedList
def print_list_and_sum(linkedList):
    current = linkedList
    total = 0
    while current is not None:
        print(f'Nilai {current["data"]}² = {current["data"]**2}')
        total += current["data"]**2
        current = current["next"]
    print(f'Total/jumlah = {total}')
linkedlist = None
for i in range(1, 6):
    linkedlist = insertAtTail(linkedlist, i)
print_list_and_sum(linkedlist)