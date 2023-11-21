def enqueue(queue, queueMaxCapacity, newData):
    frontIndex = queueMaxCapacity - 1
    rearIndex = 0
    if queue[frontIndex] is None:
        queue[frontIndex] = newData
        return queue
    if queue[rearIndex] is not None:
        print('antrian penuh')
        return queue
    for i in range(queueMaxCapacity-2, -1, -1):
        if queue[i] is None:
            queue[i] = newData
            return queue
def queueIsEmpty(frontIndex, queue):
    return queue[frontIndex] is None
def dequeue(queue, queueMaxCapacity):
    frontIndex = -1
    tempQueue = queue
    queue = [None] * queueMaxCapacity
    if queueIsEmpty(frontIndex, tempQueue):
        return tempQueue
    for i in range(queueMaxCapacity-2, -1, -1):
        queue[i+1] = tempQueue[i]
    return queue
def countAvailable(queue, queueMaxCapacity):
    count = 0
    for i in range(queueMaxCapacity):
        if queue[i] is None:
            count += 1
    return count
def countData(queue, queueMaxCapacity):
    count = 0
    for i in range(queueMaxCapacity):
        if queue[i] is not None:
            count += 1
    return count