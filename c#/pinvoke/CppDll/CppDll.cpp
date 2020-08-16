#include "CppDll.h"

CPPCallback callback;
__declspec(dllexport) void SetCallback(CPPCallback cb)
{
    callback = cb;
}

__declspec(dllexport) void InvokeCallback(int someParameters)
{
    callback(someParameters);
}

__declspec(dllexport) uint64_t Add(uint64_t a, uint64_t b) 
{
    return a + b;
}
