#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    double F;
    const double G = 6.67259e-11, m1 = 1.987e+30, m2 = 5.975e+24, R = 1.495e+11;
    cout << "太阳的质量为:" << m1 << endl;
    cout << "地球的质量为:" << m2 << endl;
    cout << "地球与太阳的距离为:" << R << endl;
    F = (G * m1 * m2) / (R * R);
    cout << "地球与太阳之间的万有引力为:" << F << endl;
    getch();
}