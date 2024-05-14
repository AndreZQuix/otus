using _3._Lucky;
using Testing;

public class Program
{
    public static void Main(string[] args)
    {
        Lucky lucky = new Lucky();
        Tester tester = new Tester(lucky, $"C:/Users/User/Downloads/1.Tickets");
        tester.RunTests();
    }
}