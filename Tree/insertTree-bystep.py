def create_node(data):
    return {'left':None, 'data':data, 'right':None}

def insert(tree, data):                           # baris 1
    print(f'1 def insert({tree}, {data}):')
    newNode = create_node(data)                   # baris 2
    print(f'2 newNode = {newNode}')
    if tree == None:                              # baris 3
        print(f'3 if {tree} == None:     True')
        tree = newNode                            # baris 4
        print(f'4    tree = {tree}')
    elif tree != None:                              # baris 5
        print(f'5 if {tree} != None:     True')
        if data < tree['data']:                   # baris 6
            print(f'6    if {data} < {tree["data"]}:     True')
            if tree['left'] == None:              # baris 7
                print(f'7    if {tree["left"]} == None:     True')
                tree['left'] = create_node(data)  # baris 8
                print(f'8    tree["left"] = {tree["left"]}')
            else:                                 # baris 9
                print(f'7    if {tree["left"]} == None:    False')
                print(f'9    else:                        True')
                insert(tree['left'], data)        # baris 10
                print(f'10       insert({tree["left"]}, {data})')
        else:                                     # baris 11
            print(f'6    if {data} < {tree["data"]}:    False')
            print(f'11    else:                        True')
            if tree['right'] == None:             # baris 12
                print(f'12       if {tree["right"]} == None:     True')
                tree['right'] = create_node(data) # baris 13
                print(f'13       tree["right"] = {tree["right"]}')
            else:                                 # baris 14
                print(f'12       if {tree["right"]} == None:    False')
                print(f'14 else:                        True')
                insert(tree['right'], data)       # baris 15
                print(f'15 insert({tree["right"]}, {data})')
    print(f'5 else if {tree} != None:    False')
    print(f'16 return {tree}')
    return tree                                   # baris 16

tree = None
insert(tree, 11)
insert(tree, 6)
insert(tree, 3)
print(tree)