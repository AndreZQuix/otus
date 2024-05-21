using _5.BaseDataStructures;
using System.Collections;
using System.Diagnostics;
using System.Security.Cryptography;

namespace BaseDataStructures
{
    public class Program
    {
        public static void CheckSingleArray()
        {
            for (int i = 1000; i <= 1000000; i *= 10)
            {
                SingleArray<int> arr = new SingleArray<int>();
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Put(j);
                }
                stopwatch.Stop();
                Console.Write($"Single array put {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                stopwatch.Reset();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Del(0);
                }
                Console.Write($"Single array delete {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                SingleArray<int> arr2 = new SingleArray<int>();
                stopwatch.Reset();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr2.Put(0, j);
                }
                stopwatch.Stop();
                Console.Write($"Single array put at beginning {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                SingleArray<int> arr3 = new SingleArray<int>();
                stopwatch.Reset();
                stopwatch.Start();
                Random rnd = new Random();
                for (int j = 0; j < i; j++)
                {
                    arr3.Put(rnd.Next(0, arr3.Size()), j);
                }
                stopwatch.Stop();
                Console.Write($"Single array put at random {i}: {stopwatch.ElapsedMilliseconds} ms\n");
                Console.WriteLine();
            }
        }

        public static void CheckVectorArray()
        {
            for (int i = 1000; i <= 1000000; i *= 10)
            {
                VectorArray<int> arr = new VectorArray<int>();
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Put(j);
                }
                stopwatch.Stop();
                Console.Write($"Vector array put {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                stopwatch.Reset();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Del(0);
                }
                Console.Write($"Vector array delete {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                VectorArray<int> arr2 = new VectorArray<int>();
                stopwatch.Reset();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Put(0, j);
                }
                stopwatch.Stop();
                Console.Write($"Vector array put at beginning {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                VectorArray<int> arr3 = new VectorArray<int>();
                stopwatch.Reset();
                stopwatch.Start();
                Random rnd = new Random();
                for (int j = 0; j < i; j++)
                {
                    arr.Put(rnd.Next(0, arr3.Size()), j);
                }
                stopwatch.Stop();
                Console.Write($"Vector array put at random {i}: {stopwatch.ElapsedMilliseconds} ms\n");
                Console.WriteLine();
            }
        }

        public static void CheckFactorArray()
        {
            for (int i = 1000; i <= 1000000; i *= 10)
            {
                FactorArray<int> arr = new FactorArray<int>();
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Put(j);
                }
                stopwatch.Stop();
                Console.Write($"Factor array put {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                stopwatch.Reset();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Del(0);
                }
                Console.Write($"Factor array delete {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                FactorArray<int> arr2 = new FactorArray<int>();
                stopwatch.Reset();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Put(0, j);
                }
                stopwatch.Stop();
                Console.Write($"Factor array put at beginning {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                FactorArray<int> arr3 = new FactorArray<int>();
                stopwatch.Reset();
                stopwatch.Start();
                Random rnd = new Random();
                for (int j = 0; j < i; j++)
                {
                    arr.Put(rnd.Next(0, arr3.Size()), j);
                }
                stopwatch.Stop();
                Console.Write($"Factor array put at random {i}: {stopwatch.ElapsedMilliseconds} ms\n");
                Console.WriteLine();
            }
        }

        public static void CheckDefaultArray()
        {
            for (int i = 1000; i <= 1000000; i *= 10)
            {
                ArrayList arr = new ArrayList();
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Add(j);
                }
                stopwatch.Stop();
                Console.Write($"Default array put {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                stopwatch.Reset();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.RemoveAt(0);
                }
                Console.Write($"Default array delete {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                FactorArray<int> arr2 = new FactorArray<int>();
                stopwatch.Reset();
                stopwatch.Start();
                for (int j = 0; j < i; j++)
                {
                    arr.Insert(0, j);
                }
                stopwatch.Stop();
                Console.Write($"Default array put at beginning {i}: {stopwatch.ElapsedMilliseconds} ms\n");

                FactorArray<int> arr3 = new FactorArray<int>();
                stopwatch.Reset();
                stopwatch.Start();
                Random rnd = new Random();
                for (int j = 0; j < i; j++)
                {
                    arr.Insert(rnd.Next(0, arr3.Size()), j);
                }
                stopwatch.Stop();
                Console.Write($"Default array put at random {i}: {stopwatch.ElapsedMilliseconds} ms\n");
                Console.WriteLine();
            }
        }

        public static void Main(string[] args)
        {
            Console.WriteLine("VECTOR ARRAY");
            CheckVectorArray();

            Console.WriteLine("FACTOR ARRAY");
            CheckFactorArray();

            Console.WriteLine("DEFAULT ARRAY");
            CheckDefaultArray();

            Console.WriteLine("SINGLE ARRAY");
            CheckSingleArray();

            //int height = 4;
            //int width = 3;
            //MatrixArray<int> matrixArray = new MatrixArray<int>(height, width);
            //for(int i = 0; i < matrixArray.Height(); i++)
            //{
            //    for (int j = 0; j < matrixArray.Width(); j++)
            //    {
            //        matrixArray[i, j] = i;
            //    }
            //}

            //matrixArray[2, 1] = 5;

            //matrixArray.Put(3, 2, 11);
            //matrixArray.Del(1, 1);

            //for (int i = 0; i < matrixArray.Height(); i++)
            //{
            //    for (int j = 0; j < matrixArray.Width(); j++)
            //    {
            //        Console.Write(matrixArray[i, j] + " ");
            //    }
            //    Console.WriteLine();
            //}

            //var q = new PriorityQueue<int>();
            //q.Enqueue(1, 23);
            //q.Enqueue(1, 15);
            //q.Enqueue(3, 44);
            //Console.WriteLine("Current queue: ");
            //q.Print();

            //q.Dequeue();
            //Console.WriteLine("Current queue: ");
            //q.Print();

            //q.Enqueue(0, 100);
            //Console.WriteLine("Current queue: ");
            //q.Print();

            //q.Dequeue();
            //Console.WriteLine("Current queue: ");
            //q.Print();

            //q.Dequeue();
            //Console.WriteLine("Current queue: ");
            //q.Print();
        }
    }
}