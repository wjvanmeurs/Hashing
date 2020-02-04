//------------------------------------------------------------------------------
//	hashingtest.cpp
//
//	Main program for testing SymbolTable features
//------------------------------------------------------------------------------
#include <iostream>

#include "hashing_linkage.h"
#include "SymbolTable.h" 

#include "Hasher1.h"
#include "HasherMax.h"

using std::cout;
using hashing::Symbol;
using hashing::SymbolTable;
using hashing::Hasher;
using hashing::Hasher1;
using hashing::HasherMax;

int main()
{
	Hasher*	pHasher1 =		new Hasher1;
	Hasher*	pHasherMax =	new HasherMax;

	SymbolTable* pSymbolTable = new SymbolTable();

	// This SymbolTable instance now hashes all strings on value 1:
	pSymbolTable->SetHasher( pHasher1 );
	const Symbol& symbolA = pSymbolTable->GetSymbolForString("firstString");
	const Symbol& symbolB = pSymbolTable->GetSymbolForString("secondString");
	const Symbol& symbolC = pSymbolTable->GetSymbolForString("thirdString");

	//	This SymbolTable now hashes all strings to LLONG_MAX-2
	pSymbolTable->SetHasher( pHasherMax );
	try
	{
		const Symbol& symbolD = pSymbolTable->GetSymbolForString("d");
		const Symbol& symbolE = pSymbolTable->GetSymbolForString("e");
		const Symbol& symbolF = pSymbolTable->GetSymbolForString("f");
	}

	catch (std::overflow_error exc)
	{
		cout << "Exception occurred" << std::endl;
	}

	pSymbolTable->Print();

	int c = getchar();
	exit(0);
}

//------------------------------------------------------------------------------
//                              MODIFICATION HISTORY
//------------------------------------------------------------------------------
//  Wil van Meurs													  2019-10-09
//      Initial Version
//------------------------------------------------------------------------------

