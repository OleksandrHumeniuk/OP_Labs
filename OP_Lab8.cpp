#include <iostream>
#include <iomanip>
#include <stdarg.h>
#include <cmath>
#include <time.h>


using namespace std;

int randomNum();

int inputArrayLength();
int** buildNewArray(int);
void outputArray(int ** array, int length);
void sortArrayAscending(int ** array, int length);
void deleteArray(int ** array, int length);

bool isNegativeRow(int *array);
int diagonalSum(int ** array, int length);
int smallestNum(int spaceHolder,...);


int main() {
    
    srand(unsigned(time(NULL)));
    
    int m = inputArrayLength(); // The length of all arrays in the program
    
    int **arr1 = buildNewArray(m); // Array #1 with random integer numbers
    int **arr2 = buildNewArray(m); // Array #2 with random integer numbers
    int **arr3 = buildNewArray(m); // Array #3 with random integer numbers
    
    cout << "\nFirst Array" << endl;
    outputArray(arr1, m);
    
    cout << "Second Array" << endl;
    outputArray(arr2, m);
    
    cout << "Third Array" << endl;
    outputArray(arr3, m);
    
    int sum1 = diagonalSum(arr1, m); // Diagonal sum of array #1
    int sum2 = diagonalSum(arr2, m); // Diagonal sum of array #2
    int sum3 = diagonalSum(arr3, m); // Diagonal sum of array #3
    
    cout << "Diagonal sum of the first array: " << sum1 << endl;
    cout << "Diagonal sum of the second array: "<< sum2 << endl;
    cout << "Diagonal sum of the third array: " << sum3 << "\n\n";
    
    int minDiagonalSum = smallestNum(0, sum1, sum2, sum3, -1); // The smallest diagonal sum among all three arrays
    
    if (minDiagonalSum == sum1){
        cout << "The first array has the smallest diagonal sum" << endl;
        sortArrayAscending(arr1, m);
        cout << "Sorted Array" << endl;
        outputArray(arr1, m);
    }
    
    else if(minDiagonalSum == sum2){
        cout << "The second array has the smallest diagonal sum" << endl;
        sortArrayAscending(arr2, m);
        cout << "Sorted Array" << endl;
        outputArray(arr2, m);
    }
    
    else
    {
        cout << "The third array has the smallest diagonal sum" << endl;
        sortArrayAscending(arr3, m);
        cout << "Sorted Array"<< endl;
        outputArray(arr3, m);
    }
    
    deleteArray(arr1, m);
    deleteArray(arr2, m);
    deleteArray(arr3, m);

    
    return 0;
}

int randomNum(){ // Generate and return a random int number between -100 and 99
    return rand()%200 - 100;
}

int inputArrayLength(){ // User input and return the length of arrays
    
    int m;
    cout << "Input the length of arrays: ";
    cin >> m;
    
    return m;
}

int** buildNewArray(int length){ // Declare and initialize 2D array with random integers
    
    int **array = new int* [length];
    
    for (int i = 0; i < length; i++){
        array[i] = new int [length];
    }
    
    for (int col = 0; col < length; col++){
        for (int row = 0; row < length; row++){
            array[col][row] = randomNum();
        }
    }
    
    return array;
}

void outputArray(int ** array, int length){ // Print out 2D array in the console
    
    for (int col = 0; col < length; col++){
        for (int row = 0; row < length; row++){
            cout << setw(9) << array[col][row];
        }
        cout << endl;
    }
    cout << endl;
    
}

bool isNegativeRow(int *array){ //Returns true if the first element of the array is negative, false otherwise
    
    return array[0] < 0 ? true : false;
}

int diagonalSum(int ** array, int length){ // Finds the sum of diagonal elements, whose row's first element is                                               negative
    
    int sum = 0;
    
    for (int i = 0; i < length; i ++){
        
        if (isNegativeRow(array[i])){
            sum += abs(array[i][i]);
        }
    }
    
    return sum;
}

int smallestNum(int spaceHolder,...){ // Returns the smallest number out of all parameters
    
    va_list pArg;
    va_start(pArg,spaceHolder);
    
    int term;
    
    int min = INT_MAX;
    
    while ((term = va_arg(pArg,int)) > 0){
        
        if (min > term){
            min = term;
        }
    }
    
    va_end(pArg);
    
    return min;
}

void sortArrayAscending(int ** array, int length){ // Sort 2D array in ascending order
    
    int pos, min;
    
    for (int i = 0; i < length; i++){
        
        for (int j = 0; j < length; j++){
            
            min = array[i][j];
            pos = j;
            
            for (int k = j+1; k < length; k++){
                
                if (array[i][k] < min){
                    
                    min = array[i][k];
                    pos = k;
                }
            }
            
            array[i][pos] = array[i][j];
            array[i][j] = min;
        }
    }
}

void deleteArray(int ** array, int length){ // Deletes 2D array
    for (int i = 0; i < length; i++){
        delete[] array[i];
    }
    delete[] array;
}

