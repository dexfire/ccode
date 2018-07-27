#include <cstring>
#include <iostream>
using namespace std;
char *str = (char *)"I Love GPLT";

int main() {
    for (int i = 0; i < strlen(str); i++)
        cout << *(str + i) << endl;
    return 0;
}