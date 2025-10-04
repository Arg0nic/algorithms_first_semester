#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int getMax(const std::vector<int>& a) {
    int mx = a[0];
    for (int x : a)
        if (x > mx) mx = x;
    return mx;
}

void countingSort(std::vector<int>& a, int exp) {
    int n = a.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[--count[digit]] = a[i];
    }

    a = output;
}

void radixSort(std::vector<int>& a) {
    int maxNum = getMax(a);

    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSort(a, exp);
}

int main() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 100000);

    std::vector<int> a(10);
    for (int& x : a) x = dist(rng);

    std::cout << "Before: ";
    for (int x : a) std::cout << x << " ";
    std::cout << "\n";

    radixSort(a);

    std::cout << "After:  ";
    for (int x : a) std::cout << x << " ";
    std::cout << "\n";
}
