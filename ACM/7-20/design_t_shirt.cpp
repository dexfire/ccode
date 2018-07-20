#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;
// N people  M total elements K used
int N, M, K;

void req2idx(double ele[], double req, int count, int result[], int offset) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < M; j++) {
            if (req == ele[j]) {
                ele[j] = 0;
                result[offset + i] = j;
            }
        }
    }
}

int main() {
    while (cin >> N >> M >> K) {
        double element[N];
        double element_copy[N];
        int result[K];
        int req;
        for (int i = 0; i < N; i++) {
            element[i] = element_copy[i] = 0;
            for (int j = 0; j < M; j++) {
                cin >> req;
                element_copy[j] = element[j] += req;
            }
        }

        sort(element, element + N);

        int c, offset = 0;
        for (int i = M - 1; i > M - K - 1; i--) {
            c = 1;
            while (element[i] == element[i - 1]) {
                i--;
                c++;
            }
            req2idx(element_copy, c, element[i], result, offset);
            offset += c;
        }
        sort(result, result + K);
        for (int i = K - 1; i > 0; i--) {
            cout << result[i] << " ";
        }
        cout << result[0] << endl;
    }
    return 0;
}