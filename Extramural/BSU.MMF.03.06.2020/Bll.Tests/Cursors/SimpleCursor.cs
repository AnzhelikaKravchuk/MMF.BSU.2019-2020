using System;

namespace Bll.Tests.Cursors
{
    public struct SimpleCursor : ICursor
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