#include <iostream>
#include <vector>
using namespace std;

long long mergeCnt(vector<int>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = a[left + i];
    for (int j = 0; j < n2; ++j) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long cnt = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
            cnt += (n1 - i);
        }
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    return cnt;
}

long long countInvRec(vector<int>& a, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long c1 = countInvRec(a, left, mid);
    long long c2 = countInvRec(a, mid + 1, right);
    long long c3 = mergeCnt(a, left, mid, right);
    return c1 + c2 + c3;
}

int main() {
    vector<int> nums = {2, 3, 8, 6, 1};
    long long ans = countInvRec(nums, 0, (int)nums.size() - 1);
    cout << ans << '\n';
    return 0;
}
