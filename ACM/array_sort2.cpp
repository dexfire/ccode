//#include<stdio.h>
#include <iostream>
#include <time.h>
using namespace std;
int abs(int x)
{
 return x>0?x:(-x);
}
void swap(int *n,int *m);
void quicksort(int a[],int left,int right);
// int main()
// {  
//    int a[100];
//    int n,i;
//    while(scanf("%d",&n)!=0)
//    { 
//    	for(i=0;i<n;i++)
//    	scanf("%d",&a[i]);
// 	quicksort(a,0,n-1);
// 	for(i=0;i<n;i++)
// 	printf("%d ",a[i]); 
//    }
//    return 0;
//  }
 void quicksort(int a[],int left,int right)
 {
 	int i,j,t;
 	if(left<right)
 	{
 		t=abs(a[left]);
 		i=left;
 		j=right+1;
 		while(1)
 		{
 			while(i+1<(right+1)&&abs(a[++i])>t);
 			while(j-1>-1&&abs(a[--j])<t);
 			if(i>=j)
 			break;
 			swap(&a[i],&a[j]);
		 }
		 a[left]=a[j];
		 a[j]=t;
		 quicksort(a,left,j-1);
		 quicksort(a,j+1,right);
	 }
 	
  } 
  void swap(int *n,int *m)
  {
  	int s=*n;
  	*n=*m;
  	*m=s;
  }

  int main(){
	srand(time(NULL));
	int arr[100];
	for (int i = 0; i < 100;i++){
		cout<<(arr[i] = rand())<<"\t";
	}
	cout << endl;
	quicksort(arr, 0, 99);
	for (int i = 0; i < 100;i++){
		cout<<arr[i]<<"\t";
	}
	system("pause");
  }
