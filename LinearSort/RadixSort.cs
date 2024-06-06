using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinearSort
{
    public class RadixSort
    {
        public void Sort(ref int[] arr)
        {
            const int _base = 10;
            const int digits = 3;
            int[] T = new int[arr.Length];
            int r = 1;
            for(int d = 0; d < digits; d++)
            {
                int[] radix = new int[10];
                for(int i = 0; i < arr.Length; i++)
                {
                    int dig = arr[i] / r % _base;
                    radix[dig]++;
                }

                int z = 0;
                for(int i = 0; i < _base; i++)
                {
                    z += radix[i];
                    radix[i] = z;
                }

                for(int i = arr.Length - 1; i >= 0; i--)
                {
                    int dig = arr[i] / r % _base;
                    radix[dig]--;
                    T[radix[dig]] = arr[i];
                }

                for(int i = 0; i < arr.Length; i++)
                {
                    arr[i] = T[i];
                }

                r *= _base;
            }
        }
    }
}
