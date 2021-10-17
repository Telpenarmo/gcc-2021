#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

inline array<int, 168> load_primes();
vector<int> factorize(int n)
{
   auto primes = load_primes();
   vector<int> factors;
   for (int p : primes)
   {
      if (p * p > n)
         break;
      if (n % p == 0)
      {
         factors.push_back(p);
      }
      while (n % p == 0)
      {
         n /= p;
      }
   }
   if (n > 1)
      factors.push_back(n);
   return factors;
}

void countStablePartitions(int n, vector<int> &values)
{
   unordered_map<int, int> groups;
   for (int v : values)
   {
      if (v == 1)
      {
         groups[1] = -1;
      }
      auto factors = factorize(v);
      for (auto f : factors)
      {
         auto x = groups.emplace(f);
      }
   }
}

int main()
{
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> values[i];
   }
   countStablePartitions(n, values);
   return 0;
}

inline array<int, 168> load_primes()
{
   return {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
           101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
           197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,
           311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421,
           431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547,
           557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
           661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
           809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929,
           937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
}