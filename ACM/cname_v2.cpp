#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

bool is_identify(string nm){
	if(isalpha(nm.at(0))) return false;
}

int main(int argc,char *argv[]){
	int n;
	char nm[50];
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin.getline(nm,50);
			cout<<"hello"<<endl;
			cout<<is_identify(nm)?"yes":"no"<<endl;
		}
	}
}
