#include <iostream>
#include <vector>
using namespace std;


void insertionSort(vector<int>& arr, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= l && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void modifiedMergeSort(vector<int>& arr, int l, int r, int m) {
    if (r - l + 1 <= m) {
        insertionSort(arr, l, r);
        return;
    }

    int mid = l + (r - l) / 2;
    modifiedMergeSort(arr, l, mid, m);
    modifiedMergeSort(arr, mid + 1, r, m);
    merge(arr, l, mid, r);
}

int main() {
    vector<int> a = {38, 27, 43, 3, 9, 82, 10};

    int m = 32;

    modifiedMergeSort(a, 0, a.size() - 1, m);

    cout << "Sorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}


/*
Ответы на вопросы из задачи:

1) Сортировка вставкой сортирует n/m последовательностей длины m за время Θ(nm).
   (т.к. каждая вставка O(m^2), всего n/m блоков => (n/m)*m^2 = nm)

2) Слияние n/m отсортированных блоков занимает Θ(n log(n/m)).

3) Итоговая сложность алгоритма:
   T(n) = Θ(nm + n log(n/m)).

4) Чтобы алгоритм работал так же быстро, как обычный Merge Sort (Θ(n log n)),
   нужно, чтобы m = O(log n).

5) На практике обычно выбирают m в пределах 16…64 (например, m = 32),
   потому что вставки на малых массивах работают быстрее из-за простоты и кеш-локальности.

6) Для массивов размера 10^3 … 10^7:
   log2(10^3) ≈ 10, log2(10^7) ≈ 23,
   значит теоретически оптимум m ≈ 10…25,
   но на практике лучше выбрать m ≈ 16 или m ≈ 32.
*/