#include <iostream>

int main() {
    int b, q, n; // Ініціалізація змінних b, q, n
    
    std:: cout << "Please enter the value of b: "; // Ввід змінної b
    std:: cin >> b;
    
    std:: cout << "Please enter the value of q: "; // Ввід змінної q
    std:: cin >> q;
    
    std:: cout << "Please enter the value of n: "; // Ввід змінної n
    std:: cin >> n;
    
    int sum = b; // Ініціалізація змінної суми
    
    for (int i = 1; i<n; i++){ // Цикл додасть до суми всі n членів геометричної прогресії крім першого
        b *= q;
        sum += b;
    }
    
    std::cout << "The sum is " << sum << "\n" ; // Вивід значення суми
    
    return 0; // Вихід з програми
}
