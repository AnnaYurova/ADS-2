// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  int tmp = value;
  if (n == 0) {
    return 0;
  }
  for (int i = 1; i < n; i++) {
    value *= tmp;
  }
  return value;
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
  double e = 0;
  uint64_t i = 0;
    while (i <= count) {
      e += calcItem(x, i);
      i += 1;
    }
  return  e;
}

double sinn(double x, uint16_t count) {
  double e = 0;
  for (uint16_t i = 1; i <= count; i++) {
    e += pown(-1, i-1) * calcItem(x, (2 * i) - 1);
  }
  return  e;
}

double cosn(double x, uint16_t count) {
  double e = 0;
  uint64_t i = 1;
    while (i <= count) {
      e += pown(-1, i - 1) * calcItem(x, (2 * i) - 2);
      i += 1;
    }
  return  e;
}
