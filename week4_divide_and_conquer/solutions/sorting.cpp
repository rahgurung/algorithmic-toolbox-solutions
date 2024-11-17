#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int pivot = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= pivot) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void three_way_partition(vector<int> &a, int l, int r, int &lt, int &gt) {
  // Choose the first element as pivot
  int pivot = a[l];

  // lt is the boundary of the less-than part
  lt = l;

  // gt is the boundary of the greater-than part
  gt = r;

  // i is the current element being processed
  int i = l;

  while (i <= gt) {
    if (a[i] < pivot) {
      swap(a[lt], a[i]);
      lt++;
      i++;
    } else if (a[i] > pivot) {
      swap(a[i], a[gt]);
      gt--;
    } else {
      i++;
    }
  }
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  // Generate a random number
  int k = l + rand() % (r - l + 1);

  // Randomize the pivot
  swap(a[l], a[k]);

  // lt and gt will represent the boundaries of the three partitions
  int lt, gt;
  three_way_partition(a, l, r, lt, gt);

  // int m = partition2(a, l, r);

  randomized_quick_sort(a, l, lt - 1);
  randomized_quick_sort(a, gt + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
