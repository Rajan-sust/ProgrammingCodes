#include <iostream>

// Node class represents each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class manages the linked list
class LinkedList {
public:
    Node* head;

    // Constructor to initialize the linked list
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the beginning of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the linked list elements
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Function to search for a specific value in the linked list
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to delete a node with a specific value from the linked list
    void remove(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Value not found in the list." << std::endl;
            return;
        }

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        std::cout << "Value " << value << " deleted from the list." << std::endl;
    }
};

int main() {
    LinkedList list;

    // Insert some values into the linked list
    list.insert(5);
    list.insert(10);
    list.insert(15);

    // Display the linked list
    std::cout << "Linked List: ";
    list.display();

    // Search for a value in the linked list
    int valueToFind = 10;
    if (list.search(valueToFind)) {
        std::cout << valueToFind << " is found in the list." << std::endl;
    } else {
        std::cout << valueToFind << " is not found in the list." << std::endl;
    }

    // Remove a value from the linked list
    int valueToRemove = 10;
    list.remove(valueToRemove);

    // Display the updated linked list
    std::cout << "Updated Linked List: ";
    list.display();

    return 0;
}
