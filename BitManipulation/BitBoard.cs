using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BitManipulation
{
    public class BitBoard
    {
        protected ulong bb = 0;
        public virtual void Steps() { }
        public BitBoard(ulong mask)
        {
            bb = mask;
        }

        public BitBoard(string s)
        {
            int point;
            s = s.ToUpper();
            try
            {
                point = int.Parse(s);
            }
            catch
            {
                try
                {
                    point = (s[0] - 'A') + (s[1] - '1') * 8;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                    return;
                }
            }
            bb = (ulong)1 << point;
        }

        public void Print(int row = 0)
        {
            Console.SetCursorPosition(0, row);
            bool invertColor = false;
            for(int i = 8; i > 0; i--)
            {
                Console.BackgroundColor = ConsoleColor.White;
                Console.ForegroundColor = ConsoleColor.Black;
                Console.Write(i.ToString() + ":  ");
                for(int j = 0; j < 8; j++)
                {
                    Console.ForegroundColor = ConsoleColor.Black;
                    if(invertColor)
                    {
                        Console.BackgroundColor = ConsoleColor.DarkGray;
                    }
                    else
                    {
                        Console.BackgroundColor = ConsoleColor.White;
                    }

                    ulong b = (ulong)1 << ((i - 1) * 8 + j);
                    if ((bb & b) > 0)
                    {
                        Console.BackgroundColor = ConsoleColor.Red;
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    Console.Write(" " + ((i - 1) * 8 + j).ToString().PadLeft(2, ' ') + " ");
                    invertColor = !invertColor;
                }
                invertColor = !invertColor;
                Console.WriteLine();
            }
            Console.BackgroundColor = ConsoleColor.White;
            Console.Write("     ");
            for(int i = 0; i < 8; i++)
            {
                Console.Write((char)('A' + i) + "   ");
            }
            Console.WriteLine();
            Console.SetCursorPosition(0, 10 + row);
        }
    }

    public class King : BitBoard
    {
        public King(string s) : base(s) { }
        public King(ulong mask) : base(mask) { }
        public override void Steps()
        {
            ulong mask = (bb & 0x7F7F7F7F7F7F7F7F) << 1;
            mask |= (bb & 0xFEFEFEFEFEFEFEFE) >> 1;
            mask |= (bb << 8);
            mask |= bb >> 8;
            mask |= (bb & 0xFEFEFEFEFEFEFEFE) >> 9;
            mask |= (bb & 0xFEFEFEFEFEFEFEFE) << 7;
            mask |= (bb & 0x7F7F7F7F7F7F7F7F) << 9;
            mask |= (bb & 0x7F7F7F7F7F7F7F7F) >> 7;
            bb = mask;
        }
    }

    public class Knight : BitBoard
    {
        public Knight(string s) : base(s) { }
        public Knight(ulong mask) : base(mask) { }
        public override void Steps()
        {
            ulong nA = 0xFEFEFEFEFEFEFEFE;
            ulong nAB = 0xFCFCFCFCFCFCFCFC;
            ulong nH = 0x7F7F7F7F7F7F7F7F;
            ulong nGH = 0x3F3F3F3F3F3F3F3F;

            ulong mask = nGH & (bb << 6 | bb >> 10)
             | nH & (bb << 15 | bb >> 17)
             | nA & (bb << 17 | bb >> 15)
             | nAB & (bb << 10 | bb >> 6);
            bb = mask;
        }
    }
}
