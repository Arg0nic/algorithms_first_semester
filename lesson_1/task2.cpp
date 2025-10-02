#include <iostream>


int main(void) {

    int a1[] = {5, 2, 9, 1, 7, 3}; // массив ломающий сортировку
    int n1 = sizeof(a1) / sizeof(a1[0]);


    for( int i = 0; i < n1 - 1; ++ i ) {
        for( int j = i ; j < n1 - 1; ++ j ) {
            if ( a1[ j ] > a1 [ j + 1]) std::swap ( a1[ j ] , a1[ j + 1]);
        }
    }

    for(int i = 0; i < n1; i++) {
        std::cout << a1[i] << " ";
    }

    return 0;
}