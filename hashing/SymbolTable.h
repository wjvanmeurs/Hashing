#pragma once
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
#include "Hasher.h"
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
		//	in the SymbolTable; return reference to the new Symbol.
		//	Raise std::out_of_range exception if a Symbol already exists.
		const Symbol& SetSymbol( const string& str, long hashValue );

	public:
		SymbolTable() : 
			m_Collisions(0), m_pHasher(new Hasher) {};
		virtual ~SymbolTable() 
		{
			delete m_pHasher;
		};

		static SymbolTable& SingleInstance();

		//	Return true only if a symbol is present for the supplied hash value
		bool HasSymbolFor( const long& hashValue ) const;

		//	Return true only if a Symbol is present for the supplied string;
		//	In case the Symbol does not exist, proposedHash is the hash value
		//	suggested for association with the string value.
		bool FindSymbolForString( const string& str, long& proposedHash );

		//	Return reference to the symbol for the supplied string value
		//	Create the Symbol of it is not yet present in the SymbolTable
		const Symbol& GetSymbolForString( const string& str );

		//	Returns reference to the Symbol associated with the supplied hash value.
		//	Raises exception std::out_of_range if no Symbol exists for the hash
		const Symbol& GetSymbolForHash( const long& hashValue ) const;			

		//	Print content
		virtual void Print() const;

		//	Install hasher for string hashing 
		void SetHasher( Hasher* pHasher );

	protected:
		int		m_Collisions;

	public:
		Hasher*	m_pHasher;
	};
}  // namespace hashing


//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2019-09-30
//      Initial version
//------------------------------------------------------------------------------