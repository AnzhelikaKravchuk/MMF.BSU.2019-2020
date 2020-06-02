using System.Collections.Generic;
using System;

namespace Bll.Tests.Comparers
{
    public class IntegerByAbsComparer : IComparer<int>
    {
        public int Compare(int x, int y)
            => Math.Abs(x).CompareTo(Math.Abs(y));
    }
}