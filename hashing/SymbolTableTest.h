#pragma once;
//------------------------------------------------------------------------------
//	File: SymbolTableTest.h
//
//		This class extends SymbolTable with the capability to enter a Symbol
//		with given string value and hash value. This enables testing SymbolTable
//		behavior in the presence of collisions or table overflow.
//------------------------------------------------------------------------------
#include <iostream>
#include <map>

#include "hashing_linkage.h"
#include "hashing.h"
#include "Symbol.h"
#include "SymbolTable.h"

using std::map;
using std::string;


namespace hashing
{
	class HASHING_LINKAGE SymbolTableTest : public SymbolTable
	{
	public:

		SymbolTableTest() {};
		virtual ~SymbolTableTest() {};

		static SymbolTableTest& GetSingleInstance();

		const Symbol& InsertSymbolFor(
			const long hashValue,
			const string );
	};
}  // namespace hashing

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2019-10-04
//      Initial version
//------------------------------------------------------------------------------