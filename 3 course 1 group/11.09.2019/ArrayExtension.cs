using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1
{
    public static class ArrayExtension
    {
        public static void BubbleSort(int[] array)
        {
            AbsComparer comparer = new AbsComparer();

            if (array is null)
            {
                throw new ArgumentNullException($"{nameof(array)} can not be null!");
            }

            if (array.Length == 0)
            {
                return;
            }
            
            for (int i = 0; i < array.Length; i++)
            {
                for (int j = 0; j < array.Length; j++)
                {
                    if (comparer.Compare(array[j], array[j + 1]) <= 0
                    {

                    }
                }
            }


        }

        public static void MergeSort(int[] array)
        {

        }

        public static void QuickSort(int[] array)
        {

        }
    }
}
