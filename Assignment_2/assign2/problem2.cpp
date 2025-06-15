#include <string>
#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        std::string data;
        Node* next;
    };

    Node* head;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insertFront(const std::string& value);
    bool isEmpty() const;
    int getSize() const;
    void printList() const;

    // Big Three
    SinglyLinkedList(const SinglyLinkedList& other);
    SinglyLinkedList& operator=(const SinglyLinkedList& other);
    void clear(Node* node);
     // New methods for reversing
    void reverseIterative();
    void reverseRecursive();
private:
    Node* reverseRecursiveHelper(Node* node);
};


// Constructor
SinglyLinkedList::SinglyLinkedList() : head(nullptr), size(0) {}

// Destructor
SinglyLinkedList::~SinglyLinkedList() {
    clear(head);
}

// Insert at front
void SinglyLinkedList::insertFront(const std::string& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    size++;
}

// Is empty
bool SinglyLinkedList::isEmpty() const {
    return head == nullptr;
}

// Get size
int SinglyLinkedList::getSize() const {
    return size;
}

// Print list
void SinglyLinkedList::printList() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}

// Copy constructor
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other) : head(nullptr), size(0) {
    Node* current = other.head;
    Node** tail = &head;
    while (current) {
        *tail = new Node;
        (*tail)->data = current->data;
        (*tail)->next = nullptr;
        tail = &((*tail)->next);
        current = current->next;
        size++;
    }
}

// Assignment operator
SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other) {
    if (this != &other) {
        clear(head);
        Node* current = other.head;
        Node** tail = &head;
        while (current) {
            *tail = new Node;
            (*tail)->data = current->data;
            (*tail)->next = nullptr;
            tail = &((*tail)->next);
            current = current->next;
            size++;
        }
    }
    return *this;
}

// Clear list
void SinglyLinkedList::clear(Node* node) {
    if (node == nullptr) return;
    clear(node->next);
    delete node;
}

// --------------- YOUR CODE HERE -------------------// 
void SinglyLinkedList::reverseIterative(){
    if  (!head) return;
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    


}
void SinglyLinkedList::reverseRecursive(){

}


int main() {
    SinglyLinkedList list;
    list.insertFront("Banana");
    list.insertFront("Apple");
    list.insertFront("Orange");

    list.printList(); // Orange -> Apple -> Banana -> nullptr

    return 0;
}
