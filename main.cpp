#include <iostream>
#include <cstdlib>
#include <ctime>
#include "countingsort.h"

using namespace std;

int main() {
    int n;
    cout << endl << "Enter size of input array: ";
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
        
        //ensures that each run of the program will generate a different sequence of random numbers.
        srand(time(nullptr));
        
        // generates n random numbers between 0 and range
        int range;
        cout << "Enter range of the randomized number: ";
        cin >> range;
        range++;
        for (int i = 0; i < n; i++) {
            array[i] = rand() % range;
        }
    }

    cout << "Sort by Ascending (y/n): ";
    cin >> choice;
    if (choice == 'y') {
        countingSort(array, n);
    } else {
        descendingCountingSort(array, n);   
    }
    return 0;
}