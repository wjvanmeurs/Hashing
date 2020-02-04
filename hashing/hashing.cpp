//------------------------------------------------------------------------------
//	Function compute_hash computes hash value for a supplied string, according 
//	to the algorithm defined in 
//	https://cp-algorithms.com/string/string-hashing.html
//----
#include <iostream>

#include "hashing.h"
#include "hashing_linkage.h"

using namespace std;

HASHING_LINKAGE long compute_hash( string const& s ) {
	const int p = 127;
	const long m = long( 1e9 + 9 );
	long hash_value = 0;
	long p_pow = 1;
	for (char c : s) {
		hash_value = (hash_value + c * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2020-01-30
//      Initial version
//------------------------------------------------------------------------------