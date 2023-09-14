// Rose Tran - CS 310
// This program counts the steps to find out the search values

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;

vector<int> simulDoubleLinearSearch(const vector<int> &array, int searchValue)
{
  int step = 0; // to count the steps it takes to search for the searchValue

  int index = 0;
  int count = 0;
  vector<int> searchResult; // an int vector for storing the founded indexs

  while (index < array.size()) 
  {
    step++; // update the step everytime it goes through an available position in the array
    if (array[index] == searchValue)
    {
      searchResult.push_back(index);
      count++; 
      if (count == 2) // if founded two first values, return the indexs and stop the programm
      {
        //store steps in searchResults to retrieve later to calculate average
        searchResult.push_back(step);

        return searchResult;
      }
    } 
    index++;
  }
  searchResult.clear(); // remove every values in the vector for the case not found two first matched values
  searchResult.push_back(-1); // not found two first matched values

  //store steps in searchResults to retrieve later to calculate average
  searchResult.push_back(step);

  return searchResult;
}

int main()
{
  srand(time(0));
  const double SIMULATION = 1000; //the number of iterations
  const int N = 100000; //input size
  const int upper = 15000;
  const int lower = 0;

  double total = 0; // sum of all the steps through 1000 iterations
  int hits, miss = 0; // the number of time found out the first two matched index
                      // and the number of time not found out the first two matched index
  vector<int> array; 

  for (int i = 0; i < SIMULATION; i++)
  {
    //add N random values to the vector
    for (int j = 0; j < N; j++)
    {
      array.push_back((rand() % (upper - lower + 1)) + lower);
    }
  
    // generate a random search value from 0 to 15000
    int searchValue = (rand() % (upper - lower + 1)) + lower;
  
    vector<int> searchResult = simulDoubleLinearSearch(array, searchValue);
    
    if (searchResult.size() == 3) // 3 includes 2 searched values and one step
    {
      hits++; 
      total += searchResult[searchResult.size()-1];
    } 
    else //not found
    {
      miss++;
      total += searchResult[searchResult.size()-1];
    }

    array.clear();
  }

  cout << "Average steps: " << setprecision(10) << total/SIMULATION << endl;
  cout << "Hits: " << hits << endl;
  cout << "Miss: " << miss << endl;
  
  return 0;
}
