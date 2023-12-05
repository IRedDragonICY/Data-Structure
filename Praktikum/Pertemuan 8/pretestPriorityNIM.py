'''
2.	Gambarkan cara kerja antrian berprioritas menggunakan doubly link list (insert & remove) Dengan menggunakan 3 digit NIM terakhir masing-masing praktikan ditambah dengna angka 22 setelahnya dengan total angka 5.
Contoh : 4 0 1 2 2
Gambarkan secara step by step untuk insert dan remove data antrian berprioritas menggunkaan doubly link list

'''

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class PriorityQueue:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def insert(self, data):
        new_node = Node(data)
        if self.is_empty() or data < self.head.data:
            new_node.next = self.head
            if self.head is not None:
                self.head.prev = new_node
            self.head = new_node
        else:
            current = self.head
            while current.next is not None and current.next.data < data:
                current = current.next
            new_node.next = current.next
            if current.next is not None:
                current.next.prev = new_node
            current.next = new_node
            new_node.prev = current

    def remove(self, data):
        if self.is_empty():
            return
        current = self.head
        while current is not None:
            if current.data == data:
                if current.prev is not None:
                    current.prev.next = current.next
                else:
                    self.head = current.next
                if current.next is not None:
                    current.next.prev = current.prev
                return
            current = current.next

    def display(self):
        current = self.head
        while current is not None:
            print(current.data, end=' ')
            current = current.next
        print()

# Masukkan angka 4, 0, 1, 2, 2 ke dalam antrian berprioritas
queue = PriorityQueue()
queue.insert(4)
queue.display()
queue.insert(0)
queue.display()
queue.insert(1)
queue.display()
queue.insert(2)
queue.display()
queue.insert(2)
queue.display()
# Tampilkan isi antrian berprioritas
queue.display()

# Hapus angka 2 dari antrian berprioritas
queue.remove(2)

# Tampilkan isi antrian berprioritas setelah penghapusan
queue.display()
