def stackIsEmpty(stack, rearIndex):                              # baris ke-1
    print("1 def stackIsEmpty(", stack,",", rearIndex,")")
    print("2 return ", stack[rearIndex]," is None                                    ", stack[rearIndex] is None)
    return stack[rearIndex] is None                              # baris ke-2
                                                                 # baris ke-3
def stackIsFull(stack, frontIndex):                              # baris ke-4
    print("4 def stackIsFull(", stack,",", frontIndex,")")
    print("5 return ", stack[frontIndex]," is not None                               ", stack[frontIndex] is not None)
    return stack[frontIndex] is not None                         # baris ke-5
                                                                 # baris ke-6
def pushStack(stack, stackMaxCapacity, newData):                 # baris ke-7
    print("7 def pushStack(", stack,",", stackMaxCapacity,",", newData,")")
    rearIndex = -1                                               # baris ke-8
    print("8 rearIndex = -1")
    frontIndex = 0                                               # baris ke-9
    print("9 frontIndex = 0")
                                                                 # baris ke-10
    if stackIsEmpty(stack, rearIndex):                           # baris ke-11
        print("11 if stackIsEmpty(", stack,",", rearIndex,"),                      ", stackIsEmpty(stack, rearIndex))
        stack[rearIndex] = newData                               # baris ke-12
        print("12 stack[",rearIndex,"] = ", newData)
        print("13 return ", stack)
        return stack                                             # baris ke-13
                                                                 # baris ke-14
    print("11 if stackIsEmpty(", stack,",", rearIndex,"),                          ", stackIsEmpty(stack, rearIndex))
    if stackIsFull(stack, frontIndex):                           # baris ke-15
        print("15 if stackIsFull(", stack,",", frontIndex,"),                      ", stackIsFull(stack, frontIndex))
        print("16 return ", stack)
        return stack                                             # baris ke-16
                                                                 # baris ke-17
    print("15 if stackIsFull(", stack,",", frontIndex,"),                          ", stackIsFull(stack, frontIndex))
    for i in range(stackMaxCapacity-1, -1, -1):                  # baris ke-18
        print("18 for", i," in range(", stackMaxCapacity-1, ", -1, -1)                        True")
        if stack[i] == None:                                     # baris ke-19
            print("19 if ", stack[i]," == None", "                                       ", stack[i] == None)
            stack[i] = newData                                   # baris ke-20
            print("20 stack[",i,"] = ", newData)
            print("21 return ", stack)
            return stack                                         # baris ke-21
        print("19 if ", stack[i]," == None", "                                       ", stack[i] == None)
                                                                 # baris ke-22
    print("18 for", i," in range(", stackMaxCapacity-1, ", -1, -1)                        False")
stackMaxCapacity = 4                                             # baris ke-23
stack = [None] * stackMaxCapacity                                # baris ke-24
                                                                 # baris ke-25
newData = 6                                                      # baris ke-26
print("26 newData = ", newData)
print("27 stack = pushStack(", stack,",", stackMaxCapacity,",", newData,")")
stack = pushStack(stack, stackMaxCapacity, newData)              # baris ke-27
print(stack)                                                     # baris ke-28
print("28 print(", stack,") = ", stack)
                                                                 # baris ke-29
newData = 3                                                      # baris ke-30
print("30 newData = ", newData)
print("31 stack = pushStack(", stack,",", stackMaxCapacity,",", newData,")")
stack = pushStack(stack, stackMaxCapacity, newData)              # baris ke-31
print("32 print(", stack,") = ", stack)
print(stack)                                                     # baris ke-32
                                                                 # baris ke-33
newData = 11                                                     # baris ke-34
print("34 newData = ", newData)
print("35 stack = pushStack(", stack,",", stackMaxCapacity,",", newData,")")
stack = pushStack(stack, stackMaxCapacity, newData)              # baris ke-35
print("36 print(", stack,") = ", stack)
print(stack)                                                     # baris ke-36