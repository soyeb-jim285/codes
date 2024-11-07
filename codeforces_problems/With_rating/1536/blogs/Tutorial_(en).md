# Tutorial_(en)

We hope you liked the problems! If you’re curious about the two different problem formats, initially [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani"), [golions](https://codeforces.com/profile/golions "Master golions"), [qlf9](https://codeforces.com/profile/qlf9 "Candidate Master qlf9") and I were working on Omkar 3 with [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "International Grandmaster antontrygubO_o") while [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra") was working on a separate round with [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27"). We eventually decided to join forces and combine the rounds, resulting in the current Omkar 3. 

 [1536A - Omkar and Bad Story](../problems/A._Omkar_and_Bad_Story.md "Codeforces Round 724 (Div. 2)")
=============================================================================================================

Idea: [rabaiBomkarBittalBang](https://codeforces.com/profile/rabaiBomkarBittalBang "Candidate Master rabaiBomkarBittalBang")

Preparation: [rabaiBomkarBittalBang](https://codeforces.com/profile/rabaiBomkarBittalBang "Candidate Master rabaiBomkarBittalBang"), [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani"), [qlf9](https://codeforces.com/profile/qlf9 "Candidate Master qlf9")

[Video editorial](https://codeforces.com/https://www.youtube.com/watch?v=GZeihS2xTSc)

 **Hint**Consider what happens when a contains a negative number.

 **Solution**We first claim that if any negative number exists in a, then no solution exists. Denote p as the smallest number in a and q as another arbitrary number in the array (as n≥2, q always exists). Clearly, |q−p|=q−p>0. However, because p is negative, q−p>q. As such, adding q−p to the output array would create the pair (q−p,p) with difference q−2p>q−p. We have the same problem as before; thus, it is impossible to create a *nice* array if there exists a negative number in a.

After we deal with this case, we now claim that b=[0,1,2,...,100] is a valid *nice* array for any a that contains no negative numbers. It is easy to verify that this is a valid *nice* array. And since in this case, every element of a is nonnegative and distinct, it is always possible to rearrange and add elements to a to obtain b.

 **Implementation in Java by rabaiBomkarBittalBang**
```cpp
//DecimalFormat f = new DecimalFormat("##.00");

import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;
public class OmkarAndBadStory {
    public static void main(String[] omkar) throws Exception
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        StringBuilder sb = new StringBuilder();
        int cases = Integer.parseInt(st.nextToken());
        for(int i = 0; i < cases; i++)
        {
            solve(in, st, sb);
        }
        System.out.print(sb);
    }
    public static void solve(BufferedReader in, StringTokenizer st, StringBuilder sb) throws Exception
    {
        int k = Integer.parseInt(in.readLine());
        String s = in.readLine();
        st = new StringTokenizer(s);
        boolean hasneg = false;
        int max = 0;
        int x;
        int[] arr = new int[k];
        for(int i = 0; i < k; i++)
        {
            x = Integer.parseInt(st.nextToken());
            arr[i] = x;
            if(x < 0)
            {
                hasneg = true;
            }
            else
            {
                max = Math.max(max, x);
            }
        }
        if(hasneg)
        {
            sb.append("NOn");
        }
        else
        {
            sb.append("YESn");
            sb.append((max+1)+"n");
            for(int i = 0; i < max; i++)
            {
                sb.append(i + " ");
            }
            sb.append(max+"");
            sb.append("n");
        }
    }

}
```
 **Implementation in Kotlin by Tlatoani**
```cpp
fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val numberballs = readLine()!!.split(" ").map { it.toInt() }
        if (numberballs.min()!! < 0) {
            println("nO")
        } else {
            println("yEs")
            println(numberballs.max()!! + 1)
            println((0..numberballs.max()!!).joinToString(" "))
        }
    }
}
```
 **Implementation in C++ by kefaa2**
```cpp
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        bool f = false;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x < 0) f = true;
        }
        if (f) {
            cout << "NOn";
        }
        else {
            cout << "YESn";
            cout << 101 << 'n';
            for (int i = 0; i <= 100; i++) cout << i << " ";
            cout << 'n';
        }
    }
    return 0;
}
```
 **Implementation in Haskell by Tlatoani**
```cpp
import Data.List (intercalate)
import Control.Monad (replicateM)

main = do t <- read <$> getLine
          replicateM t solve

solve = do getLine
           xs <- (map read . words) <$> getLine
           putStrLn (if any (< 0) xs then "nO" else ("yEsn101n" ++ intercalate " " (map show [0..100])))
```
 [1536B - Prinzessin der Verurteilung](../problems/B._Prinzessin_der_Verurteilung.md "Codeforces Round 724 (Div. 2)")
=====================================================================================================================

Idea: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

Preparation: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

[Video editorial](https://codeforces.com/https://www.youtube.com/watch?v=--_QUTD7t94)

 **Hint 1**Pigeonhole principle

 **Hint 2**What is the longest the answer can be?

 **Solution**Let’s brute force check all substrings of length <= 3 and print the lexicographically smallest one that doesn’t appear as a substring in the input. We can guarantee that we will come across the answer due to the pigeonhole principle. There are at most n+n−1+n−2=3n−3 possible substrings of length 3 or shorter in the input. There exist 26+262+263=18278 total substrings of length 3 or shorter. It is impossible for the input to contain all 18278 substrings, as 3n−3<18278 for n≤1000.

Final runtime looks something like O(18278n) or O(n) depending on how you implement substring checking.

 **Implementation in Java by hu_tao**
```cpp
//stan hu tao
//come to K-expo!!!
//watch me get carried in nct ridin
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

public class FischlPog
{
    public static void main(String hi[]) throws Exception
    {
        ArrayList<String> ls = new ArrayList<String>();
        for(int a=0; a < 26; a++)
            ls.add(get(a)+"");
        for(int a=0; a < 26; a++)
            for(int b=0; b < 26; b++)
                ls.add(get(a)+""+get(b));
        for(int a=0; a < 26; a++)
            for(int b=0; b < 26; b++)
                for(int c=0; c < 26; c++)
                    ls.add(get(a)+""+get(b)+""+get(c));
        Collections.sort(ls, (x,y) -> {
            int len1 = x.length();
            int len2 = y.length();
            if(len1 != len2)
                return len1-len2;
            return x.compareTo(y);
        });
        //assume multitests exist
        BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(infile.readLine());
        int T = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        while(T-->0)
        {
            int N = Integer.parseInt(infile.readLine());
            String input = infile.readLine();
            HashSet<String> substrings = new HashSet<String>();
            for(int len=1; len <= 3; len++)
                for(int i=0; i < N-len+1; i++)
                    substrings.add(input.substring(i, i+len));
            for(int i=0; i < ls.size(); i++)
                if(!substrings.contains(ls.get(i)))
                {
                    sb.append(ls.get(i)+"n");
                    break;
                }
        }
        System.out.print(sb);
    }
    public static char get(int a)
    {
        return (char)(a+'a');
    }
}
```
 **Implementation in Kotlin by Tlatoani**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        for (length in 1..n) {
            var mex = ""
            var answer: String? = null
            fun recur() {
                if (mex.length == length) {
                    if (mex !in s) {
                        answer = mex
                    }
                } else {
                    for (chara in 'a'..'z') {
                        mex += chara
                        recur()
                        if (answer != null) {
                            return
                        }
                        mex = mex.substring(0 until mex.lastIndex)
                    }
                }
            }
            recur()
            if (answer != null) {
                println(answer)
                break
            }
        }
    }
}
```
 **Implementation in C++ by 1-gon**
```cpp
#include <bits/stdc++.h>
 
#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<string> se;
    rep(i, 0, n) {
        string ss;
        for(int k = 0; k < 5 && i + k < n; k++) {
            ss.push_back(s[i + k]);
            se.insert(ss);
        }
    }
    rep(len, 1, 6) {
        string t(len, 'a');
        while(true) {
            if(se.count(t) == 0) {
                cout << t << 'n';
                return;
            }
            int idx = len - 1;
            while(idx >= 0 && t[idx] == 'z') {
                t[idx] = 'a';
                idx--;
            }
            if(idx < 0) break;
            t[idx]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}
```
 **Implementation in Haskell by Tlatoani**
```cpp
import Data.List (intercalate, tails, isPrefixOf, head)
import Control.Monad (replicateM)
import Data.Maybe (fromJust, listToMaybe, catMaybes)

main = do t <- read <$> getLine
          replicateM t solve

solve = do getLine
           s <- getLine
           putStrLn (leastNonSubstring s)

leastNonSubstring s = head $ catMaybes [leastOfLength l | l <- [1..]]
  where leastOfLength l = helper "" l
        helper prefix 0 | isSubstring prefix s = Nothing
                        | otherwise            = Just prefix
        helper prefix l = listToMaybe $ catMaybes [helper (prefix ++ [letter]) (l - 1) | letter <- ['a'..'z']]

isSubstring s t = any id (map (isPrefixOf s) (tails t))
```
 [1536C - Diluc and Kaeya](../problems/C._Diluc_and_Kaeya.md "Codeforces Round 724 (Div. 2)")
=========================================================================================================

Idea: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

Preparation: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

[Video editorial](https://codeforces.com/https://www.youtube.com/watch?v=00TBpmgCwe4)

 **Hint 1**Turn into geometry problem

 **Hint 2**Represent every prefix as (x,y) point in cartesian plane where x = frequency of ‘D’ and y = frequency of ‘K’. Draw a polyline connecting these points in order of increasing length of prefix.

 **Hint 3**Draw a line from origin to point. What can we say about intersections of poly-line with this line?

 **Solution**For each prefix, label it with a pair (a,b) where a = frequency of ‘D’ in this prefix and b = frequency of ‘K’ in this prefix. Divide a and b by gcd(a,b). If we iterate over all prefixes from to left, we can notice that the answer for the prefix equals the 
# of occurrences of this pair we have seen so far! This can be visualized by drawing a poly-line as mentioned in the hints.

As for implementation, you can use a map in C++ or a HashMap in Java to achieve O(nlogn) or O(n) runtime.

 **Implementation in Java by hu_tao**
```cpp
//stan hu tao
//come to K-expo!!!
//watch me get carried in nct ridin
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

public class DilucKaeyaModel
{
    public static void main(String hi[]) throws Exception
    {
        BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(infile.readLine());
        int T = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        while(T-->0)
        {
            st = new StringTokenizer(infile.readLine());
            int N = Integer.parseInt(st.nextToken());
            char[] arr = infile.readLine().toCharArray();
            HashMap<String, Integer> map = new HashMap<String, Integer>();
            int dc = 0;
            int kc = 0;
            for(char c: arr)
            {
                if(c == 'D')
                    dc++;
                else
                    kc++;
                int a = dc;
                int b = kc;
                if(a == 0)
                    b = 1;
                else if(b == 0)
                    a = 1;
                else
                {
                    int gcd = gcd(a, b);
                    a /= gcd;   b /= gcd;
                }
                String key = a+":"+b;
                push(map, key);
                sb.append(map.get(key)+" ");
            }
            sb.append("n");
        }
        System.out.print(sb);
    }
    public static int gcd(int a, int b)
    {
        if(a > b)
        {
            int t = a;
            a = b;
            b = t;
        }
        if(a == 0)
            return b;
        return gcd(b%a, a);
    }
    public static void push(HashMap<String, Integer> map, String k)
    {
        if(!map.containsKey(k))
            map.put(k, 1);
        else
            map.put(k, map.get(k)+1);
    }
}
```
 **Implementation in Kotlin by Tlatoani**
```cpp
import java.util.*
fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val freq = mutableMapOf<Pair<Int, Int>, Int>()
        var d = 0
        var k = 0
        val joiner = StringJoiner(" ")
        for (chara in readLine()!!) {
            when (chara) {
                'D' -> d++
                'K' -> k++
            }
            val g = gcd(d, k)
            val r = Pair(d / g, k / g)
            freq[r] = (freq[r] ?: 0) + 1
            joiner.add(freq[r]!!.toString())
        }
        println(joiner)
    }
}

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)
```
 **Implementation in C++ by smax**
```cpp
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

pair<int, int> getRatio(int a, int b) {
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int d = 0, k = 0;
        map<pair<int, int>, int> mp;
        for (char c : s) {
            if (c == 'D') d++;
            else k++;
            cout << ++mp[getRatio(d, k)] << " ";
        }
        cout << "n";
    }

    return 0;
}
```
 **Implementation in Haskell by Tlatoani**
```cpp
import Data.List (intercalate)
import Control.Monad (mapM, replicateM)
import Data.Ratio ((%))
import Data.Map (empty, findWithDefault, insert)

