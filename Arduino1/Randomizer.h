#pragma once

constexpr unsigned int a = 1664525;
constexpr unsigned int c = 1013904223;
constexpr unsigned int m = 4294967296; // 2^32


unsigned int customRand(unsigned int& seed) {
    seed = (a * seed + c) % m;
    return seed;
}

int getRandomIndex(int max) {

  unsigned int seed = 42;
  int randomValue = customRand(seed) % max; // Use % 5 for random value [0, 4] (inclusive)
  return randomValue;
}