#include <stdint.h>

extern "C" {
	/*
		set call back function
	*/
	typedef void (*CPPCallback)(uint64_t someParamers);
	__declspec(dllexport) void __cdecl  SetCallback(CPPCallback cb);

	/*
		invode call back function
	*/
	__declspec(dllexport) void __cdecl  InvokeCallback(int someParameters);

	//sample test function
	__declspec(dllexport) uint64_t __cdecl  Add(uint64_t a, uint64_t b);
}