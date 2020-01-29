#pragma once
#pragma warning( disable : 4251)
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

#include "hashing.h"
#include "hashing_linkage.h"

using std::string;
using std::map;

namespace hashing
{

	class HASHING_LINKAGE Symbol
	{
	private:
		//	hide copy constructor
		Symbol(const Symbol&);

	public:
		Symbol(const string&, const long long);
		virtual ~Symbol() {};
		bool operator ==(const Symbol& s) const;

		const string&	str()	const;
		const long long hash()	const;

		void Print() const;

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