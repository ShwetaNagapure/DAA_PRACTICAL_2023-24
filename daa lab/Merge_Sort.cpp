#include<iostream>
using namespace std;

// Function prototypes
void mergeR(int arr[], int low, int up);
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2);
void copy(int arr[], int temp[], int low, int up);

int main() {
    int n;

    // Prompting user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Array to store elements
    int arr[n];

    // Prompting user to enter array elements
    cout << "Enter elements in the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Performing merge sort
    mergeR(arr, 0, n - 1);

    // Displaying sorted array
    cout << "\nThe merge sort result is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}

// Recursive function to perform merge sort
void mergeR(int arr[], int low, int up) {
    int mid;
    int temp[10]; // Temporary array for merging

    // Base case: If the low index is less than the up index
    if (low < up) {
        mid = (low + up) / 2;

        // Sorting left sublist
        mergeR(arr, low, mid);

        // Sorting right sublist
        mergeR(arr, mid + 1, up);

        // Merging two sublists
        merge(arr, temp, low, mid, mid + 1, up);

        // Copying merged array back to original array
        copy(arr, temp, low, up);
    }
}

// Function to merge two sorted subarrays
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2) {
    int i = low1;
    int j = low2;
    int k = low1;

    // Merging two subarrays into temp array
    while ((i <= up1) && (j <= up2)) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copying remaining elements of left sublist
    while (i <= up1) {
        temp[k++] = arr[i++];
    }

    // Copying remaining elements of right sublist
    while (j <= up2) {
        temp[k++] = arr[j++];
    }
}

// Function to copy elements from temp array to original array
void copy(int arr[], int temp[], int low, int up) {
    for (int i = low; i <= up; i++) {
        arr[i] = temp[i];
    }
}
//Output
/*
Enter the size of the first array: 2
Enter elements of the first array:
22 42
Enter the size of the second array: 3
Enter elements of the second array:
44 12 18 1

The merged and sorted array is:
12 18 22 42 44
*/