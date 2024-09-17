#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

int get_majority_element(vector<int> &arr) {
    std::unordered_map<int, int> count_map;
    int n = arr.size();

    // Step 1: Count occurrences of each element and check
    // if it is greater than n/2
    for (int i = 0; i < n; i++) {
        count_map[arr[i]]++;
        if (count_map[arr[i]] > n/2) {
          return 1;
        }
    }

    return 0; // No majority element
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a) << '\n';
}
