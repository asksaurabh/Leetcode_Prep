#include <bits/stdc++.h>
using namespace std;

bool isOdd(int num) {
	return (num & 1) == 1 ? true : false;
}

int getIth(int num, int i) {
	int mask = (1 << i);

	return (num & mask) > 0 ? 1 : 0;
}

int setIth(int num, int i) {
	int mask = (1 << i);

	return (num | mask);
}

int clearIth(int num, int i) {
	int mask = (1 << i);
	mask = ~(mask);        // Introducing 0 at ith place

	return (num & mask);
}

int updateIth(int num, int i, int val) {
	// first clear the ith bit (prep it to put val there)
	int mask = ~(1 << i);
	num = (num & mask);

	// Now set the ith bit with val
	mask = (val << i);
	num = (num | mask);

	return num;
}

int clearLastI(int num, int i) {
	int mask = (-1 << i);
	return (num & mask);
}

int clearInRange(int i, int j, int num) {
	int a = (-1 << (j + 1));
	int b = (1 << i) - 1;

	int mask = (a | b);

	return (num & mask);
}


int replaceBits(int N, int i, int j, int M) {
	// FIrst clear bits in range [i..j] for appropriate setting
	N = clearInRange(i, j, N);

	// Now put M at right place for setting
	int mask = (M << i);

	return (N | mask);
}

void isPowerOfTwo(int num) {

	if ((num & (num - 1)) == 0)
		cout << "Yes\n";
	else
		cout << "No\n";
}

// T.C -> O(log4(n))
void isPowerOfFour(int num) {

	// A power of 2 is not necessarily a power of 4 (For eg. 8)
	if (num < 4) {
		// say num = 1
		cout << "No\n";
		return;
	}

	while (num % 4 == 0) {
		num /= 4;
	}

	if (num == 1)
		cout << "Yes\n";
	else
		cout << "No\n";
}

// T.C -> O(log2(n))
int countSetBits(int num) {

	int count = 0;
	while (num > 0) {
		int lastBit = (num & 1);
		if (lastBit == 1)
			count++;

		num = num >> 1;
	}

	return count;
}

// t.C -> O(no of set bits)
int countSetBitsHack(int num) {
	int count = 0;
	while (num > 0) {
		num = (num & (num - 1));      // Removes last set bit from num
		count++;
	}

	return count;
}

int binary(int num) {
	int ans = 0;
	int p = 1;

	while (num > 0) {
		int lastBit = (num & 1);
		ans = ans + lastBit * p;
		p = p * 10;
		num = num >> 1;
	}

	return ans;
}

int main() {

	int num = 5;

	// Odd or even
	cout << isOdd(num) << "\n";

	// Get ith bit from left (start from left with 0th bit)
	int i = 2;
	cout << getIth(num, i) << "\n";

	// Set ith bit
	i = 1;
	cout << setIth(num, i) << "\n";

	// Clear ith bit
	i = 0;
	cout << clearIth(num, i) << "\n";

	// Update ith bit
	i = 1;
	int val = 1;
	cout << updateIth(num, i, val) << "\n";

	// Clear last i bits
	i = 2;
	cout << clearLastI(num, i) << "\n";

	// Clear bits in range i to j
	i = 1;
	int j = 3;
	int n = 31;

	cout << clearInRange(i, j, n) << "\n";

	// Replace bits in N my M in range i to j
	int N = 15;
	i = 1, j = 3;
	int M = 2;

	cout << replaceBits(N, i, j, M) << "\n";

	// Check if N is a power of 2 in O(1) time
	int num1 = 16, num2 = 18, num3 = 15;

	isPowerOfTwo(num1);
	isPowerOfTwo(num2);
	isPowerOfTwo(num3);

	cout << "--------------\n";

	// Check if N is a power of 4
	num1 = 16, num2 = 8, num3 = 5;

	isPowerOfFour(num1);
	isPowerOfFour(num2);
	isPowerOfFour(num3);


	// COunt number of set bits O(log2(n))
	num = 15;
	cout << countSetBits(num) << "\n";

	// COunt number of set bits HACK : O(no of set bits)
	num = 15;
	cout << countSetBitsHack(num) << "\n";

	// Get binary representation
	num = 15, num1 = 8, num2 = 10;

	cout << binary(num) << "\n";
	cout << binary(num1) << "\n";
	cout << binary(num2) << "\n";

	return 0;
}