using SelectionHeapSort;
using System.Diagnostics;
using Testing;

int[] CreateRandomArray(int length)
{
    int[] array = new int[length];
    Random random = new Random();
    for(int i = 0; i < length; i++)
    {
        array[i] = random.Next(0, 100);
    }
    return array;
}

SelectionSort srt = new();
Tester tester = new(srt, "C:\\Users\\User\\Downloads\\sorting-tests\\0.random");
tester.RunTests();

tester = new(srt, "C:\\Users\\User\\Downloads\\sorting-tests\\1.digits");
tester.RunTests();

tester = new(srt, "C:\\Users\\User\\Downloads\\sorting-tests\\2.sorted");
tester.RunTests();

tester = new(srt, "C:\\Users\\User\\Downloads\\sorting-tests\\3.revers");
tester.RunTests();

for (int i = 100; i <= 1000000; i *= 10)
{
    int[] arr = CreateRandomArray(i);
    SelectionSort srt2 = new();
    Stopwatch sw = Stopwatch.StartNew();
    srt.SelectionSortAlg(ref arr);
    sw.Stop();
    Console.WriteLine($"Elapsed selection sort time for {i} elements: {sw.ElapsedMilliseconds} ms");
}