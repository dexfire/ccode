<<<<<<< HEAD
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100000;
int N, M;
int rabbits[MAX];

struct arrow {
    int attack;
    int price;
    int idx;
    // �˺��ߣ��۸��->�˺���,�۸��
    friend bool operator<(arrow a, arrow b) {
        if (a.attack == b.attack)
            return a.price < b.price;
        return a.attack < b.attack;
    }
} arrs[MAX];

/***
 * ��ĿҪ�� ��
 * 			ɱ����������
 * 			����Ǯ����
 *
 * 		�����˺��ͼ۸񲻳����ȡ��еļ��˺��ߣ��������ۡ�
 * 1��������С����  ������С����
 * 2������һ����˼·����
 * �������ɱ������
 * �����ٵ�Ǯ��ɱѪ���ٵ����ӣ�����ɱ���Ͷ�����֧��������Ǯ��
 **/
int main() {
    freopen("rabbits.txt", "r", stdin);
    while (cin >> N >> M) {
        priority_queue<int> rabits; //����  ������ȶ��У�Ѫ����С

        int t;
        while (N--) {
            cin >> t;
            rabits.push(t);
        }
        for (int i = 0; i < M; i++) {
            cin >> arrs[i].attack;
        }
        for (int i = 0; i < M; i++) {
            cin >> arrs[i].price;
            arrs[i].idx = i;
        }
        int gold = 0;
        int hp;
        bool okay = true;
        if (M < N) { //�϶�����ȫɱ��
            okay = false;
        } else { //��ʼɱ����
            while (!rabits.empty()) {
                hp = rabits.top(); //��Ѫ���������ӿ�ʼ�����������������Сֵ
                rabits.pop();
                priority_queue<arrow> qarrs;       // ��̬������
                for (int i = M - 1; i >= 0; i--) { //��ɱ�����ӵļ��������
                    if (arrs[i].attack >= hp) {
                        qarrs.push(arrs[i]);
                    }
                }
                if (qarrs.empty()) {
                    okay = false;
                    break;
                } else {
                    gold +=
                        qarrs.top().price; //��ɱ����ǰѪ����ߵ����ӵ���С����
                    arrs[qarrs.top().idx].attack = 0; //�����ظ�
                    cout << gold;
                }
            }
        }
        if (okay)
            cout << gold << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
=======
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100000;
int N, M;
int rabbits[MAX];

struct arrow {
    int attack;
    int price;
    int idx;
    // �˺��ߣ��۸��->�˺���,�۸��
    friend bool operator<(arrow a, arrow b) {
        if (a.attack == b.attack)
            return a.price < b.price;
        return a.attack < b.attack;
    }
} arrs[MAX];

/***
 * ��ĿҪ�� ��
 * 			ɱ����������
 * 			����Ǯ����
 *
 * 		�����˺��ͼ۸񲻳����ȡ��еļ��˺��ߣ��������ۡ�
 * 1��������С����  ������С����
 * 2������һ����˼·����
 * �������ɱ������
 * �����ٵ�Ǯ��ɱѪ���ٵ����ӣ�����ɱ���Ͷ�����֧��������Ǯ��
 **/
int main() {
    freopen("rabbits.txt", "r", stdin);
    while (cin >> N >> M) {
        priority_queue<int> rabits; //����  ������ȶ��У�Ѫ����С

        int t;
        while (N--) {
            cin >> t;
            rabits.push(t);
        }
        for (int i = 0; i < M; i++) {
            cin >> arrs[i].attack;
        }
        for (int i = 0; i < M; i++) {
            cin >> arrs[i].price;
            arrs[i].idx = i;
        }
        int gold = 0;
        int hp;
        bool okay = true;
        if (M < N) { //�϶�����ȫɱ��
            okay = false;
        } else { //��ʼɱ����
            while (!rabits.empty()) {
                hp = rabits.top(); //��Ѫ���������ӿ�ʼ�����������������Сֵ
                rabits.pop();
                priority_queue<arrow> qarrs;       // ��̬������
                for (int i = M - 1; i >= 0; i--) { //��ɱ�����ӵļ��������
                    if (arrs[i].attack >= hp) {
                        qarrs.push(arrs[i]);
                    }
                }
                if (qarrs.empty()) {
                    okay = false;
                    break;
                } else {
                    gold +=
                        qarrs.top().price; //��ɱ����ǰѪ����ߵ����ӵ���С����
                    arrs[qarrs.top().idx].attack = 0; //�����ظ�
                    cout << gold;
                }
            }
        }
        if (okay)
            cout << gold << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
>>>>>>> 36d7ee913d0bbaf3688fa4b5f3ecb33e5f923eb6
}