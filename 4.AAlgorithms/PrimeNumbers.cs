using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using Testing;

namespace PrimeNumbersAlg
{
    public class PrimeNumbers : ITask
    {
        public string Run(string[] data)
        {
            int a = Convert.ToInt32(data[0]);
            int res = PrimeNumbersCount(a);
            return res.ToString();
        }

        public bool IsPrime(int n)
        {
            if(n == 2 || n == 3) return true;
            if(n % 2 == 0 || n % 3 == 0) return false;
            for(int i = 2; i < n; i++) 
            {
                if (n % i == 0)
                    return false;
            }
            return true;
        }

        public int PrimeNumbersCount(int amount)
        {
            int count = 0;
            for(int i = 2; i <= amount; i++)
            {
                if (IsPrime(i))
                    count++;
            }
            return count;
        }
    }
}
