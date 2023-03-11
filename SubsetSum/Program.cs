using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Running;
using MyBenchMarks;
public class Test
{
    public static void Main()
    {
        BenchmarkRunner.Run<Test>(new MyConfig(x => Math.Pow(3,x)*x, x => 1));
    }

    private int[] data;
    [Params(11, 12, 13, 14, 15,16)]
    public int N;

    [GlobalSetup]
    public void MakeSetup()
    {
        // maybe you need an ***INITIAL*** setup.
        data = new int[N];
        for (int i = 0; i < N; i++)
        {
            data[i] = i + 1;
        }
    }

    [Benchmark(Description = "SubsetSum")]
    public int Algorithm() => subset_sum_david(data);
    public static int subset_sum_david(int[] A)
    {
        /*
        Magic of this solution is that it never creates subsets, so no overhead.
        */
        int n = A.Length;
        int ans = 0;
        
        // for every subset do :
        for (int i = 0; i < (1 << n); i++) // 2**n * c1  
        {
            // this iterates over all of its subsets
            for (int j = i; true; j = (j-1) & i) //  2**(n-c)*(C_c)^n * c2 = 3^n * c2
            /* 
            we are doing the following count for each subset of the array, iterate over all of its subsets, that number is also the number we get by to each subset of the array counting how many sets are that include him, summing it will give the array.  
            */

            /*
            (working on base2)
            dados j, i, probar que el mayor número de la forma x & i menor que j es para x = j-1.
            */

            // for dressed like a while.
            {
                // now for all the elements in the array, if the element happens to be in the array then we add it to the answer.
                for (int k = 0; k < n; k++) // n*(c3+c4+c5) 
                {
                    if ( (j & (1 << k)) == 1 << k)
                    {
                        ans += A[k];
                    }
                }

                if (j == 0) //c6
                {
                    break;
                }
            }
        }
        return ans;
    }    
}