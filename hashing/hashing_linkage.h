#pragma once
#ifdef HASHING_EXPORTS
#define HASHING_LINKAGE __declspec(dllexport)
#else
#define HASHING_LINKAGE __declspec(dllimport)
#endif