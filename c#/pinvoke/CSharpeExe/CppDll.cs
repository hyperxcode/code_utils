using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CSharpeExe
{
    public class CppDll
    {
        [DllImport("CppDll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetCallback(IntPtr callback);

        [DllImport("CppDll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void InvokeCallback(int someParameters);

        [DllImport("CppDll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Add(int a, int b);

        [DllImport("CppDll", CallingConvention = CallingConvention.Cdecl)]
        public static extern string SubString(string str, string substr, int loc);

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void CSharpDelegate(int someParameters);

        public static int AddEx(int a, int b)
        {
            return a + b;
            //return Add(a, b);
        }

    }
}
