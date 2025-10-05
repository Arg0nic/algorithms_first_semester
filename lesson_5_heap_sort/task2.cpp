#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void heap(vector<uint32_t>& a, int n, int i) {
    int big = i;
    int c1 = 3 * i + 1;
    int c2 = 3 * i + 2;
    int c3 = 3 * i + 3;

    if (c1 < n && a[c1] > a[big]) big = c1;
    if (c2 < n && a[c2] > a[big]) big = c2;
    if (c3 < n && a[c3] > a[big]) big = c3;

    if (big != i) {
        swap(a[i], a[big]);
        heap(a, n, big);
    }
}

void heapSort(vector<uint32_t>& a) {
    int n = a.size();

    // строим тернарную кучу
    for (int i = n / 3 - 1; i >= 0; i--)
        heap(a, n, i);

    // извлекаем элементы по одному
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heap(a, i, 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> Ns = {1000, 10000, 100000, 1000000};

    mt19937 rng(random_device{}());
    uniform_int_distribution<uint32_t> dist(0, UINT32_MAX);

    for (int N : Ns) {
        cout << "N = " << N << '\n';
        vector<uint32_t> a(N);
        for (auto& x : a) x = dist(rng);
        vector<uint32_t> b = a;

        auto start = chrono::high_resolution_clock::now();
        heapSort(a);
        auto end = chrono::high_resolution_clock::now();
        cout << "Ternary heap sort time: " 
             << chrono::duration<double>(end - start).count() << " s\n";

        start = chrono::high_resolution_clock::now();
        sort(b.begin(), b.end());
        end = chrono::high_resolution_clock::now();
        cout << "std::sort time: " 
             << chrono::duration<double>(end - start).count() << " s\n";

        if (a == b)
            cout << "Correct\n\n";
        else
            cout << "Error\n\n";
    }
}
