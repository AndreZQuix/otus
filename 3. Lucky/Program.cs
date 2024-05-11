public class Program
{
    public static long Lucky(int N)
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
    public static void Main(string[] args)
    {
        Console.WriteLine(Lucky(2));
    }
}