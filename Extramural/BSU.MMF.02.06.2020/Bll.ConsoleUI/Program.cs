using System;
using static Bll.EnumerableExtension;
using static System.Console;

namespace Bll.ConsoleUI
{
    static class Program
    {
        static void Main(string[] args)
        {
            int[] array = new[] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
            
            WriteLine("Source array");
            Array.ForEach(array, i => Write($"{i} "));

            Sort(array);
            
            WriteLine("\nSorted array");
            Array.ForEach(array, i => Write($"{i} "));
        }
    }
}