using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Testing;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace QuickMergeSort
{
    public class QuickSort : ITask
    {
        private void Swap(int[] arr, long index1, int index2)
        {
            int temp = arr[index1];
            arr[index1] = arr[index2];
            arr[index2] = temp;
        }

        private int Partition(ref int[] arr, int leftIndex, int rightIndex)
        {
            int pivot = arr[rightIndex];
            int middleIndex = leftIndex - 1;
            for (int j = leftIndex; j <= rightIndex; j++)
            {
                if (pivot >= arr[j])
                {
                    middleIndex++;
                    if (middleIndex != j)
                    {
                        Swap(arr, middleIndex, j);
                    }
                }
            }
            return middleIndex;
        }

        public void QuickSortAlg(ref int[] array, int leftIndex, int rightIndex)
        {
            if (leftIndex >= rightIndex) return;
            int middleIndex = Partition(ref array, leftIndex, rightIndex);
            QuickSortAlg(ref array, leftIndex, middleIndex - 1);
            QuickSortAlg(ref array, middleIndex + 1, rightIndex);
            return;
        }

        public string Run(string[] data)
        {
            int size = Convert.ToInt32(data[0]);
            int[] arr = data[1].Split(" ").Select(int.Parse).ToArray();

            Stopwatch sw = Stopwatch.StartNew();
            QuickSortAlg(ref arr, 0, arr.Length - 1);
            sw.Stop();
            Console.WriteLine($"QuickSort elapsed time: {sw.ElapsedMilliseconds} ms");
            return System.String.Join(" ", arr);
        }
    }
}
