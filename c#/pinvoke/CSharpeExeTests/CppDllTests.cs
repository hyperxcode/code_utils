using Microsoft.VisualStudio.TestTools.UnitTesting;
using CSharpeExe;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpeExe.Tests
{
    [TestClass()]
    public class CppDllTests
    {
        [TestMethod()]
        public void AddTest()
        {
            Assert.AreEqual(23, CppDll.Add(4, 19));
        }
        [TestMethod()]
        public void AddExTest()
        {
            Assert.AreEqual(23, CppDll.AddEx(4, 19));
        }
    }
}