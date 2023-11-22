#include <iostream>
#include <iomanip>
#define MAX_SIZE 7
using namespace std;
class Stack {
private:
    int A[MAX_SIZE]; 
    int top; 
    
public:
    Stack() {
        top = -1; 
    }

    void push(int x) {
        if(top == MAX_SIZE -1) { 
            cout << "Error: stack overflow";
            return;
        }
        A[++top] = x;
        display("push");
    }


    void pop() {
        if(top == -1) { 
            cout << "Error: No element to pop";
            return;
        }
        display("pop");
        top--; 
    }

    int Top() {
        return A[top];
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        return false;
    }
    void display(){
        display("");
    }
    void display(string status) {
        string border = "----------";
        string blank = "      |          |";

        cout << "Stack: " << endl;
        for (int i = MAX_SIZE - 1; i >= 0; i--) {
            cout << "       " << border << endl;
            if (i > top) {
                cout << blank << endl;
                continue;
            }
            string label = (status == "push" && i == top) ? "\033[1;34mPUSH->\033[0m" : "      ";
            cout << label << "| \033[32m" << setw(5) << A[i] << "\033[0m    |";
            if (status == "pop" && i == top)
                cout << "\033[1;31m -> POP\033[0m";
            cout << endl;
        }
        cout << "       " << border << endl;
    }
};

class Menu {
private:
    Stack S;
public:
    void displayMenu() {
        int choice;
        while (true){
            cout << "+---------------------------------+"<<endl;
            cout << "| Model Stack using Static Array  |"<<endl;
            cout << "+---------------------------------+"<<endl;
            cout << "| 1. Push                         |" << endl;
            cout << "| 2. Pop                          |" << endl;
            cout << "| 3. Print Stack                  |" << endl;
            cout << "| 4. Exit                         |" << endl;
            cout << "+---------------------------------+"<<endl;
            cout << "Size of stack: " << MAX_SIZE << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice) {
                case 1:
                    int x;
                    cout << "Enter element to push: ";
                    cin >> x;
                    S.push(x);
                    break;
                case 2:
                    S.pop();
                    break;
                case 3:
                    S.display();
                    break;
                case 4:
                    cout << "Exiting..." << endl;
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice" << endl;
            }
            cout<<endl<<endl;
            system("Pause");system("cls");
        }
    }
};

int main() {
    Menu menu;
    menu.displayMenu();
    return 0;
}