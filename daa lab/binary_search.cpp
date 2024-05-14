#include<iostream>
using namespace std;

// Function to perform binary search on a sorted integer array
int binarySearch(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    int mid, found = 0;

    // Loop until the low index is greater than the high index
    while (low <= high) {
        mid = (low + high) / 2;

        // Check if the middle element is equal to the target value
        if (arr[mid] == n) {
            found = 1;
            break;
        }
        // If the middle element is less than the target value,
        // update the low index to search the right half
        else if (arr[mid] < n) {
            low = mid + 1;
        }
        // If the middle element is greater than the target value,
        // update the high index to search the left half
        else {
            high = mid - 1;
        }
    }

    // Return the index of the target value if found, otherwise -1
    return found? mid : -1;
}

int main() {
    int i, n;
    int a[9]; // Declaring an integer array 'a' of size 9

    cout << "Enter the elements in array :" << endl;

    // Taking input for each element of the array from the user
    for (i = 0; i < 9; i++) {
        cin >> a[i];
    }

    cout << "Enter the element to be searched:" << endl;
    cin >> n;

    // Call the binarySearch function and store the result in the 'result' variable
    int result = binarySearch(a, n);

    // Check if the target value is found in the array
    if (result!= -1) {
        cout << "Element found at index " << result << "!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0; // Indicating successful completion of the program
}
// Output
/*
Enter 9 elements in array :
8 4 9 2 7 3 2 11 54
Enter the element to be searched:11
Element found at index 7!
*/