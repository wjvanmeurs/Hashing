#pragma once;
//------------------------------------------------------------------------------
//	Class SymbolTable
//
//	This singleton class contains a map object that maps hash values on Symbol
//	instances.
//------------------------------------------------------------------------------
#include <iostream>
#include <map>

#include "hashing/hashing.h"
#include "hashing/Symbol.h"

using std::map;
using std::string;


namespace hashing
{
	class  SymbolTable
	{
	protected:
		map<long long, Symbol const*>		m_symbolMap;

	public:

		HASHING_API SymbolTable() : m_Collisions(0) {};
		HASHING_API virtual ~SymbolTable() {};

		HASHING_API static SymbolTable& SingleInstance();

		HASHING_API bool HasSymbolFor(const long long hashValue);
		HASHING_API const Symbol& GetSymbolFor(const long long hashValue);
		HASHING_API const Symbol& GetSymbolFor(const string str);

		HASHING_API virtual void Print() const;

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