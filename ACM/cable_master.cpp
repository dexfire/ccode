#include <iostream>
#include <iomanip>
#include <math.h>
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
		//Debug 		cout << mid <<"\t" <<pcs<<endl;
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
	// 二分查找法的 临界条件值查找模型
	double val=mid, inv=max;
	while(fabs(inv-val)>=0.01){
		mid = min + (max - min) / 2;
		
		pcs = 0;
		for (int i = 0; i < N; i++)
		{
			pcs += (int)(arr[i] / mid);
		}

		if(pcs==K){
			min = val = mid;
		}else{
			max = inv = mid;
		}
		// Debug		
		// cout << val << "\t" << inv << endl;
	}

	// 最终结果的处理：保留2位
	// 感觉mid应该减 个0.01 但是减了就不对了
	val = ((int) ((val)  * 100)) / 100.0;	
	return val;
}

int main(){
	while(true){
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
		double res = (scan(arr, 0, sum / N, N, K) > 0);
		cout << setiosflags(ios::fixed) <<setprecision(2)<< (res>0.01?res:0) << endl;

	}
	// Debug 
	// system("pause");
}
