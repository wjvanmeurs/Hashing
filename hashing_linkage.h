	#pragma once
	#ifdef HASHING_EXPORTS
	#define HASHING_API __declspec(dllexport)
	#else
	#define HASHING_API __declspec(dllimport)
	#endif