using BitManipulation;

BitBoard king = new King("11");
Console.Clear();
king.Print();
king.Steps();
king.Print(11);

BitBoard knight = new Knight("27");
knight.Steps();
knight.Print(22);