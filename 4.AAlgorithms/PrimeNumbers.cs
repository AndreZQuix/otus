using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4.AAlgorithms
{
    public class PrimeNumbers
    {
        public static bool IsPrime(int n)
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

        public static int PrimeNumbersCount(int amount)
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