main = do t <- read <$> getLine
          replicateM t solve

solve = do getLine
           s <- getLine
           putStrLn (intercalate " " (map show (maxBlocks s)))

maxBlocks s = helper s empty 0 0
  where helper "" _ _ _ = []
        helper (c:s) prev d k = x : helper s prev' d' k'
          where (d', k') | c == 'D' = (d + 1, k)
                         | c == 'K' = (d, k + 1)
                r | k' == 0   = 69000000 % 1
                  | otherwise = d' % k'
                x = (findWithDefault 0 r prev) + 1
                prev' = insert r x prev
```
 [1536D - Omkar and Medians](../problems/D._Omkar_and_Medians.md "Codeforces Round 724 (Div. 2)")
===========================================================================================================

Idea: [rabaiBomkarBittalBang](https://codeforces.com/profile/rabaiBomkarBittalBang "Candidate Master rabaiBomkarBittalBang")

Preparation: [rabaiBomkarBittalBang](https://codeforces.com/profile/rabaiBomkarBittalBang "Candidate Master rabaiBomkarBittalBang"), [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani")

[Video editorial](https://codeforces.com/https://www.youtube.com/watch?v=JyOFalVJaEc)

 **Solution**For some k<n, assume b1,b2,⋯,bk is the *OmkArray* of some a1,a2,⋯,a2k−1, and we want to see what values of a2k,a2k+1 we can add so that b1,b2,⋯,bk+1 is the *OmkArray* of a1,a2,⋯,a2k+1. Let c1,c2,⋯,c2k−1 be a1,a2,⋯,a2k−1 sorted in ascending order.

If bk+1≥bk, note that bk=ck and there are k−2 elements of a ≥ck+1, so no matter how large a2k,a2k+1 are there will be at most k elements larger than ck+1 in a1,a2,⋯,a2k+1. This gives bk+1≤ck+1. We can use a similar argument to show bk+1≥ck−1. Now we want to bound ck+1 and ck−1. Note that each distinct value among b1,b2,⋯,bk must appear at least once in a1,a2,⋯,a2k−1. Therefore, if i, j satisfy that bi is the largest value of bi≤bk and i≠k, and bj is the smallest value of bj≥bk, j≠k, then we have ck+1≤bj, ck−1≥bi, and so bi≤bk+1≤bj. If no such largest/smallest values exist, then we can assume bk+1 is not bounded above/below.

Therefore, if b has an *OmkArray*, it is necessary that for all i, there does not exist a j≤i such that bj is between bi and bi+1, exclusive. I claim this is also sufficient. We can construct such an array a using the following algorithm:

 * Let a1=b1.
* If bi+1=bj for some bj<bi with j<i, let a2k−2,a2k−1=−∞ (we can replace −∞ with some sufficiently small constant at the end of our array creation process).
* Otherwise, if bi+1<bi then let a2k−2=−∞, a2k−1=bi+1.
* If bi+1=bj for some bj>bi with j<i, let a2k−2,a2k−1=∞ (we can replace ∞ with some sufficiently large constant at the end of our array creation process).
* Otherwise, if bi+1>bi then let a2k−2=∞, a2k−1=bi+1.
* Finally, if bi+1=bi, let a2k−2=−∞, a2k−1=∞.

This means that an equivalent condition to having an *OmkArray* is for all i, there does not exist a j≤i such that bj is between bi and bi+1, exclusive. There are multiple ways to check this for an array b, but one clean way would be to keep some TreeSet s, and check if bi+1 is between \t{s.ceil(bi)} and \t{s.floor(bi)} for all i, and then adding bi+1 to s if it is not already added. 

 **Linear time implementation in Java by rabaiBomkarBittalBang**
```cpp
//Praise our lord and saviour qlf9
import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;
public class C{
public static void main(String[] omkar) throws Exception
{
   BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
   StringTokenizer st = new StringTokenizer(in.readLine());
   StringBuilder sb = new StringBuilder();
   int cases = Integer.parseInt(st.nextToken());
   for(int i = 0; i < cases; i++)
   {
      solve(in, st, sb);
   }  
   System.out.print(sb);
        }
 public static void solve(BufferedReader in, StringTokenizer st, StringBuilder sb) throws Exception
 {
   int n = Integer.parseInt(in.readLine());
   int[] arr = readArr(n, in, st);
   Node currNode = new Node(arr[0]);
   int currVal;
   Node temp;
   for(int i = 1; i < n; i++)
   {
      currVal = arr[i];
      if(currVal < currNode.value)
      {
         if(currNode.prev != null && currVal < currNode.prev.value)
         {
            sb.append("NOn");
            return;
         }
         if(currNode.prev == null || currNode.prev.value < currVal)
         {
            temp = new Node(currVal);
            temp.prev = currNode.prev;
            temp.next = currNode;
            if(currNode.prev != null)
            {
               currNode.prev.next = temp;
            }
            currNode.prev = temp;
            currNode = temp;
         }
         else
         {
            currNode = currNode.prev;
         }
      }
      else if(currVal > currNode.value)
      {
         if(currNode.next != null && currVal > currNode.next.value)
         {
            sb.append("NOn");
            return;
         }
         if(currNode.next == null || currNode.next.value > currVal)
         {
            temp = new Node(currVal);
            temp.next = currNode.next;
            temp.prev = currNode;
            if(currNode.next != null)
            {
               currNode.next.prev = temp;
            }
            currNode.next = temp;
            currNode = temp;
         }
         else
         {
            currNode = currNode.next;
         }
      }
   }
   sb.append("YESn");
 }
 public static int[] readArr(int N, BufferedReader in, StringTokenizer st) throws Exception
 {
    int[] arr = new int[N];
    st = new StringTokenizer(in.readLine());
    for(int i=0; i < N; i++)
    arr[i] = Integer.parseInt(st.nextToken());
    return arr;
 }
 static class Node
 {
   int value;
   Node prev;
   Node next;
   public Node(int v)
   {
      value = v;
      prev = null;
      next = null;
   }
 }
}
```
 **Implementation in Kotlin by Tlatoani**
```cpp
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val tokenizer = StringTokenizer(jin.readLine())
        var mid = tokenizer.nextToken().toInt()
        val treeSet = TreeSet<Int>()
        treeSet.add(Int.MIN_VALUE)
        treeSet.add(mid)
        treeSet.add(Int.MAX_VALUE)
        var answer = true
        for (j in 2..n) {
            val next = tokenizer.nextToken().toInt()
            if (next < treeSet.lower(mid)!! || next > treeSet.higher(mid)!!) {
                answer = false
                break
            }
            mid = next
            treeSet.add(mid)
        }
        out.appendln(if (answer) "yEs" else "nO")
    }
    print(out)
}
```
 **Implementation in C++ by kefaa2**
```cpp
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
int a[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        set<int> s;
        s.insert(a[1]);
        bool ok = true;
        for (int i = 2; i <= n; i++) {
            int prv = a[i - 1];
            if (prv != a[i]) {
                if (prv < a[i]) {
                    auto it = s.upper_bound(prv);
                    if (it != s.end() && (*it < a[i])) {
                        ok = false;
                        break;
                    }
                }
                if (prv > a[i]) {
                    auto it = s.lower_bound(prv);
                    if (it != s.begin() && (*(--it) > a[i])) {
                        ok = false;
                        break;
                    }
                }
            }
            s.insert(a[i]);
        }
        if (ok) cout << "YESn";
        else cout << "NOn";
    }
    return 0;
}
```
 **Implementation in Haskell by Tlatoani**
```cpp
import Data.List (intercalate)
import Data.Set (singleton, lookupLT, lookupGT, insert)
import Control.Monad (mapM, replicateM)

