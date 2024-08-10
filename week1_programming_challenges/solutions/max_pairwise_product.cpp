#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long n = numbers.size();

    long long first_largest_index = -1;
    long long second_largest_index = -1;

    for (int i = 0; i < numbers.size(); i++) {
        if (first_largest_index == -1 || numbers[i] > numbers[first_largest_index]) {
            first_largest_index = i;
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        if ((second_largest_index == -1 || numbers[i] > numbers[second_largest_index]) && first_largest_index != i) {
            second_largest_index = i;
        }
    }

    return static_cast <long long>(numbers[first_largest_index]) * static_cast <long long>(numbers[second_largest_index]);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
