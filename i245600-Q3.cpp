#include <iostream>
#include <string>
using namespace std;

struct BookNode 
{

    int BookID;
    string Title;
    string Author;
    BookNode* next;
    BookNode* prev;
    
    BookNode(int id, string t, string a) : BookID(id), Title(t), Author(a), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList 
{
private:

    BookNode* head;
    BookNode* tail;

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void addToStart(int id, string title, string author) 
    {
        BookNode* newNode = new BookNode(id, title, author);
        
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void addToEnd(int id, string title, string author) {
        BookNode* newNode = new BookNode(id, title, author);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void addAtPosition(int id, string title, string author, int position) {
        if (position <= 0) {
            addToStart(id, title, author);
            return;
        }
        
        BookNode* newNode = new BookNode(id, title, author);
        BookNode* current = head;
        int count = 0;
        
        while (current && count < position - 1) {
            current = current->next;
            count++;
        }
        
        if (!current) {
            addToEnd(id, title, author);
            return;
        }
        
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }
    
    void deleteByID(int id) {
        BookNode* current = head;
        while (current) {
            if (current->BookID == id) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }
    
    void displayForward() {
        BookNode* current = head;
        cout << "Forward: ";
        while (current) {
            cout << "[" << current->BookID << ": " << current->Title << "] -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    
    void displayBackward() {
        BookNode* current = tail;
        cout << "Backward: ";
        while (current) {
            cout << "[" << current->BookID << ": " << current->Title << "] -> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
    
    ~DoublyLinkedList() {
        BookNode* current = head;
        while (current) {
            BookNode* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoublyLinkedList library;
    library.addToStart(1, "C++ Programming", "Bjarne Stroustrup");
    library.addToEnd(2, "Data Structures", "Mark Weiss");
    library.addAtPosition(3, "Algorithms", "CLRS", 1);
    
    library.displayForward();
    library.displayBackward();
    
    library.deleteByID(2);
    cout << "\nAfter deletion:" << endl;
    library.displayForward();
    
    return 0;
}