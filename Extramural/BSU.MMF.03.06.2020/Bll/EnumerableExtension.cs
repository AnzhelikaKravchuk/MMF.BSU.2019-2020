using System;
using System.Collections.Generic;

// class, struct, interface, delegate, methods <- generic

namespace Bll
{
    public static class EnumerableExtension
    {
        public static IEnumerable<T> CustomWhere<T>(this IEnumerable<T> source, Predicate<T> predicate)
        {
            foreach (var t in source)
            {
                if (predicate.Invoke(t))
                {
                    yield return t;
                }
            }
        }
        
        public static void Sort<T>(this T[] source) where T : IComparable<T> // T : System.Object
        {
            source.Sort(Comparer<T>.Default);
        }

        public static void Sort<T>(this T[] source, IComparer<T> comparer) // IComparer -> Comparer
        {
            //source.Sort(comparer, new SimpleCursor(0, source.Length - 1));
            source.Sort(new Comparison<T>(comparer.Compare));
        }

        public static void Sort<T>(this T[] source, Comparison<T> comparer) // IComparer -> Comparer
        {
            ICursor cursor = new SimpleCursor(0, source.Length - 1);
            
            if (source is null)
            {
                throw new ArgumentNullException($"{nameof(source)} cannot be null.");
            }

            if (comparer is null)
            {
                throw new ArgumentNullException($"{nameof(comparer)} cannot be null.");
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
                    //if (comparer.Invoke(source[previous], source[next]) > 0) 
                    if (comparer(source[previous], source[next]) > 0)
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

        public static void Sort<T>(this T[] source, IComparer<T> comparer, ICursor cursor)
        {
            if (source is null)
            {
                throw new ArgumentNullException($"{nameof(source)} cannot be null.");
            }

            if (comparer is null)
            {
                throw new ArgumentNullException($"{nameof(comparer)} cannot be null.");
            }

            //validation IComparer ICursor

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

        private static void Swap<T>(ref T a, ref T b) // T : Object
        {
            T t = a;
            a = b;
            b = t;
        }

        private struct SimpleCursor : ICursor
        {
            private int start;
            private int end;
            private int current;

            public SimpleCursor(int start, int end) : this()
            {
                Start = start;
                End = end;
                current = Start;
            }

            public int Start
            {
                get => start;
                //public int get_Start(){}
                private set => start =
                    value < 0 ? throw new ArgumentException($"{nameof(start)} cannot be less than zero.") : value;
                //private void set_Start(int value){}
            }

            public int End
            {
                get => end;
                private set
                {
                    if (value < 0)
                    {
                        throw new ArgumentException($"{nameof(end)} cannot be less than zero.");
                    }

                    if (value < start)
                    {
                        throw new ArgumentException($"{nameof(end)} cannot be less than {nameof(start)}.");
                    }

                    end = value;
                }
            }

            public int Next => ++current;

            public void Reset() => current = Start;
        }
    }
}