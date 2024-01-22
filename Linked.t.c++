//Perform Stack operations using Linked List implementation.//
// Node template for the linked list
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& value) : data(value), next(nullptr) {}
};

// Stack template using linked list
template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor to free allocated memory
    ~Stack() {
        clear();
    }

    // Function to push an element onto the stack
    void push(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow, cannot pop an element.\n";
            return;
        }

        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }

    // Function to get the top element of the stack
    T peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty, cannot peek.\n";
            return T();
        }

        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Function to display the elements of the stack
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }

        Node<T>* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    // Function to clear the stack and free memory
    void clear() {
        Node<T>* current = top;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        top = nullptr;
    }
};

int main() {
    // Sample usage
    Stack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack: ";
    stack.display();

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    std::cout << "Stack after pop: ";
    stack.display();

    return 0;
}
