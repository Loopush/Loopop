//g++ -Wall I.cpp
#include <iostream>
#include <vector>
#include <stdio.h> // freopen , stdin , stdout

using namespace std;

void printvector(vector <int> v){
for(int j=0;j<(int)(v.size());j++) cout<<v[j]<<"\t";
cout<<"\n";
}

int main(){

	//freopen("FILE_NAME_FOR_INPUT","r",stdin);
	//freopen("FILE_NAME_FOR_OUTPUT","w",stdout);
	
	int n,k,index=0;

	vector <int> i;

	i.push_back(2);i.push_back(3);i.push_back(5);

	n=i.size();
	
	vector <int> c(n);
	
	printvector(c);

	while(index!=n){

		index=0;
		
		while(index<n){
		
		if(c[index]<i[index]) {c[index]++;for(k=0;k<index;k++) c[k]=0;break;}
		
		index++;
		}
		
	printvector(c);
	}

//fclose (stdout);
return 0;
}

