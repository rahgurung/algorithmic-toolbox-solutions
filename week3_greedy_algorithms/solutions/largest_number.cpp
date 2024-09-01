#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool isGreaterNumber(string a, string b) {
  return a + b > b + a;
}

string largest_number(vector<string> a) {
  std::stringstream ret;
  int arraySize = a.size();
  for (size_t i = 0; i < arraySize; i++) {
    // Get the digit to be removed by looping over
    int indexOfDigitOfGreaterNumber = 0;
    for(size_t j = 1; j < a.size(); j++) {
      if(isGreaterNumber(a[indexOfDigitOfGreaterNumber], a[j])) {
        continue;
      } else {
        indexOfDigitOfGreaterNumber = j;
      }
    }

    // Add that digit to string stream
    ret << a[indexOfDigitOfGreaterNumber];

    // Remove that digit from array
    a.erase(a.begin() + indexOfDigitOfGreaterNumber);
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a) << "\n";
}
