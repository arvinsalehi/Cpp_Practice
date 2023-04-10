#include <algorithm>
#include <iostream>
#include "Stack.h"

using namespace std;

void ReOrder(int newarr[], int arr[], int size) {
    Stack stack;
    Queue queue;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            stack.push(arr[i]);
        } else if (arr[i] > 0) {
            queue.enqueue(arr[i]);
        }
    }

    int idx = 0;
    while (!stack.isEmpty()) {
        newarr[idx++] = stack.top();
        stack.pop();
    }

    while (!queue.isEmpty()) {
        newarr[idx++] = queue.front();
        queue.dequeue();
    }

    newarr[idx] = 0;
}

// Custom compare function for std::sort to sort the numbers from greatest to least
bool customCompare(int a, int b) {
    return a > b;
}

int main() {
    const int SIZE = 18;
    int array[] = { -3,2,-1,5,1,-4,0,11,12,13,-11,-12,0,-1,-2,6,8,7 };
    int newArray[SIZE] = { 0 };

    // Print out the original array
    std::cout << "array:    ";
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Reorder this array in newArray
    ReOrder(newArray, array, SIZE);
    // Print out the new array
    std::cout << "newArray: ";
    for (int i : newArray) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Sort newArray using the standard sort function providing a custom compare function
    // to sort the numbers from greatest to least.
    std::sort(newArray, newArray + SIZE - 1, customCompare);

    // Print out the sorted new array
    std::cout << "newArray sorted: ";
    for (int i : newArray) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
