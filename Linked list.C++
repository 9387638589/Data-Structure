#include <iostream>

// Node template for the linked list
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

// Linked List template
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to free allocated memory
    ~LinkedList() {
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
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return; // Element not found
        }

        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
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

    // Function to reverse the linked list
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Function to concatenate two linked lists
    LinkedList<T> concatenate(const LinkedList<T>& otherList) const {
        LinkedList<T> result = *this;

        Node<T>* current = result.head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = otherList.head;

        return result;
    }

    // Overloading + operator to concatenate two linked lists
    LinkedList<T> operator+(const LinkedList<T>& otherList) const {
        return concatenate(otherList);
    }

    // Function to display the linked list
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to clear the linked list and free memory
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
    LinkedList<int> list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);

    LinkedList<int> list2;
    list2.insert(4);
    list2.insert(5);

    std::cout << "List 1: ";
    list1.display();

    std::cout << "List 2: ";
    list2.display();

    LinkedList<int> concatenatedList = list1 + list2;
    std::cout << "Concatenated List: ";
    concatenatedList.display();

    return 0;
}