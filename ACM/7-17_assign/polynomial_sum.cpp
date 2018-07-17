#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double A(int n){
    double res = 0;
    for (int i = 0;i<n;i++){
        if(i%2){
            res += -1.0 / (i+1);
        }else{
            res += 1.0 / (i+1);
        }
    }
    return res;
}

int main(){
    int n,t;
    cout << setiosflags(ios::fixed) << setprecision(2);
    while(cin >> n){
        for (int i = 0; i < n;i++){
            cin >> t;
            cout << A(t) << endl;
        }
    }
}
