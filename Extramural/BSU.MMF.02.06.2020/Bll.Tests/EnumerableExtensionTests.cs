using System;
using System.Collections.Generic;
using Bll.Tests.Comparers;
using Bll.Tests.Cursors;
using NUnit.Framework;

namespace Bll.Tests
{
    [TestFixture]
    public class EnumerableExtensionTests
    {
        // [TestCase(new[] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, new[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})]
        // [TestCase(new[] {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}, new[] {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1})]
        // public void SortTests(int[] actual, int[] expected)
        // {
        //     EnumerableExtension.Sort(actual);
        //     CollectionAssert.AreEqual(expected, actual);
        // }

        [TestCase(new[] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, ExpectedResult = new[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})]
        [TestCase(new[] {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10},
            ExpectedResult = new[] {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1})]
        public int[] SortTests(int[] actual)
        {
            EnumerableExtension.Sort(actual);
            return actual;
        }

        [Test]
        public void Sort_ArrayIsNull_ThrowArgumentNullException()
        {
            Assert.Throws<ArgumentNullException>(() => EnumerableExtension.Sort(null));
        }

        private static IEnumerable<TestCaseData> SortWithComparerTestCases
        {
            get
            {
                yield return new TestCaseData(new[] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
                        new IntegerByAbsComparer())
                    .Returns(new[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
                yield return new TestCaseData(new[] {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1},
                        new IntegerByAbsComparer())
                    .Returns(new[] {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10});
            }
        }

        [TestCaseSource(nameof(SortWithComparerTestCases))]
        public int[] SortWithComparerTests(int[] actual, IComparer<int> comparer)
        {
            EnumerableExtension.Sort(actual, comparer);
            return actual;
        }

        private static IEnumerable<TestCaseData> SortWithComparerAndCursorTestCases
        {
            get
            {
                yield return new TestCaseData(new[] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
                        new IntegerByAbsComparer(),
                        new SimpleCursor(0, 9))
                    .Returns(new[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
                yield return new TestCaseData(new[] {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10},
                        new IntegerByAbsComparer(),
                        new SimpleCursor(0, 9))
                    .Returns(new[] {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10});
                yield return new TestCaseData(new[] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
                        new IntegerByAbsComparer(),
                        new ByStepCursor(0, 9, 2))
                    .Returns(new[] {2, 9, 4, 7, 6, 5, 8, 3, 10, 1});
                yield return new TestCaseData(new[] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
                        new IntegerByAbsComparer(),
                        new ByStepCursor(0, 9, 3))
                    .Returns(new[] {1, 9, 8, 4, 6, 5, 7, 3, 2, 10});
            }
        }

        [TestCaseSource(nameof(SortWithComparerAndCursorTestCases))]
        public int[] SortWithComparerAndCursorTests(int[] actual, IComparer<int> comparer, ICursor cursor)
        {
            EnumerableExtension.Sort(actual, comparer, cursor);
            return actual;
        }
    }
}