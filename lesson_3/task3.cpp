#include <iostream>
#include <vector>
using namespace std;


void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void findPairs(vector<int>& a, unsigned int S) {
    int n = a.size();
    mergeSort(a, 0, n - 1);

    int l = 0, r = n - 1;

    while (l < r) {
        long long sum = (long long)a[l] + (long long)a[r];
        if (sum == S) {
            cout << "Pair: (" << a[l] << ", " << a[r] << ")\n";
            l++;
            r--;
        } else if (sum < S) {
            l++;
        } else {
            r--;
        }
    }

}

int main() {
    vector<int> A = {10, 3, 7, 1, 9, 12, 5};
    unsigned int S = 13;

    findPairs(A, S);

    return 0;
}
