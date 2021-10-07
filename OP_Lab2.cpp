#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES

using namespace std;
int main() {
    
    float x;    // Оголошення змінних x та y
    float y;
    
    cout << "Please enter the value of x: "; // Ввід змінної x
    cin >> x;
    
    cout << "Please enter the value of y: "; // Ввід змінної y
    cin >> y;
    
    float r = sqrt(y*y + x*x); // Обчислення r (відстань від центру до нашої точки)
    float a;
    
    bool result; // Оголошення змінної result
    
    if (r <= 1){    // Точка буде в колі тільки якщо r не більше 1
        
        a = atan(y/x);      // Обчислення полярного кута a (від -Пі/2 до Пі/2)
        
        if (x >= 0 && !(x==0 && y < 0)){    // Перевірка чи точка в 1 або 4 чверті і не належить                                           нижньому пунктирі
            
            if ((M_PI/4 <= a && M_PI/2 >= a)||(M_PI/-4 <= a && 0 >= a)){ // Перевіряємо чи кут a                                                                    належить секторам (                                                                     включая крайні точки)
                result = true;
            }
            
            else {
                result = false;
            }
        }
        
        else{
            
            if ((M_PI/4 < a && M_PI/2 > a)||(-M_PI/4 < a && 0 > a)){ // Перевіряємо чи кут a                                                                    належить секторам (не                                                                   включая крайні точки)
                result = true;
            }
            else{
                result = false;
            }
            
        }
    }
    else {
        result = false;
    }

    if (result){ // Виведення результату залежно від змінної result
        cout << "Your point is inside the selected sectors\n";
    }
    else {
        cout << "Your point is not inside the selected sectors\n";
    }
    
    return 0;
}

