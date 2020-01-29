#include "hashing/Symbol.h"

using namespace std;

namespace hashing
{

	//------------------------------------------------------------------------------
	//	Constructor
	//------------------------------------------------------------------------------
	Symbol::Symbol(const string& rStr, const long long hash) :
		m_string(rStr), m_hash(hash) {};

	const string& Symbol::str() const
	{
		return m_string;
	}

	const long long Symbol::hash() const
	{
		return m_hash;
	}

	void Symbol::Print() const
	{
		cout << "hash: " << m_hash;
		cout << ";  string: " << m_string;
		cout << endl;
	}

	bool Symbol::operator ==(const Symbol& s) const
	{
		return s.m_hash == m_hash;
	}
}