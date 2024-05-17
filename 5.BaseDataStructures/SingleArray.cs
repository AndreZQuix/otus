using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5.BaseDataStructures
{
    public class SingleArray<T>
    {
        T[] data;
        int size;

        public SingleArray()
        { 
            data = [];
            size = 0;
        }
        
        public SingleArray(int size)
        {
            data = new T[size]; 
            this.size = size;
        }

        public SingleArray(T[] data) 
        { 
            this.data = data;
            size = data.Length;
        }

        public T this[int key]
        {
            get => Get(key);
            set => PutWithoutMove(key, value);
        }

        private void PutWithoutMove(int index, T value)
        {
            if (index >= size)
            {
                Resize();
            }

            data[index] = value;
        }

        public int Size()
        {
            return size;
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
            if (index >= size)
            {
                Resize();
                data[index] = value;
                return;
            }

            T[] newData = new T[size + 1];
            for (int i = 0; i < index; i++)
            {
                newData[i] = data[i];
            }
            newData[index] = value;
            for(int i = index + 1; i < size; i++)
            {
                newData[i] = data[i];
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
            T[] newData = new T[size - 1];
            for(int i = 0; i < newData.Length; i++)
            {
                if (i == index)
                    continue;
                newData[i] = data[i];
            }
            data = newData;
            size--;
            return val;
        }

        private void Resize()
        {
            ++size;
            T[] newData = new T[size];
            data.CopyTo(newData, 0);
            data = newData;
        }
    }
}
