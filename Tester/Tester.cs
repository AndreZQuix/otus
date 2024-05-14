using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Testing
{
    public class Tester
    {
        private ITask task;
        private string path;

        public Tester(ITask task, string path)
        {
            this.task = task;
            this.path = path;
        }

        public void RunTests() 
        {
            int nr = 0;
            while(true)
            {
                string inFile = $"{path}/test.{nr}.in";
                string outFile = $"{path}/test.{nr}.out";
                if(!File.Exists(outFile) || !File.Exists(inFile)) 
                {
                    return;
                }

                Console.WriteLine($"Test {nr}: {RunTest(inFile, outFile)}");
                nr++;
            }
        }

        private bool RunTest(string inFile, string outFile)
        {
            try
            {
                string[] data = File.ReadAllLines(inFile);
                string expected = File.ReadAllText(outFile).Trim();
                string actual = task.Run(data).Trim();
                Console.WriteLine($"Expected: {expected} Actual: {actual}");
                return expected == actual;
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.ToString());
                return false;
            }
        }
    }
}
