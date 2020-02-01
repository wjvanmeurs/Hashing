//------------------------------------------------------------------------------
//	hashingtest.cpp
//
//	Main program for testing SymbolTable features
//------------------------------------------------------------------------------
#include <iostream>
#include "SymbolTableTest.h"
#include "hashing_linkage.h"

using std::cout;
using hashing::Symbol;
using hashing::SymbolTable;
using hashing::SymbolTableTest;

int main()
{
	SymbolTableTest* pSymbolTableTest = new SymbolTableTest();

	const Symbol& symbolA = pSymbolTableTest->GetSymbolFor("firstString");
	const Symbol& symbolB = pSymbolTableTest->GetSymbolFor("secondString");
	const Symbol& symbolC = pSymbolTableTest->GetSymbolFor("thirdString");

	const long	lHash = 1;
	pSymbolTableTest->PushSymbolFor(lHash, "a");
	pSymbolTableTest->PushSymbolFor(lHash, "b");
	pSymbolTableTest->PushSymbolFor(lHash, "c");
	pSymbolTableTest->PushSymbolFor(lHash, "d");

	const long	lHashMax = LONG_MAX - 2;

	try
	{
		pSymbolTableTest->PushSymbolFor(lHashMax, "A");
		pSymbolTableTest->PushSymbolFor(lHashMax, "B");
		pSymbolTableTest->PushSymbolFor(lHashMax, "C");
		pSymbolTableTest->PushSymbolFor(lHashMax, "D");
	}
	catch (std::overflow_error exc)
	{
		cout << "Exception occurred" << std::endl;
	}

	pSymbolTableTest->Print();

	getchar();
	exit(0);
}

//------------------------------------------------------------------------------
//                              MODIFICATION HISTORY
//------------------------------------------------------------------------------
//  Wil van Meurs													  2019-10-09
//      Initial Version
//------------------------------------------------------------------------------