main = do t <- read <$> getLine
          replicateM t solve

solve = do getLine
           xs <- (map read . words) <$> getLine
           putStrLn (if isOmkArray xs then "yEs" else "nO")

isOmkArray :: [Int] -> Bool
isOmkArray (x:xs) = helper xs x (singleton x)
  where helper [] _ _ = True
        helper (x:xs) prev allPrev | maybe False (x <) (lookupLT prev allPrev) || maybe False (x >) (lookupGT prev allPrev) = False
                                   | otherwise                                                                              = helper xs x (insert x allPrev)
```
 [1536E - Omkar and Forest](../problems/E._Omkar_and_Forest.md "Codeforces Round 724 (Div. 2)")
==========================================================================================================

Idea: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

Preparation: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

[Video editorial](https://codeforces.com/https://www.youtube.com/watch?v=cqzBCjXIUwA)

 **Hint 1**Consider forcing some set of ‘#’ positions to be 0 and the rest to be positive integers.

 **Hint 2**Multisource BFS

 **Solution**Imagine picking some subset of ‘#’ and making them 0. Then there is exactly one way to make all the remaining ‘#’ positive integers. To see why, imagine multisource BFS with all 0 as the sources. After the BFS, each ‘#’ will be equal to the minimum distance from itself to any 0 cell. Difference between adjacent cells will be at most 1. Proof can be shown by contradiction: if two cells with difference ≥2 existed, then the larger of these cells is not labeled with the shortest distance to a source (since the distance from the smaller cell +1 will be a better choice). Because of the nature of BFS, we can also ensure the second condition is also satisfied, since the only cells that have no neighbor strictly smaller will be the source cells. This is the only valid assignment because if we make any number larger, there will exist a pair of cells with difference ≥2. If we try to make any number smaller, there will exist a cell with positive karma that has no strictly smaller neighbor.

If we let k equal to the frequency of ‘#’ in the input, then the answer is 2k. Keep in mind of the special case where the input is all ‘#’, in which case you have to subtract 1. This is because a possible arrangement must contain at least one cell with karma of 0. 

Obviously the solution runs in O(nm) time.

 **Implementation in Java by hu_tao**
```cpp
//Model Solution 2, uses fast expo
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

