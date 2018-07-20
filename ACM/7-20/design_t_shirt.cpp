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
                break;
            }
        }
    }
}

int main() {
    while (cin >> N >> M >> K) {
        double element[M];
        double element_copy[M];
        int result[K];
        double req;
        fill(element, element + M, 0);
        fill(element_copy, element_copy + M, 0);
        for (int i = 0; i < N; i++) {
            element[i] = element_copy[i] = 0;
            for (int j = 0; j < M; j++) {
                cin >> req;
                element_copy[j] = element[j] += req;
            }
        }

        sort(element, element + M);

        int c, offset = 0;
        for (int i = M - 1; i > M - K - 1; i--) {
            c = 1;
            while (i > (M - K - 2) && element[i] == element[i - 1]) {
                i--;
                c++;
            }
            req2idx(element_copy, element[i], c, result, offset);
            offset += c;
        }
        sort(result, result + K);
        for (int i = K - 1; i > 0; i--) {
            cout << result[i] + 1 << " ";
        }
        cout << result[0] + 1 << endl;
    }
    return 0;
}