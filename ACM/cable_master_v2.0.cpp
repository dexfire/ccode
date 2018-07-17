#include <iostream>

using namespace std;

void buble_sort(double arr[], int N) {
  for (int i = 0; i < N;) {
    for (int j = i; j < N; j++) {
    }
  }
}

void binary_test(double arr[], double _min, double _max, int N, int K) {
  // 注意：分的份数和 每份长度成反比
  //  littile_inv 记录比较小的不符合要求长度【对应比较大的份数】
  //  last_val 记录上次的复合条件的长度
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