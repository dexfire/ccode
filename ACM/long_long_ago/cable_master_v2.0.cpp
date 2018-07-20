#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;


int calc_pcs(double arr[], double len, int N, int K) {
  int pcs = 0;
  for (int i = 0; i < N; i++) {
    pcs += (int)(arr[i] / len);
    if (pcs > K)
      break;
  }
  return pcs;
}

// double binary_test1(double arr[], double _min, double _max, int N, int K) {
//   double min, max;
//   while()
// }

double binary_test(double arr[], double _min, double _max, int N, int K) {
  if (_min > _max)
    return 0;
  else if (_min == _max) {
    if (calc_pcs(arr, _min, N, K) >= K)
      return _min;
    else
      return 0;
  }
  sort(arr, arr + N);
  // 注意：分的份数和 每份长度成反比
  //  littile_inv 记录比较小的不符合要求长度【对应比较大的份数】
  //  last_val 记录上次的复合条件的长度
  double min = _min, mid, max = _max, last_max_inv = _max, last_val = 0;
  int pcs;
  while (true) {
    // cout << min << " , " << mid << " , " << max << "  " << pcs <<":"<<K<<
    // endl;
    mid = min + (max - min) / 2;
    pcs = calc_pcs(arr, mid, N, K);
    if (((max - min) < 0.001)) {
      if (pcs >= K)
        return mid;
      else
        return min;
    } else if (pcs == K) {
      min = last_val = mid;
      break;
    } else if (pcs > K) {
      min = mid;
    } else if (pcs < K) {
      last_max_inv = max = mid;
    }
  }

  while ((last_max_inv - last_val) > 0.001) {
    mid = min + (max - min) / 2;
    pcs = calc_pcs(arr, mid, N, K);
    // cout << mid << mid;
    if (pcs < K) {
      last_max_inv=max = mid;
    } else { // 只能是 pcs == K
      last_val = min = mid;
    }
    //cout << last_val << endl;
  }
  return last_val;
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
      max += arr[i] / K;
    }
    cout << binary_test(arr, 0.01, max, N, K)<<endl;
  }
  return 0;
}

// void swap(double *a, double *b) {
//   double t = *a;
//   *a = *b;
//   *b = t;
// }

// void buble_sort(double arr[], int N) {
//   for (int i = 0; i < N; i++) {
//     for (int j = i; j < N; j++) {
//       if (arr[i] > arr[j])
//         swap(arr + i, arr + j);
//     }
//   }
// }

// int main() {
//   // Debug
//   int N = 4;
//   int K = 11;
//   double arr[] = {8.02, 7.43, 4.57, 5.39};
//   double max = 0;
//   for (int i = 0; i < N; i++)
//     max += arr[i];
//   max /= K;
//   cout << setiosflags(ios::fixed) << setprecision(2)
//        << binary_test(arr, 0.01, max, N, K) << endl;
//   system("pause");
// }