    void pop() {
        if(top == -1) { 
            cout << "Error: No element to pop";
            return;
        }
        display("pop");
        top--; 
    }
