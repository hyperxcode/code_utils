using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharpeExe
{
   

    public partial class Form1 : Form
    {

        public CppDll.CSharpDelegate csharpDelegate;
        void Init()
        {
        }

        public Form1()
        {
            InitializeComponent();
            Init();
        }
        public static void CSharpCallback(int someParameters)
        {
            MessageBox.Show("called from c++ data:" + someParameters);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            csharpDelegate = new CppDll.CSharpDelegate(CSharpCallback);
            CppDll.SetCallback(Marshal.GetFunctionPointerForDelegate(csharpDelegate));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            CppDll.InvokeCallback(123);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int c = CppDll.Add(4, 19);
            MessageBox.Show(c.ToString());
        }
    }
}
