using FiboAlg;
using PowerAlg;
using PrimeNumbersAlg;
using Testing;

public class Program
{
    public static void Main(string[] args)
    {
        PowerB powerB = new PowerB();
        Tester tester = new Tester(powerB, $"C:/Users/User/Downloads/3.Power");
        tester.RunTests();

        Fibonacci fibo = new Fibonacci();
        Tester tester2 = new Tester(fibo, $"C:/Users/User/Downloads/4.Fibo");
        tester2.RunTests();

        PrimeNumbers pn = new PrimeNumbers();
        Tester tester3 = new Tester(pn, $"C:/Users/User/Downloads/5.Primes");
        tester3.RunTests();
    }
}