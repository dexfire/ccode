#include <iostream>

using namespace std;

void buble_sort(double arr[], int N) {
  for (int i = 0; i < N;) {
    for (int j = i; j < N; j++) {
    }
  }
}

void binary_test(double arr[], double _min, double _max, int N, int K) {
  // ע�⣺�ֵķ����� ÿ�ݳ��ȳɷ���
  //  littile_inv ��¼�Ƚ�С�Ĳ�����Ҫ�󳤶ȡ���Ӧ�Ƚϴ�ķ�����
  //  last_val ��¼�ϴεĸ��������ĳ���
  double min = _min, mid, max = _max, last_max_inv,last_val;
  int pcs;
  while (true) {
    mid = min + (max - min) / 2;
    pcs = 0;
    for (int i = 0; i < N; i++) {
      pcs += (int)(arr[i] / mid);
      if (pcs > K)
        break;
    }
    if (pcs > K) {
      min = mid;
    } else if (pcs == K) {
      break;
    } else {
      last_max_inv = max = mid;
    }
  }

  last_val = mid;
  while (last_max_inv - last_val < 0.01) {
    mid = min + (max - min) / 2;
    pcs = 0;
    for (int i = 0; i < N; i++) {
      pcs += (int)(arr[i] / mid);
      if (pcs > K)
        break;
    }
    if(pcs<K){
      last_max_inv = mid;
    }
  }
}

int main() {
  int N, K;
  while (true) {
    cin >> N >> K;
    double arr[N], max;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
      max += arr[i] / N;
    }
    binary_test(arr, N, K);
  }
}