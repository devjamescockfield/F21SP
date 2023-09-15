using System;

namespace MatrixMultiplication
{
    class MatrixMultiplication
    {
        static void Main(string[] args)
        {
            int[,] matrix1 = new int[3, 3];
            int[,] matrix2 = new int[3, 3];
            int[,] answer = new int[3, 3];
            int i, j;

            Console.WriteLine("Enter your first matrix of size 3x3: ");
            Console.WriteLine(" -------------------------- ");

            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    Console.Write("element - [{0},{1}] : ", i, j);
                    matrix1[i, j] = Convert.ToInt32(Console.ReadLine());
                }
            }

            Console.WriteLine("Enter your second matrix of size 3x3: ");
            Console.WriteLine(" -------------------------- ");

            for (i=0; i<3; i++)
            {
                for (j=0; j<3; j++)
                {
                    Console.Write("element - [{0},{1}] : ", i, j);
                    matrix2[i, j] = Convert.ToInt32(Console.ReadLine());
                }
            }

            Console.WriteLine("Multiplying Matrices...");
            answer = MultiplyMatrices(matrix1, matrix2);
            if(answer == null)
            {
                Console.WriteLine("ERROR: Matrices couldn't be multiplied.");
            } else
            {
                Console.WriteLine("The multiplied matrix result is: ");
                for(i=0; i<3; i++)
                {
                    Console.WriteLine("\n");
                    for(j=0; j<3; j++)
                    {
                        Console.WriteLine("element - [{0}, {1}] = {2}\t", i, j, answer[i, j]);
                    }
                }
            }
            
        }

        private static int[,] MultiplyMatrices(int[,] matrix1, int[,] matrix2)
        {
            int rMatrix1 = matrix1.GetLength(0);
            int cMatrix1 = matrix1.GetLength(1);
            int rMatrix2 = matrix2.GetLength(0);
            int cMatrix2 = matrix2.GetLength(1);

            if (cMatrix1 != rMatrix2)
            {
                Console.WriteLine("Matrices can't be multiplied");
                return null;
            }
            else
            {
                int temp = 0;
                int[,] result = new int[rMatrix1, cMatrix2];

                for (int i = 0; i < rMatrix1; i++)
                {
                    for (int j = 0; j < cMatrix2; j++)
                    {
                        temp = 0;
                        for (int k = 0; k < cMatrix1; k++)
                        {
                            temp = matrix1[i, k] * matrix2[k, j];
                        }
                        result[i, j] = temp;
                    }
                }
                return result;
            }
        }
    }
}
