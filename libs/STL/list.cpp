#include <iostream>
#include <list>

using namespace std;

int array1 [] = { 9, 16, 36 };
int array2 [] = { 1, 4 };

int main ()
{
  list< int > l1 (array1, array1 + 3);
  list< int > l2 (array2, array2 + 2);
  list< int >::iterator i1 = l1.begin ();
  l1.splice (i1, l2);
  list< int >::iterator i2 = l1.begin ();
  while (i2 != l1.end ())
    cout << *i2++ << endl;

  //---------------------------------------- 
   list<int> L;
   L.push_back(0);              // Insert a new element at the end
   L.push_front(0);             // Insert a new element at the beginning
   L.insert(++L.begin(),2);     // Insert "2" before position of first argument
                                // (Place before second argument)
   L.push_back(5);
   L.push_back(6);

   list<int>::iterator i;

   for(i=L.begin(); i != L.end(); ++i) cout << *i << " ";
   cout << endl;
   return 0;
}