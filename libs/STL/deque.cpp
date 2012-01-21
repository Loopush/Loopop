#include <iostream>
#include <deque>

using namespace std;

int main ()
{
  deque< int > d;
  d.push_back (4); // Add after end.
  d.push_back (9);
  d.push_back (16);
  d.push_front (1); // Insert at beginning.
  for (int i = 0; i < (int)(d.size()); i++)
    cout << "d[" << i << "] = " << d[i] << endl;
  cout << endl;
  d.pop_front (); // Erase first element.
  d[2] = 25; // Replace last element.
  for (int i = 0; i < (int)(d.size()); i++)
    cout << "d[" << i << "] = " << d[i] << endl;
  return 0;
}