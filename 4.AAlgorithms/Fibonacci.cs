using _4.AAlgorithms;
using System.Numerics;
using Testing;

namespace FiboAlg
{
    public class Fibonacci : ITask
    {
        public string Run(string[] data)
        {
            BigInteger a = BigInteger.Parse(data[0]);
            BigInteger res = FibonacciMatrix(a);
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

        public BigInteger FibonacciMatrix(BigInteger a)
        {
            BigInteger[,] d = new BigInteger[2, 2];
            d[0, 0] = 1;
            d[1, 0] = 1;
            d[0, 1] = 1;
            d[1, 1] = 0;
            Matrix m = new Matrix(d);
            return m.Power(a)[0, 1];
        }
    }
}
