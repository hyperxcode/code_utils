using System;
using CSharpeExe;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace UnitTest
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Assert.AreEqual(23, CppDll.Add(4, 19));
        }

        [TestMethod]
        public void TestMethod2()
        {
            Assert.AreEqual(23, 23);
        }
    }
}
 