//Implement Circular Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.//
#include <iostream>
// Node template for the circular linked list
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

// Circular Linked List template
template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Destructor to free allocated memory
    ~CircularLinkedList() {
        clear();
    }

    // Function to insert a new element at the end of the list
    void insert(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            head->next = head; // Make it circular
        } else {
            Node<T>* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Make it circular
        }
    }

    // Function to delete the first occurrence of a number in the list
    void remove(const T& value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            Node<T>* current = head;

            while (current->next != head) {
                current = current->next;
            }

            current->next = head->next;
            head = head->next;

            delete temp;
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;

        do {
            prev = current;
            current = current->next;
        } while (current != head && current->data != value);

        if (current == head) {
            return; // Element not found
        }

        prev->next = current->next;
        delete current;
    }

    // Function to search for a number in the list
    bool search(const T& value) const {
        if (head == nullptr) {
            return false;
        }

        Node<T>* current = head;
        do {
            if (current->data == value) {
                return true; // Found
            }
            current = current->next;
        } while (current != head);

        return false; // Not found
    }

    // Function to reverse the circular linked list
    void reverse() {
        if (head == nullptr) {
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        head->next = prev;
        head = prev;
    }

    // Function to display the circular linked list
    void display() const {
        if (head == nullptr) {
            return;
        }

        Node<T>* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);

        std::cout << std::endl;
    }

    // Function to clear the circular linked list and free memory
    void clear() {
        if (head == nullptr) {
            return;
        }

        Node<T>* current = head;
        Node<T>* next = nullptr;

        do {
            next = current->next;
            delete current;
            current = next;
        } while (current != head);

        head = nullptr;
    }
};

int main() {
    // Sample usage
    CircularLinkedList<int> circularList;
    circularList.insert(1);
    circularList.insert(2);
    circularList.insert(3);

    std::cout << "Original Circular List: ";
    circularList.display();

    circularList.remove(2);
    std::cout << "List after removing 2: ";
    circularList.display();

    circularList.reverse();
    std::cout << "Reversed Circular List: ";
    circularList.display();

    return 0;
}
