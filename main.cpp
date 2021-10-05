#include <iostream>
#include <math.h>
using namespace std;
// 2 задание - 1 вариант
// 3 задание - метод правых треугольников 
double zadanie_2(double x){
    double y, y_abs, result;
    y = pow(x,2)+x-1;
    y_abs = abs(y);
    if (y_abs<1){
        result = pow(y,3)-1;
    } else if ((y_abs>=1)&&(y_abs<=2)){
        result = 2*y-1;
    } else if (y_abs>2){
        result = 0.625*y-1;
    }
    return result;
}

double zadanie_3(double a, double b){
    double sum_val,sum,h;
    h = (b-a)/5;
    sum_val=a;
    sum = 0;
    for (int count = 1; count < 6; ++count){
        sum_val = sum_val+h;
        sum = sum+(pow(sum_val,2)+2*sum_val+1);
    }
    return sum*h;
}


int main()
{
    cout << "zadanie 2: "<< "\n";
    cout << "A: "<< zadanie_2(14.65) << "\n";
    cout << "B: "<< zadanie_2(19.93) << "\n";
    cout << "C: "<< zadanie_2(12.86) << "\n";
    cout << "zadanie 3: "<< "\n";
    cout << zadanie_3(2,5) << "\n";

    return 0;
}
