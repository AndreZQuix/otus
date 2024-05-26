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

            Console.WriteLine();
            for(int j = 0; j < A.Length; j++)
            {
                Console.Write(A[j]);
            }
        }
    }
    sw.Stop();
    Console.WriteLine("Elapsed time: " + sw.ElapsedMilliseconds + " ms");
    return A;
}

static int[] InsertionSortShift(int[] A)
{
    Stopwatch sw = Stopwatch.StartNew();
    for (int i = 1; i < A.Length; i++)
    {
        int index = i;
        int r = A[i];
        while (index > 0)
        {
            if (A[index - 1] <= r)
                break;
            A[index] = A[index - 1];
            index--;
        }
        A[index] = r;
    }
    sw.Stop();
    Console.WriteLine("Elapsed time: " + sw.ElapsedMilliseconds + " ms");
    return A;
}

static int BinarySearch(int[] A, int key, int left, int right)
{
    if (left > right)
        return left;
    int mid = (left + right) / 2;
    if (key < A[mid])
        return BinarySearch(A, key, left, mid - 1);
    return BinarySearch(A, key, mid + 1, right);
}

static int[] InsertionSortBinarySearch(int[] A)
{
    Stopwatch sw = Stopwatch.StartNew();
    for (int i = 1; i < A.Length; i++)
    {
        int r = A[i];
        int pos = BinarySearch(A, r, 0, i - 1);
        for(int j = i - 1; j >= pos; j--)
        {
            A[j + 1] = A[j];
        }
        A[pos] = r;
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

int size = 10;
int[] arr = new int[size];
Random rnd = new();
Console.WriteLine("Unsorted: ");
for (int i = 0; i < size; i++)
{
    arr[i] = rnd.Next(0, size);
    Console.Write($"{arr[i]} ");
}
Console.WriteLine("\n");

//Console.WriteLine("Bubble sorted: ");
//BubbleSort(arr);

//Console.WriteLine("Bubble sorted optimized: ");
//BubbleSortOptimized(arr);

//Console.WriteLine("Insertion sorted: ");
//InsertionSort(arr);

Console.WriteLine("Insertion sorted with binary search: ");
var res2 = InsertionSortBinarySearch(arr);
for (int i = 0; i < res2.Length; i++)
{
    Console.Write($"{res2[i]} ");
}
Console.WriteLine("\n");

//Console.WriteLine("Shell sorted: ");
//ShellSort(arr, 2);

//for (int i = 0; i < res3.Length; i++)
//{
//    Console.Write($"{res3[i]} ");
//}
//Console.WriteLine("\n");