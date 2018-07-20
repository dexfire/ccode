#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    while(cin >> n >> m){
        double a[n][m];
        double stu_avg[n];
        double subj_avg[m];
        int ex=0;
        double av1;
        memset(a, 0, sizeof(a));
        memset(stu_avg, 0, sizeof(stu_avg));
        memset(subj_avg, 0, sizeof(subj_avg));
        for (int i = 0; i < n;i++){
            av1 = 0;
            for (int j = 0; j < m;j++){
                cin >> a[i][j];
                subj_avg[j] += a[i][j];
                av1 += a[i][j];
            }
            // ��ѧ��ƽ����xxxͬʱ���xxx  - > ������ͬʱ������� AE
            //cout << (stu_avg[i] = av1 / m) << " ";
            stu_avg[i] = av1 / m;
        }
        // ���ѧ��ƽ��
        cout<< setiosflags(ios::fixed) << setprecision(2) ;
        for (int i = 0; i < n-1;i++)
            cout  <<stu_avg[i] << " ";
        cout << stu_avg[n-1] << endl;
        // ���Ŀƽ����ͬʱ���
        
        for (int j = 0; j < m-1;j++)
            cout << (subj_avg[j] /= n) << " ";
        cout << (subj_avg[m-1] /= n) << setprecision(0)<< endl;
        // ͳ����������
        int mark;
        for (int i = 0; i < n;i++){
            mark = 1;
            for (int j = 0; j < m;j++){
                if(a[i][j]<subj_avg[j] ){
                    mark = 0;
                    break;
                }
                
            }
            if(mark)
                ex += 1;
        }
        cout <<ex<<endl;
        system("pause");
    }
    return 0;
}
