#include <iostream>

using namespace std;
int main(){
    int n, k;
    while(cin>>n>>k){
        // Scores
        int sc[n];
        int fsc[n];
        float rate[n];
        int ridx[n];
        for (int i = 0; i < n;i++)
            cin >> sc[i];
        for (int i = 0; i < n; i++){
            cin >> fsc[i];
            rate[i] = sc[i] / fsc[i];
        }
        int rank;
        for (int i = 0; i < n;i++){
            rank = 0;
            for (int j = 0; j < n;j++){
                if (rate[i] > rate[j])
                    rank++;
            }
            ridx[i] = rank;
        }
        sort[ridx];
    }
}