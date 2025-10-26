#include <iostream>
using namespace std;

class LinkedListStack {
private:
    struct Node {
        char data;
        Node* next;
        Node(char d) : data(d), next(nullptr) {}
    };
    Node* top;
public:
    LinkedListStack() : top(nullptr) {}
    
    void push(char x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    
    char pop() {
        if (!top) return '\0';
        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
};

class ArrayStack {
private:
    char* arr;
    int capacity;
    int topIndex;
public:
    ArrayStack(int size) {
        capacity = size;
        arr = new char[capacity];
        topIndex = -1;
    }
    
    void push(char x) {
        if (topIndex == capacity - 1) return;
        arr[++topIndex] = x;
    }
    
    char pop() {
        if (topIndex == -1) return '\0';
        return arr[topIndex--];
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
    
    ~ArrayStack() {
        delete[] arr;
    }
};

void ChangeLocationWithStacks(char *Array, int b1, int b2) {
    LinkedListStack stack;
    for (int i = b1; i <= b2; i++) {
        stack.push(Array[i]);
    }
    for (int i = b1; i <= b2; i++) {
        Array[i] = stack.pop();
    }
}

void PrintPatternWithStacks(int n) {
    ArrayStack stack(n * n);
    for (int i = n; i > 0; i -= 2) {
        if (i > 0) stack.push(i + '0');
    }
    
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "1 ";
    }
}

int main() {
    char arr[] = {'C','O','M','P','U','T','E','R'};
    ChangeLocationWithStacks(arr, 3, 7);
    for (int i = 0; i < 8; i++) cout << arr[i] << " ";
    
    cout << endl;
    PrintPatternWithStacks(4);
    
    cout << "\nAlgorithm Analysis:\n";
    cout << "Linked List Stack - Insert/Delete: O(1), Memory: Dynamic\n";
    cout << "Array Stack - Insert/Delete: O(1), Memory: Fixed\n";
    
    return 0;
}