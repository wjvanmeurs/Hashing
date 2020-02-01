#pragma once;
//------------------------------------------------------------------------------
//	Class SymbolTable
//
//		This singleton class maintains Symbol objects, one for every string 
//		encountered.
//		Symbols can be retrieved on string value or on hash value.
//		
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

		//	Return true if a Symbol is present for the supplied string;
		//	In case the Symbol does not exist, proposedHash is the hash value
		//	suggested to be associated with the string value.
		bool FindSymbolFor( const string&, long proposedHash );

		//	Create a symbol for the supplied string and hash value and store it
		//	in the SymbolTable.
		const Symbol& SetSymbol( const string&, long proposedHash );


	public:
		SymbolTable() : m_Collisions(0) {};
		virtual ~SymbolTable() {};

		static SymbolTable& SingleInstance();

		//	Return true if a symbol is present for the supplied hash value
		bool HasSymbolFor( const long hashValue& ) const;

		//	Return the symbol that is stored for the specified hash value
		//	Throw out_of_range exception if no symbol present.
		const Symbol& GetSymbolFor( const long hashValue& ) const;

		//	Return the symbol that is stored for the specified string value
		//	If no symbol exists, creat one and enter it into symbol table
		const Symbol& GetSymbolFor(const long hashValue&) const;

		//	Print content
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