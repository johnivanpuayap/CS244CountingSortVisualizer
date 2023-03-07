/* 
The following code is an implementation of the counting sort algorithm, which is a sorting 
algorithm that works by counting the number of occurrences of each element in an array and 
using that information to sort the array in ascending order.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ANSI escape sequences for colored output
const string BLUE = "\033[34m";
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string RESET = "\033[0m";

// A function that prints the given array of integers with the specified color
void printArray(int *array, int n, string color) {
    cout << color;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << RESET << endl;
}

// The implementation of the counting sort algorithm
void countingSort(int *array, int n) {

    // find maximum element in the array    
    int k;
    k = *array;

    for(int i = 0; i < n; i++){
        if(array[i] > k) {
            k = array[i];
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
        count[array[i]]++;
        cout << "Count array after processing element " << array[i] << ": ";
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

        cout << "Processing input: " << array[i] << endl;
        output[count[array[i]]-1] = array[i];

        cout << "\t Adding number " << array[i] << " to position " << count[array[i]] << " of the output array."<< endl;
        count[array[i]]--;

        cout << "\t Decrementing the value of index " << array[i] << endl; 

        cout << "Results" << endl;
        cout << "Output array: ";
        printArray(output, n, YELLOW);

        
        cout << "Count array: ";
        printArray(count, k + 1, RED);
        
        cout << endl;
    }

    cout << "Sorting finished!" << endl << endl;
    
    cout << "Input array: ";
    printArray(array, n, BLUE);
    cout << "Count array: ";
    printArray(count, k+1, RED);
    cout << "Output array: ";
    printArray(output, n, YELLOW);
}

//main function
int main() {

    int n;
    cout << "Enter size of input array: ";
    cin >> n;

    int array[n];
    
    char choice;
    cout << "Enter the numbers manually (y/n)? ";
    cin >> choice;
    if (choice == 'y') {
        
        for (int i = 0; i < n; i++) {
            cout << "Enter number " << (i+1) << ": ";
            cin >> array[i];
        }
    } else {
        
        //initialize random seed 
        //ensures that each run of the program will generate a different sequence of random numbers.
        srand(time(nullptr));
        
        // generates n random numbers between 0 and range
        int range;
        cout << "Enter range of the randomized number: ";
        cin >> range++;
        for (int i = 0; i < n; i++) {
            array[i] = rand() % range;
        }
    }

    cout << "Input array: ";
    printArray(array, n, BLUE);

    countingSort(array, n);
    return 0;
}