using System;

namespace Bll.Tests.Cursors
{
    public class ByStepCursor : ICursor
    {
        private int start;
        private int end;
        private int step;
        private int current;

        public ByStepCursor(int start, int end, int step)
        {
            Start = start;
            End = end;
            Step = step;
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

        public int Step
        {
            get => step;
            private set => step =
                value < 0 ? throw new ArgumentException($"{nameof(step)} cannot be less than zero.") : value;
        }

        public int Next => current += Step;
        
        public void Reset() => current = Start;
    }
}