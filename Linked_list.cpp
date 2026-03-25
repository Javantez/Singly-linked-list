#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;
    int size;
    int comparisons;
    int operations;
    
public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
        size = 0;
        comparisons = 0;
        operations = 0;
    }
    
    // Destructor - free memory
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    
    // Get current size
    int getSize() {
        return size;
    }
    
    // Get metrics
    int getComparisons() { return comparisons; }
    int getOperations() { return operations; }
    
    // Reset metrics
    void resetMetrics() {
        comparisons = 0;
        operations = 0;
    }
    
    // Insert at beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
        operations++;
        cout << "Inserted " << data << " at beginning" << endl;
    }
    
    // Insert at end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        operations++;
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
                operations++;
            }
            current->next = newNode;
        }
        size++;
        cout << "Inserted " << data << " at end" << endl;
    }
    
    // Insert at position
    bool insertAtPosition(int data, int position) {
        if (position < 0 || position > size) {
            cout << "Invalid position! Valid: 0 to " << size << endl;
            return false;
        }
        
        Node* newNode = new Node(data);
        operations++;
        
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next;
                operations++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
        cout << "Inserted " << data << " at position " << position << endl;
        return true;
    }
    
    // Delete by value
    bool deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return false;
        }
        
        operations++;
        
        if (head->data == value) {
            comparisons++;
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            cout << "Deleted " << value << " from beginning" << endl;
            return true;
        }
        
        Node* current = head;
        while (current->next != nullptr) {
            comparisons++;
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                size--;
                operations++;
                cout << "Deleted " << value << endl;
                return true;
            }
            current = current->next;
            operations++;
        }
        
        cout << "Value " << value << " not found" << endl;
        return false;
    }
    
    // Delete at position
    bool deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return false;
        }
        
        if (position < 0 || position >= size) {
            cout << "Invalid position! Valid: 0 to " << size - 1 << endl;
            return false;
        }
        
        operations++;
        
        if (position == 0) {
            Node* temp = head;
            int deletedData = head->data;
            head = head->next;
            delete temp;
            size--;
            cout << "Deleted " << deletedData << " at position 0" << endl;
            return true;
        }
        
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
            operations++;
        }
        
        Node* temp = current->next;
        int deletedData = temp->data;
        current->next = current->next->next;
        delete temp;
        size--;
        cout << "Deleted " << deletedData << " at position " << position << endl;
        return true;
    }
    
    // Search for a value
    int search(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }
        
        Node* current = head;
        int position = 0;
        comparisons = 0;
        operations++;
        
        while (current != nullptr) {
            comparisons++;
            if (current->data == value) {
                cout << "Found " << value << " at position " << position << endl;
                cout << "Comparisons made: " << comparisons << endl;
                return position;
            }
            current = current->next;
            position++;
            operations++;
        }
        
        cout << "Value " << value << " not found" << endl;
        cout << "Comparisons made: " << comparisons << endl;
        return -1;
    }
  
    void traverse() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* current = head;
        int position = 0;
        
        cout << "\nLinked List Contents:" << endl;
        cout << "---------------------" << endl;
        while (current != nullptr) {
            cout << "Position " << position << ": " << current->data << endl;
            current = current->next;
            position++;
        }
        cout << "Total elements: " << size << endl;
    }
    
    void displayMetrics() {
        cout << "\n" << string(40, '=') << endl;
        cout << "PERFORMANCE METRICS" << endl;
        cout << string(40, '=') << endl;
        cout << "Operations performed: " << operations << endl;
        cout << "Comparisons made: " << comparisons << endl;
        cout << "Current list size: " << size << endl;
        cout << string(40, '=') << endl;
    }
};

int main() {
    cout << string(50, '=') << endl;
    cout << "SINGLY LINKED LIST IMPLEMENTATION" << endl;
    cout << "COSC 333 - DESIGN AND ANALYSIS" << endl;
    cout << "Student: Javan Otieno" << endl;
    cout << "Registration: EB3.67256.23" << endl;
    cout << string(50, '=') << endl;
    
    SinglyLinkedList list;
    
    cout << "\n--- Testing Insert Operations ---" << endl;
    
    list.insertAtEnd(20);
    list.traverse();
    
    list.insertAtBeginning(10);
    list.traverse();
    
    list.insertAtBeginning(5);
    list.traverse();
    
    list.insertAtPosition(15, 2);
    list.traverse();
    
    cout << "\n--- Testing Delete Operations ---" << endl;
    
    list.deleteByValue(20);
    list.traverse();
    
    list.deleteAtPosition(1);
    list.traverse();
    
    cout << "\n--- Testing Search ---" << endl;
    
    list.search(15);
    list.search(100);
    
    list.displayMetrics();
    
    cout << "\nFinal size: " << list.getSize() << endl;
    
    return 0;
}
