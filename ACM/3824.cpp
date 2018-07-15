#include <iostream>
using namespace std;
#define N 4
#define ADD 0
#define MINUS 1
#define MUTIPLY 2
#define DIVIDE 3

void verify(int arr[] ){
    // 处理过程 C4,2 C3,2 C2,2

    //C4,2
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
                    cout<<arr[i]<<"\t"<<arr[j]<<"\t"<<arr[k]<<"\t"<<arr[l]<<endl;
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