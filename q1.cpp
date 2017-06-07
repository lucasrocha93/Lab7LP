#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;


template <typename InputIterator>
InputIterator closest2mean(InputIterator first, InputIterator last) {
  int mean = 0;
  int n = 0;
  InputIterator current = first;
  while (current != last) {
    mean += *current;
    n++;
    current++;
  }
  mean = mean / n;
  int closest_difference = abs(*first - mean);
  int current_difference;
  InputIterator result = first;
  current = first;
  while (current != last) {
    current_difference = abs(*current - mean);
    if (current_difference < closest_difference) {
      closest_difference = current_difference;
      result = current;
    }
    current++;
  }
  return result;
}


int main() {
  vector<int> v {1, 2, 3, 30, 40, 50};
  auto result = closest2mean(v.begin(), v.end());
  cout << (*result) << endl;
  return 0;
}
