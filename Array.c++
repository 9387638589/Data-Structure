Perform Queues operations using Circular Array Implementation.Use Templates.
#include <iostream>
#include <stdexcept>
// Queue template using circular array
template <typename T, std::size_t MaxSize>
class CircularArrayQueue {
private:
    T* array;
    std::size_t front;
    std::size_t rear;
    std::size_t count;

public:
    // Constructor
    CircularArrayQueue() : front(0), rear(0), count(0) {
        array = new T[MaxSize];
    }

    // Destructor to free allocated memory
    ~CircularArrayQueue() {
        delete[] array;
    }

    // Function to enqueue an element into the queue
    void enqueue(const T& value) {
        if (count == MaxSize) {
            throw std::overflow_error("Queue overflow, cannot enqueue more elements.");
        }

        array[rear] = value;
        rear = (rear + 1) % MaxSize;
        ++count;
    }

    // Function to dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue underflow, cannot dequeue an element.");
        }

        front = (front + 1) % MaxSize;
        --count;
    }

    // Function to get the front element of the queue
    T frontElement() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty, cannot get front element.");
        }

        return array[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Function to display the elements of the queue
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        std::size_t index = front;
        for (std::size_t i = 0; i < count; ++i) {
            std::cout << array[index] << " ";
            index = (index + 1) % MaxSize;
        }

        std::cout << std::endl;
    }
};

int main() {
    // Sample usage
    const std::size_t maxSize = 5;
    CircularArrayQueue<int, maxSize> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Queue: ";
    queue.display();

    std::cout << "Front element: " << queue.frontElement() << std::endl;

    queue.dequeue();
    std::cout << "Queue after dequeue: ";
    queue.display();

    return 0;
}