public class OmkarAndForestModel2
{
    static final long MOD = 1000000007L;
    public static void main(String hi[]) throws Exception
    {
        BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(infile.readLine());
        int T = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        while(T-->0)
        {
            st = new StringTokenizer(infile.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int cnt = 0;
            for(int i=0; i < N; i++)
            {
                String row = infile.readLine();
                for(char c: row.toCharArray())
                    if(c == '#')
                        cnt++;
            }
            long res = power(2, cnt, MOD);
            if(cnt == N*M)
                res = (res-1+MOD)%MOD;
            sb.append(res+"n");
        }
        System.out.print(sb);
    }
    public static long power(long x, long y, long p)
    {
        //0^0 = 1
        long res = 1L;
        x = x%p;
        while(y > 0)
        {
            if((y&1)==1)
                res = (res*x)%p;
            y >>= 1;
            x = (x*x)%p;
        }
        return res;
    }
}
```
 **Implementation in Kotlin by Tlatoani**
```cpp
const val MOD = 1000000007L

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        var zeros = (1..n).sumBy{ readLine()!!.count { it == '0' } }
        var answer = 1L
        for (j in 1..(n * m) - zeros) {
            answer *= 2L
            answer %= MOD
        }
        if (zeros == 0) {
            answer--
        }
        println(answer)
    }
}
```
 **Implementation in C++ by kefaa2**
```cpp
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        int ans = 1;
        bool has =false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '0') {
                    has = true;
                }
                else {
                    ans = (2LL * ans) % mod;
                }
            }
        }
        if (has) {
            cout << ans << 'n';
        }
        else {
            cout << (ans - 1) << 'n';
        }
    }
    return 0;
}
```
 **Implementation in Haskell by Tlatoani**
```cpp
import Data.List (intercalate)
import Control.Monad (replicateM)

