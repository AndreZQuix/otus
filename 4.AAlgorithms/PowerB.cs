using System.Globalization;
using Testing;

namespace PowerAlg
{
    public class PowerB : ITask
    {
        public string Run(string[] data)
        {
            double a = Double.Parse(data[0], CultureInfo.InvariantCulture);
            double p = Double.Parse(data[1], CultureInfo.InvariantCulture);
            double res = Power(a, p);
            double result = Math.Round(res, MidpointRounding.AwayFromZero);
            NumberFormatInfo nfi = new NumberFormatInfo();
            nfi.NumberDecimalSeparator = ".";
            return result.ToString(nfi);
        }

        public double Power(double a, double p)
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
