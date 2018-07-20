#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void reorder(int *nums,int count){
	for(int i = 0;i<count;i++){
		for(int j=i;j<count;j++){
			if(abs(*(nums+i))<abs(*(nums+j))) swap(nums+i,nums+j);
            //cout<<*(nums+j)<<'\n';
		}
	}
	for(int i=0;i<count-1;i++) cout<<*(nums+i)<<" ";
	cout<<*(nums+count-1)<<endl;
}

int main(int argc, char const *argv[]){
	int a[100] = {0};
	int count = 0;
	memset((wchar_t *)a, 0, 100);
	while(1){
		cin>>count;
		if(count==0)break;
		for (int i = 0; i < count;i++){
			cin >> a[i];
		}
		reorder(a,count);
	}
}