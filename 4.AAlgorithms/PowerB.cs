using Testing;

namespace PowerAlg
{
    public class PowerB : ITask
    {
        public string Run(string[] data)
        {
            double a = Convert.ToInt32(data[0]);
            double p = Convert.ToInt32(data[1]);
            double res = Power(a, p);
            return res.ToString();
        }

        public static double Power(double a, double p)
        {
            if (p == 0) return 1.0;
            if (p == 1) return a;
            if (p % 2 == 0)
            {
                double x = Power(a, p / 2);
                return x * x;
            }
            return a * Power(a, p - 1);
        }
    }
}
