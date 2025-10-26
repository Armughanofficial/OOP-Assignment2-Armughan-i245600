#include <iostream>
#include <string>
using namespace std;

class Feature 
{

protected:

    string Name;

public:

    Feature(string n) : Name(n) {}
    virtual void analyze() = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature 
{

public:

    LandFeature(string n) : Feature(n) {}
    void analyze() override {
        cout << "Land area detected: " << Name << endl;
    }
};

class WaterFeature : public Feature 
{

public:

    WaterFeature(string n) : Feature(n) {}
    void analyze() override {
        cout << "Water body detected: " << Name << endl;
    }
};

struct Node {

    int FeatureID;

    Feature* featurePtr;

    Node* next;

    Node(int id, Feature* f) : FeatureID(id), featurePtr(f), next(nullptr) {}
};

class LinkedList {

private:

    Node* head;

public:

    LinkedList() : head(nullptr) {}
    
    void insertAtEnd(int id, Feature* f) 
    {
        Node* newNode = new Node(id, f);

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    
    void deleteByID(int id) 
    {
        if (!head) return;

        if (head->FeatureID == id) 
        {
            Node* temp = head;
            head = head->next;
            delete temp->featurePtr;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next && current->next->FeatureID != id) 
        {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp->featurePtr;
            delete temp;
        }
    }
    
    void displayAll() 
    {
        Node* temp = head;
        while (temp) {
            temp->featurePtr->analyze();
            temp = temp->next;
        }
    }
    
    void reverseList() 
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
    
    ~LinkedList() 
    {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp->featurePtr;
            delete temp;
            temp = next;
        }
    }
};

int main() 
{
    
    LinkedList list;
    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Mountain"));
    
    cout << "Original List:" << endl;
    list.displayAll();
    
    cout << "\nAfter deleting ID 2:" << endl;
    list.deleteByID(2);
    list.displayAll();
    
    cout << "\nReversed List:" << endl;
    list.reverseList();
    list.displayAll();
    
    return 0;
}