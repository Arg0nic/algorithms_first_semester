#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

int getMax(const vector<int>& a) {
    int mx = a[0];
    for (int x : a)
        if (x > mx) mx = x;
    return mx;
}

void countingSort(vector<int>& a, int exp) {
    int n = a.size();
    vector<int> output(n);
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

void radixSort(vector<int>& a) {
    int maxNum = getMax(a);
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSort(a, exp);
}

// Обёртка для сортировки с отрицательными
void radixSortWithNegatives(vector<int>& a) {
    int minA = *min_element(a.begin(), a.end());
    if (minA < 0) {
        for (int& x : a)
            x -= minA; // сдвигаем всё в положительный диапазон
    }

    radixSort(a);

    if (minA < 0) {
        for (int& x : a)
            x += minA; // возвращаем значения обратно
    }
}

int main() {
    const int N = 10000000;
    vector<int> a(N);

    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(-100000, 100000);

    for (int& x : a) x = dist(rng);

    vector<int> b = a;

    auto start = chrono::high_resolution_clock::now();
    radixSortWithNegatives(a);
    auto end = chrono::high_resolution_clock::now();
    cout << "Radix sort time: "
         << chrono::duration<double>(end - start).count() << " s\n";

    start = chrono::high_resolution_clock::now();
    sort(b.begin(), b.end());
    end = chrono::high_resolution_clock::now();
    cout << "std::sort time:  "
         << chrono::duration<double>(end - start).count() << " s\n";


}
