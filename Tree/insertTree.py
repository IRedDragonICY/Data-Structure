def create_node(data):
    return {'left':None, 'data':data, 'right':None}

def insert(tree, data):
    if tree == None:
        tree = create_node(data)
    else:
        if data < tree["data"]:
            if tree["left"] == None:
                tree["left"] = create_node(data)
            else:
                insert(tree["left"], data)
        else:
            if tree["right"] == None:
                tree["right"] = create_node(data)
            else:
                insert(tree["right"], data)
    return tree
tree = None
tree = insert(tree, 11)
tree = insert(tree, 6)
tree = insert(tree, 3)


print_in_order(tree)