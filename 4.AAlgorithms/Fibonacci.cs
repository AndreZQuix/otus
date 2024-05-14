using System.Numerics;
using Testing;

namespace FiboAlg
{
    public class Fibonacci : ITask
    {
        public string Run(string[] data)
        {
            BigInteger a = BigInteger.Parse(data[0]);
            BigInteger res = FibonacciIter(a);
            return res.ToString();
        }

        public BigInteger FibonacciRec(BigInteger a)
        {
            if (a == 0 || a == 1) return a;
            return FibonacciRec(a - 1) + FibonacciRec(a - 2);
        }

        public BigInteger FibonacciIter(BigInteger a)
        {
            BigInteger f1 = 1;
            BigInteger f2 = 1;
            BigInteger f3 = 0;
            for(int i = 2; i < a; i++)
            {
                f3 = f1 + f2;
                f1 = f2;
                f2 = f3;
            }
            return f3;
        }

        public int FibonacciF(int a)
        {
            double sqrt = Math.Sqrt(5);
            double cst = (1 + sqrt) / 2;
            double result = (Math.Pow(cst, a) / sqrt) + 0.5;
            return Convert.ToInt32(Math.Round(result, 0, MidpointRounding.ToZero));
        }
    }
}
