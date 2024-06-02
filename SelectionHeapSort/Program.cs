using SelectionHeapSort;
using System.Diagnostics;

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

for (int i = 100; i <= 1000000; i *= 10)
{
    int[] arr = CreateRandomArray(i);
    SelectionSort srt = new();
    Stopwatch sw = Stopwatch.StartNew();
    srt.SelectionSortAlg(ref arr);
    sw.Stop();
    Console.WriteLine($"Elapsed selection sort time for {i} elements: {sw.ElapsedMilliseconds} ms");
}