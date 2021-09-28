#include <iostream>
#include <math.h>
using namespace std;

double ha(double a,double b,double c){
    double result;
    double p = a+b+c;
    result = (2/a)*sqrt(p*(p-a)*(p-b)*(p-c));
    return result;
}

double hb (double a,double b,double c){
    double result;
    double p = a+b+c;
    result = (2/b)*sqrt(p*(p-a)*(p-b)*(p-c));
    return result;
}

double hc (double a,double b,double c){
    double result;
    double p = a+b+c;
    result = (2/c)*sqrt(p*(p-a)*(p-b)*(p-c));
    return result;
}

string zadanie_2(double x){
    int y;
    int z;

    if (x>=0){
       y = fabs(2-x)/(pow(x,2)+sqrt(x)-2);
    } else {
        return "недопустимое x";
    }


    z = fabs(fabs(x)-y);

    if (y > z) return "y > z";
    if (y < z) return "y < z";
    if (y = z) return "y = z";
}

int main()
{
    cout << ha(14.65, 19.93, 12.86) << "\n";
    cout << hb(14.65, 19.93, 12.86) << "\n";
    cout << hc(14.65, 19.93, 12.86) << "\n";

    cout << zadanie_2(4.5) << "\n";
    return 0;
}
