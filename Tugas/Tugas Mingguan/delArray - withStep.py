def delArray(values, arrSize, posisi):         # baris 1
    print (f"1 def delArray({values}, {arrSize},  {posisi})")
    tempValues = [None]*arrSize                # baris 2
    print (f"2    tempValues = {tempValues}")
    for i in range(posisi, arrSize-1):         # baris 3
        print (f"3    for {i} in range({posisi}, {arrSize-1})            #True")
        values[i] = values[i+1]                # baris 4
        print (f"4       values[{i}] = {values[i+1]}              {values}")
    print (f"3    for {i+1} in range({posisi}, {arrSize-1})            #False")
    tempValues = values                        # baris 5
    print (f"5    tempValues = {tempValues}")
    values = [None]*(arrSize-1)                # baris 6
    print (f"6    values = {values}")
    for i in range(arrSize-1):                 # baris 7
        print (f"7    for {i} in range({arrSize-1})            #True")
        values[i] = tempValues[i]              # baris 8
        print (f"8       values[{i}] = {tempValues[i]}             # {values}")
    print (f"7    for {i+1} in range({arrSize-1})            #False")
    print (f"9    return {values}")
    return values                              # baris 9
values = [5,2,3,6,1]
arrSize = 5
posisi = 3
delArray(values, arrSize, posisi)
