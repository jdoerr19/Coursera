
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

//SLOWEST and non passing template solution
int MaxPairwiseProduct_0(const vector<int>& numbers)
{
  int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

//fixed the max size issue by changing int to long
unsigned long MaxPairwiseProduct_1(const vector<int>& numbers)
{
    unsigned long result = 0;
    unsigned long n = numbers.size();
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (numbers[i] * numbers[j] > result)
            {
                result = (unsigned long) numbers[i] * numbers[j];
            }
        }
    }
    return result;
}

//Speed Up algorithm so it doesn't take n^2 steps
//go through numbers one time to find max and min values
unsigned long MaxPairwiseProduct_2(const vector<int>& numbers)
{
    unsigned long result = 0;
    unsigned long n = numbers.size();
    
    int largestNumIndex = 0;
    for (int j = 0; j < n; ++j)
    {
        if (numbers[j] > numbers[largestNumIndex])
        {
            largestNumIndex = j;
        }
    }
    int secondLargestNumIndex;
    if (largestNumIndex == 0)
        secondLargestNumIndex = 1;
    else
        secondLargestNumIndex = 0;
        
    for (int i = 0; i < n; ++i)
    {
        if (numbers[i] > numbers[secondLargestNumIndex] && i != largestNumIndex)
        {
            secondLargestNumIndex = i;
        }
    }
    result = (unsigned long) numbers[largestNumIndex] * numbers[secondLargestNumIndex];
    
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    unsigned long test = 9000000000;
    unsigned long result = MaxPairwiseProduct_2(numbers);
    cout << result << "\n";
    return 0;
}
