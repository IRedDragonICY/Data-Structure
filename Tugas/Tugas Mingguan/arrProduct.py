def insertArray(values, newValue, position, arraySize):
    tempValues = values
    values = [None] * (arraySize + 1)
    for i in range(arraySize):
        values[i] = tempValues[i]
    for i in range(arraySize, position, -1):
        values[i] = tempValues[i-1]
    values[position] = newValue
    return values

# di bangkitkan 5, 2, 3, 6 dan 1
values = []
values = insertArray(values, 5, 0, 0)
values = insertArray(values, 2, 1, 1)
values = insertArray(values, 3, 2, 2)
values = insertArray(values, 6, 3, 3)
values = insertArray(values, 1, 4, 4)
print(values)