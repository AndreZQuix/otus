using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace QuickMergeSort
{
    public class QuickSort
    {
        private void Swap(ref int[] arr, int index1, int index2)
        {
            int temp = arr[index1];
            arr[index1] = arr[index2];
            arr[index2] = temp;
        }

        private int Partition(ref int[] array, int low, int high)
        {
            int pivot = array[(low + high) / 2];
            int i = low - 1;
            int j = high + 1;
            while (true)
            {
                do
                {
                    i++;
                } while (array[i] < pivot);

                do
                {
                    j--;
                } while (array[j] > pivot);

                if (i >= j)
                    return j;

                Swap(ref array, i, j);
            }
        }

        public void QuickSortAlg(ref int[] array, int low, int high)
        {
            if (low < high)
            {
                int pivotIndex = Partition(ref array, low, high);
                QuickSortAlg(ref array, low, pivotIndex - 1);
                QuickSortAlg(ref array, pivotIndex + 1, high);
            }
        }
    }
}
