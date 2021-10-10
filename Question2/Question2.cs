using System;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Example
{
    
    public static int securitiesBuying(int z, List<int> security_value)
    {
        int no_of_stocks = 0;
        var pairs = security_value.Select((x, i) => (num: x, index: i+1)).OrderBy(pair => pair.num);

        int sum = 0;
        foreach (var pair in pairs)
        {
            for (var i = 0; i < pair.index; i++)
            {
                sum += pair.num;
                if (sum > z) return no_of_stocks;
                no_of_stocks++;
            }
        }
        return no_of_stocks; 
    }
    
   public static void Main()
   {
        int z= Convert.ToInt32(Console.ReadLine());    
        var security_value = new List<int>();
        string input = Console.ReadLine();
        string pattern = " ";
      String[] substrings = Regex.Split(input, pattern);    
      foreach (string s in substrings)
      {
          security_value.Add(Convert.ToInt32(s));
      }
      int no_of_stocks_purchased = securitiesBuying(z,security_value);
      Console.WriteLine(no_of_stocks_purchased);
      
   }
}