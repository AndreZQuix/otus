using System.Diagnostics;

static void Swap(ref int[] arr, int index1, int index2)
{
    int k = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = k;
}

static int[] BubbleSort(int[] A)
{
    Stopwatch sw = Stopwatch.StartNew();
    for(int i = 0; i < A.Length; i++)
    {
        for(int j = 0; j < A.Length - 1; j++)
        {
            if (A[j] >= A[j + 1])
            {
                Swap(ref A, j, j + 1);
            }
        }
    }
    sw.Stop();
    Console.WriteLine("Elapsed time: " + sw.ElapsedMilliseconds + " ms");
    return A;
}

static int[] BubbleSortOptimized(int[] A)
{
    Stopwatch sw = Stopwatch.StartNew();
    bool swapped = false;
    for (int i = 0; i < A.Length; i++)
    {
        for (int j = 0; j < A.Length - i - 1; j++)
        {
            if (A[j] >= A[j + 1])
            {
                Swap(ref A, j, j + 1);
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
    sw.Stop();
    Console.WriteLine("Elapsed time: " + sw.ElapsedMilliseconds + " ms");
    return A;
}

static int[] InsertionSort(int[] A)
{
    Stopwatch sw = Stopwatch.StartNew();
    for (int i = 1; i < A.Length; i++)
    {
        int index = i - 1;
        while(index >= 0)
        {
            if (A[index] <= A[index + 1])
                break;
            Swap(ref A, index, index + 1);
            index--;
        }
    }
    sw.Stop();
    Console.WriteLine("Elapsed time: " + sw.ElapsedMilliseconds + " ms");
    return A;
}

static int[] ShellSort(int[] A, int gapDiv)
{
    Stopwatch sw = Stopwatch.StartNew();
    for (int gap = A.Length / gapDiv; gap > 0; gap /= gapDiv)
    {
        for (int j = gap; j < A.Length; j++)
        {
            for (int i = j; i >= gap; i -= gap)
            {
                if (A[i - gap] <= A[i])
                    break;
                Swap(ref A, i - gap, i);
            }
        }
    }
    sw.Stop();
    Console.WriteLine("Elapsed time: " + sw.ElapsedMilliseconds + " ms");
    return A;
}

int size = 100000;
int[] arr = new int[size];
Random rnd = new();
//Console.WriteLine("Unsorted: ");
//for(int i = 0; i < size; i++)
//{
//    arr[i] = rnd.Next(0, size);
//    Console.Write($"{arr[i]} ");
//}
//Console.WriteLine("\n");

//Console.WriteLine("Bubble sorted: ");
//BubbleSort(arr);

//Console.WriteLine("Bubble sorted optimized: ");
//BubbleSortOptimized(arr);

//Console.WriteLine("Insertion sorted: ");
//InsertionSort(arr);
//for (int i = 0; i < res2.Length; i++)
//{
//    Console.Write($"{res2[i]} ");
//}
//Console.WriteLine("\n");

Console.WriteLine("Shell sorted: ");
ShellSort(arr, 2);

//for (int i = 0; i < res3.Length; i++)
//{
//    Console.Write($"{res3[i]} ");
//}
//Console.WriteLine("\n");