def delArray(values, arrSize, posisi):
    tempValues = [None]*arrSize  
    for i in range(posisi, arrSize-1):
        values[i] = values[i+1]
    tempValues = values
    values = [None]*(arrSize-1)  
    for i in range(arrSize-1):
        values[i] = tempValues[i]
    return values