#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void heap(vector<uint32_t>& arr, int n, int i) {
    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[big])
        big = l;
    if (r < n && arr[r] > arr[big])
        big = r;
    if (big != i) {
        swap(arr[i], arr[big]);
        heap(arr, n, big);
    }
}

void mySort(vector<uint32_t>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sizes = {1000, 10000, 100000, 1000000};

    mt19937 gen(random_device{}());
    uniform_int_distribution<uint32_t> rnd(0, UINT32_MAX);

    for (int n : sizes) {
        cout << "N = " << n << '\n';
        vector<uint32_t> v1(n);
        for (auto& x : v1) x = rnd(gen);
        vector<uint32_t> v2 = v1;

        auto t1 = chrono::high_resolution_clock::now();
        mySort(v1);
        auto t2 = chrono::high_resolution_clock::now();
        cout << "heap sort: " << chrono::duration<double>(t2 - t1).count() << " s\n";

        t1 = chrono::high_resolution_clock::now();
        sort(v2.begin(), v2.end());
        t2 = chrono::high_resolution_clock::now();
        cout << "std sort:  " << chrono::duration<double>(t2 - t1).count() << " s\n";

        if (v1 == v2)
            cout << "ok\n\n";
        else
            cout << "bad\n\n";
    }
}
