using System;
using System.Linq;
using System.Collections.Generic;
using static Bll.EnumerableExtension;
using static System.Console;

namespace Bll.ConsoleUI
{
    static class Program
    {
        static void Main(string[] args)
        {
            List<int> array = new List<int>(new []{10, 9, 6, 8, 7, 6, 5, 4, 3, 6, 2, 1});
            
            var @where = array
                .Where(t => t % 2 == 0)
                .Where(t => t >= 10)
                .Select(t => t * 100)
                .Select(t => $"{t.ToString()},   ");
            
            array.Add(122);
            array.Add(44);
            
            foreach (var t in @where)
            {
                Console.Write($"{t} ");
            }

            // var strings = new string[] {"one", "three", "four", "a", "hello world"};
            // var @where1 = strings.Where(t => t.Length >= 3);
            // foreach (var t in @where1)
            // {
            //     Console.Write($"{t} ");
            // }

            // WriteLine("Source array");
            // Array.ForEach(array, i => Write($"{i} "));
            //
            // //Sort(array);
            //
            // WriteLine("\nSorted array");
            // Array.ForEach(array, i => Write($"{i} "));
        }
    }
}