#include <iostream>

int get_change(int m) {
  int tenCoins = 0;
  int fiveCoins = 0;
  int oneCoins = 0;

  // Denominations of 10 is possible
  if(m >= 10) {
    tenCoins = m/10;
    m = m % 10;
  }

  // Denominations of 5 is possible
  if(m >= 5) {
    fiveCoins = m/5;
    m = m % 5;
  }

  // Denominations of 1 is possible
  if(m >= 1) {
    oneCoins = m/1;
    m = m % 1;
  }
  
  return tenCoins + fiveCoins + oneCoins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
