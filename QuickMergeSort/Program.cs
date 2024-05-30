using QuickMergeSort;


int[] arr = { 51, 95, 66, 72, 42, 38, 39, 41, 15 };
int N = arr.Length;
Console.WriteLine("Unsorted:");
for (int i = 0; i < N; i++)
    Console.Write(arr[i] + " ");
Console.WriteLine();

QuickSort srt = new QuickSort();
srt.QuickSortAlg(ref arr, 0, N - 1);
Console.WriteLine("Quick sort:");
for (int i = 0; i < N; i++)
    Console.Write(arr[i] + " ");
Console.WriteLine();