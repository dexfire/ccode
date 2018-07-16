#include <iostream>
#include <iomanip>
using namespace std;

void swap(double *a,double *b){
	double t = *a;
	*a = *b;
	*b = t;
}

void sort(double arr[],int N){
	for (int i = 0; i < N;i++){
		for (int j = i; j < N;j++){
			if(arr[i]<arr[j])
				swap(&arr[i],&arr[j]);
		}
	}
}

double scan(double arr[],double _min,double _max,int N,int K){
	sort(arr,N);
	double min = _min ,max = _max,mid;
	int pcs = 0;
	while(pcs!=K){
		mid = min + (max - min) / 2;
		//Debug cout << mid <<"\t" <<pcs<<endl;
		pcs = 0;
		for (int i = 0; i < N;i++){
			pcs += (int)(arr[i] /mid);
		}
		if( pcs <K){
			max = mid;
		}else{
			min = mid;
		}
	}

	// 				length:  min---------mid----------max
	// 				pieces:  MAX---------pcs----------MIN
	//K-target pieces:  xxxxxxxoooxxxxxxxxxxxxxxxx(符合条件的长度为一个区间)
	// 下面开始找到这个区间中最大的长度值
	// 错误答案：超时
	while(pcs==K){
		// mid 每次增长1cm
		mid += 1e-2;
		pcs = 0;
		for (int i = 0; i < N;i++){
			pcs += (int)(arr[i] /mid);
		}
	}
	double last_mid=mid;
	while(mid>last_mid){
		// mid 每次增长1cm
		pcs = 0;
		for (int i = 0; i < N;i++){
			pcs += (int)(arr[i] /mid);
		}
		if(pcs==K)
			last_mid = mid;
			
	}

	// 最终结果的处理：保留2位
	// 感觉mid应该减 个0.01 但是减了就不对了
	mid = ((int) ((mid)  * 100)) / 100.0;	
	return mid;
}

int main(){
	int N,K;
	cin >> N >> K;
	double arr[N];
	double sum = 0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		sum+=arr[i];
	}

	//Debug
	// int N = 4;
	// int K= 11;
	// double arr[] = {8.02, 7.43, 4.57, 5.39};
	// double sum = 0;
	// for (int i = 0; i < N;i++)
	// 	sum += arr[i];
	cout << setiosflags(ios::fixed) <<setprecision(2)<< scan(arr, 0, sum / N, N, K) << endl;
	//system("pause");
}
