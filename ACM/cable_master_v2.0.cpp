#include <iomanip>
#include <iostream>
using namespace std;

void swap(double *a, double *b) {
  double t = *a;
  *a = *b;
  *b = t;
}

void buble_sort(double arr[], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (arr[i] > arr[j])
        swap(arr + i, arr + j);
    }
  }
}

// int calc_pcs(double arr[], double len, int N,int K) {
//   int c = 0;
//   for (int i = 0; i < N;i++)
//     c += (int)(arr[i] / len);
//   return c-K;
// }

// double binary_test1(double arr[], double _min, double _max, int N, int K) {
//   double min, max;
//   while()
// }

double binary_test(double arr[], double _min, double _max, int N, int K) {
  if (_min > _max)
    return 0;
  else if (_min == _max) {
    return _min;
  }
  // ע�⣺�ֵķ����� ÿ�ݳ��ȳɷ���
  //  littile_inv ��¼�Ƚ�С�Ĳ�����Ҫ�󳤶ȡ���Ӧ�Ƚϴ�ķ�����
  //  last_val ��¼�ϴεĸ��������ĳ���
  double min = _min, mid, max = _max, last_max_inv = _max, last_val = 0;
  int pcs;
  while (true) {
    // cout << min << " , " << mid << " , " << max << "  " << pcs <<":"<<K<<
    // endl;
    mid = min + (max - min) / 2;
    pcs = 0;
    for (int i = 0; i < N; i++) {
      pcs += (int)(arr[i] / mid);
      if (pcs > K)
        break;
    }
    if (((max - min) < 0.01)) {
      return mid;
    } else if (pcs == K) {
      last_val = mid;
      break;
    } else if (pcs > K) {
      min = mid;
    } else if (pcs < K) {
      last_max_inv = max = mid;
    }
  }

  while ((last_max_inv - last_val) < 0.01) {
    mid = min + (max - min) / 2;
    pcs = 0;
    for (int i = 0; i < N; i++) {
      pcs += (int)(arr[i] / mid);
      if (pcs > K)
        break;
    }
    // cout << mid;
    if (pcs < K) {
      last_max_inv = mid;
    } else { // ֻ���� pcs == K
      last_val = min = mid;
    }
  }
  return mid;
}

int main() {
  int N, K;
  double max;
  cout << setiosflags(ios::fixed) << setprecision(2);
  while ( cin >> N >> K) {
    double arr[N];
    max = 0;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
      max += (double)arr[i] / K;
    }
    cout << binary_test(arr, 0.01, max, N, K)<<endl;
  }
}