#include <iostream>

class Number {
    long long int num;
public:
    Number() : num(0) {}

    void input() {
        
        std::cout << "Input: ";
        std::cin >> num; 
        if (num < 1 || num > 99999 ) {
            std::cout << "Must five digit number... (click enter to continue)...\n";
            system("pause");system("cls");input();
        }
    }
    
    void printReverseIterative() const {
        int rev = 0;
        for (int temp = num; temp; temp /= 10)
            rev = rev * 10 + temp % 10;
        std::cout << "Output (Iterative): " << rev << '\n';
    }
    
    void printReverseRecursive() const {
        printReverseRecursive(num, 0);
    }

private:
   static void printReverseRecursive(int n, int rev) {
       if(n == 0) { 
           std::cout << "Output (Recursive): " << rev; 
           return; 
       }

       printReverseRecursive(n / 10, rev * 10 + n % 10);
   }  
};

int main(){
    Number n;

    n.input();
    n.printReverseIterative();
    n.printReverseRecursive();

   return 0;
}
