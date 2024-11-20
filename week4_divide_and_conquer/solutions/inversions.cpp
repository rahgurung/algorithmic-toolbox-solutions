#include <iostream>
#include <vector>

using std::vector;

long long merge_and_count(vector<int> &a, vector<int> &b, size_t left, size_t mid, size_t right) {
    size_t i = left, j = mid, k = left;
    long long inv_count = 0;

    // Merge two sorted halves
    while (i < mid && j < right) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            // Count inversions
            inv_count += mid - i; // All remaining elements in the left half form inversions
        }
    }

    // Copy remaining elements from the left half (if any)
    while (i < mid) {
        b[k++] = a[i++];
    }

    // Copy remaining elements from the right half (if any)
    while (j < right) {
        b[k++] = a[j++];
    }

    // Copy back the merged elements into original array
    for (i = left; i < right; i++) {
        a[i] = b[i];
    }

    return inv_count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  number_of_inversions += merge_and_count(a, b, left, ave, right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
