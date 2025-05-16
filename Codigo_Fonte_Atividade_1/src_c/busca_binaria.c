#include "busca_binaria.h"
#include <stdio.h> 


int busca_binaria(int n) {
    if (n <= 0) {
        return 0;
    }

    int left = 1;
    int right = n;
    int first_bad = n + 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            first_bad = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return first_bad;
}