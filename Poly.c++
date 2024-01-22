#include <iostream>

// Node template for the polynomial linked list
template <typename T>
struct Node {
    T coefficient;
    int exponent;
    Node* next;

    Node(const T& coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

// Polynomial linked list template
template <typename T>
class Polynomial {
private:
    Node<T>* head;

public:
    // Constructor
    Polynomial() : head(nullptr) {}

    // Destructor to free allocated memory
    ~Polynomial() {
        clear();
    }

    // Function to insert a term into the polynomial
    void insertTerm(const T& coefficient, int exponent) {
        Node<T>* newNode = new Node<T>(coefficient, exponent);

        if (head == nullptr || exponent > head->exponent) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr && current->next->exponent >= exponent) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to add another polynomial to this polynomial
    void addPolynomial(const Polynomial<T>& other) {
        Node<T>* result = nullptr;
        Node<T>** current = &result;

        Node<T>* currentThis = head;
        Node<T>* currentOther = other.head;

        while (currentThis != nullptr || currentOther != nullptr) {
            if (currentThis != nullptr && (currentOther == nullptr || currentThis->exponent > currentOther->exponent)) {
                *current = new Node<T>(currentThis->coefficient, currentThis->exponent);
                currentThis = currentThis->next;
            } else if (currentOther != nullptr && (currentThis == nullptr || currentOther->exponent > currentThis->exponent)) {
                *current = new Node<T>(currentOther->coefficient, currentOther->exponent);
                currentOther = currentOther->next;
            } else {
                // Exponents are equal, add coefficients
                *current = new Node<T>(currentThis->coefficient + currentOther->coefficient, currentThis->exponent);
                currentThis = currentThis->next;
                currentOther = currentOther->next;
            }

            current = &((*current)->next);
        }

        clear();
        head = result;
    }

    // Function to display the polynomial
    void display() const {
        Node<T>* current = head;

        while (current != nullptr) {
            std::cout << current->coefficient;
            if (current->exponent > 0) {
                std::cout << "x^" << current->exponent;
            }

            current = current->next;

            if (current != nullptr) {
                std::cout << " + ";
            }
        }

        std::cout << std::endl;
    }

    // Function to clear the polynomial and free memory
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
    Polynomial<int> poly1, poly2;

    // Sample usage
    poly1.insertTerm(3, 2);
    poly1.insertTerm(-2, 1);
    poly1.insertTerm(5, 0);

    poly2.insertTerm(1, 3);
    poly2.insertTerm(4, 1);
    poly2.insertTerm(-3, 0);

    std::cout << "Polynomial 1: ";
    poly1.display();

    std::cout << "Polynomial 2: ";
    poly2.display();

    poly1.addPolynomial(poly2);

    std::cout << "Result after addition: ";
    poly1.display();

    return 0;
}