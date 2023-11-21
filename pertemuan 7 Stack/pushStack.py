def stackIsEmpty(stack, rearIndex):                              # baris ke-1
    return stack[rearIndex] is None                              # baris ke-2
                                                                 # baris ke-3
def stackIsFull(stack, frontIndex):                              # baris ke-4
    return stack[frontIndex] is not None                         # baris ke-5
                                                                 # baris ke-6
def pushStack(stack, stackMaxCapacity, newData):                 # baris ke-7
    rearIndex = -1                                               # baris ke-8
    frontIndex = 0                                               # baris ke-9
                                                                 # baris ke-10
    if stackIsEmpty(stack, rearIndex):                           # baris ke-11
        stack[rearIndex] = newData                               # baris ke-12
        return stack                                             # baris ke-13
                                                                 # baris ke-14
    if stackIsFull(stack, frontIndex):                           # baris ke-15
        return stack                                             # baris ke-16
                                                                 # baris ke-17
    for i in range(stackMaxCapacity-1, -1, -1):                  # baris ke-18
        if stack[i] == None:                                     # baris ke-19
            stack[i] = newData                                   # baris ke-20
            return stack                                         # baris ke-21
                                                                 # baris ke-22
stackMaxCapacity = 4                                             # baris ke-23
stack = [None] * stackMaxCapacity                                # baris ke-24
                                                                 # baris ke-25
newData = 6                                                      # baris ke-26
stack = pushStack(stack, stackMaxCapacity, newData)              # baris ke-27
print(stack)                                                     # baris ke-28
                                                                 # baris ke-29
newData = 3                                                      # baris ke-30
stack = pushStack(stack, stackMaxCapacity, newData)              # baris ke-31
print(stack)                                                     # baris ke-32
                                                                 # baris ke-33
newData = 11                                                     # baris ke-34
stack = pushStack(stack, stackMaxCapacity, newData)              # baris ke-35
print(stack)                                                     # baris ke-36