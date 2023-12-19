def delNode(tree, searchKey):  # Line 1
    if tree is None:  # Line 2
        return None  # Line 3
    # Line 4
    if tree['V'] == searchKey:  # Line 5
        if tree['L'] is None and tree['R'] is None:  # Line 6
            return None  # Line 7 (Delete leaf node)
        elif tree['L'] is not None and tree['R'] is None:  # Line 8
            return tree['L']  # Line 9 (Delete node with one left child)
        elif tree['R'] is not None and tree['L'] is None:  # Line 10
            return tree['R']  # Line 11 (Delete node with one right child)
        else:  # Line 12
            # Delete node with two children
            successor = findMinValNode(tree['R'])  # Line 13
            tree['V'] = successor['V']  # Line 15
            tree['R'] = delNode(tree['R'], successor['V'])  # Line 16
    else:  # Line 17
        tree['L'] = delNode(tree['L'], searchKey)  # Line 18
        tree['R'] = delNode(tree['R'], searchKey)  # Line 19
    # Line 20
    return tree  # Line 21

def findMinValNode(tree):  # Line 22
    if tree is None:  # Line 23
        return None  # Line 24
    elif tree['L'] is None:  # Line 25
        return tree  # Line 26
    else:  # Line 27
        return findMinValNode(tree['L'])  # Line 28
    


