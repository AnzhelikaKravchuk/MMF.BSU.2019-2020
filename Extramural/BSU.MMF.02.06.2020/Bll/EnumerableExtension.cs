using System;
using System.Collections.Generic;

namespace Bll
{
    public static class EnumerableExtension
    {
        public static void Sort(int[] source) // System.Int32 : IComparable -> CompareTo int (-1, 0, 1)
        {
            if (source is null)
            {
                throw new ArgumentNullException(nameof(source));
            }

            bool isSorted = false;

            int i = 1;

            while (!isSorted)
            {
                isSorted = true;

                for (int j = 0; j < source.Length - i; j++)
                {
                    if (source[j].CompareTo(source[j + 1]) > 0)
                    {
                        Swap(ref source[j], ref source[j + 1]);
                        isSorted = false;
                    }
                }

                i++;
            }
        }

        public static void Sort(int[] source, IComparer<int> comparer) // IComparer -> Comparer
        {
            if (source is null)
            {
                throw new ArgumentNullException(nameof(source));
            }

            bool isSorted = false;

            int i = 0;

            while (!isSorted)
            {
                isSorted = true;

                int previous = 0, //j
                    next = previous + 1; //j+1 step = 1, 2, 3,

                while (next < source.Length - i) //end
                {
                    if (comparer.Compare(source[previous], source[next]) > 0)
                    {
                        Swap(ref source[previous], ref source[next]);
                        isSorted = false;
                    }

                    previous = next;
                    next = previous + 1; //
                }

                i++;
            }
        }

        public static void Sort(int[] source, IComparer<int> comparer, ICursor cursor)
        {
            if (source is null)
            {
                throw new ArgumentNullException($"{nameof(source)} cannot be null.");
            }

            bool isSorted = false;

            int i = 0;

            while (!isSorted)
            {
                isSorted = true;

                cursor.Reset();
                
                int previous = cursor.Start,
                    next = cursor.Next;

                while (next <= cursor.End - i)
                {
                    if (comparer.Compare(source[previous], source[next]) > 0)
                    {
                        Swap(ref source[previous], ref source[next]);
                        isSorted = false;
                    }

                    previous = next;
                    next = cursor.Next;
                }
                i++;
            }
        }

        private static void Swap(ref int a, ref int b)
        {
            int t = a;
            a = b;
            b = t;
        }
    }
}