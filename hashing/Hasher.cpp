
#include <iostream>

#include "Hasher.h"
#include "hashing.h"

namespace hashing
{
	long Hasher::Hash( const string& str )
	{
		return compute_hash(str );
	}
}

//------------------------------------------------------------------------------
//                              Modification History
//------------------------------------------------------------------------------
// Wil van Meurs													  2020-02-04
//      Initial version
//------------------------------------------------------------------------------