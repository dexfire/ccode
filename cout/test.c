#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    double F;
    const double G = 6.67259e-11, m1 = 1.987e+30, m2 = 5.975e+24, R = 1.495e+11;
    cout << "̫��������Ϊ:" << m1 << endl;
    cout << "���������Ϊ:" << m2 << endl;
    cout << "������̫���ľ���Ϊ:" << R << endl;
    F = (G * m1 * m2) / (R * R);
    cout << "������̫��֮�����������Ϊ:" << F << endl;
    getch();
}