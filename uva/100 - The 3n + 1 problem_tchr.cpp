#include<iostream>
#include <stdio.h>

using namespace std;

int main()
{
long max,a,b,temp,a1,b1,counter,n;

while(cin>>a>>b){

max=1;

a1=a;b1=b;
if(a>b) {temp=a;a=b;b=temp;}; 

for(long i=a;i<=b;++i){
	
	counter=1;n=i;
	while(n!=1)
	{
	counter++;
	if(n%2==1) {n=3*n+1;}
	else {n=n/2;} 
	}
	
	if(counter>max) max=counter;
	};

	cout<<a1<<" "<<b1<<" "<<max<<"\n";
}
return 0;
}