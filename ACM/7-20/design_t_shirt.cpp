#include <algorithm>
#include <iostream>

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
    // Ҫ�� �ҳ���������ֵ
    // ˼·��  ����ֵ�ϲ�����ӣ�->  ����ֵ���� -> ȡ�������ֵ
    //              -> ��������ֵ��Ӧ��ԭ�±꣨�ѵ�������ֵ��ͬʱ�Ĵ��� ->
    //              �±�ֵ������ -> �������
    while (cin >> N >> M >> K) {
        double element[M];
        double element_copy[M];

        double req;
        fill(element, element + M, 0.0);  // ��ʼ��Ϊ0
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> req;
                element[j] += req;
                element_copy[j] = element[j];  //����һ��ԭ���� ���ں��������±�
            }
        }
        sort<double*>(element, element + M);  //������ֵ����
        int result[K];                        //�������յ��±�ֵ���
        int c, offset = 0;                    // c : ����ֵ�ظ�����
        // offset : �������ĵ�ǰд��λ��
        for (int i = M - 1; i > M - K - 1;
             i--) {  // ȡ����ֵ����K����M -> M-K��-1
            c = 1;
            //ͳ������ֵ�ظ�����
            while (i > (M - K - 2) && element[i] == element[i - 1]) {
                i--;
                c++;
            }
            // ����ֵתΪ�±�ֵ�������result������
            req2idx(element_copy, element[i], c, result, offset);
            offset += c;  //�ƶ�result���鵱ǰд��λ��
        }
        sort(result, result + K);
        //�������
        for (int i = K - 1; i > 0; i--) {
            cout << result[i] + 1 << " ";
        }
        cout << result[0] + 1 << endl;
    }
    return 0;
}