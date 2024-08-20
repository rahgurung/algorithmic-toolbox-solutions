#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

// Get index with largest value per weight in an array
int getIndexOfLargestValuePerWeight(vector<int> weights, vector<int> values) {
  double largestValue = -1;
  int largestIndex = 0;
  for(int i=0; i<weights.size(); i++) {
    double valuePerWeight = (double) values[i]/weights[i];
    if (valuePerWeight > largestValue) {
      largestValue = valuePerWeight;
      largestIndex = i;
    }
  }
  return largestIndex;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  while(capacity > 0 && !weights.empty()) {
    // Find index with max value per weight
    int i = getIndexOfLargestValuePerWeight(weights, values);

    if(capacity < weights[i]) {
      double valuePerWeight = (double) values[i]/weights[i];
      value += (valuePerWeight * capacity);
      break;
    } else {
      value += values[i];
      capacity -= weights[i];
    }

    // Remove used item
    weights.erase(weights.begin() + i);
    values.erase(values.begin() + i);
  }
  
  // Round the value to 4 decimal places
  value = std::round(value * 10000) / 10000;

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