md x = mod x 1000000007

main = do t <- read <$> getLine
          replicateM t solve

solve = do n:m:[] <- (map read . words) <$> getLine
           free <- (sum . map (sum . map (chara -> if chara == '#' then 1 else 0))) <$> replicateM n getLine
           putStrLn $ show (if free == n * m then pow 2 free - 1 else pow 2 free)

pow :: (Integral a) => Integer -> a -> Integer
pow _ 0 = 1
pow x y = md $ x * (pow x (y - 1))
```
 [1536F - Omkar and Akmar](../problems/F._Omkar_and_Akmar.md "Codeforces Round 724 (Div. 2)")
=========================================================================================================

Idea: [golions](https://codeforces.com/profile/golions "Master golions")

Preparation: [golions](https://codeforces.com/profile/golions "Master golions")

[Video editorial](https://codeforces.com/https://www.youtube.com/watch?v=iTou7R_fJfY)

 **Hint 1**Solve a simpler version of the problem, where you just need to print who would win if both players play optimally.

 **Hint 1 Hint**Consider the possible ending states of the board.

 **Hint 1 Solution**The 2nd player, Omkar, always wins no matter what either player does. The easiest way to see this is by considering ending states of the board. An ending state with an even number of letters means that the 2nd player wins (because the first player is the next player and there are no more moves), and an ending state with an odd number of letters means that the 1st player wins.

An ending state must be in the form ABABA... or BABA..., where there are 0 or 1 empty cells in between each letter and the letters form an alternating pattern. If there is more than 1 empty cell in between two cells, then a player will be able to play a letter, thus it is not a valid ending state.

If an ending state has two of the same letters next to each other, then it is not a valid ending state. Either they are next to each other, which is illegal, or there is at least one empty cell in between them, which means that a player can play the other letter in between.

Since the ending state must form an alternating pattern, there must be an even number of states. Thus, the 2nd player, Omkar, always wins.

 **Hint 2**Find the implication of the 2nd player always winning on the number of optimal games.

 **Hint 2 Solution**Because the 2nd player always wins no matter what, the number of optimal games basically means the total number of possible games.

 **Solution**Because of Hint 1 and Hint 2, we want to find the total number of possible games. This can be done by iterating over the number of moves and counting the number of ways to play a game with that number of moves. 

We want to find the number of games that end in x moves on a board of size n. 

The first step is to calculate the total number of ending states. If x=n, the total number of ending states is just 2 because you can either have ABABA... or BABAB...

Otherwise, a game that ends in x moves will consist of x letters, for example A|B|A|B|... where a | is a possible location of a single empty cell (there cannot be multiple empty cells next to each other or else it would not be a valid ending state). There are x possible places where there can be an empty cell, and n−x empty cells, so there are (xn−x) ways to choose places to put empty cells. Due to the circular nature of the board, you need to account for the case where the first cell on the board is an empty cell (the previous formula only works if the first cell is not empty). If you set the first cell to be empty, there are not x−1 possible places to put an empty cell and n−x−1 remaining empty cells, so you have to add (x−1n−x−1). Multiply the answer by 2 to account for starting with an A or B.

Finally, multiply by x! to account for all the ways you can reach each ending configuration.

Thus, if x=n, there are 2⋅x! optimal games, otherwise there are 2⋅((xn−x)+(x−1n−x−1))⋅x! optimal games.

Add up the number of games that end in x moves for all even x from ⌈n2⌉ to n, inclusive. Thus, the solution is O(n).

 **Implementation in Java by golions**
```cpp
//make sure to make new file!
import java.io.*;
import java.util.*;

