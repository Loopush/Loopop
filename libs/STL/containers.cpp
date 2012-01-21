//g++ -Wall -O3
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const long N=100000000;

static clock_t start_t,end_t;

void tic()
{
start_t=clock();
};
void toc(string m="")
{
end_t=clock();
cout<<"\nDone "<<m<<" in "<<(float)(1.0*(end_t-start_t)/(1.0*CLOCKS_PER_SEC))<<" seconds.\n";
};

void f(long& i)	//call by reference
{
i=i*i;
};

int main()
{

long *a=NULL;
vector <long> v;

tic();
a=new long[N];
for(long i=0;i<N;++i) a[i]=i;
toc("FILL AN ARRAY");

tic();
for(long i=0;i<N;++i) v.push_back(i);
toc("FILL A VECTOR");

tic();
for(long i=0;i<N;++i) f(v[i]);
toc("MODIFY ALL ELEMENTS []");

vector <long>::iterator iv=v.begin();
tic();
for(iv=v.begin();iv!=v.end();++iv) f(*iv);
toc("MODIFY ALL ELEMENTS THROUGH ITERATOR");

tic();
for_each(v.begin(),v.end(),f);
toc("MODIFY ALL ELEMENTS WITH for_each ALGORITHM");

cin.get();
}