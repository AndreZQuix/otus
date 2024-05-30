using QuickMergeSort;
using System.Diagnostics;

static int[] CreateRandomArray(int size)
{
    int[] array = new int[size];
    Random random = new Random();
    for(int i = 0; i < size; i++)
    {
        array[i] = random.Next();
    }
    return array;
}

for(int i = 100; i <= 1000000; i *= 10)
{
    int[] arr = CreateRandomArray(i);
    QuickSort srt = new();
    Stopwatch sw = Stopwatch.StartNew();
    srt.QuickSortAlg(ref arr, 0, arr.Length - 1);
    sw.Stop();
    Console.WriteLine($"Quick sort {i} elements: {sw.ElapsedMilliseconds} ms");
}

Console.WriteLine();

for (int i = 100; i <= 1000000; i *= 10)
{
    int[] arr = CreateRandomArray(i);
    MergeSort srt = new();
    Stopwatch sw = Stopwatch.StartNew();
    srt.MergeSortAlg(ref arr, 0, arr.Length - 1);
    sw.Stop();
    Console.WriteLine($"Merge sort {i} elements: {sw.ElapsedMilliseconds} ms");
}
