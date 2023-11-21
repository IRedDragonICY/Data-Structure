class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def push(self, data):
        node = Node(data)
        if self.top:
            node.next = self.top
            self.top = node
        else:
            self.top = node
        self.size += 1

    def pop(self):
        if self.top:
            data = self.top.data
            self.top = self.top.next
            self.size -= 1
            return data
        else:
            print('Stack sedang kosong')

    def checkPush(self, n):
        counter = 0
        temp = self.top
        while temp:
            if temp.data == None:
                counter += 1
            temp = temp.next
        if counter >= n:
            return "Data bisa di-push ke stack"
        else:
            return "Data tidak bisa di-push ke stack"

# Contoh penggunaan fungsi
stack = Stack()

stack.push(None)
stack.push(None)
stack.push(4)
stack.push(2)
stack.push(12)

n = 2
print(stack.checkPush(n))

n = 3
print(stack.checkPush(n))
