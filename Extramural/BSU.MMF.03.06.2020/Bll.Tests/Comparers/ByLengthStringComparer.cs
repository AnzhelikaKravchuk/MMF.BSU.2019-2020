using System;
using System.Collections.Generic;

namespace Bll.Tests.Comparers
{
    public class ByLengthStringComparer : IComparer<string>
    {
        public int Compare(string x, string y)
        {
            if (x is null)
            {
                return -1;
            }
            
            if (y is null)
            {
                return 1;
            }

            return x.Length.CompareTo(y.Length);
        }
    }
}