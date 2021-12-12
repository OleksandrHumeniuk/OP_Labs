#include <iostream>
#include <time.h>
#include <cmath>
#include <iomanip>

using namespace std;

float randomNum();
int inputArrayLength();
void outputArray(float[], int);
void deleteArray(float[]);

float* buildNewArray(int);
float* buildArrayC(float[],float[],int);

float findArrayMean(float[], int);
int findMaxIndex(float[], int);
void replaceElement(float[],float, int);

int main()
{
    srand((unsigned)time(NULL));
    
    int n = inputArrayLength(); // The length of all arrays in the program
    
    float *a = buildNewArray(n); // Array a with random float numbers
    float *b = buildNewArray(n); // Array b with random float numbers
    float *c = buildArrayC(a,b,n); // Array c, based on elements of a, b, and the given formula

    cout << left << setw(15) <<"Array A: ";
    outputArray(a,n);
    
    cout << left <<setw(15) <<"Array B: ";
    outputArray(b,n);
    
    cout << left << setw(15) << "Array C: ";
    outputArray(c,n);
    
    float mean = findArrayMean(c,n); // The mean value of elements of array c
    int index = findMaxIndex(c,n); // The index of maximum element of array c
    
    cout << "\nThe mean of the array c is: " << mean << endl;
    cout << "The max element of the array c has index: " << index << endl;
    
    replaceElement(c,mean,index);
    
    cout << "\n" << left << setw(15) << "New Array C: ";
    outputArray(c,n);
    
    deleteArray(a);
    deleteArray(b);
    deleteArray(c);
    
    return 0;
}

float randomNum(){ // Generate and return a random float number between 0 and 1
     
    return (float)(rand())/(float)RAND_MAX*100;
}

float* buildNewArray(int n){ // Generate a dynamic array with length n, initialize it with random float                              numbers, and return this array
    float *a = new float [n];
    
    for (int i = 0; i < n; i++){
        a[i] = randomNum();
    }
    
    return a;
}

float* buildArrayC(float arr1[],float arr2[],int n){ // Generate a dynamic array "c" with length n, and                                                        initialize it with elements, based on arr1 and arr2 and the given formula
    float *c = new float [n];
    
    for (int i = 0; i < n; i++){
        c[i] = abs(pow(arr1[i],2) + pow(arr2[i],2));
    }
    
    return c;
}

void outputArray(float array[], int n){ // Print out all elements of array
    
    for (int i = 0; i < n; i++){
        cout << setw(9) << array [i];
    }
    
    cout << "\n";
    
}

float findArrayMean(float array[], int n){ // Find and return mean of all elements of array
    
    float sum = 0;
    
    for (int i = 0; i < n; i++){
        sum += array[i];
    }
    
    return (sum/n);
}

int findMaxIndex(float array[], int n){ // Find and return the index of the maximum element of array
    
    float max = array[0];
    int maxIndex = 0;
    
    for (int i = 1; i < n; i++){
        if (array[i] > max){
            maxIndex = i;
            max = array[i];
        }
    }
    
    return maxIndex;
}

int inputArrayLength(){ // Let's the user input and return the length of arrays
    
    int n;
    cout << "Input the length of arrays: ";
    cin >> n;
    
    return n;
}

void replaceElement(float array[],float value, int index){ // Replaces the element of array with given                                                               index with given value
    array[index] = value;
}

void deleteArray(float array[]){ // Deletes array
    delete[] array;
}

