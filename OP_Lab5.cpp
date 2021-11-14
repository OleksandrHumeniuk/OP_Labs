#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int limit = 1000;
    
    for (int i = 1; i<=limit; i++){ // Арифметичний цикл, що перебирає всі натурально числа менше чим limit
        
        int curNum = i; //Поточне число записується в змінній curNum
        int opNum = 0;
    
        int digits = 0;
    
        while (curNum !=0){ // Ітераційний цикл, що знаходить кількість цифр в числі і записує її в digits
            digits ++;
            curNum = curNum/10;
        }

        curNum = i;
        
        for (int j = digits - 1;j>=0;j--){ // Арифметичний цикл, що "будує" обернене число та записує його в opNum
            opNum = opNum + ((curNum%10)* pow(10,j));
            curNum = curNum/10;
        }
    
        if (i==opNum){ // Якщо число співпадає з йому оберненим, то це число - паліндром
        cout << opNum << endl;
        }
    
    }
    return 0;
}
