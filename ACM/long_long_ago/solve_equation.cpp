#include <iostream>
#include <math.h>
using namespace std;
double f(double x){
	return pow(x,3)-5*pow(x,2)+10*x-80;
}

double binary_search(double (*f)(double x),double st,double ed){
	double L = st;
	double R = ed;
	double mid;
	while(true){
		mid = L+(R-L)/2;
		if(fabs(f(mid))<1e-6) return mid;
		// 函数单增，中点值为正
		// ->  右边取中值 
		if( (*f)(mid) > 0){
			R = mid; 
		}else{
			L = mid;
		}
	}
	return 0;
}

int main(){
	double x = binary_search(f,0,100);
	cout<<x<<endl;
	cout<<(*f)(x)<<endl;
	system("pause");
}
