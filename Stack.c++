#include <iostream>
#include <stdexcept>

// Stack template using array
template <typename T, std::size_t MaxSize>
class StackArray {
private:
    T* array;
    std::size_t top;

public:
    // Constructor
    StackArray() : top(0) {
        array = new T[MaxSize];
    }

    // Destructor to free allocated memory
    ~StackArray() {
        delete[] array;
    }

    // Function to push an element onto the stack
    void push(const T& value) {
        if (top == MaxSize) {
            throw std::overflow_error("Stack overflow, cannot push more elements.");
        }
        array[top++] = value;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow, cannot pop an element.");
        }
        --top;
    }

    // Function to get the top element of the stack
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty, cannot peek.");
        }
        return array[top - 1];
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == 0;
    }

    // Function to display the elements of the stack
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }

        for (std::size_t i = 0; i < top; ++i) {
            std::cout << array[i] << " ";
        }

        std::cout << std::endl;
    }
};

int main() {
    // Sample usage
    const std::size_t maxSize = 5;
    StackArray<int, maxSize> stack;

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