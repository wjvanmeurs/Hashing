#include <iostream>

#include "hashing.h"
#include "hashing_linkage.h"

using namespace std;

HASHING_LINKAGE long compute_hash(string const& s) {
	const int p = 127;
	const long m = 1e9 + 9;
	long long hash_value = 0;
	long long p_pow = 1;
	for (char c : s) {
		hash_value = (hash_value + c * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}