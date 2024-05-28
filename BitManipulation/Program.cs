using BitManipulation;

BitBoard king = new King("11");
Console.Clear();
king.Steps();
king.Print();

BitBoard knight = new Knight("27");
knight.Steps();
knight.Print(11);

Console.SetCursorPosition(0, 22);
Console.BackgroundColor = ConsoleColor.Black;
Console.ForegroundColor = ConsoleColor.White;

static int GetOnesBit_rev1(int num)
{
    int count = 0;
    while (num > 0)
    {
        if ((num & 0x01) > 0)
        {
            count++;
        }
        num >>= 1;
    }
    return count;
}

static int GetOnesBit_rev2(int num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num &= (num - 1);
    }
    return count;
}

Console.WriteLine(GetOnesBit_rev1(255));
Console.WriteLine(GetOnesBit_rev2(255));