values = [1, 8, 11, 3, 6]
position = 1


def insertArray(values, position, value):
    arrSize = len(values)
    arrSize += 1
    tempValues = [0] * (arrSize)
    for i in range(arrSize):
        if i < position:
            tempValues[i] = values[i]
        elif i == position:
            tempValues[i] = value
        else:
            tempValues[i] = values[i - 1]
    return tempValues


values = insertArray(values, position, 7)
print(values)
