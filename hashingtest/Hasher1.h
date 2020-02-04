#pragma once
//------------------------------------------------------------------------------
//	File: Hasher1.h
//
//		Test hasher that maps all strings on hash value 1
//------------------------------------------------------------------------------
#include <iostream>
#include <map>

#include "hashing_linkage.h"
#include "Hasher.h"

using std::string;
using std::map;

namespace hashing
{

	class Hasher1 : public Hasher
	{
	public:
		Hasher1() {};
		virtual ~Hasher1() {};

		virtual long Hash(const string& str)
		{
			return 1;
		};
	};
}   // namespace hashing

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2020-02-04
//      Initial version
//------------------------------------------------------------------------------