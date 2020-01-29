#pragma once
//------------------------------------------------------------------------------
//	Class Symbol
//
//	This class associates a string with its hash value.
//	Symbol instances are maintained in a singleton SymbolTable object
//	The Symbol instance is a stand-in for the string it contains and permits 
//	efficient string equality tests.
//------------------------------------------------------------------------------
#include <iostream>
#include <map>

#include "hashing/hashing.h"

using std::string;
using std::map;

namespace hashing
{

	class Symbol
	{
	private:
		//	hide copy constructor
		Symbol(const Symbol&);

	public:
		HASHING_API Symbol(const string&, const long long);
		HASHING_API virtual ~Symbol() {};
		HASHING_API bool operator ==(const Symbol& s) const;

		HASHING_API const string&	str() const;
		HASHING_API const long long hash() const;

		HASHING_API void Print() const;

		string                  m_string;
		long long				m_hash;
	};
}   // namespace hashing

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2019-09-19
//      Initial version
//------------------------------------------------------------------------------