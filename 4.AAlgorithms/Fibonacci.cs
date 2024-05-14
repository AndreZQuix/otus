using Testing;

namespace FiboAlg
{
    public class Fibonacci : ITask
    {
        public string Run(string[] data)
        {
            double a = Convert.ToInt32(data[0]);
            double res = FibonacciIter(a);
            return res.ToString();
        }

        public static double FibonacciRec(double a)
        {
            if (a == 0 || a == 1) return a;
            return FibonacciRec(a - 1) + FibonacciRec(a - 2);
        }

        public static double FibonacciIter(double a)
        {
            double f0 = 0;
            double f1 = 1;
            double f2 = 0;
            for(int i = 2; i < a; i++)
            {
                f2 = f0 + f1;
                f0 = f1;
                f1 = f2;
            }
            return f2;
        }
    }
}
