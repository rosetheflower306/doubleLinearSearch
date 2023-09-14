// Rose Tran - CS 310
// This program implements linearSearch that will return a vector that
// contains two searched values' indexs. If not found then 
// return -1 

#include <iostream>
#include <vector>
using namespace std;

vector<int> linearSearch(const vector<int> &array, int searchValue)
{
  int index = 0;
  int count = 0;
  vector<int> searchResult; // an int vector for storing the founded indexs
  while (index < array.size()) 
  {
    if (array[index] == searchValue)
    {
      searchResult.push_back(index); 
      count++; 
      if (count == 2) // if founded two first values, return the indexs and stop the programm
      {
        return searchResult;
      }
    }
    index++;
  }
  searchResult.clear(); // remove every values in the vector for the case not found two first matched values
  searchResult.push_back(-1); // not found two first matched values
  return searchResult;
}

int main()
{
  vector<int> array {10, 50, 16, 1, 9, 15, 16, 20, 16, 2, 5};
  int searchValue = 15;
  vector<int> searchResult = linearSearch(array, searchValue);

  // output the found or not found indexs
  for (int x : searchResult)
  {
    cout << x << endl;
  }
  
  return 0;
}