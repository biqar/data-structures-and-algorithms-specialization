#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

int main() {
    int n;
    int mx = -1;
    int mx2 = -1;
    std::cin >> n;
    std::vector<long long int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
        //if(numbers[i] >= mx) {
        //    mx2 = mx;
        //    mx = numbers[i];
        //}
    }

    sort(numbers.begin(), numbers.end());

    //std::cout << MaxPairwiseProduct(numbers); << "\n";
    std::cout << numbers[n-1]*numbers[n-2] << "\n";
    //std::cout << mx*mx2 << "\n";
    return 0;
}
