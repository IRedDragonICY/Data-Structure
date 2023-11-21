class Stack:
    def __init__(self, stackMaxCapacity):
        self.stack = [None] * stackMaxCapacity
        self.stackMaxCapacity = stackMaxCapacity

    # Fungsi untuk menambah elemen (push)
    def pushStack(self, newData):
        bottomIndex = -1
        topIndex = 0

        # jika stack kosong
        if self.stack[bottomIndex] == None:
            self.stack[bottomIndex] = newData
            return self.stack

        for i in range(self.stackMaxCapacity-1, -1, -1):
            # jika stack penuh
            if self.stack[topIndex] != None:
                print('Stack sedang penuh')
                break

            if self.stack[i] == None:
                self.stack[i] = newData
                return self.stack

        return self.stack

    # Fungsi untuk menghapus elemen (pop)
    def popStack(self):
        bottomIndex = -1
        topIndex = 0

        for i in range(0, self.stackMaxCapacity):
            if self.stack[bottomIndex] == None:
                print('Stack sedang kosong')
                break

            if self.stack[i] != None:
                self.stack[i] = None
                return self.stack

        return self.stack

    def checkPush(self, n):
        counter = 0
        for i in self.stack:
            if i == None:
                counter += 1
        if counter >= n:
            return "Data bisa di-push ke stack"
        else:
            return "Data tidak bisa di-push ke stack"


# Contoh penggunaan fungsi
stackMaxCapacity = 5
stack = Stack(stackMaxCapacity)

newData = 6
stack.pushStack(newData)
print(stack.stack)

newData = 3
stack.pushStack(newData)
print(stack.stack)

newData = 11
stack.pushStack(newData)
print(stack.stack)

n = 2
print(stack.checkPush(n))

n = 3
print(stack.checkPush(n))