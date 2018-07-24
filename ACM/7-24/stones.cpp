#include <iostream>
#include <queue>
using namespace std;
#define max(a, b) (a > b ? a : b)
struct stone {
    int p;
    int dis;
};
struct cmp {
    // �������� λ��С���� -> ���������
    inline bool operator()(stone &a, stone &b) {
        if (a.p == b.p) // ���λ����ͬ�������ȴ��������Ǹ����ӵľ�����С��
            return a.dis < b.dis;
        return a.p > b.p;
    }
};
int T;
int n;
bool odd;
long long result;
int main() {
    /***
     *	��ʯͷ�������ĵ����������ӣ�ż��������
     *				ʯͷ���ޣ�����һֱѭ����
     *				���һ�δ����һ��һ����ż�����ģ�������������һ�Σ���Ϊż����
     * һ��int ��¼������ :��Ϊ���ս���� ÿ��ż��������¼��λ��
     * һ����С���ȶ���
     * ÿ���������ݵĲ�����
     * 			����ǰ��������ż����
     * 			Ȼ���жϵ�ǰӦ�ô� ��С���ȶ��� ��������������ȶ�������
     * ż������ֱ�ӷŽ�����
     * �������������� �� +dis �������һ����С���ȶ���
     *
     * ż���� ֱ�ӷ������
     */
    // freopen("stones.txt", "r", stdin);
    cin >> T;
    while (T--) {
        result = 0;
        cin >> n;
        priority_queue<stone, vector<stone>, cmp> q;
        for (int i = 0; i < n; i++) {
            stone t;
            cin >> t.p >> t.dis;
            q.push(t);
        }
        odd = false;
        while (!q.empty()) {
            odd = !odd;
            stone now = q.top();
            q.pop();
            // ������ͬλ�õ�Сʯͷ����
            while (!q.empty() && q.top().p == now.p) {
                q.pop();
                odd = !odd; // ???
            }

            if (odd) {
                // cout << "throw " << now.p << " -> " << now.p + now.dis <<
                // endl;
                now.p += now.dis;
                result = max(result, now.p);
                q.push(now);
            } else {
                // cout << "stay " << now.p << endl;
                result = max(result, now.p);
            }
        }
        cout << result << endl;
    }
    return 0;
}
