using System;
using System.Linq;

namespace EuclidsDivisorAlgorithm
{
    class CommonDivisorAlgorithm
    {
        static void Main(string[] args)
        {
            int x, y = 0;

            Console.WriteLine("Enter your first number: ");
            x = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter your second number: ");
            y = int.Parse(Console.ReadLine());

            Console.WriteLine("You have entered " + x + " and " + y + "\nThe common divisor of these numbers is: " + GCD(x, y));
        }

        static int GCD(int x, int y)
        {
            if(y == 0)
            {
                return x;
            }

            int r = x % y;

            return GCD(y, r);
        }
    }
}
