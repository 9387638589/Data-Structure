#include <iostream>
#include <stdexcept>

// Node template for the linked list
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

// Double-Ended Queue (Deque) template using linked list
template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    // Constructor
    Deque() : front(nullptr), rear(nullptr) {}

    // Destructor to free allocated memory
    ~Deque() {
        clear();
    }

    // Function to insert an element at the front of the deque
    void pushFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Function to insert an element at the rear of the deque
    void pushRear(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove an element from the front of the deque
    void popFront() {
        if (isEmpty()) {
            throw std::underflow_error("Deque underflow, cannot pop from the front.");
        }

        Node<T>* temp = front;
        front = front->next;

        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }

        delete temp;
    }

    // Function to remove an element from the rear of the deque
    void popRear() {
        if (isEmpty()) {
            throw std::underflow_error("Deque underflow, cannot pop from the rear.");
        }

        Node<T>* temp = rear;
        rear = rear->prev;

        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr;
        }

        delete temp;
    }

    // Function to get the front element of the deque
    T getFront() const {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty, cannot get front element.");
        }

        return front->data;
    }

    // Function to get the rear element of the deque
    T getRear() const {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty, cannot get rear element.");
        }

        return rear->data;
    }

    // Function to check if the deque is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Function to display the elements of the deque from front to rear
    void display() const {
        if (isEmpty()) {
            std::cout << "Deque is empty.\n";
            return;
        }

        Node<T>* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    // Function to clear the deque and free memory
    void clear() {
        Node<T>* current = front;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        front = rear = nullptr;
    }
};

int main() {
    // Sample usage
    Deque<int> deque;

    deque.pushFront(1);
    deque.pushRear(2);
    deque.pushFront(3);

    std::cout << "Deque: ";
    deque.display();

    std::cout << "Front element: " << deque.getFront() << std::endl;
    std::cout << "Rear element: " << deque.getRear() << std::endl;

    deque.popFront();
    std::cout << "Deque after popping from the front: ";
    deque.display();

    deque.popRear();
    std::cout << "Deque after popping from the rear: ";
    deque.display();

    return 0;
}