def stackIsEmpty(stack, rearIndex):  # baris ke-1
    print("1 def stackIsEmpty(", stack,",", rearIndex,")")
    print("2 return ", stack[rearIndex]," is None                                    ", stack[rearIndex] is None)
    return stack[rearIndex] is None  # baris ke-2

def stackIsFull(stack, frontIndex):  # baris ke-4
    print("4 def stackIsFull(", stack,",", frontIndex,")")
    print("5 return ", stack[frontIndex]," is not None                               ", stack[frontIndex] is not None)
    return stack[frontIndex] is not None  # baris ke-5

def popStack(stack):  # baris ke-7
    print("7 def popStack(", stack,")")
    rearIndex = -1  # baris ke-8
    print("8 rearIndex = -1")
    frontIndex = 0  # baris ke-9
    print("9 frontIndex = 0")

    if stackIsEmpty(stack, rearIndex):  # baris ke-11
        print("11 if stackIsEmpty(", stack,",", rearIndex,"),                      ", stackIsEmpty(stack, rearIndex))
        stack[rearIndex] = None  # baris ke-12
        print("12 stack[",rearIndex,"] = None")
        print("13 return ", stack)
        return stack  # baris ke-13

    if stackIsFull(stack, frontIndex):  # baris ke-15
        print("15 if stackIsFull(", stack,",", frontIndex,"),                      ", stackIsFull(stack, frontIndex))
        print("16 return ", stack)
        return stack  # baris ke-16

    for i in range(len(stack)):  # baris ke-18
        print("18 for", i," in range(", len(stack),")")
        if stack[i] is not None:  # baris ke-19
            print("19 if ", stack[i]," is not None", "                                       ", stack[i] is not None)
            stack[i] = None  # baris ke-20
            print("20 stack[",i,"] = None")
            print("21 return ", stack)
            return stack  # baris ke-21
        print("19 if ", stack[i]," is not None", "                                       ", stack[i] is not None)

stack = [None,11,3,6]  
print("stack = ", stack)
print("23 stack = popStack(", stack,")")
stack = popStack(stack)  # baris ke-22
print("24 print(", stack,")")
print(stack)  # baris ke-23
print("25 stack = popStack(", stack,")")
stack = popStack(stack)  # baris ke-24
print("26 print(", stack,")")
print(stack)  # baris ke-25