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

static int[] ShellSort(int[] A)
{
    Stopwatch sw = Stopwatch.StartNew();
    for (int gap = A.Length/2; gap > 0; gap /= 2)
    {
        for(int j = gap; j < A.Length; j++)
        {
            for(int i = j; i >= gap; i -= gap)
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

int size = 10;
int[] arr = new int[size];
Random rnd = new();
Console.WriteLine("Unsorted: ");
for(int i = 0; i < size; i++)
{
    arr[i] = rnd.Next(0, size);
    Console.Write($"{arr[i]} ");
}
Console.WriteLine("\n");

Console.WriteLine("Bubble sorted: ");
int[] res1 = BubbleSort(arr);
for (int i = 0; i < res1.Length; i++)
{
    Console.Write($"{res1[i]} ");
}
Console.WriteLine("\n");

Console.WriteLine("Insertion sorted: ");
int[] res2 = InsertionSort(arr);
for (int i = 0; i < res2.Length; i++)
{
    Console.Write($"{res2[i]} ");
}
Console.WriteLine("\n");

Console.WriteLine("Shell sorted: ");
int[] res3 = ShellSort(arr);
for (int i = 0; i < res3.Length; i++)
{
    Console.Write($"{res3[i]} ");
}
Console.WriteLine("\n");