
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 8;

// Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

// Display Array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[SIZE] = {45, 12, 78, 23, 56, 9, 34, 67};

    // Make a copy of the original array
    int sortedArr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        sortedArr[i] = arr[i];
    }

    // Sort the copy
    sort(sortedArr, sortedArr + SIZE);

    cout << "Original Unsorted Array: ";
    display(arr, SIZE);

    cout << "Sorted Copy: ";
    display(sortedArr, SIZE);

    int existing = 23;
    int missing = 50;

    // Linear Search on original array
    cout << "\n--- Linear Search on Unsorted Array ---\n";

    int result = linearSearch(arr, SIZE, existing);
    if (result != -1)
        cout << existing << " found at index " << result << endl;
    else
        cout << existing << " not found\n";

    result = linearSearch(arr, SIZE, missing);
    if (result != -1)
        cout << missing << " found at index " << result << endl;
    else
        cout << missing << " not found\n";

    // Binary Search on sorted copy
    cout << "\n--- Binary Search on Sorted Copy ---\n";

    result = binarySearch(sortedArr, SIZE, existing);
    if (result != -1)
        cout << existing << " found at index " << result << endl;
    else
        cout << existing << " not found\n";

    result = binarySearch(sortedArr, SIZE, missing);
    if (result != -1)
        cout << missing << " found at index " << result << endl;
    else
        cout << missing << " not found\n";

    // Binary Search on original unsorted array
    cout << "\n--- Binary Search on Unsorted Array ---\n";

    result = binarySearch(arr, SIZE, existing);
    if (result != -1)
        cout << existing << " found at index " << result << endl;
    else
        cout << existing << " not found\n";

    result = binarySearch(arr, SIZE, missing);
    if (result != -1)
        cout << missing << " found at index " << result << endl;
    else
        cout << missing << " not found\n";

    return 0;
}

