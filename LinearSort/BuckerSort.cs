using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinearSort
{
    public class BuckerSort
    {
        public int GetMax(int[] arr, int knownMax = -1)
        {
            if (knownMax >= 0)  // если максимальное число уже известно
                return knownMax;

            int max = arr[0];
            for(int i = 0; i < arr.Length; i++)
            {
                if (arr[i] > max)
                    max = arr[i];
            }
            return max;
        }

        public void Sort(ref int[] arr, int knownMax = -1)
        {
            const int bucketsCount = 10;
            IList<int>[] buckets = new List<int>[bucketsCount];

            int max = GetMax(arr, knownMax);
            int j;
            for (int i = 0; i < arr.Length; i++)
            {
                int m = (arr[i] / (max + 1)) * bucketsCount;
                //int m = arr[i] * bucketsCount / 1000;
                if (buckets[m] == null)
                {
                    buckets[m] = new List<int>();
                }

                if (buckets[m].Count == 0)
                {
                    buckets[m].Add(arr[i]);
                }
                else
                {
                    j = 0;
                    while((j < buckets[m].Count) && (buckets[m][j] < arr[i]))
                    {
                        j++;
                    }
                    buckets[m].Insert(j, arr[i]);
                }
            }

            j = 0;
            for(int i = 0; i < buckets.Length; i++)
            {
                if (buckets[i] == null)
                    continue;

                for(int k = 0; k < buckets[i].Count; k++)
                {
                    arr[j++] = buckets[i][k];
                }
            }
        }
    }
}
