#include <iostream>
#include <vector>
#include <random>

using namespace std;


int main(void) {

    int N, K, Q;
    cin >> N >> K >> Q;

    mt19937 rng(random_device{}()); // генератор случайных чисел
    uniform_int_distribution<int> dist(0, K - 1); // диапазон [0, K-1]

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = dist(rng);
    }

    vector<int> C(K, 0);
    for(int x: A) C[x]++;

    vector<int> P(K+1, 0);
    for (int i = 0; i < K; i++) P[i+1] = P[i] + C[i];


    while (Q--) {
        int l, r;
        cin >> l >> r;
        if (l < 0) l = 0;
        if (r >= K) r = K - 1;
        cout << P[r + 1] - P[l] << "\n";
    }


    return 0;
}

