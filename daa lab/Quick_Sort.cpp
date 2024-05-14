#include <iostream>
using namespace std;

// Function prototypes
void quickSort(int[], int, int);
int partition(int[], int, int);

int main() {
    int n;

    // Prompting user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Array to store elements
    int arr[n];

    // Prompting user to enter array elements
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sorting the array using Quick Sort
    quickSort(arr, 0, n - 1);

    // Displaying sorted elements
    cout << "Sorted elements are:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    // Base case: If the low index is less than the high index, partition the array
    if (low < high) {
        // Partitioning the array
        int pivotIndex = partition(arr, low, high);

        // Sorting left sublist
        quickSort(arr, low, pivotIndex - 1);

        // Sorting right sublist
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choosing the pivot element as the first element of the array
    int i = low + 1; // Index to track the smaller elements
    int j = high; // Index to track the larger elements

    while (i <= j) {
        // Finding an element greater than the pivot
        while (arr[i] < pivot) {
            i++;
        }
        // Finding an element smaller than the pivot
        while (arr[j] > pivot) {
            j--;
        }
        // If i is less than or equal to j, swap the elements at indices i and j
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        } else {
            i++;
        }
    }
    // Placing the pivot element at its correct position
    arr[low] = arr[j];
    arr[j] = pivot;

    return j; // Returning the index of the pivot element
}
//Output
/*
Enter the number of elements in the array: 5
Enter the elements of the array: 55 22 11 4 9
The unsorted array is: 55 22 11 4 9 
The sorted array is: 4 9 11 22 55 
*/