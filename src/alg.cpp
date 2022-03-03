// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double tmp = 1;
  for (uint16_t i = 1; i < n; i++) {
    tmp *= value;
  }
  return tmp;
}

uint64_t fact(uint16_t n) {
  if (n < 0)
    return 0;
  if (n == 0)
    return 1;
  else
    return n * fact (n - 1);
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double e = 1;
  for (int i = 1; i <= count; i++) {
      e += calcItem(x, i);
    }
  return  e;
}

double sinn(double x, uint16_t count) {
  double e = 0;
  for (uint16_t i = 1; i <= count; i++) {
    e += pown(-1, i - 1) * pown(x, 2 * i - 1) / fact(2 * i - 1);
  }
  return  e;
}

double cosn(double x, uint16_t count) {
  double e = 1;
  for (uint16_t i = 1; i <= count; i++) {
     e += pown(-1, i - 1) * pown(x, 2 * i - 2) / fact(2 * i - 2);
    }
  return  e;
}
