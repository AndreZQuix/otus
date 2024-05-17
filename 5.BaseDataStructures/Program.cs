using _5.BaseDataStructures;
using System.Security.Cryptography;

namespace BaseDataStructures
{
    public class Program
    {
        public static void Main(string[] args)
        {
            //SingleArray<int> arr = new SingleArray<int>(10);
            //for (int i = 0; i < 10; i++)
            //{
            //    arr[i] = i + 100;
            //}

            //arr.Put(arr.Size());

            //for (int i = 0; i < arr.Size(); i++)
            //{
            //    Console.WriteLine(arr.Get(i));
            //}

            //VectorArray<int> vecArr = new VectorArray<int>(10, 5);
            //for (int i = 0; i < 10; i++)
            //{
            //    vecArr[i] = i;
            //}

            //for (int i = 0; i < 5; i++)
            //{
            //    vecArr.Put(5, i);
            //}

            //for(int i = 0; i < vecArr.Size(); i++)
            //{
            //    Console.WriteLine(vecArr[i]);
            //}

            //Console.WriteLine(vecArr.Size());

            FactorArray<int> facArr = new FactorArray<int>(10, 2);
            for (int i = 0; i < 10; i++)
            {
                facArr[i] = i;
            }

            for (int i = 0; i < 5; i++)
            {
                facArr.Put(i);
            }

            facArr.Put(facArr.Size(), 22);

            for (int i = 0; i < facArr.Size(); i++)
            {
                Console.WriteLine(facArr[i]);
            }

            Console.WriteLine(facArr.Size());


        }
    }
}