#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print (vector < double > vector_)
{
  for (int i = 0; i < (int)(vector_.size()); i++)
    cout << vector_[i] << " ";
  cout << endl;
}

int main ()
{
  vector < double > v1; // Empty vector of doubles.
  v1.push_back (32.1);
  v1.push_back (40.5);
  vector< double > v2; // Another empty vector of doubles.
  v2.push_back (3.56);
  cout << "v1 = ";
  print (v1);
  cout << "v2 = ";
  print (v2);
  v1.swap (v2); // Swap the vector's contents.
  cout << "v1 = ";
  print (v1);
  cout << "v2 = ";
  print (v2);
  v2 = v1; // Assign one vector to another.
  cout << "v2 = ";
  print (v2);
  
  //-------------------------------------------------
  
    vector<int> v;  // create an empty vector of integers
  int input;
  while (cin >> input)    // while not end of file
    v.push_back (input);  // append to vector
 
  // sort takes two random iterators, and sorts the elements between
  // them.  As is always the case in STL, this includes the value
  // referred to by first but not the one referred to by last; indeed,
  // this is often the past-the-end value, and is therefore not
  // dereferenceable.
  sort(v.begin(), v.end());
 
  int n = v.size();
  for (int i = 0; i < n; i++)
    cout << v[i] << "\n";  
	
  random_shuffle (v.begin(), v.end());    
  for (int i = 0; i < n; i++)
    cout << v[i] << "\n";  
		 
  return 0;
}