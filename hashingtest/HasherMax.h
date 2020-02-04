#pragma once
//------------------------------------------------------------------------------
//	File: HasherMax.h
//
//		Test hasher that maps all strings on LLONG_MAX-2
//------------------------------------------------------------------------------
#include <iostream>
#include <map>

#include "hashing_linkage.h"
#include "Hasher.h"

using std::string;
using std::map;

namespace hashing
{

	class HasherMax: public Hasher
	{
	public:
		HasherMax() {};
		virtual ~HasherMax() {};

		virtual long Hash(const string& str)
		{
			return LONG_MAX - 2;
		};
	};
}   // namespace hashing

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2020-02-04
//      Initial version
//------------------------------------------------------------------------------