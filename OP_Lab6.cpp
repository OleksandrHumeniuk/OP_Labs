#include <iostream>

using namespace std;

int A(int n, int m);

int main() {
    
    int n, m; // Введенні числа m і n
    
    cout << "Input number n: ";
    cin >> n;
    
    cout << "Input number m: ";
    cin >> m;
    
    cout << "The result is: " << A(n,m) << endl;
    
    
    return 0;
}

int A(int n, int m){ //Функція Акермана
    if (n == 0){
        return m+1;
    }
    else if (m == 0){
        return A(n-1,1);
    }
    else{
        return A(n-1,A(n,m-1));
    }
}