public class OmkarAndAkmarSolution{
   
   public static int MAXN = 1000005;
   public static long MOD = 1000000007L;
   public static long[] fac;
   public static long[] ifac;
   
   public static void main(String[] args)throws IOException{
      BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter out = new PrintWriter(System.out);
      
      int n = Integer.parseInt(f.readLine());
      
      fac = new long[MAXN];
      ifac = new long[MAXN];
      
      fac[0] = 1L;
      ifac[0] = 1L;
      for(int k = 1; k < MAXN; k++){
         fac[k] = (fac[k-1] * (long)k + MOD)%MOD;
         ifac[k] = modInverse(fac[k],MOD);
      }
      
      /*
      ifac[MAXN-1] = modInverse(fac[MAXN-1],MOD);
      for(int k = MAXN-2; k >= 0; k--){
         ifac[k] = (ifac[k+1]*(long)(k+1) + MOD)%MOD;
      }*/
      
      int start = (n+1)/2;
      if(start % 2 == 1) start++;
      
      long answer = 0L;
      for(int k = start; k <= n; k+=2){
         long prod1 = 1L;
         if(n-k>=1){
            //doesn't do first skip
            prod1 = choose(k,n-k);
            //does first skip
            prod1 = (prod1 + choose(k-1,n-k-1) + MOD)%MOD;
         }
         long prod2 = (prod1*2L + MOD)%MOD;
         long prod3 = (prod2*fac[k] + MOD)%MOD;
         answer = (answer + prod3 + MOD)%MOD;
      }
      
      out.println(answer);
      
      
      
      
      
      
      
      
      out.close();
   }
   
