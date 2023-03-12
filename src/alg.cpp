// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    uint16_t k = 0;
    for (uint16_t i = 0; i <= count; i++) {
        k += calcItem(x, i);
    }
    return k;
}

double sinn(double x, uint16_t count) {
    uint16_t k = 0;
    for (uint16_t i = 1; i <= count; i++) {
        k += pown(-1, i - 1) * calcItem(x, (2 * k - 1));
    }
    return k;
}

double cosn(double x, uint16_t count) {
    uint64_t k = 1;
    for (uint64_t i = 2; i <= count; i++) {
        k += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
    }
    return k;
}
