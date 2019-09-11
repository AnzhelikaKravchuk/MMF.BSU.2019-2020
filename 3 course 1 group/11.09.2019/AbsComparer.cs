using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1
{
    public class AbsComparer
    {
        public int Compare(int lhs, int rhs) 
            => Math.Abs(lhs) - Math.Abs(rhs);
    }

    public class LengthComparer
    {
        public int Compare(int lhs, int rhs)
            => lhs.ToString().Length - rhs.ToString().Length;
    }
}
