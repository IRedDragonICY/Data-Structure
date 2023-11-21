def insertArray(values, newValue, position, arraySize): # baris 1
    print (f"1 def insertArray({values}, {newValue}, {position}, {arraySize})")
    tempValues = values                                 # baris 2
    print (f"2    tempValues = {tempValues}")
    values = [None] * (arraySize + 1)                      # baris 3
    print (f"3    values = {values}")
    for i in range(arraySize):                          # baris 4
        print (f"4    for {i} in range({arraySize})            #True")
        values[i] = tempValues[i]                       # baris 5
        print (f"5       values[{i}] = {tempValues[i]}             # {values}")
    print (f"4    for {arraySize} in range({arraySize})            #False")
    for i in range(arraySize, position, -1):            # baris 6
        print (f"6    for {i} in range({arraySize}, {position}, -1)            #True")
        values[i] = tempValues[i-1]                     # baris 7
        print (f"7       values[{i}] = {tempValues[i-1]}             # {values}")
    print (f"6    for {position} in range({arraySize}, {position}, -1)            #False")
    values[position] = newValue                         # baris 8
    print (f"8    values[{position}] = {newValue}             # {values}")
    print (f"9    return {values}")
    return values                                       # baris 9
values = []                                             # baris 10
values = insertArray(values, 5, 0, 0)                   # baris 11
values = insertArray(values, 2, 1, 1)                   # baris 12
values = insertArray(values, 3, 2, 2)                   # baris 13
values = insertArray(values, 1, 3, 3)                   # baris 14
values = insertArray(values, 6, 3, 4)                   # baris 15
print(values)                                           # baris 16