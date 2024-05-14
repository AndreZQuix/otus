using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Testing;

namespace _3._Lucky
{
    internal class Lucky : ITask
    {
        public string Run(string[] data)
        {
            int N = Convert.ToInt32(data[0]);
            long count = LuckyN(N);
            return count.ToString();
        }

        public long LuckyN(int N)
        {
            long count = 0;
            Next(N, 0, 0);
            return count;

            void Next(int n, int sumA, int sumB)
            {
                if (n == 0)
                {
                    if (sumA == sumB)
                    {
                        count++;
                    }
                    return;
                }
                for (int a = 0; a <= 9; a++)
                    for (int b = 0; b <= 9; b++)
                        Next(n - 1, sumA + a, sumB + b);
            }
        }
    }
}
