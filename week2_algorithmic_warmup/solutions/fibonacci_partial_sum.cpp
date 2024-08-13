#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    if (from == 0) {
        return fibonacci_sum_fast(to);
    }

    long long toSum = fibonacci_sum_fast(to);
    long long fromSum = fibonacci_sum_fast(from-1);
    long long difference = toSum - fromSum;
    if(difference > 0) {
        return difference;
    }
    return difference + 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
