#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if(n < 3) {
    summands.push_back(n);
    return summands;
  }

  int possibleInteger = 2;
  summands.push_back(1);
  n -= 1;

  while(true) {
    int possibleDeduction = n - possibleInteger;
    if(possibleDeduction > summands[summands.size() - 1] && possibleDeduction > possibleInteger) {
      summands.push_back(possibleInteger);
      n -= possibleInteger;
      possibleInteger++;
    } else {
      summands.push_back(n);
      break;
    }
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  std::cout << '\n';
}
