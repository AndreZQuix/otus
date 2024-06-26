﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Testing;

namespace SelectionHeapSort
{
    public class SelectionSort : ITask
    {
        private void Swap(ref int[] arr, int index1, int index2)
        {
            int temp = arr[index1];
            arr[index1] = arr[index2];
            arr[index2] = temp;
        }

        public void SelectionSortAlg(ref int[] arr)
        {
            for (int i = 0; i < arr.Length - 1; ++i)
            {
                int minIndex = i;
                for (int j = i + 1; j < arr.Length; ++j)
                {
                    if (arr[j] < arr[minIndex])
                        minIndex = j;
                }
                Swap(ref arr, minIndex, i);
            }
        }

        public string Run(string[] data)
        {
            int size = Convert.ToInt32(data[0]);
            int[] arr = data[1].Split(" ").Select(int.Parse).ToArray();
            Stopwatch sw = Stopwatch.StartNew();
            SelectionSortAlg(ref arr);
            sw.Stop();
            Console.WriteLine($"Selection sort elapsed time: {sw.ElapsedMilliseconds} ms");
            return String.Join(" ", arr);
        }
    }
}
