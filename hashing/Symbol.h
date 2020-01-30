#pragma once
#pragma warning( disable : 4251)
//------------------------------------------------------------------------------
//	File: Symbol.h
//
//		Class Symbol asssoicates a string with its corresponding hash value.
//		Symbols are created by an instance of SymbolTable, which guatantees
//		that a given string is associated with only one hash-value and that a 
//		given hash-value is associated with at most one string value.
//------------------------------------------------------------------------------
#include <iostream>
#include <map>

#include "hashing.h"
#include "hashing_linkage.h"

using std::string;
using std::map;

namespace hashing
{

	class HASHING_LINKAGE Symbol
	{
	private:
		//	hide copy and assignment constructors
		Symbol( const Symbol&) ;
		bool operator==(const Symbol& s) const;

	public:
		Symbol( const string&, const long );
		virtual ~Symbol() {};

		const string&	str()	const;
		const long long hash()	const;

		void Print() const;

	private:
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