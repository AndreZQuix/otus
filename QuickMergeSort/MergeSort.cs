using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using Testing;

namespace QuickMergeSort
{
    public class MergeSort : ITask
    {
        public string Run(string[] data)
        {
            int size = Convert.ToInt32(data[0]);
            int[] arr = data[1].Split(" ").Select(int.Parse).ToArray();
            Stopwatch sw = Stopwatch.StartNew();
            MergeSortAlg(arr);
            sw.Stop();
            Console.WriteLine($"MergeSort elapsed time: {sw.ElapsedMilliseconds} ms");
            return System.String.Join(" ", arr);
        }

        private static void MergeArray(int[] arr, int[] left, int[] right)
        {
            int i = 0, j = 0, k = 0;

            while (i < left.Length && j < right.Length)
            {
                if (left[i] <= right[j])
                    arr[k++] = left[i++];
                else
                    arr[k++] = right[j++];
            }

            while (i < left.Length)
                arr[k++] = left[i++];

            while (j < right.Length)
                arr[k++] = right[j++];
        }

        public void MergeSortAlg(int[] arr)
        {
            if (arr.Length <= 1)
                return;

            int mid = arr.Length / 2;

            int[] left = new int[mid];
            int[] right = new int[arr.Length - mid];

            for (int i = 0; i < mid; i++)
                left[i] = arr[i];
            for (int i = mid; i < arr.Length; i++)
                right[i - mid] = arr[i];

            MergeSortAlg(left);
            MergeSortAlg(right);
            MergeArray(arr, left, right);
        }
    }
}
