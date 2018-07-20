#include <iostream>
#include <math.h>
#include <string>

using namespace std;
#define N 4
#define CN 24
#define ADD 0
#define MINUS 1
#define MUTIPLY 2
#define DIVIDE 3

int a[CN][N];

string op2ch(int op){
    switch (op)
    {
        case ADD:
            return " + ";
        case MINUS:
            return " - ";
        case MUTIPLY:
            return " * ";
        case DIVIDE:
            return " / ";
    }
    return "";
}

double calc(double a,double b,int op){
    switch (op)
    {
        case ADD:
            return a + b;
        case MINUS:
            return a - b;
        case MUTIPLY:
            return a * b;
        case DIVIDE:
            if(b==0){
                // Debug cout << "Zero_Divided - a,b,op="<< a << op2ch(op) << b << endl;
                return -999999.123456f;
            }
            return a / b;
    }
    return 0;
}

void verify(int src[] ){
    //C4,2
    double result;
    for (int i = 0; i < CN;i++){
        for (int j = 0; j < 4;j++){
            for (int k = 0; k < 4;k++){
                for (int l = 0;l < 4; l++)
                {
                    // 第一种结合顺序
                    result = calc(
                        calc(
                            calc(src[a[i][0]], src[a[i][1]], j),
                        src[a[i][2]], k), 
                    src[a[i][3]], l);
                    if(abs(result-24)<1e-10)
                    cout << "[ ( " << src[a[i][0]] << op2ch(j) << src[a[i][1]] << " ) "
                         << op2ch(k) << src[a[i][2]] << " ] " << op2ch(l) << src[a[i][3]] << " = " << result << endl;
                    // 第二种结合顺序
                    result = calc(
                                    calc(src[a[i][0]], src[a[i][1]], j), 
                                    calc(src[a[i][2]], src[a[i][3]], l),
                                    k);
                    if(abs(result-24)<1e-10)
                    cout << " ( " << src[a[i][0]] << op2ch(j) << src[a[i][1]] << " ) "
                         << op2ch(k) << " ( "<<src[a[i][2]] << op2ch(l) << src[a[i][3]] << " ) " << " = " << result << endl;
                    // 第三种结合顺序
                    result = calc(
                                     calc(src[a[i][0]], 
                                        calc(src[a[i][1]],src[a[i][2]],k),
                                    j),
                                src[a[i][3]], l);
                    if(abs(result-24)<1e-10)
                    cout << "[ " << src[a[i][0]] << op2ch(j) << " ( "<<src[a[i][1]]
                         << op2ch(k) << src[a[i][2]]<<" ) " << " ] " << op2ch(l) << src[a[i][3]] << " = " << result << endl;
                    // 第四种结合顺序
                    result = calc(
                                    src[a[i][0]],
                                    calc(
                                        calc(src[a[i][1]],src[a[i][2]],k),
                                        src[a[i][3]],
                                        l),
                                 j);
                    if(abs(result-24)<1e-10)
                    cout << src[a[i][0]] << op2ch(j) << " [  ( "<<src[a[i][1]]
                         << op2ch(k) << src[a[i][2]]<<" ) "  << op2ch(l) << src[a[i][3]] << " ] = " << result << endl;
                    // 第五种结合顺序
                    result = calc(
                                    src[a[i][0]],
                                    calc(
                                        src[a[i][1]],
                                        calc(src[a[i][2]],src[a[i][3]],l),
                                    k),
                                 j);
                    if(abs(result-24)<1e-10)
                    cout << src[a[i][0]] << op2ch(j) << " [  "<<src[a[i][1]]
                         << op2ch(k)<<" ( " << src[a[i][2]] << op2ch(l) << src[a[i][3]] << " ) ] = " << result << endl;
                }
            }
        }
    }
}

int main(){
    int arr[N];
    int idx = 0;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            if(j==i)
                continue;
            for (int k = 0; k < N;k++){
                if(k==i||j==k)
                    continue;
                for (int l = 0; l < N;l++){
                    if(l==i||l==j||l==k)
                        continue;
                    a[idx][0] = i;
                    a[idx][1] = j;
                    a[idx][2] = k;
                    a[idx++][3] = l;
                    //cout<<"Debug:" <<arr[i]<<"\t"<<arr[j]<<"\t"<<arr[k]<<"\t"<<arr[l]<<endl;
                    // Debug cout<<i<<"\t"<<j<<"\t"<<k<<"\t"<<l<<endl;
                }
            }
        }
    }

    while(true){
        for (int i = 0; i < N;i++)
        cin >> arr[i];
        verify(arr);
        // Debug
        // cout<<calc(
        //                             4,
        //                             calc(
        //                                 3,
        //                                 calc(1,1,1),
        //                             3),
        //                          3);
    }

    system("pause");
}
