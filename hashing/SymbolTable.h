#pragma once;
//------------------------------------------------------------------------------
//	Class SymbolTable
//
//	This singleton class contains a map object that maps hash values on Symbol
//	instances.
//------------------------------------------------------------------------------
#include <iostream>
#include <map>

#include "hashing_linkage.h"
#include "hashing.h"
#include "Symbol.h"

using std::map;
using std::string;


namespace hashing
{
	class HASHING_LINKAGE SymbolTable
	{
	protected:
		map<long, Symbol const*>		m_symbolMap;

	public:

		SymbolTable() : m_Collisions(0) {};
		virtual ~SymbolTable() {};

		static SymbolTable& SingleInstance();

		bool HasSymbolFor(const long hashValue);
		const Symbol& GetSymbolFor(const long hashValue);
		const Symbol& GetSymbolFor(const string str);

		virtual void Print() const;

	protected:
		int		m_Collisions;
	};
}  // namespace hashing

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2019-09-30
//      Initial version
//------------------------------------------------------------------------------