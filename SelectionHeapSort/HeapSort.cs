using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Testing;

namespace SelectionHeapSort
{
    public class HeapSort : ITask
    {
        private void Swap(ref int[] arr, int index1, int index2)
        {
            int temp = arr[index1];
            arr[index1] = arr[index2];
            arr[index2] = temp;
        }

        public void HeapSortAlg(ref int[] arr)
        {
            int N = arr.Length;

            for (int i = N / 2 - 1; i >= 0; i--)
                Heapify(ref arr, N, i);

            for (int i = N - 1; i > 0; i--)
            {
                Swap(ref arr, i, 0);
                Heapify(ref arr, i, 0);
            }
        }

        void Heapify(ref int[] arr, int N, int i)
        {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < N && arr[l] > arr[largest])
                largest = l;

            if (r < N && arr[r] > arr[largest])
                largest = r;

            if (largest != i)
            {
                Swap(ref arr, i, largest);
                Heapify(ref arr, N, largest);
            }
        }

        public string Run(string[] data)
        {
            int size = Convert.ToInt32(data[0]);
            int[] arr = data[1].Split(" ").Select(int.Parse).ToArray();
            Stopwatch sw = Stopwatch.StartNew();
            HeapSortAlg(ref arr);
            sw.Stop();
            Console.WriteLine($"Heap sort elapsed time: {sw.ElapsedMilliseconds} ms");
            return String.Join(" ", arr);
        }
    }
}
