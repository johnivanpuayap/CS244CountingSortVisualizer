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

void printArray(vector<int>& arr, int n, string color) {
    cout << color;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << RESET << endl;
}

void countingSort(vector<int>& arr, int n) {
    // find maximum element in the array
    int maxVal = *max_element(arr.begin(), arr.end());
    cout << endl << "Max value: " << maxVal << endl << endl;

    // create count array with size equal to (maxVal + 1)
    vector<int> count(maxVal + 1, 0);

    // count frequency of each element in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        cout << "Count array after processing element " << arr[i] << ": ";
        printArray(count, maxVal + 1, RED);
    }

    // calculate the sum of indexes
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i-1];
    }
    

    cout << endl << "Count array after adding the sum of indexes: ";
    printArray(count, maxVal + 1, RED);
    cout << endl;
    
    // create output array and copy elements from input array to output array in sorted order
    vector<int> output(n);
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
        printArray(count, maxVal + 1, RED);
        
        cout << endl;
    }

    cout << "Sorting finished!" << endl;
    
    cout << "Input array: ";
    printArray(arr, n, BLUE);
    cout << "Count array: ";
    printArray(count, maxVal+1, RED);
    cout << "Output array: ";
    printArray(output, n, YELLOW);
}

int main() {
    srand(time(nullptr));

    int n;
    int k;
    cout << "Enter size of input array: ";
    cin >> n;

    vector<int> arr(n);
    char choice;
    cout << "Do you want to enter the numbers manually (y/n)? ";
    cin >> choice;
    if (choice == 'y') {
        
        for (int i = 0; i < n; i++) {
            cout << "Enter numbers: " << (i+1);
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