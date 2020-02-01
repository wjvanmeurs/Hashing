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
	//	FindSymbolFor
	//		Return true if a Symbol is present for the supplied string;
	//		In case the Symbol does not exist, proposedHash is the hash value
	//		suggested to be asscoiated with the string value.
	//----------------------------------------------------------------------------
	bool SymbolTable::FindSymbolFor( const string& str, long proposedHash )
	{
		bool		found = false;
		long 		proposedHash = compute_hash( str );
		bool		matchingHash = HasSymbolFor( proposedHash );
		const Symbol* pSymbol = NULL;

		if ( matchingHash )
		{
			if ( str == m_symbolMap[ proposedHash ]->str )
			{
				//	A symbol exists for this string
				found = true;
			}
			else do
			{
				m_Collisions++;
				if (proposedHash == LLONG_MAX )
				{
					throw std::overflow_error( 
						"SymbolTable instance overflowed" );
				}
				matchingHash = HasSymbolFor( ++proposedHash );
				if ( matchingHash )
				{
					if (str == m_symbolMap[proposedHash]->str)
					{
						//	A symbol exists for this string
						found = true;
					}
				}
			} while ( matchingHash && !found )
		}
		else do
		{
			const Symbol& rSymbol = GetSymbolFor(hashValue);
			if (rSymbol.str() == str)
			{
				pSymbol = &rSymbol;
			}
			else
			{
				m_Collisions++;
				if (hashValue == LLONG_MAX)
				{
					throw std::overflow_error("SymbolTable instance overflowed");
				}
				matchingHash = HasSymbolFor(++hashValue);
				if (!matchingHash)
				{
					pSymbol = new Symbol(str, hashValue);
					m_symbolMap[hashValue] = pSymbol;
				}
			}
		} while (matchingHash && !pSymbol);
		return *pSymbol;
	}


	//----------------------------------------------------------------------------
	//	GetSymbolFor
	//		Returns reference to the Symbol associated with the supplied hash value.
	//		Raises exception std::out_of_range if no Symbol exists for the hash
	//----------------------------------------------------------------------------
	const Symbol& SymbolTable::GetSymbolFor(const long hashValue)
	{
		return *m_symbolMap.at(hashValue);
	}


	//----------------------------------------------------------------------------
	//	SetSymbol
	//	Create a symbol for the supplied string and hash value and store it
	//	in the SymbolTable.
	//----------------------------------------------------------------------------
	const Symbol& SymbolTable::SetSymbol( const string& str, long hashValue )
	{
		Symbol* pSymbol = new Symbol( str, hashValue );
		m_symbolMap[ hashValue ] = pSymbol;
		return *pSymbol;
	}


	//----------------------------------------------------------------------------
	//	GetSymbolFor
	//	Returns the Symbol associated with the supplied string.
	//	If no Symbol exists for the supplied string, it is created first and added
	//	to the SymbolTable.
	//	In case the hashvalue collides with another string hash, the hashvalue is 
	//	incremented. If necessary, such incrementing is continued until either a 
	//	matching string Symbol is found or an empty slot. In the latter case
	//	the Symbol is created and entered at the empty slot.
	//----------------------------------------------------------------------------
	const Symbol& SymbolTable::GetSymbolFor(const string str)
	{
		long 			hashValue = compute_hash(str);
		bool			matchingHash = HasSymbolFor(hashValue);
		const Symbol* pSymbol = NULL;

		if (!matchingHash)
		{
			pSymbol = new Symbol(str, hashValue);
			m_symbolMap[hashValue] = pSymbol;
		}
		else do
		{
			const Symbol& rSymbol = GetSymbolFor(hashValue);
			if (rSymbol.str() == str)
			{
				pSymbol = &rSymbol;
			}
			else
			{
				m_Collisions++;
				if (hashValue == LLONG_MAX)
				{
					throw std::overflow_error("SymbolTable instance overflowed");
				}
				matchingHash = HasSymbolFor(++hashValue);
				if (!matchingHash)
				{
					pSymbol = new Symbol(str, hashValue);
					m_symbolMap[hashValue] = pSymbol;
				}
			}
		} while (matchingHash && !pSymbol);
		return *pSymbol;
	}


	//----------------------------------------------------------------------------
	//	print
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
}  // namespace hashing

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2019-09-23
//      Initial version
//------------------------------------------------------------------------------