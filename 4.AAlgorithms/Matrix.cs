﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace _4.AAlgorithms
{
    public class Matrix
    {
        private readonly BigInteger[,] data;
        public int Height => data.GetUpperBound(0) + 1;
        public int Width => data.GetUpperBound(1) + 1;

        public ref BigInteger this[int row, int column] => ref data[row, column];

        public Matrix(int h, int w, BigInteger d)
        {
            data = new BigInteger[h, w];
            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    data[i, j] = d;
                }
            }
        }

        public Matrix(BigInteger[,] data)
        {
            this.data = data;
        }

        public void Print()
        {
            for (int i = 0; i < Height; i++)
            {
                for (int j = 0; j < Width; j++)
                {
                    Console.Write($"{data[i, j]} ");
                }
                Console.WriteLine();
            }
        }

        public bool IsMultiplyPossible(Matrix matrix)
        {
            return Width == matrix.Height;
        }

        public static Matrix operator*(Matrix m1, Matrix m2)
        {
            return m1.Multiply(m2);
        }

        public Matrix Multiply(Matrix matrix)
        {
            if(!IsMultiplyPossible(matrix))
            {
                Console.WriteLine("Unable to multiply");
                return new Matrix(Height, Width, -1);
            }

            Matrix result = new Matrix(Height, matrix.Width, 0);
            for(int i = 0; i < Height; i++)
            {
                for(int j = 0; j < matrix.Width; j++)
                {
                    for(int k = 0; k < matrix.Height; k++)
                    {
                        result[i,j] += this[i, k] * matrix[k, j];
                    }
                }
            }
            return result;
        }

        public Matrix Power(BigInteger power)
        {
            if(power == 0) return new Matrix(Height, Width, 0);

            if (power == 1) return this;
            Matrix result = this;
            if (power % 2 == 0)
            {
                Matrix x = Power(power / 2);
                return x * x;
            }
            return result * Power(power - 1);
        }
    }
}
