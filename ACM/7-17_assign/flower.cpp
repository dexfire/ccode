#include <cmath>
#include <iostream>
using namespace std;

bool verify(int in)
{
    int sum=0,x=in;
    while (x!=0)
    {
        //cout << "\t"<<pow(x % 10,3)<< endl;
        sum += pow(x % 10, 3);;
        x /= 10;
    }
    return (sum == in);
}

int main()
{
    int a,b;
    while (cin >> a>>b){
        int arr[b - a];
        int idx=0;
        for (int i = a; i <= b;i++){
            if(verify(i))
                arr[idx++] = i;
        }

        if(idx>0){
            for (int j = 0; j < idx-1;j++)
                cout << arr[j] << " ";
            cout << arr[idx - 1] << endl;
        }else{
            cout << "no" << endl;
        }
    }
    system("pause");
}