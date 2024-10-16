# Bit Manipulation Essentials for Competitive Programming

Bit manipulation is a powerful tool often used in competitive programming to optimize code and solve problems efficiently. This repository provides essential bit manipulation techniques and functions that are frequently used in competitive programming.

## Table of Contents

- [Basics](#basics)
  - [Checking if a number is odd or even](#checking-if-a-number-is-odd-or-even)
  - [Swapping two numbers without a temporary variable](#swapping-two-numbers-without-a-temporary-variable)
  - [Multiplying and dividing by powers of 2](#multiplying-and-dividing-by-powers-of-2)
- [Common Operations](#common-operations)
  - [Set a bit](#set-a-bit)
  - [Clear a bit](#clear-a-bit)
  - [Toggle a bit](#toggle-a-bit)
  - [Check if a bit is set](#check-if-a-bit-is-set)
  - [Count the number of set bits](#count-the-number-of-set-bits)
- [Advanced Techniques](#advanced-techniques)
  - [Isolate the rightmost set bit](#isolate-the-rightmost-set-bit)
  - [Turn off the rightmost set bit](#turn-off-the-rightmost-set-bit)
  - [Check if a number is a power of two](#check-if-a-number-is-a-power-of-two)
  - [XOR tricks](#xor-tricks)

## Basics

### Checking if a number is odd or even

You can check whether a number is odd or even by checking its least significant bit.

```cpp
bool isEven(int n) {
    return !(n & 1);
}

bool isOdd(int n) {
    return n & 1;
}
```

Swapping two numbers without a temporary variable
You can swap two numbers using XOR.

```cpp
void swap(int &a, int &b) {
a ^= b;
b ^= a;
a ^= b;
}
```

Multiplying and dividing by powers of 2
To multiply a number by 2^k left shift it by k. To divide, right shift by k.

```cpp
int multiplyByPowerOf2(int n, int k) {
return n << k;
}

int divideByPowerOf2(int n, int k) {
return n >> k;
}
```

Common Operations

- Set the i-th bit of a number
- Clear the i-th bit of a number.
- Toggle the i-th bit of a number (flip it).
- Check if the i-th bit is set.

```cpp
int setBit(int n, int i) {
return n | (1 << i);
}

int clearBit(int n, int i) {
return n & ~(1 << i);
}

int toggleBit(int n, int i) {
return n ^ (1 << i);
}

bool isBitSet(int n, int i) {
return (n & (1 << i)) != 0;
}
```

Count the number of set bits
Use Brian Kernighan's Algorithm to count the number of 1-bits (set bits) in a number.

```cpp
int countSetBits(int n) {
int count = 0;
while (n > 0) {
n &= (n - 1); // Turn off the rightmost set bit
count++;
}
return count;
}
```

Advanced Techniques
Isolate the rightmost set bit
This operation extracts the rightmost set bit from a number.

```cpp
int isolateRightmostSetBit(int n) {
return n & (-n);
}
```

Turn off the rightmost set bit
This operation turns off the rightmost set bit.

```cpp
int turnOffRightmostSetBit(int n) {
return n & (n - 1);
}

bool isPowerOfTwo(int n) {
return n > 0 && (n & (n - 1)) == 0;
}

```
