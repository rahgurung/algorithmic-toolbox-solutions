#include <iostream>
int gcd_fast(int a, int b) {
  int current_gcd = 1;
  while(true) {
    int remainder = a%b;
    if(remainder == 0) {
      current_gcd = b;
      break;
    } else {
      a = b;
      b = remainder;
    }
  }
  return current_gcd;
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
  long long gcd = gcd_fast(a, b);
  return static_cast <long long>(a) * static_cast <long long>(b)/gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
