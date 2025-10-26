#include <iostream>
#include <string>
using namespace std;

struct Customer {
    int CustomerID;
    string Name;
    int TicketsRequested;
    Customer* next;
    
    Customer(int id, string name, int tickets) : CustomerID(id), Name(name), TicketsRequested(tickets), next(nullptr) {}
};

class Queue {
private:
    Customer* front;
    Customer* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    
    void enqueue(int id, string name, int tickets) {
        Customer* newCustomer = new Customer(id, name, tickets);
        if (!rear) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
    }
    
    void dequeue() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Customer* temp = front;
        cout << "Serving customer: " << temp->Name << " with " << temp->TicketsRequested << " tickets" << endl;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }
    
    void display() {
        Customer* current = front;
        cout << "Current Queue: ";
        while (current) {
            cout << "[" << current->CustomerID << ": " << current->Name << " - " << current->TicketsRequested << " tickets] -> ";
            current = current->next;
        }
        cout << "END" << endl;
    }
    
    ~Queue() {
        while (front) {
            dequeue();
        }
    }
};

int main() {
    Queue ticketQueue;
    ticketQueue.enqueue(1, "Alice", 2);
    ticketQueue.enqueue(2, "Bob", 1);
    ticketQueue.enqueue(3, "Charlie", 4);
    
    ticketQueue.display();
    
    ticketQueue.dequeue();
    ticketQueue.display();
    
    ticketQueue.dequeue();
    ticketQueue.display();
    
    return 0;
}