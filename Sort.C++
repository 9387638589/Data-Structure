#include <iostream>
#include <vector>

// Function template for Insertion Sort
template <typename T>
void insertionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

// Function template for Bubble Sort
template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function template for Selection Sort
template <typename T>
void selectionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// Function template to display the sorted array
template <typename T>
void displaySortedArray(const std::vector<T>& arr) {
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Sample usage
    std::vector<int> elements = {5, 2, 9, 1, 5, 6};

    std::cout << "Choose sorting algorithm:" << std::endl;
    std::cout << "1. Insertion Sort" << std::endl;
    std::cout << "2. Bubble Sort" << std::endl;
    std::cout << "3. Selection Sort" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            insertionSort(elements);
            break;
        case 2:
            bubbleSort(elements);
            break;
        case 3:
            selectionSort(elements);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            return 1;
    }

    std::cout << "Sorted array: ";
    displaySortedArray(elements);

    return 0;
}