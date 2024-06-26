﻿using LinearSort;
using System.Diagnostics;

int[] CreateRandomArray(int length)
{
    int[] array = new int[length];
    Random random = new Random();
    for (int i = 0; i < length; i++)
    {
        array[i] = random.Next(0, 999);
    }
    return array;
}

for (int i = 100; i <= 1000000; i *= 10)
{
    int[] arr = CreateRandomArray(i);
    BuckerSort srt = new();
    Stopwatch sw = Stopwatch.StartNew();
    srt.Sort(ref arr, 999);
    sw.Stop();
    Console.WriteLine($"Elapsed bucket sort time for {i} elements: {sw.ElapsedMilliseconds} ms");
}

for (int i = 100; i <= 1000000; i *= 10)
{
    int[] arr = CreateRandomArray(i);
    CountSort srt = new();
    Stopwatch sw = Stopwatch.StartNew();
    srt.Sort(ref arr);
    sw.Stop();
    Console.WriteLine($"Elapsed count sort time for {i} elements: {sw.ElapsedMilliseconds} ms");
}

for (int i = 100; i <= 1000000; i *= 10)
{
    int[] arr = CreateRandomArray(i);
    RadixSort srt = new();
    Stopwatch sw = Stopwatch.StartNew();
    srt.Sort(ref arr);
    sw.Stop();
    Console.WriteLine($"Elapsed radix sort time for {i} elements: {sw.ElapsedMilliseconds} ms");
}