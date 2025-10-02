#include <iostream>

int main(void) {

    int a1[] = {5, 2, 9, 1, 7, 3};
    int a2[] = {4, 1, 8, 6};
    int a3[] = {10, 20, 30, 40, 50};
    int a4[] = {7, 7, 7, 7};

    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);
    int n3 = sizeof(a3) / sizeof(a3[0]);
    int n4 = sizeof(a4) / sizeof(a4[0]);


    for(int i = 1; i < n1; i++) {
        int j = i;
        while (j > 0 && (
        ((j+1) % 2 == 0 && a1[j] < a1[j-1]) ||
        ((j+1) % 2 != 0 && a1[j] > a1[j-1])
    )) {
    std::swap(a1[j-1], a1[j]);
    j--;
}

    }

    for(int i = 0; i < n1; i++) {
        std::cout << a1[i] << " ";
    }
    

    
    return 0;

}