   //a choose b, a!/(b!(a-b)!)
   public static long choose(int a, int b){
      long prod = (fac[a]*ifac[b] + MOD)%MOD;
      long prod2 = (prod*ifac[a-b] + MOD)%MOD;
      return prod2;
   }
   
   public static long modInverse(long a, long m)
    {
        long m0 = m;
        long y = 0;
        long x = 1;
        if (m == 1)
            return 0;
 
        while (a > 1) {
            // q is quotient
            long q = a / m;
 
            long t = m;
 
            // m is remainder now, process
            // same as Euclid's algo
            m = a % m;
            a = t;
            t = y;
 
            // Update x and y
            y = x - q * y;
            x = t;
        }
 
        // Make x positive
        if (x < 0)
            x += m0;
 
        return x;
    }
   
      
}
```
 **Implementation in Kotlin by Tlatoani**
```cpp
const val MOD = 1000000007L

fun main() {
    val n = readLine()!!.toInt()
    val factorial = LongArray(n + 1)
    factorial[0] = 1L
    for (j in 1..n) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val invFactorial = LongArray(n + 1)
    invFactorial[n] = factorial[n] pow -1
    for (j in n - 1 downTo 0) {
        invFactorial[j] = ((j + 1).toLong() * invFactorial[j + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (b in 0..a) ((factorial[a] * ((invFactorial[b] * invFactorial[a - b]) % MOD)) % MOD) else 0L
    var answer = 0L
    for (k in 0..n step 2) {
        answer += factorial[k] * (choose(k, n - k) + choose(k - 1, n - k - 1))
        answer %= MOD
    }
    answer *= 2L
    answer %= MOD
    println(answer)
}

const val MOD_TOTIENT = MOD.toInt() - 1

infix fun Long.pow(power: Int): Long {
    var e = power
    e %= MOD_TOTIENT
    if (e < 0) {
        e += MOD_TOTIENT
    }
    if (e == 0 && this == 0L) {
        return this
    }
    var b = this % MOD
    var res = 1L
    while (e > 0) {
        if (e and 1 != 0) {
            res *= b
            res %= MOD
        }
        b *= b
        b %= MOD
        e = e shr 1
    }
    return res
}
```
 **Implementation in C++ by kefaa2**
```cpp
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
const int maxN = 2e6 + 10;
int inv[maxN], fact[maxN], invfact[maxN];
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    inv[1] = 1;
    fact[0] = invfact[0] = fact[1] = invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
        fact[i] = mult(fact[i - 1], i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    int ans = 0;
    int n;
    cin >> n;
    for (int moves = 0; moves <= n - 1; moves++) {
        int spaces = n - 1 - moves;
        int coef = cnk(moves + 1, spaces);
        if (moves % 2 == 0) continue;
        int fi = (moves + 1) / 2;
        coef = mult(coef, fact[moves]);
     //   cout << coef << endl;
        ans = sum(ans, coef);
    }
    ans = mult(ans, 2 * n);
    cout << ans;
    return 0;
}
```
 **Implementation in Haskell by Tlatoani**
```cpp
import Data.List (reverse)
import Data.Array (listArray, (!))

chara = 1000000007
md x = mod x chara

main = do n <- read <$> getLine
          putStrLn $ show (solve n)

solve n = md $ 2 * (sum (map (k -> md (factorials!k * (choose k (n - k) + choose (k - 1) (n - k - 1)))) [0,2..n]))
  where factorials = listArray (0, n) (reverse (helper n))
          where helper 0 = 1:[]
                helper n' = md (n' * f):fs
                  where fs@(f:_) = helper (n' - 1)
        invFactorials = listArray (0, n) (helper 0)
          where helper n' | n' == n   = inv (factorials!n):[]
                          | otherwise = md ((n' + 1) * f):fs
                  where fs@(f:_) = helper (n' + 1)
        choose a b | 0 <= b && b <= a = md $ factorials!a * (md (invFactorials!b * invFactorials!(a - b)))
                   | otherwise        = 0

modPow :: (Integral a) => Integer -> a -> Integer
modPow _ 0 = 1
modPow x y = md $ (if even y then 1 else x) * modPow (md (x * x)) (div y 2)

inv x = modPow x (chara - 2)
```
