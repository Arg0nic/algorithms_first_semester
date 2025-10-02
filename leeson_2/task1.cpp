#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <set>

using namespace std;

vector<int> generate_smooth3(int n) {
    vector<int> res;
    for (long long p = 1; p <= n; p *= 2) {
        for (long long q = p; q <= n; q *= 3) {
            res.push_back((int)q);
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}


void shell_sort(vector<int>& a) {
    int n = (int)a.size();
    vector<int> gaps = generate_smooth3(n);

    for (int g = (int)gaps.size() - 1; g >= 0; --g) {
        int h = gaps[g];
        if (h <= 0) continue;
        for (int i = h; i < n; ++i) {
            int temp = a[i];
            int j = i;
            while (j >= h && a[j - h] > temp) {
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = temp;
        }
    }
}


bool is_sorted_vec(const vector<int>& v) {
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < v[i-1]) return false;
    }
    return true;
}


int main() {
    mt19937 rng(12345);
    uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    vector<int> sizes = {1000, 10000, 100000, 1000000};

    for (int n : sizes) {
        cout << "N = " << n << endl;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = dist(rng);

        // shell sort
        auto a1 = arr;
        auto start = chrono::high_resolution_clock::now();
        shell_sort(a1);
        auto end = chrono::high_resolution_clock::now();
        double t1 = chrono::duration<double>(end - start).count();

        cout << "  shell_sort: " << t1 << "s, ok=" << is_sorted_vec(a1) << endl;

        // std::sort
        auto a2 = arr;
        start = chrono::high_resolution_clock::now();
        sort(a2.begin(), a2.end());
        end = chrono::high_resolution_clock::now();
        double t2 = chrono::duration<double>(end - start).count();

        cout << "  std::sort  : " << t2 << "s, ok=" << is_sorted_vec(a2) << endl;
    }
}