#include <iostream>

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* rear;

public:
    CircularLinkedList() {
        rear = nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (rear == nullptr) {
            newNode->next = newNode;
            rear = newNode;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
        }
    }

    void insertBack(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (rear == nullptr) {
            newNode->next = newNode;
            rear = newNode;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;  // Update the rear pointer
        }
    }

    void insertBetween(int value, int afterValue, int beforeValue) {
       if (rear == nullptr) return;  // Empty list

       Node* currentNode= rear->next;

       while (currentNode != nullptr && currentNode != rear && 
              (currentNode -> data != afterValue || currentNode -> next -> data != beforeValue)) 
       {  
           currentNode= currentNode -> next;  
       }  

       if(currentNode==nullptr || currentNode==rear)
           return;  // Invalid position

      // Create a new node and insert it between 'after' and 'before' nodes
      Node *newNode=new Node();  
     	newNode -> data=value;  
     	newNode -> next=currentNode -> next;  
     	currentNode -> next=newNode;   
   }

   void printCircularListTwice() { 
    	Node *temp=rear -> next;  

    	do{  
        	std::cout << temp -> data << " ";  
        	temp=temp -> next;  

    	} while(temp!=rear);  

    	temp=temp -> next;

    	do{  
        	std::cout << temp -> data << " "; 
        	temp=temp -> next ; 

    	} while(temp!=rear); 

    	std::cout<<std::endl ;
   }
};

int main() { 
	CircularLinkedList circularList;

	circularList.insertFront(1);
	circularList.insertFront(2);
	circularList.insertFront(3);

	circularList.insertBack(6);
	circularList.insertBack(7);
	circularList.insertBack(8);

	circularList.insertBetween(4, 1, 6);

	// Cetak elemen melingkar dua kali
	circularList.printCircularListTwice();

	return 0 ;
}
