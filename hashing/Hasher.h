#pragma once
//------------------------------------------------------------------------------
//	File: Hasher.h
//
//		Class Hasher hosts the string hashing function to organize strings in 
//		a SymbolTable.
//		Normally class hashing uses the algortihm described in:
//		https://cp-algorithms.com/string/string-hashing.html`.
//		For testing of the handling of collisions and range overflow situations,
//		subclasses are used that generate specific hash values.
//------------------------------------------------------------------------------
#include <iostream>
#include <map>

#include "hashing_linkage.h"

using std::string;
using std::map;

namespace hashing
{

	class HASHING_LINKAGE Hasher
	{
	public:
		Hasher() {};
		virtual ~Hasher() {};

		virtual long Hash( const string& str );
	};
}   // namespace hashing

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2020-02-04
//      Initial version
//------------------------------------------------------------------------------