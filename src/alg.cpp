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
  return (pown(x,n) / fact(n));
}

double expn(double x, uint16_t count) {
  double e = 0;
  uint64_t check = 0;
    while (check <= count) {
      e += calcItem (x,check);
      check += 1;
    }
  return  e;
}

double sinn(double x, uint16_t count) {
  double e = 0;
  for (uint16_t check = 1; check <= count; check++) {
    e += pown (-1, check-1) * calcItem (x, (2 * check) - 1);
  }
  return  e;
}

double cosn(double x, uint16_t count) {
  double e = 0;
  uint64_t check = 1;
    while (check <= count) {
      e += pown (-1, check - 1) * calcItem (x, (2 * check) - 2) ;
      check += 1;
    }
  return  e;
}
