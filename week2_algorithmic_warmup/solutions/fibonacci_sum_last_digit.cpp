#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_fibonacci_huge_fast(long long n,  long long m) {
    if (n <= 1)
        return n;

    // Find the period length
    std::vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    int i = 2;
    while(true) {
        arr.push_back((arr[i-1] + arr[i-2]) % m);

        if(arr[i-1] == 0 && arr[i] == 1) {
            arr.pop_back();
            arr.pop_back();
            break;
        }
        i++;
    }

    long long remainder = n % arr.size();

    return arr[remainder];
}


int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    long long fib = get_fibonacci_huge_fast(n+2, 10);
    long long sum = (fib - 1) % 10;

    return (sum+ 10) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    std::cout << '\n';
}
