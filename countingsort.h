#include <iostream>
#include <cstdlib>
#include "color.h"

using namespace std;

// A function that prints the given array of integers with the specified color
void printArray(int *array, int n, string color) {
    cout << color;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << RESET << endl;
}

//A function that implements counting sort
void countingSort(int *array, int n) {
        
    cout << endl << "Input array: ";
    printArray(array, n, BLUE);
    cout << endl << GREEN;
    cout << "PHASE 01: FIND MAX AND CREATE" << endl;
    cout << RESET << endl;

    // find maximum element in the array    
    int k;
    k = *array;

    for(int i = 0; i < n; i++){
        if(array[i] > k) {
            k = array[i];
        }
    }

    cout << "Max value: " << k << endl << endl;

    // create count array with size equal to (k + 1) and assign every value to 0
    int count[k+1];
    
    for(int i = 0; i < k+1; i++) {
        count[i] = 0;
    }
    
    cout << GREEN;
    cout << "PHASE 02: COUNT/TALLY" << endl;
    cout << RESET << endl;

    //count frequency of each element in the input array
    for (int i = 0; i < n; i++) {
        count[array[i]]++;
        cout << "Count array after counting element " << array[i] << ": ";
        printArray(count, k + 1, RED);
    }

    cout << endl << GREEN;
    cout << "PHASE 03: CUMULATIVE COUNT" << endl;
    cout << RESET;

    // calculate the cumulative sum
    for (int i = 1; i <= k; i++) {
        count[i] += count[i-1];
    }
    

    cout << endl << "Count array after storing the cumulative sum: ";
    printArray(count, k + 1, RED);
    cout << endl;
    

    cout << GREEN;
    cout << "PHASE 04: PLACE AND DECREMENT" << endl;
    cout << RESET << endl;


    //create output array with size equal to n
    //Assigning it to 0 is for visualization purpose only. Can be removed if not needed.
    int output[n];
    for(int i = 0; i < n; i++) {
        output[i] = 0;
    }
   
    //copy elements from input array to output array in sorted order
    for (int i = n-1; i >= 0; i--) {

        cout << "Processing input: " << array[i] << endl;

        cout << "\t Copying number " << array[i] << " to index " << count[array[i]] - 1 << " of the output array."<< endl;
        output[count[array[i]]-1] = array[i];
        
        cout << "\t Decrementing the value of index " << array[i] << "." << endl; 
        count[array[i]]--;
        
        cout << "Results" << endl;
        cout << "Output array: ";
        printArray(output, n, YELLOW);

        cout << "Count array: ";
        printArray(count, k + 1, RED);
        
        cout << endl;
    }

    cout << GREEN;
    cout << "SORTING FINISHED!" << endl;
    cout << RESET << endl;
    
    cout << "Input array: ";
    printArray(array, n, BLUE);
    cout << "Count array: ";
    printArray(count, k+1, RED);
    cout << "Output array: ";
    printArray(output, n, YELLOW);
}

//A function that implements a descending counting sort
void descendingCountingSort(int *array, int n) {
   
    cout << endl << "Input array: ";
    printArray(array, n, BLUE);
    cout << endl << GREEN;
    cout << "PHASE 01: FIND MAX AND CREATE" << endl;
    cout << RESET << endl;

    // find maximum element in the array    
    int k;
    k = *array;

    for(int i = 0; i < n; i++){
        if(array[i] > k) {
            k = array[i];
        }
    }

    cout << "Max value: " << k << endl << endl;

    // create count array with size equal to (k + 1) and assign every value to 0
    int count[k+1];
    
    for(int i = 0; i < k+1; i++) {
        count[i] = 0;
    }
    
    cout << GREEN;
    cout << "PHASE 02: COUNT/TALLY" << endl;
    cout << RESET << endl;

    // count frequency of each element in the input array but you put it k - i index instead of i
    for (int i = 0; i < n; i++) {
        count[k - array[i]]++;
        cout << "Count array after counting element " << array[i] << ": ";
        printArray(count, k + 1, RED);
    }

    cout << endl << GREEN;
    cout << "PHASE 03: CUMULATIVE COUNT" << endl;
    cout << RESET;

    // calculate the cumulative sum in reverse order
    for (int i = k-1; i >= 0; i--) {
        count[i] += count[i+1];
    }
    
    cout << endl << "Count array after storing the cumulative sum: ";
    printArray(count, k + 1, RED);
    cout << endl;
    cout << GREEN;
    cout << "PHASE 04: PLACE AND DECREMENT" << endl;
    cout << RESET << endl;

    //create output array with size equal to n
    //Assigning it to 0 is for visualization purpose only. Can be removed if not needed.
    int output[n];
    for(int i = 0; i < n; i++) {
        output[i] = 0;
    }
   
    //copy elements from input array to output array in sorted order
    for (int i = 0; i < n; i++) {
        cout << "Processing input: " << array[i] << endl;

        cout << "\t Copying number " << array[i] << " to (n - count[k - " << array[i] << "]) which is index " << n - count[k - array[i]] << " of the output array."<< endl;
        output[n - count[k - array[i]]] = array[i];

        cout << "\t Decrementing the value of k - " << array[i] << " which is index " << k - array[i] << "." << endl; 
        count[k - array[i]]--;

        cout << "Results" << endl;
        cout << "Output array: ";
        printArray(output, n, YELLOW);

        cout << "Count array: ";
        printArray(count, k + 1, RED);
        
        cout << endl;
    }

    cout << GREEN;
    cout << "SORTING FINISHED!" << endl;
    cout << RESET << endl;
    
    cout << "Input array: ";
    printArray(array, n, BLUE);
    cout << "Count array: ";
    printArray(count, k+1, RED);
    cout << "Output array: ";
    printArray(output, n, YELLOW);
}

