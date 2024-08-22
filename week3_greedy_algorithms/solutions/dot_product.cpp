#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

// Get index with largest value in an array
int getIndexOfLargestValue(vector<int> arr) {
  if(arr.size() == 1) {
    return 0;
  }
  double largestValue = arr[0];
  int largestIndex = 0;
  for(int i=1; i<arr.size(); i++) {
    if (arr[i] > largestValue) {
      largestValue = arr[i];
      largestIndex = i;
    }
  }
  return largestIndex;
}

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  int n = a.size();
  for (size_t i = 0; i < n; i++) {
    int largestIndexOfA = getIndexOfLargestValue(a);
    int largestIndexOfB = getIndexOfLargestValue(b);

    result += (long long) (a[largestIndexOfA]) * b[largestIndexOfB];
    a.erase(a.begin() + largestIndexOfA);
    b.erase(b.begin() + largestIndexOfB);
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
