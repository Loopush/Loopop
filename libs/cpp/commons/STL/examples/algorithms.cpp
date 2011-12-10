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

long x=(long)(N/2);

vector <long> v;

for(long i=0;i<N;++i) v.push_back(i+1);

vector<long>::iterator i;

tic();
i=find(v.begin(),v.end(),x);
toc("ITERATOR FIND");

vector<long>::reverse_iterator j;
tic();
j=find(v.rbegin(),v.rend(),x);
toc("REVERSE_ITERATOR FIND");

cout<<"\n"<<*i<<"  "<<*j; // with -O3 it is somehow necesary

cin.get();
}