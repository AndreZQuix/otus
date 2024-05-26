using SimpleSort;
using System.Diagnostics.Metrics;
using Testing;

public class Program
{
    public static void Main(string[] args)
    {
        SortingAlgorithms srt = new();
        Tester tester = new Tester(srt, $"C:\\Users\\User\\Downloads\\sorting-tests\\0.random");
        tester.RunTests();

        tester = new Tester(srt, $"C:\\Users\\User\\Downloads\\sorting-tests\\1.digits");
        tester.RunTests();

        tester = new Tester(srt, $"C:\\Users\\User\\Downloads\\sorting-tests\\2.sorted");
        tester.RunTests();

        tester = new Tester(srt, $"C:\\Users\\User\\Downloads\\sorting-tests\\3.revers");
        tester.RunTests();
    }
}