#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void quickSort3(vector<int>& a, int left, int right, mt19937& rng) {
    if (left >= right) return;

    uniform_int_distribution<int> dist(left, right);
    int pivot = a[dist(rng)];

    int i = left, j = right;
    int k = left;
    while (k <= j) {
        if (a[k] < pivot) swap(a[i++], a[k++]);
        else if (a[k] > pivot) swap(a[k], a[j--]);
        else k++;
    }

    quickSort3(a, left, i - 1, rng);
    quickSort3(a, j + 1, right, rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 10000000;
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(0, 1000000);

    vector<int> a(N);
    for (int& x : a) x = dist(rng);
    vector<int> b = a;

    auto t1 = chrono::high_resolution_clock::now();
    quickSort3(a, 0, N - 1, rng);
    auto t2 = chrono::high_resolution_clock::now();
    cout << "3-way QuickSort: " << chrono::duration<double>(t2 - t1).count() << " s\n";

    t1 = chrono::high_resolution_clock::now();
    sort(b.begin(), b.end());
    t2 = chrono::high_resolution_clock::now();
    cout << "std::sort:       " << chrono::duration<double>(t2 - t1).count() << " s\n";

    cout << (a == b ? "Correct\n" : "Error\n");
}
