#include<iostream>
#include<cmath>

using namespace std;

int gcd(int a, int b)
{
        if(b == 0)
        {
                return a;
        }
        else
        {
                return gcd(b, a % b);
        }
};

int main()
{
long N,i,a,b,c,k,l,m,counter,sum;
bool *n;
while(cin>>N)
{
n=new bool[N+1];for(i=0;i<N+1;i++) n[i]=0;
counter=0;

for(k=1;k<=(int)(sqrt(N));k++)
	{
	for(l=k+1;l<=(int)(sqrt(N));l++)
	{	
		a=l*l-k*k;b=2*k*l;c=k*k+l*l;
		if(c<=N && gcd(a,b)==1) counter++;
		for(m=1;c*m<=N;m++)
		{
		 n[m*a]=1;n[m*b]=1;n[m*c]=1;	
		}
	}
	}
	
cout<<counter;
sum=0;
for(i=0;i<N+1;i++) sum+=n[i];
cout<<" "<<N-sum<<endl;
delete [] n;
}

return 0;
}