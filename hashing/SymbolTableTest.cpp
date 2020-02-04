//------------------------------------------------------------------------------
//	File: SymbolTableTest.cpp
//------------------------------------------------------------------------------
#include "SymbolTableTest.h"

using namespace std;
using std::map;

namespace hashing
{
	static SymbolTableTest s_singleInstance; // define the singleton instance

	SymbolTableTest& SymbolTableTest::GetSingleInstance()
	{
		return s_singleInstance;
	}

	//--------------------------------------------------------------------------
	//	InsertSymbolFor
	//		Compute the hash of supplied string; if a Symbol exists for this 
	//		hash and it is associated with another string value, continue 
	//		incrementing the hash and finding Symbols with different string 
	//		values until either a copy is found of the supplied string, or an
	//		empty hash slot is found. 
	//		In the latter case create the Symbol with the string and
	//		incremented hash value.
	//----------------------------------------------------------------------------
	const Symbol& SymbolTableTest::InsertSymbolFor(
		const long hash, const string str )
	{
		long hashValue = hash;
		bool matchingHash = HasSymbolFor( hashValue );
		const Symbol* pSymbol = NULL;

		if ( !matchingHash )
		{
			//	Empty slot, so this is a new hash/string combination
			pSymbol = new Symbol( str, hashValue );
			m_symbolMap[ hashValue ] = pSymbol;
		}
		else do
		{
			//	This slot is already occupied
			const Symbol& rSymbol = SymbolTable::GetSymbolForHash( hashValue );
			if ( rSymbol.str() == str )
			{
				//	This is known hash/string combination
				pSymbol = &rSymbol;
			}
			else
			{
				//	Same hash value, but different string: collision
				//	increment the hash and check again
				m_Collisions++;
				if ( hashValue == LLONG_MAX )
				{
					throw std::overflow_error(
						"SymbolTable instance overflowed" );
				}
				matchingHash = HasSymbolFor( ++hashValue );
				if ( !matchingHash )
				{
					pSymbol = new Symbol( str, hashValue );
					m_symbolMap[ hashValue ] = pSymbol;
				}
			}
		} while ( matchingHash && !pSymbol );
		return *pSymbol;
	}


}  // namespace hashing

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2019-10-04
//      Initial version
//------------------------------------------------------------------------------