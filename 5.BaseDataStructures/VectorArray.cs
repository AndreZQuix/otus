using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5.BaseDataStructures
{
    public class VectorArray<T>
    {
        T[] data;
        int size;
        int vector;
        int capacity;

        public VectorArray()
        { 
            data = [];
            size = 0;
            vector = 100;
            capacity = size + vector;
        }
        
        public VectorArray(int size, int vector = 100)
        {
            capacity = size + vector;
            data = new T[capacity]; 
            this.size = size;
            this.vector = vector;
        }

        public VectorArray(T[] data, int vector = 100) 
        {
            capacity = size + vector;
            data = new T[capacity];
            data.CopyTo(this.data, 0);
            size = data.Length;
            this.vector = vector;
        }

        public T this[int key]
        {
            get => Get(key);
            set => PutWithoutMove(key, value);
        }

        private void PutWithoutMove(int index, T value)
        {
            if(index >= size)
            {
                throw new IndexOutOfRangeException();
            }

            data[index] = value;
        }

        public int Size()
        {
            return size;
        }

        public int Vector()
        { 
            return vector;
        }

        public bool IsEmpty()
        {
            return size == 0;
        }

        public T Get(int index)
        {
            return data[index];
        }

        public void Put(int index, T value)
        {
            if(index > size)
            {
                throw new IndexOutOfRangeException();
            }

            if(size == capacity)
            {
                Resize();
            }

            T[] newData = new T[capacity];
            size++;
            for(int i = 0; i < index; i++)
            {
                newData[i] = data[i];
            }
            newData[index] = value;
            for(int i = index + 1; i < size; i++)
            {
                newData[i] = data[i - 1];
            }
            data = newData;
        }

        public void Put(T value)
        {
            if(value == null)
            {
                throw new ArgumentNullException(nameof(value));
            }

            Put(size, value);
        }

        public T Del(int index)
        {
            if(index >= size)
            {
                throw new IndexOutOfRangeException(nameof(index));
            }

            T val = data[index];
            --size;
            T[] newData = new T[capacity];
            for(int i = 0; i < size; i++)
            {
                if (i == index)
                    continue;
                newData[i] = data[i];
            }
            data = newData;
            return val;
        }

        private void Resize()
        {
            Console.WriteLine("Resize");
            capacity = size + vector;
            T[] newData = new T[capacity];
            data.CopyTo(newData, 0);
            data = newData;
        }
    }
}
