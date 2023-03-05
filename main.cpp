#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// ANSI escape sequences for colored output
const string BLUE = "\033[34m";
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string RESET = "\033[0m";

void printArray(int *arr, int n, string color) {
    cout << color;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << RESET << endl;
}

void countingSort(int *arr, int n) {
    
    // find maximum element in the array    
    int k;
    k = *arr;

    for(int i = 0; i < n; i++){
        if(arr[i] > k) {
            k = arr[i];
        }
    }

    cout << endl << "Max value: " << k << endl << endl;

    // create count array with size equal to (k + 1) and assign every value to 0
    int count[k+1];
    
    for(int i = 0; i < k+1; i++) {
        count[i] = 0;
    }
    
    //create output array with size equal to n
    int output[n];

    //for visualization purpose only. Can be removed if not needed.
    for(int i = 0; i < n; i++) {
        output[i] = 0;
    }
   

    // count frequency of each element in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        cout << "Count array after processing element " << arr[i] << ": ";
        printArray(count, k + 1, RED);
    }

    // calculate the sum of indexes
    for (int i = 1; i <= k; i++) {
        count[i] += count[i-1];
    }
    

    cout << endl << "Count array after adding the sum of indexes: ";
    printArray(count, k + 1, RED);
    cout << endl;
    
    //copy elements from input array to output array in sorted order
    for (int i = n-1; i >= 0; i--) {

        cout << "Processing input: " << arr[i] << endl;
        output[count[arr[i]]-1] = arr[i];

        cout << "\t Adding number " << arr[i] << " to position " << count[arr[i]] << " of the output array."<< endl;
        count[arr[i]]--;

        cout << "\t Decrementing the value of index " << arr[i] << endl; 

        cout << "Results" << endl;
        cout << "Output array: ";
        printArray(output, n, YELLOW);

        
        cout << "Count array: ";
        printArray(count, k + 1, RED);
        
        cout << endl;
    }

    cout << "Sorting finished!" << endl;
    
    cout << "Input array: ";
    printArray(arr, n, BLUE);
    cout << "Count array: ";
    printArray(count, k+1, RED);
    cout << "Output array: ";
    printArray(output, n, YELLOW);
}

int main() {
    srand(time(nullptr));

    int n;
    cout << "Enter size of input array: ";
    cin >> n;

    int arr[n];
    
    char choice;
    cout << "Enter the numbers manually (y/n)? ";
    cin >> choice;
    if (choice == 'y') {
        
        for (int i = 0; i < n; i++) {
            cout << "Enter number " << (i+1) << ": ";
            cin >> arr[i];
        }
    } else {
        // generate n random numbers between 1 and 9
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 9 + 1;
        }
    }

    cout << "Input array: ";
    printArray(arr, n, BLUE);

    countingSort(arr, n);
    return 0;
}