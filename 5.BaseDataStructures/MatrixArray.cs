using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5.BaseDataStructures
{
    public class MatrixArray<T>
    {
        T[,] data;
        int height;
        int width;

        public MatrixArray()
        {
            data = new T[0,0];
            height = 0;
            width = 0;
        }
        
        public MatrixArray(int height, int width)
        {
            data = new T[height, width];
            this.height = height;
            this.width = width;
        }

        public MatrixArray(T[,] data) 
        { 
            this.data = data;
            height = data.GetLength(0);
            width = data.GetLength(1);
        }

        public T this[int key1, int key2]
        {
            get => Get(key1, key2);
            set => PutWithoutMove(key1, key2, value);
        }

        private void PutWithoutMove(int index1, int index2, T value)
        {
            if (index1 >= height || index2 >= width)
            {
                Resize();
            }

            data[index1, index2] = value;
        }

        public int Height()
        {
            return height;
        }

        public int Width()
        {
            return width;
        }

        public bool IsEmpty()
        {
            return height == 0 || width == 0;
        }

        public T Get(int index1, int index2)
        {
            return data[index1, index2];
        }

        public void Put(int index1, int index2, T value)
        {
            if (index1 >= height || index2 >= width)
            {
                Resize();
                data[index1, index2] = value;
                return;
            }

            T[,] newData = new T[height + 1, width + 1];
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    newData[i, j] = data[i, j];
                }
            }
            newData[index1, index2] = value;
            newData[index1 + 1, index2 + 1] = data[index1, index2];
            height++;
            width++;
            data = newData;
        }

        public void Put(T value)
        {
            if(value == null)
            {
                throw new ArgumentNullException(nameof(value));
            }

            Put(height, width, value);
        }

        public T Del(int index1, int index2)
        {
            if (index1 >= height || index2 >= width)
            {
                throw new IndexOutOfRangeException("Wrong indexes");
            }

            T val = data[index1, index2];
            T[,] newData = new T[height, width];
            for(int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (i == index1 && j == index2)
                        continue;
                    newData[i, j] = data[i, j];
                }
            }
            data = newData;
            return val;
        }

        private void Resize()
        {

            T[,] newData = new T[height + 1, width + 1];
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    newData[i, j] = data[i, j];
                }
            }
            data = newData;
            height++;
            width++;
        }
    }
}
