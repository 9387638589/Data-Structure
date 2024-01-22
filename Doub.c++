#include <iostream>

// Node template for the doubly linked list
template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List template
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr) {}

    // Destructor to free allocated memory
    ~DoublyLinkedList() {
        clear();
    }

    // Function to insert a new element at the end of the list
    void insert(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Function to delete the first occurrence of a number in the list
    void remove(const T& value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            return; // Element not found
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;
    }

    // Function to search for a number in the list
    bool search(const T& value) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true; // Found
            }
            current = current->next;
        }
        return false; // Not found
    }

    // Function to reverse the doubly linked list
    void reverse() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // Function to display the doubly linked list forward
    void displayForward() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to display the doubly linked list backward
    void displayBackward() const {
        Node<T>* current = head;
        while (current != nullptr && current->next != nullptr) {
            current = current->next;
        }

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    // Function to clear the doubly linked list and free memory
    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    // Sample usage
    DoublyLinkedList<int> doublyList;
    doublyList.insert(1);
    doublyList.insert(2);
    doublyList.insert(3);

    std::cout << "Original List (Forward): ";
    doublyList.displayForward();

    std::cout << "Original List (Backward): ";
    doublyList.displayBackward();

    doublyList.remove(2);
    std::cout << "List after removing 2: ";
    doublyList.displayForward();

    doublyList.reverse();
    std::cout << "Reversed List: ";
    doublyList.displayForward();

    return 0;
}