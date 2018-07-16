#include <iostream>
using namespace std;
#define N 4
#define CN 24
#define ADD 0
#define MINUS 1
#define MUTIPLY 2
#define DIVIDE 3

char *op2ch(int op){
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
}

int calc(int a,int b,int op){
    switch (op)
    {
        case ADD:
            return a + b;
        case MINUS:
            return a - b;
        case MUTIPLY:
            return a * b;
        case DIVIDE:
            if(b==0)
                return 999999;
            return a / b;
    }
}

void verify(int src[] ){
    //C4,2
    int a[CN][N];
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
                    //cout<<arr[i]<<"\t"<<arr[j]<<"\t"<<arr[k]<<"\t"<<arr[l]<<endl;
                    cout<<i<<"\t"<<j<<"\t"<<k<<"\t"<<l<<endl;
                }
            }
        }
    }

    int result;
    for (int i = 0; i < CN;i++){
        for (int j = 0; j < 4;j++){
            for (int k = 0; k < 4;k++){
                for (int l = 0;l < 4; l++)
                {
                    result = calc(calc(calc(src[a[i][0]], src[a[i][1]], j), src[a[i][2]], k), src[a[i][3]], l);
                    if(result==24)
                    cout << "[ ( " << src[a[i][0]] << op2ch(j) << src[a[i][1]] << " ) "
                         << op2ch(k) << src[a[i][2]] << " ] " << op2ch(l) << src[a[i][3]] << " = " << result << endl;
                }
            }
        }
    }

    // for (int i = 0; i < N;i++){
    //     for (int j = i+1; j < N;j++){
    //         for (int k = j+1; k < N;k++){
    //             cout<<arr[i]<<"\t"<<arr[j]<<"\t"<<arr[k]<<"\t"<<endl;
    //         }
    //     }
    // }

}

int main(){
    int arr[N];
    for (int i = 0; i < N;i++)
        cin >> arr[i];
    verify(arr);
    system("pause");
}