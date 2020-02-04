#include <iostream>
#include "hashing.h"
#include "SymbolTable.h"
#include "Symbol.h"

using namespace std;
using std::map;

namespace hashing
{
	// define the singleton instance
	static SymbolTable& s_singleInstance = *(new SymbolTable); // define the singleton instance

	SymbolTable& SymbolTable::SingleInstance()
	{
		return s_singleInstance;
	}


	//----------------------------------------------------------------------------
	//	HasSymbolFor
	//		Return true only if a symbol is present for the supplied hash value.
	//----------------------------------------------------------------------------
	bool SymbolTable::HasSymbolFor( const long& hashValue) const
	{
		return !m_symbolMap.at( hashValue );
	}


	//----------------------------------------------------------------------------
	//	FindSymbolForString
	//		Return true only if a Symbol is present for the supplied string;
	//		In case the Symbol does not exist, proposedHash is the hash value
	//		suggested for association with the string value.
	//---------------------------------------------------------------------------
	bool SymbolTable::FindSymbolForString( 
		const string& str, long proposedHash )
	{
		proposedHash =	m_Hasher.Hash( str );

		bool			found = false;
		bool			matchingHash = HasSymbolFor( proposedHash );
		const Symbol*	pSymbol = NULL;

		if ( matchingHash )
		{
			if ( str == m_symbolMap[ proposedHash ]->str() )
			{
				//	A symbol exists for this string
				found = true;
			}
			else do
			{
				m_Collisions++;
				if ( proposedHash == LLONG_MAX )
				{
					throw std::overflow_error( 
						"SymbolTable instance overflowed" );
				}
				matchingHash = HasSymbolFor( ++proposedHash );
				if ( matchingHash )
				{
					if ( str == m_symbolMap[ proposedHash ]->str() )
					{
						//	A symbol exists for this string
						found = true;
					}
				}
			} while ( matchingHash && !found );
		}
		return found;
	}


	//----------------------------------------------------------------------------
	//	GetSymbolForHash
	//		Returns reference to the Symbol associated with the supplied hash value.
	//		Raises exception std::out_of_range if no Symbol exists for the hash
	//----------------------------------------------------------------------------
	const Symbol& SymbolTable::GetSymbolForHash( const long& hashValue ) const
	{
		return *m_symbolMap.at( hashValue );
	}


	//----------------------------------------------------------------------------
	//	SetSymbol
	//		Create a symbol for the supplied string and hash value and store it
	//		in the SymbolTable; return reference to the new Symbol.
	//		Raise std::out_of_range exception if a Symbol already exists.
	//----------------------------------------------------------------------------
	const Symbol& SymbolTable::SetSymbol( const string& str, long hashValue )
	{
		if ( HasSymbolFor( hashValue ))
		{
			const Symbol& cSym = GetSymbolForHash( hashValue );
			if ( cSym.str() == str )
			{
				//	Symbol already present
				return cSym;
			}
			else
			{
				throw std::out_of_range(
					"SetSymbol called on existing Symbol");
			}
		}

		Symbol* pSymbol = new Symbol( str, hashValue );
		m_symbolMap[ hashValue ] = pSymbol;
		return *pSymbol; 
	}


	//----------------------------------------------------------------------------
	//	GetSymbolForString
	//		Return reference to the symbol for the supplied string value
	//		Create the Symbol of it is not yet present in the SymbolTable
	//----------------------------------------------------------------------------
	const Symbol& SymbolTable::GetSymbolForString( const string& str )
	{
		long			proposedHash = 0;
		bool found =	FindSymbolForString( str, proposedHash );

		if ( !found )
		{
			//	Symbol not present; create it 
			SetSymbol( str, proposedHash );
		}

		return *m_symbolMap[ proposedHash ];
	}


	//----------------------------------------------------------------------------
	//	Print
	//	Prints the Symbols contained in the SymbolTable
	//----------------------------------------------------------------------------
	void SymbolTable::Print() const
	{
		std::map<long, Symbol const*>::const_iterator it;
		for (it = m_symbolMap.begin(); it != m_symbolMap.end(); ++it)
		{
			const Symbol& symbol = (*it->second);
			symbol.Print();
		}
		std::cout << "Hash collisions: " << m_Collisions;
	}


	//----------------------------------------------------------------------------
	//	SetHasher
	//		Install hasher for string hashing
	//----------------------------------------------------------------------------
	void SymbolTable::SetHasher( Hasher& hasher ) 
	{
		m_Hasher = hasher;
	}
}  // namespace hashing


//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2019-09-23
//      Initial version
//------------------------------------------------------------------------------