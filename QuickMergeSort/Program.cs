using System.Diagnostics.Metrics;
using Testing;
using QuickMergeSort;

public class Program
{
    public static void Main(string[] args)
    {
        MergeSort srt2 = new();
        Tester tester2 = new Tester(srt2, $"C:\\Users\\User\\Downloads\\sorting-tests\\0.random");
        tester2.RunTests();

        tester2 = new Tester(srt2, $"C:\\Users\\User\\Downloads\\sorting-tests\\1.digits");
        tester2.RunTests();

        tester2 = new Tester(srt2, $"C:\\Users\\User\\Downloads\\sorting-tests\\2.sorted");
        tester2.RunTests();

        tester2 = new Tester(srt2, $"C:\\Users\\User\\Downloads\\sorting-tests\\3.revers");
        tester2.RunTests();
    }
}