using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinearSort
{
    public class CountSort
    {
        public int GetMax(int[] arr)
        {
            int max = arr[0];
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] > max)
                    max = arr[i];
            }
            return max;
        }

        public void Sort(ref int[] arr)
        {
            int max = GetMax(arr);
            int[] T = new int[max + 1];
            int[] Z = new int[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                T[arr[i]]++;
            }

            int z = 0;
            for (int i = 0; i <= max; i++)
            {
                z += T[i];
                T[i] = z;
            }

            for (int i = arr.Length - 1; i >= 0; i--)
            {
                T[arr[i]]--;
                Z[T[arr[i]]] = arr[i];
            }

            for(int i = 0; i < arr.Length; ++i)
            {
                arr[i] = Z[i];
            }
        }
    }
}
