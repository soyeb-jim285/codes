# Tutorial_(en)

We hope you liked the problems! We apologize for the weak pretests for A and B -- that was a major oversight on our part. Hopefully you were still able to enjoy the contest regardless :)

We have to apologize to [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o") a bit here -- the rejection count mentioned in the [editorial](https://codeforces.com/blog/entry/79974) for [Codeforces Round 655 (Div. 2)](https://codeforces.com/contest/1372 "Codeforces Round 655 (Div. 2)") actually also included this round, as the problems from that round and problems A through G in this round were created together. We did have one more problem rejected after that round happened, bringing up the total to 73. For reference, here are the overall rejection counts for each problem:

 **Rejection Counts*** A: 12
* B: 16
* C: **6**
* D: 19
* E: 18
* F: 2

Total: **73**

Without further ado, here are the tutorials for each of the problems:

 
### [1392A - Omkar and Password](../problems/A._Omkar_and_Password.md "Codeforces Global Round 10")

If your array consists of one number repeated $n$ times, then you obviously can't do any moves to shorten the password. Otherwise, you can show that it is always possible to shorten the password to $1$ number. 

For an array consisting of $2$ or more distinct elements, considering the maximum value of the array. If its max value appears once, you can just repeat operations on the maximum array value until you are left with one number. What if the maximum elements appears more than once? Well, because there must exist at least $2$ distinct numbers, you can always pick a maximum element adjacent to a different number to perform an operation on. The array will then have one occurrence of a maximum and you can simply repeat using aforementioned logic. 

 **Solution (Kotlin) by golions**
```cpp
import java.io.*
import java.util.*
import kotlin.math.*

fun main(){
	val f = BufferedReader(InputStreamReader(System.`in`))

	for(q in 1..f.readLine().toInt()){
		val n = f.readLine().toInt()
		val array = f.readLine().split(" ").map{it.toInt()}.toHashSet()

		if(array.size == 1){
			println(n)
		} else {
			println(1)
		}
	}
}
```
 **Solution (Java) by MagentaCobra**
```cpp
/*
Omkar orz
*/
import java.util.*;
import java.io.*;
import java.math.*;

   public class ModelPasswordA
   {
      public static void main(String omkar[]) throws Exception
      {
         BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));  
         StringTokenizer st = new StringTokenizer(infile.readLine());
         int T = Integer.parseInt(st.nextToken());
         StringBuilder sb = new StringBuilder();
         while(T-->0)
         {
            int N = Integer.parseInt(infile.readLine());
            int[] arr = new int[N];
            st = new StringTokenizer(infile.readLine());
            for(int i=0; i < N; i++)
               arr[i] = Integer.parseInt(st.nextToken());
            int res = N;
            for(int i=1; i < N; i++)
               if(arr[i] != arr[i-1])
                  res = 1;
            sb.append(res+"n");
         }
         System.out.print(sb);
      }
   }

```
 **Solution (C++) by hugopm**
```cpp
#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}
	sort(all(vec));
	if (vec.front() == vec.back()) cout << n << "n";
	else cout << "1n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int nbTests;
	cin >> nbTests;
	for (int iTest = 0; iTest < nbTests; ++iTest) {
		solve();
	}
}
```
Idea: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra") and [qlf9](https://codeforces.com/profile/qlf9 "Expert qlf9")

Preparation: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

 
### [1392B - Omkar and Infinity Clock](../problems/B._Omkar_and_Infinity_Clock.md "Codeforces Global Round 10")

There's only two possible states the array can end up as. Which state it becomes after $k$ turns is determined solely by the parity of $k$.

After the first move, the array will consists of all non-negative numbers ($d-a_{i}$ will never be negative because $a_{i}$ never exceeds $d$). After one turn, let's define $x$ as max($a_{i}$) over all $i$. For any number $a_{i}$, it will turn into $x-a_{i}$. Because a zero will always exist after any one operation, $x$ will be the maximum of the array in the next turn as well. Then the value at index $i$ will turn into $x-(x-a_{i})$. This is just equal to $a_{i}$!

Now that it's obvious that our array will enter a cycle with a period of $2$, we simply do the following: If $k$ is odd, perform $1$ operation. Otherwise perform $2$ operations.

 **Solution (Kotlin) by Tlatoani**
```cpp
import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val k = line[1].last().toString().toInt() % 2
        val array = jin.readLine().split(" ").map { it.toLong() }.toLongArray()
        var m = array.max()!!
        for (j in 0 until n) {
            array[j] = m - array[j]
        }
        if (k == 0) {
            m = array.max()!!
            for (j in 0 until n) {
                array[j] = m - array[j]
            }
        }
        out.appendln(array.joinToString(" "))
    }
    print(out)
}
```
 **Solution (Java) by MagentaCobra**
```cpp
//Omkar, Holy Light
import java.util.*;
import java.io.*;
import java.math.*;

   public class ModelB
   {
      public static void main(String omkar[]) throws Exception
      {
         //query based
         BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));  
         StringTokenizer st = new StringTokenizer(infile.readLine());
         int T = Integer.parseInt(st.nextToken());
         StringBuilder sb = new StringBuilder();
         while(T-->0)
         {
            st = new StringTokenizer(infile.readLine());
            int N = Integer.parseInt(st.nextToken());
            long K = Long.parseLong(st.nextToken())%2;
            if(K == 0)  K = 2;
            int[] arr = new int[N];
            st = new StringTokenizer(infile.readLine());
            for(int i=0; i < N; i++)
               arr[i] = Integer.parseInt(st.nextToken());
            for(int turns=0; turns < K; turns++)
            {
               int max = arr[0];
               for(int x: arr)
                  max = Math.max(max, x);
               for(int i=0; i < N; i++)
                  arr[i] = max-arr[i];
            }
            for(int i=0; i < N; i++)
            {
               sb.append(arr[i]);
               if(i+1 < N)
                  sb.append(" ");
            }
            sb.append("n");
         }
         System.out.print(sb);
      }
   }
```
 **Solution (C++) by tfg**
```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		long long k;
		std::cin >> n >> k;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		if(k > 1) {
			k = 2 + k % 2;
		}
		while(k--) {
			int mx = -1000000000;
			for(int i = 0; i < n; i++) {
				mx = std::max(mx, a[i]);
			}
			for(int i = 0; i < n; i++) {
				a[i] = mx - a[i];
			}
		}
		for(int i = 0; i < n; i++) {
			std::cout << a[i] << (i + 1 == n ? 'n' : ' ');
		}
	}
}
```
Idea: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

Preparation: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

 
### [1392C - Omkar and Waterslide](../problems/C._Omkar_and_Waterslide.md "Codeforces Global Round 10")

Call the initial array $a$. We claim that the answer is $\sum max(a_i-a_{i+1}, 0)$ over the entire array of supports (call this value $ans$). Now let's show why.

First, notice that in a nondecreasing array, $ans = 0$. So, the problem is now to apply operations to the array such that $ans = 0$.

Now, let's see how applying one operation affects $ans$. Perform an operation on an arbitrary nondecreasing subarray that begins at index $i$ and ends at index $j$. Note that the differences of elements within the subarray stay the same, so the only two pairs of elements which affect the sum are $a_{i-1}, a_i$ and $a_j, a_{j+1}$.

Let's initially look at the pair $a_{i-1}, a_i$. If $a_{i-1} \leq a_i$ (or if $i = 1$), applying an operation would not change $ans$. But, if $a_{i-1} /gt a_i$, applying an operation would decrease $ans$ by $1$.

Now let's look at the pair $a_j, a_{j+1}$. If $a_j \leq a_{j+1}$ (or if $j = n$), applying an operation would not change $ans$. But, if $a_j \gt a_{j+1}$, applying an operation would increase $ans$ by $1$.

We have now shown that we can decrease $ans$ by at most $1$ with each operation, showing that it is impossible to make his supports able to hold the waterslide in fewer than $\sum max(a_i-a_{i+1}, 0)$ over the initial array. Now, let's construct a solution that applies exactly $\sum max(a_i-a_{i+1}, 0)$ operations to make the array valid.

Consider applying operations to each suffix of length $j$ until the suffix of length $j+1$ is nondecreasing. Since operations are applied iff $a_{n-j+1} \lt a_{n-j}$, and each operation decreases $a_{n-j+1} \lt a_{n-j}$ by $1$, the total number of operations would just be the sum of $max(0, a_{n-j}-a_{n-j+1})$, which is equal to $\sum max(a_i-a_{i+1}, 0)$ over the entire array.

 **Solution (Kotlin) by Tlatoani**
```cpp
import kotlin.math.max

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val hs = readLine()!!.split(" ").map { it.toLong() }
        var answer = 0L
        for (j in 1 until n) {
            answer += max(0L, hs[j - 1] - hs[j])
        }
        println(answer)
    }
}
```
 **Solution (Java) by qlf9**
```cpp
import java.util.*;
import java.io.*;

public class OmkarAndWaterslide {
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(f.readLine());
        while(t-->0){
            int n = Integer.parseInt(f.readLine());
            long[] arr = new long[n];
            StringTokenizer st = new StringTokenizer(f.readLine());
            for(int i = 0; i < n; i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }
            long ans = 0;
            for(int i = 0; i < n-1; i++){
                ans+=Math.max(0, arr[i]-arr[i+1]);
            }
            out.println(ans);
        }
        out.close();
    }
}
```
 **Solution (C++) by tfg**
```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		long long last = 0;
		long long ans = 0;
		while(n--) {
			long long x;
			std::cin >> x;
			x += ans;
			if(x >= last) {
				last = x;
			} else {
				ans += last &mdash; x;
			}
		}
		std::cout << ans << 'n';
	}
}
```
Idea: [qlf9](https://codeforces.com/profile/qlf9 "Expert qlf9")

Preparation: [qlf9](https://codeforces.com/profile/qlf9 "Expert qlf9")

 
### [1392D - Omkar and Bed Wars](../problems/D._Omkar_and_Bed_Wars.md "Codeforces Global Round 10")

As described in the statement, the only situation in which a player is not acting logically according to Bed Wars strategy is when they are being attacked by exactly $1$ player, but they are not attacking that player in response. Let the player acting illogically be player $j$. There are two cases in which player $j$ is acting illogically:

The first case is that player $j$ is being attacked by the player to their left, player $j - 1$, and not by the player to their right, player $j + 1$. This means that $s_{j - 1} = $ R, as they are attacking player $j$ who is to their right, and $s_{j + 1} = $ R, as they are attacking the player to the right instead of player $j$ who is to their left. Furthermore, since player $j$ is not being logical, instead of attacking player $j - 1$, they are attacking player $j + 1$, so $s_j = $ R. This means that in this case $s_{j - 1} = s_j = s_{j + 1} = $ R, i. e. R occurs $3$ times in a row somewhere in $s$. We want to avoid this case, so the final string (after Omkar has convinced some player to change) cannot have $3$ Rs in a row.

The second case is that player $j$ is being attacked by the player to their right, player $j + 1$, and not by the player to their left, player $j - 1$. It is easy to see that this case is essentially the same as the first case, but reversed, meaning that the final string also cannot have $3$ Ls in a row.

Combining these two cases, the condition in the statement reduces to the simple condition that the same character cannot occur $3$ times in a row in our final string. 

If we have some subsegment of length $l$ of the same character in $s$, and this subsegment is maximal, so that the characters preceding and following it in $s$ are different from the characters in it, then we can make all players in this subsegment logical by having Omkar talk to $\lfloor \frac l 3 \rfloor$ of the players in that subsegment. Therefore, assuming that not all characters in $s$ are the same, we simply find the lengths of all maximal subsegments of the same characters in $s$ (noting that we need to wrap around if $s_1 = s_n$), and sum over their lengths divided (rounding down) by $3$. Finding these lengths and summing over their quotients can be done easily by looping through $s$ in $O(n)$.

If all the characters in $s$ are the same, then we can see similarly that Omkar needs to talk to $\lceil \frac n 3 \rceil$ of the players. (Note that we are rounding up instead of down  — this is due to the circular nature of $s$).

 **Solution (Kotlin) by Tlatoani**
```cpp
import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val s = jin.readLine()
        if (s.all { it == s[0] }) {
            out.appendln((n + 2) / 3)
        } else {
            var k = 0
            while (s[k] == s[0]) {
                k++
            }
            var answer = 0
            var curr = 0
            var chara = s[k]
            for (j in k until k + n) {
                if (s[j % n] == chara) {
                    curr++
                } else {
                    answer += curr / 3
                    curr = 1
                    chara = s[j % n]
                }
            }
            answer += curr / 3
            out.appendln(answer)
        }
    }
    print(out)
}
```
 **Solution (Java) by qlf9**
```cpp
import java.util.*;
import java.io.*;

public class OmkarAndBedWars {
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(f.readLine());
        while(t-->0){
            int n = Integer.parseInt(f.readLine());
            String str = f.readLine();
            boolean same = true;
            for(int i = 1; i < n; i++){
                if(str.charAt(i) != str.charAt(0)){
                    same = false;
                    break;
                }
            }
            if(same){
                out.println((n+2)/3);
                continue;
            }
            ArrayList<Integer> count = new ArrayList<Integer>();
            int last = 0;
            int cnt = 1;
            for(int i = 1; i < n; i++){
                if(str.charAt(i) == str.charAt(last)){
                    cnt++;
                }else{
                    count.add(cnt);
                    last = i;
                    cnt = 1;
                }
            }
            if(str.charAt(n-1) == str.charAt(0)){
                count.set(0, count.get(0)+cnt);
            }else{
                count.add(cnt);
            }
            int sum = 0;
            for(int i: count) sum+=(i/3);
            out.println(sum);

        }
        out.close();
    }

}
```
 **Solution (C++) by Ari**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    while(s.size() && s[0] == s.back()) {
        cnt++;
        s.pop_back();
    }
    if(s.empty()) {
        if(cnt <= 2) {
            cout << "0n";
            return;
        }
        if(cnt == 3) {
            cout << "1n";
            return;
        }
        cout << (cnt + 2) / 3 << 'n';
        return;
    }
    s.push_back('$');
    for(int i = 0; i + 1 < s.size(); i++) {
        cnt++;
        if(s[i] != s[i + 1]) {
            ans += cnt / 3;
            cnt = 0;
        }
    }
    cout << ans << 'n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}
```
Idea: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani")

Preparation: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani")

 
### [1392E - Omkar and Duck](../problems/E._Omkar_and_Duck.md "Codeforces Global Round 10")

The problem essentially boils down to constructing a grid such that any path from $(1, 1)$ to $(n, n)$ has a different sum and you can easily determine any path from its sum. You can do this using the following construction: for all $(x, y)$, if $x$ is even, then let $a_{x,y} = 2^{x + y}$; otherwise, let $a_{x,y} = 0$.

The construction is illustrated below for $n = 8$:

$ \begin{matrix} 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\\ 2^{3} & 2^{4} & 2^{5} & 2^{6} & 2^{7} & 2^{8} & 2^{9} & 2^{10} \\\ 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\\ 2^{5} & 2^{6} & 2^{7} & 2^{8} & 2^{9} & 2^{10} & 2^{11} & 2^{12} \\\ 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\\ 2^{7} & 2^{8} & 2^{9} & 2^{10} & 2^{11} & 2^{12} & 2^{13} & 2^{14} \\\ 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\\ 2^{9} & 2^{10} & 2^{11} & 2^{12} & 2^{13} & 2^{14} & 2^{15} & 2^{16} \\\ \end{matrix} $

You can see that this construction works using the following observations: 

* The maximum value of $n$ is $25$, and $2^{2 \cdot 25} = 2^{50} < 10^{16}$.
* For any integer $j$ between $2$ and $2n$ (inclusive), all paths cross exactly one cell $(x, y)$ such that $x + y = j$.
* For any cell $(x, y)$, you can move to either one or two cells, and if you can move to two cells, then exactly one of those will have $x'$ even and exactly one of those will have $x'$ odd, as the cells will necessarily be $(x + 1, y)$ and $(x, y + 1)$ which have different parities of $x'$.

This means that the sum on any path will be the sum of distinct powers of $2$ between $2^2$ and $2^{2n}$ (inclusive), meaning that given that we know which cell $(x, y)$ the path crossed satisfying $x + y = j$, we can determine which cell $(x', y')$ the path crossed satisfying $x' + y' = j + 1$ by checking whether the path sum contains $2^{j + 1}$ and then appropriately selecting either $(x', y') = (x + 1, y)$ or $(x', y') = (x, y + 1)$. We know that the path must start at $(1, 1)$ so we can therefore easily determine the rest of the path given the sum.

 **Solution (Kotlin) by Tlatoani**
```cpp
fun main() {
    val n = readLine()!!.toInt()
    for (x in 1..n) {
        for (y in 1..n) {
            if (x % 2 == 0) {
                print(1L shl (x + y))
            } else {
                print(0)
            }
            print(" ")
        }
        println()
    }
    val q = readLine()!!.toInt()
    for (j in 1..q) {
        val k = readLine()!!.toLong()
        var x = 1
        var y = 1
        print("1 1 ")
        for (e in 3..2 * n) {
            if ((x % 2 == 0) == (((k shr e) % 2L) == 1L)) {
                y++
            } else {
                x++
            }
            print("$x $y ")
        }
        println()
    }
}
```
 **Solution (Java) by golions**
```cpp
//make sure to make new file!
import java.io.*;
import java.util.*;

public class DuckSolution{
   
   public static void main(String[] args)throws IOException{
      BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter out = new PrintWriter(System.out);
      
      int n = Integer.parseInt(f.readLine());
      
      long[][] board = new long[n][n];
      board[0][0] = 0L;
      board[n-1][n-1] = 0L;
      
      for(int k = 0; k < n; k++){
         for(int j = 0; j < n; j++){
            if(k == 0 && j == 0) continue;
            if(k == n-1 && j == n-1) continue;
            
            if(k%2 == 0){
               board[k][j] = 1L << k+j;
            }
         }
      }
      
      for(int k = 0; k < n; k++){
         StringJoiner sj = new StringJoiner(" ");
         for(int j = 0; j < n; j++){
            sj.add("" + board[k][j]);
         }
         out.println(sj.toString());
      }
      
      out.flush();
      
      int q = Integer.parseInt(f.readLine());
      for(int t = 0; t < q; t++){
         long i = Long.parseLong(f.readLine());
         
         ArrayList<Integer> x = new ArrayList<Integer>();
         ArrayList<Integer> y = new ArrayList<Integer>();
         
         int curx = 0;
         int cury = 0;
         
         x.add(1);
         y.add(1);
         
         while(curx < n-1 || cury < n-1){
            if(curx == n-1){
               cury++;
            } else if(cury == n-1){
               curx++;
            } else {
               long and = Math.max(board[curx+1][cury],board[curx][cury+1]);
               if(((i & and) > 0) ^ (board[curx+1][cury] > 0)){
                  cury++;
               } else {
                  curx++;
               }
            
            
            }
            
            x.add(curx+1);
            y.add(cury+1);
         }
         
         StringJoiner sj = new StringJoiner(" ");
         for(int k = 0; k < x.size(); k++){
            sj.add("" + x.get(k) + " " + y.get(k));
         }
         out.println(sj.toString());
         out.flush();
      }
      
      
      
      
      
      
      
      
      out.close();
   }
   
      
}
```
 **Solution (C++) by hugopm**
```cpp
#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int side; cin >> side;
	vector<vector<ll>> grid(side, vector<ll>(side, 0));
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j < side; ++j) {
			if ((i-j+side)&2LL) grid[i][j] = (1LL << (i+j));
			cout << grid[i][j] << " n"[j==side-1];
		}
	}
	cout << flush;
	int nbQuery; cin >> nbQuery;
	for (int iQuery = 0; iQuery < nbQuery; ++iQuery) {
		ll sum; cin >> sum;
		cout << "1 1";
		int row = 0, col = 0;
		for (int diag = 0; diag < 2*side-2; ++diag) {
			ll should = sum&(1LL<<(diag+1));
			if (row+1<side && grid[row+1][col] == should) ++row;
			else ++col;
			cout << " " << row+1 << " " << col+1;
		}
		cout << endl << flush;
	}
}
```
Idea: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani")

Preparation: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani") and [golions](https://codeforces.com/profile/golions "Master golions")

 
### [1392F - Omkar and Landslide](../problems/F._Omkar_and_Landslide.md "Codeforces Global Round 10")

Fun fact: This problem was originally proposed as B.

TL;DR: We can show that in the resulting array, every pair of adjacent elements differs by exactly $1$ except that there may be at most one pair of adjacent equal elements. It is easy to see that there is only one such array satisfying that condition that also has the same length and sum as the given array, so we simply calculate that array based on the sum of the given array.

Proof: Clearly, the order in which we perform the slides (transfers of one square meter of dirt from $a_{j + 1}$ to $a_j$ for some $j$) does not matter. Consider then performing slides in the following manner: whenever we perform a slide from $a_j$ to $a_{j - 1}$, after that slide, if it is possible to perform a slide from $a_{j - 1}$ to $a_{j - 2}$, we will do so, and then from $a_{j - 2}$ to $a_{j - 3}$ and so on. We will call this action "performing a sequence of slides from $a_j$".

Assume that we have just performed a sequence of slides from $a_j$. We can see that if there was a pair of adjacent elements to the left of $a_j$ that were equal, i. e. some $k < j$ such that $a_{k - 1} = a_k$, then, assuming that $a_{k -1}, a_k$ is the rightmost such pair, then the sequence of slides that we started will end with $a_k$ being increased. In this case, $a_{k - 1}$ and $a_k$ are no longer equal, but $a_k, a_{k + 1}$ may now be equal, so the amount of pairs of adjacent equal elements to the left of $a_j$ has either decreased or stayed the same.

On the other hand, if there was no such pair, then the sequence of slides would end with $a_1$ being increased, meaning it might now be true that $a_1$ and $a_2$ are equal, so that the amount of pairs of adjacent equal elements to the left of $a_j$ is either still $0$ or now $1$.

Combining these two facts, we see that if there were either $0$ or $1$ pairs of adjacent equal elements to the left of $a_j$ to start with, then there will only be either $0$ or $1$ pairs of adjacent equal elements to the left of $a_j$ after performing a sequence of slides from $a_j$.

Noting that as our array is initially strictly increasing, there are initially no pairs of adjacent equal elements, we can simply first perform as many sequences of slides from $a_2$ as possible, then perform as many sequences of slides from $a_3$ as possible, and so on, until we perform as many sequences of slides from $a_n$ as possible. When we are performing sequences of slides from $a_j$, there can clearly only be either $0$ or $1$ pairs of adjacent equal elements to the left of $a_j$, and there can't be any such pairs to the right of $a_j$ as that part of the array hasn't been touched yet and is therefore still strictly increasing. Therefore, we can conclude that once all possible slides have been performed, the entire array will contain at most $1$ pair of adjacent equal elements.

Since it cannot be possible to perform any more slides once all possible slides have been performed, all pairs of adjacent elements that are not equal must differ by at most $1$. It is easy to see that there is only one array satisfying these conditions that has the same length $n$ and sum $S = \sum_{j = 1}^n a_j$. You can construct this array by starting with the array $0, 1, 2, \dots, n - 1$, then adding $1$ to each element from left to right, looping back to the beginning when you reach the end, until the sum of the array is $S$. From this construction we can derive the following formula for the array:

$a_j = j - 1 + \lfloor \frac {S - \frac {n(n - 1)} 2} n \rfloor + \{j \leq (S - \frac {n(n - 1)} 2) \% n\}$

where $\{C\}$ is $1$ if the condition $C$ is satisfied, and $0$ otherwise.

**EDIT:** The fact that the order of operations doesn't matter turned out to be harder to prove than I thought (thanks to the comments for pointing this out), so I decided to add the following proof:

If you have two sequences of maximal operations, then what we want to show is that they have to consist of the same operations (possibly in different orders). Since they are both maximal, they must either both be empty or both be nonempty. If they are both empty then we are done.

If they are both nonempty: consider the current state of the vector (before applying either sequence of operations). Since the sequences are nonempty, there is at least one operation α that can be immediately applied on the vector.

Here we should make the observation that applying an operation at some index cannot prevent operations at other indexes from being able to be applied (it can only allow other operations to be applied).

Therefore, applying other (different) operations cannot prevent operation α from being able to be applied, so operation α must occur in both sequences. From our observation, we can see that if, in either sequence, operation α does not occur initially, then operation α can be applied initially because by performing it earlier we are not preventing any of the operations in between from being applied.

Thus, the first operation of each sequence is now the same, so we can apply the same argument to the remainder of the sequence (since it must be finite).

 **Solution (Kotlin) by Tlatoani**
```cpp
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toLong()
    val tokenizer = StringTokenizer(jin.readLine())
    var sum = 0L
    for (j in 0L until n) {
        sum += tokenizer.nextToken().toLong() - j
    }
    val joiner = StringJoiner(" ")
    for (j in 0L until n) {
        joiner.add(((sum / n) + (if (j < sum % n) 1L else 0L) + j).toString())
    }
    println(joiner)
}
```
 **Solution (Java) by qlf9**
```cpp
import java.util.*;
import java.io.*;

public class OmkarAndLandslideNumber2 {
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        long n = Long.parseLong(f.readLine());
        long sum = 0;
        StringTokenizer st = new StringTokenizer(f.readLine());
        for(int i = 0; i < n; i++){
            sum+=Long.parseLong(st.nextToken());
        }
        long k = ((sum - n*(n - 1)/2) / n);
        long diff = sum - (n*k + n*(n - 1)/2);
        StringBuilder ans = new StringBuilder();
        for(long i = 0; i < n; i++){
            if(i < diff){
                ans.append(k+i+1L);
                ans.append(" ");
            }else{
                ans.append(k+i);
                ans.append(" ");
            }
        }
        out.println(ans.toString().trim());
        out.close();
    }
}
```
 **Solution (C++) by Devil**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll n;
	cin >> n;
	ll s = 0;
	for (ll x, i = 0; i < n; ++i)
		cin >> x, s += x;

	ll l = (s - n * (n-1) / 2) / n + 1;
	s = l * n + n * (n-1) / 2 - s;
	for (int i = 0; i < n; ++i)
		cout << l + i - (n-i <= s) << " n"[i+1==n];

	return 0;
}
```
Idea: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani")

Preparation: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani") and [qlf9](https://codeforces.com/profile/qlf9 "Expert qlf9")

 
### [1392G - Omkar and Pies](../problems/G._Omkar_and_Pies.md "Codeforces Global Round 10")

Consider any two binary strings $u$ and $v$ of length $k$. Notice that if you swap the bits at positions $\alpha$ and $\beta$ in $u$ and also swap the bits at positions $\alpha$ and $\beta$ in $v$, then the amount of common bits in $u$ and $v$ remains the same. Furthermore, you can do this multiple times – i. e. applying the same sequence of swaps to $u$ and $v$ doesn't change their amount of common bits.

Let's apply this to the problem at hand. Assume that Omkar has selected the subsegment of elves between some $l$ and $r$. Let $s$ be Omkar's original binary string, let $s'$ be $s$ after applying the subsegment of swaps between $l$ and $r$ (inclusive) to it, and let $t$ be Omkar's ideal binary string. Now consider applying all the swaps in the subsegment from $1$ to $r$ (inclusive) to both $s$ and $t$, but in reverse – first we apply the $r$-th swap, then the $r - 1$-th swap, and so on, until we finally apply the $1$-st swap. 

From our first observation, these new strings $s^{\prime\prime}$ and $t^{\prime\prime}$ have the same amount of common bits as $s'$ and $t$. We additionally notice that just as $t^{\prime\prime}$ is $t$ with the subsegment of swaps from $1$ to $r$ applied in reverse, $s^{\prime\prime}$ is actually $s$ with the subsegment of swaps from $1$ to $l - 1$ applied in reverse, as the subsegment of swaps from $l$ to $r$ that were applied to $s$ to create $s'$ has been undone.

Let us then define some more strings as follows: for all $j$ such that ($0 \leq j \leq n$), let $s_j$ be the result of applying the subsegment of swaps from $1$ to $j$ in reverse to $s$, and let $t_j$ be the result of applying the subsegment of swaps from $1$ to $j$ in reverse to $s$ (so $s_0 = s$ and $t_0 = t$). We now see that the amount of common bits that result from choosing a subsegment of swaps between $l$ and $r$ is equivalent to the amount of common bits between $s_{l - 1}$ and $t_r$, and so the problem is now simply to find two indices $j_1$ and $j_2$ such that $j_2 - j_1 \geq m$ and the amount of common bits between $s_{j_1}$ and $t_{j_2}$ is the maximum possible.

Here we make another observation: if $\omega$ is the amount of common bits between two binary strings $u$ and $v$ of length $k$, $\epsilon$ is the amount of bits set to $1$ in $u$, $\zeta$ is the amount of bits set to $1$ in $v$, and $\lambda$ is the amount of common bits set to $1$ in $u$ and $v$, then $\omega = 2\lambda + k - \epsilon - \zeta$. Since we are only comparing strings derived from performing swaps on $s$ to strings derived from performing swaps on $t$, and swaps don't change the overall amount of $1$ bits in a string, $\epsilon$ and $\zeta$, like $k$, are constants – $\epsilon$ is the amount of $1$ bits in $s$, and $\zeta$ is the amount of $1$ bits in $t$. This means that maximizing $\omega$, the amount of common bits in $u$ and $v$, is equivalent to maximizing $\lambda$, the amount of common $1$ bits in $u$ and $v$.

Therefore, we can now proceed with bitmask DP to finish the problem. For a binary string $\mu$ of length $k$, let $left_\mu$ be the smallest index $j$ such that $\mu$ is a subset of $s_j$ considering $1$ bits, and let $right_\mu$ be the largest index $j$ such that $\mu$ is a subset of $t_j$ considering $1$ bits. These DP values are straightforward to compute, and we can obtain our answer by choosing the subsegment of swaps from $left_\mu$ to $right_\mu$ for any $\mu$ with the largest amount of $1$ bits such that $left_\mu$ and $right_\mu$ both exist and $right_\mu - left_\mu \geq m$.

 **Solution (Kotlin) by Tlatoani**
```cpp
import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val m = line[1].toInt()
    val k = line[2].toInt()
    val dpLeft = IntArray(1 shl k) { n + 1 }
    val dpRight = IntArray(1 shl k) { -1 }
    var original = jin.readLine().reversed().toInt(2)
    var goal = jin.readLine().reversed().toInt(2)
    val permutation = IntArray(k) { it }
    dpLeft[original] = 0
    dpRight[goal] = 0
    for (j in 1..n) {
        line = jin.readLine().split(" ")
        val a = line[0].toInt() - 1
        val b = line[1].toInt() - 1
        var c = (original shr permutation[a]) and 1
        var d = (original shr permutation[b]) and 1
        original -= c shl permutation[a]
        original -= d shl permutation[b]
        original += d shl permutation[a]
        original += c shl permutation[b]
        c = (goal shr permutation[a]) and 1
        d = (goal shr permutation[b]) and 1
        goal -= c shl permutation[a]
        goal -= d shl permutation[b]
        goal += d shl permutation[a]
        goal += c shl permutation[b]
        dpLeft[original] = min(dpLeft[original], j)
        dpRight[goal] = j
        c = permutation[a]
        d = permutation[b]
        permutation[a] = d
        permutation[b] = c
    }
    var best = -1
    var l = -1
    var r = -1
    for (mask in (1 shl k) - 1 downTo 0) {
        for (e in 0 until k) {
            if ((mask shr e) and 1 != 0) {
                dpLeft[mask - (1 shl e)] = min(dpLeft[mask - (1 shl e)], dpLeft[mask])
                dpRight[mask - (1 shl e)] = max(dpRight[mask - (1 shl e)], dpRight[mask])
            }
        }
        if (dpLeft[mask] + m <= dpRight[mask] && Integer.bitCount(mask) > best) {
            best = Integer.bitCount(mask)
            l = dpLeft[mask] + 1
            r = dpRight[mask]
        }
    }
    println(k - Integer.bitCount(original) - Integer.bitCount(goal) + (2 * best))
    println("$l $r")
}
```
 **Solution (Java) by qlf9**
```cpp
import java.io.*;
import java.util.*;

public class OmkarAndPies {
    public static int INF = Integer.MAX_VALUE/2;
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int bitstr = Integer.parseInt(f.readLine(), 2);
        int goal = Integer.parseInt(f.readLine(), 2);
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(f.readLine());
            arr1[i] = Integer.parseInt(st.nextToken());
            arr2[i] = Integer.parseInt(st.nextToken());
        }
        int[] lefts = new int[n+1];
        int[] rights = new int[n+1];
        rights[0] = goal;
        lefts[0] = bitstr;
        int[] permutation = new int[k];
        int[] indices = new int[k];
        for(int i = 0; i < k; i++){
            permutation[i] = i;
            indices[i] = i;
        }
        for(int i = 0; i < n; i++){
            int temp = indices[arr1[i]-1];
            indices[arr1[i]-1] = indices[arr2[i]-1];
            indices[arr2[i]-1] = temp;
            permutation[indices[arr1[i]-1]] = arr1[i]-1;
            permutation[indices[arr2[i]-1]] = arr2[i]-1;
            lefts[i+1] = applyPermutation(indices, bitstr, k);
            rights[i+1] = applyPermutation(indices, goal, k);
        }
        int[] dpLeft = new int[(1 << k)];
        int[] dpRight = new int[(1 << k)];
        Arrays.fill(dpLeft, INF);
        Arrays.fill(dpRight, -INF);
        for(int i = 0; i <= n; i++){
            dpLeft[lefts[i]] = Math.min(dpLeft[lefts[i]], i);
            dpRight[rights[i]] = Math.max(dpRight[rights[i]], i);
        }
        for(int i = (1 << k)-1; i > 1; i--){
            int temp = i;
            int count = 0;
            while(temp != 0){
                if(temp % 2 == 1){
                    dpLeft[i-(1 << count)] = Math.min(dpLeft[i-(1 << count)], dpLeft[i]);
                    dpRight[i-(1 << count)] = Math.max(dpRight[i-(1 << count)], dpRight[i]);
                }
                temp/=2;
                count++;
            }
        }
        for(int i = 0; i < (1 << k); i++){
            if(dpLeft[i] == 2 && dpRight[i] == 8){
                System.out.println(i);
            }
        }
        int maxVal = -INF;
        int intLeft = -1;
        int intRight = -1;
        for(int i = 0; i < (1 << k); i++){
            if(dpRight[i]-dpLeft[i] < m) continue;
            int a1 = lefts[dpLeft[i]];
            int a2 = rights[dpRight[i]];
            int count = 0;
            for(int j = 0; j < k; j++){
                if(a1 % 2 == a2 % 2) count++;
                a1/=2;
                a2/=2;
            }
            if(count > maxVal){
                maxVal = count;
                intLeft = dpLeft[i]+1;
                intRight = dpRight[i];
            }
        }
        out.println(maxVal);
        out.println(intLeft + " " + intRight);
        out.close();


    }
    public static int applyPermutation(int[] permutation, int bitstr, int k){
        int ans = 0;
        for(int i = k-1; i >= 0; i--){
           if(bitstr % 2 == 1){
               ans += (1 << (k-permutation[i]-1));
           }
           bitstr/=2;
        }
        return ans;
    }
}
```
 **Solution (C++) by mohammedehab2002**
```cpp
#include <bits/stdc++.h>
using namespace std;
int p[20],dp[2][(1<<20)];
int getmask(string s)
{
	int ans=0;
	for (int i=0;i<s.size();i++)
	ans|=((s[i]-'0')<<i);
	return ans;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	string a,b;
	cin >> a >> b;
	for (int i=0;i<k;i++)
	p[i]=i;
	for (int i=0;i<(1<<k);i++)
	{
		dp[0][i]=1e9;
		dp[1][i]=-1e9;
	}
	dp[0][getmask(a)]=0;
	dp[1][getmask(b)]=0;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		swap(p[x],p[y]);
		string aa(k,'0'),bb(k,'0');
		for (int j=0;j<k;j++)
		{
			aa[p[j]]=a[j];
			bb[p[j]]=b[j];
		}
		dp[0][getmask(aa)]=min(dp[0][getmask(aa)],i);
		dp[1][getmask(bb)]=i;
	}
	int o1=count(a.begin(),a.end(),'1'),o2=count(b.begin(),b.end(),'1');
	pair<int,pair<int,int> > ans(0,{0,0});
	for (int i=(1<<k)-1;i>=0;i--)
	{
		if (dp[1][i]-dp[0][i]>=m)
		ans=max(ans,make_pair(k-(o1+o2-2*__builtin_popcount(i)),make_pair(dp[0][i]+1,dp[1][i])));
		for (int j=0;j<k;j++)
		{
			if (i&(1<<j))
			{
				dp[0][i^(1<<j)]=min(dp[0][i^(1<<j)],dp[0][i]);
				dp[1][i^(1<<j)]=max(dp[1][i^(1<<j)],dp[1][i]);
			}
		}
	}
	printf("%dn%d %d",ans.first,ans.second.first,ans.second.second);
}
```
Idea: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani")

Preparation: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani")

 
### [1392H - ZS Shuffles Cards](../problems/H._ZS_Shuffles_Cards.md "Codeforces Global Round 10")

Firstly, let's find a simple dp. Let $f(x)$ denote the expected time before the game ends with the deck is full (with $n+m$ cards) and $S$ contains $n - x$ elements. Hence, $f(0)=0$. Our goal is to find $f(n)$.

Suppose the jokers are also numbered from $1$ to $m$ and $S$ contains $n-x$ elements. Consider the cards drawn before we draw our first joker (which causes the deck to be reshuffled). Suppose we draw $i$ cards with a number, $l$ of which is a number not in $S$, before drawing our first joker. There are $\binom{x}{l} \cdot \binom{n-x}{i-l} \cdot i!$ ways to choose and permute the first $i$ cards, $m$ ways to choose the first joker and $(n+m-i-1)!$ ways to permute the cards that were not drawn. The total time taken is $i+1+f(x-l)$. Hence, 

$f(x) = \displaystyle\sum_{l=0}^{x}\displaystyle\sum_{i=0}^{n}\binom{x}{l}\binom{n-x}{i-l} \cdot i! \cdot m \cdot \frac{(n+m-i-1)!}{(n+m)!} \cdot (f(x-l)+i+1).$

This gives us an easy $O(n^{3})$ solution. Note that $f(x)$ is also on the right hand side, so you need to move the corresponding term to the left first before computing (this is not difficult).

To optimize our solution, we just need to manipulate the sums. I will show how to simplify $\displaystyle\sum_{l=0}^{x}\displaystyle\sum_{i=0}^{n}\binom{x}{l}\binom{n-x}{i-l} \cdot i! \cdot m \cdot \frac{(n+m-i-1)!}{(n+m)!} \cdot (i+1)$. The way to simplify $\displaystyle\sum_{l=0}^{x}\displaystyle\sum_{i=0}^{n}\binom{x}{l}\binom{n-x}{i-l} \cdot i! \cdot m \cdot \frac{(n+m-i-1)!}{(n+m)!} \cdot f(x-l)$ is analogous.

We have

$\displaystyle\sum_{l=0}^{x}\displaystyle\sum_{i=0}^{n}\binom{x}{l}\binom{n-x}{i-l} \cdot i! \cdot m \cdot \frac{(n+m-i-1)!}{(n+m)!} \cdot (i+1)$

$= \frac{m \cdot x! \cdot (n-x)!}{(n+m)!} \cdot \displaystyle\sum_{l=0}^{x}\frac{1}{l!(x-l)!} \displaystyle \sum_{i=0}^{n}\frac{(i+1)! \cdot (n+m-i-1)!}{(i-l)! \cdot (n-x-i+l)!}$ (expanding and regrouping)

$= \frac{m \cdot x! \cdot (n-x)!}{(n+m)!} \cdot \displaystyle\sum_{l=0}^{x}\frac{(m-1+x-l)!(l+1)}{(x-l)!} \displaystyle \sum_{i=0}^{n}\frac{(i+1)!}{(l+1)!(i-l)!} \cdot \frac{(n+m-i-1)!}{(n-x-i+l)!(m-1+x-l)!}$ (making binomial coefficients appear)

$= \frac{m \cdot x! \cdot (n-x)!}{(n+m)!} \cdot \displaystyle\sum_{l=0}^{x}\frac{(m-1+x-l)!(l+1)}{(x-l)!} \displaystyle \sum_{i=0}^{n}\binom{i+1}{l+1}\binom{n+m-i-1}{m-1+x-l}$

Recall that $\displaystyle\sum_{i}\binom{i}{a}\binom{n-i}{b-a} = \binom{n+1}{b+1}$, because we can count the right hand side by fixing the position of the $(a+1)$-th element, where $i$ denotes the number of elements on the left of the $(a+1)$-th element. 

Hence,

$= \frac{m \cdot x! \cdot (n-x)!}{(n+m)!} \cdot \displaystyle\sum_{l=0}^{x}\frac{(m-1+x-l)!(l+1)}{(x-l)!} \cdot \binom{n+m+1}{m+x+1}$

$= \frac{m \cdot x! \cdot (n-x)!}{(n+m)!} \cdot \binom{n+m+1}{m+x+1} \cdot \displaystyle\sum_{l=0}^{x}\frac{(m-1+x-l)!}{(x-l)!} \cdot (l+1)$

$= \frac{m \cdot x! \cdot (n-x)!}{(n+m)!} \cdot \binom{n+m+1}{m+x+1} \cdot \displaystyle\sum_{l=0}^{x}\frac{(m-1+l)!}{l!} \cdot (x-l+1)$.

We can compute the latter sum in $O(1)$ via prefix sums (after splitting $x+1$ and $-l$). A similar computation can be done for $\displaystyle\sum_{l=0}^{x}\displaystyle\sum_{i=0}^{n}\binom{x}{l}\binom{n-x}{i-l} \cdot i! \cdot m \cdot \frac{(n+m-i-1)!}{(n+m)!} \cdot f(x-l)$.

Hence, $f(x)$ can be computed in $O(1)$ (with prefix sums) for $x=1$ to $n$. This gives a $O(n+m)$ time solution if you precompute factorials.

 **Solution (C++) by zscoder**
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int MOD = 998244353;

vector<int> fact;
vector<int> ifact;
vector<int> pow2;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<0) return 0;
	if(b<0) return 0;
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
}
	
int solve_slow(int n, int m)
{
	vi f(n+1,0);
	for(int k=1;k<=n;k++)
	{
		int sum=0;
		for(int l=1;l<=k;l++)
		{
			for(int i=0;i<=n;i++)
			{
				int coeff = mult(mult(choose(k,l),mult(choose(n-k,i-l), mult(fact[i], mult(m, fact[n+m-i-1])))), ifact[n+m]);
				radd(sum, mult(coeff, add(f[k-l],i+1)));
			}
		}
		{
			int l=0;
			int sumcoeff=0;
			for(int i=0;i<=n;i++)
			{
				int coeff = mult(mult(choose(k,l),mult(choose(n-k,i-l), mult(fact[i], mult(m, fact[n+m-i-1])))), ifact[n+m]);
				radd(sum, mult(coeff, i+1));
				radd(sumcoeff,coeff);
			}
			int actualcoeff = add(1,MOD-sumcoeff);
			assert(actualcoeff!=0);
			f[k]=mult(inverse(actualcoeff),sum);
		}
	}
	return f[n];
}

int solve_fast(int n, int m)
{
	vi f(n+1,0);
	int presum=0;
	for(int k=1;k<=n;k++)
	{
		int sum=mult(presum,choose(n+m,m+k));
		radd(sum,mult(fact[m-1],mult(choose(m+k+1,m+1),choose(n+m+1,m+k+1))));
		int outsidecoeff = mult(fact[k],mult(fact[n-k],mult(ifact[n+m],m)));
		sum = mult(sum, outsidecoeff);
		f[k]=mult(mult(m+k,mult(ifact[k],fact[k-1])),sum);
		//f[k]=mult(mult(k,mult(fact[m+k-1],ifact[m+k])),sum);
		radd(presum,mult(fact[m+k-1],mult(ifact[k],f[k])));
	}
	return f[n];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(int(1e7)+100);
	int n,m; cin>>n>>m;
	//cout<<solve_slow(n,m)<<'n';
	cout<<solve_fast(n,m)<<'n';
}
```
 **Solution (Java) by qlf9**
```cpp
import java.util.*;
import java.io.*;

public class ZSShufflesCards {
    public static long MOD = 998244353;
    public static long[] fact;
    public static long[] invfact;
    public static long[] pow2;
    public static int MAX = 4000005;
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        fact = new long[MAX];
        invfact = new long[MAX];
        pow2 = new long[MAX];
        fact[0] = 1;
        invfact[0] = 1;
        pow2[0] = 1;
        for(int i = 1; i < MAX; i++){
            pow2[i] = add(pow2[i-1], pow2[i-1]);
            fact[i] = mult(fact[i-1], i);
        }
        invfact[MAX-1] = inverse(fact[MAX-1]);
        for(int i = MAX-2; i >= 1; i--){
            invfact[i] = mult(invfact[i+1], i+1);
        }
        long[] ans = new long[n+1];
        long currsum = 0;
        for(int k = 1; k <= n; k++){
            long sum = mult(currsum, ncr(n+m, m+k));
            sum = add(sum,mult(fact[m-1],mult(ncr(m+k+1,m+1),ncr(n+m+1,m+k+1))));
            long outsidecoeff = mult(fact[k],mult(fact[n-k],mult(invfact[n+m],m)));
            sum = mult(sum, outsidecoeff);
            ans[k]=mult(mult(m+k,mult(invfact[k],fact[k-1])),sum);
            currsum = add(currsum,mult(fact[m+k-1],mult(invfact[k],ans[k])));
        }
        out.println(ans[n]);
        out.close();

    }
    public static long add(long a, long b){
        return((a+b)%MOD+MOD)%MOD;
    }
    public static long mult(long a, long b){
        return((a*b)%MOD+MOD)%MOD;
    }
    public static long pow(long a, long b){
        long ans = 1;
        while(b > 0){
            if((b&1) == 1) ans = mult(ans, a);
            a = mult(a, a);
            b>>=1;
        }
        return ans;
    }
    public static long ncr(long a, long b){
        if(a<0) return 0;
        if(b<0) return 0;
        if(a<b) return 0;
        if(b==0) return 1;
        if(a==b) return 1;
        return mult(fact[(int)a],mult(invfact[(int)b],invfact[(int)(a-b)]));
    }
    public static long inverse(long a){
        return pow(a, MOD-2);
    }
}
```
 **Solution (Kotlin) by Tlatoani**
```cpp
const val MOD = 998244353L

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val factorial = LongArray(4000002)
    factorial[0] = 1L
    for (j in 1..4000001) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val factInv = LongArray(4000002)
    factInv[4000001] = factorial[4000001] pow -1
    for (j in 4000000 downTo 0) {
        factInv[j] = ((j + 1).toLong() * factInv[j + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (a < 0 || b < 0 || b > a) 0L else (factorial[a] * ((factInv[b] * factInv[a - b]) % MOD)) % MOD
    val answer = LongArray(n + 1)
    var currSum = 0L
    for (k in 1..n) {
        var sum = currSum * choose(n + m, m + k)
        sum %= MOD
        sum += factorial[m - 1] * ((choose(m + k + 1, m + 1) * choose(n + m + 1, m + k + 1)) % MOD)
        sum %= MOD
        sum *= (factorial[k] * ((factorial[n - k] * ((factInv[n + m] * m.toLong()) % MOD)) % MOD)) % MOD
        sum %= MOD
        answer[k] = sum * (((m + k).toLong() * ((factInv[k] * factorial[k - 1]) % MOD)) % MOD)
        answer[k] %= MOD
        currSum += factorial[m + k - 1] * ((factInv[k] * answer[k]) % MOD)
        currSum %= MOD
    }
    println(answer[n])
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
Idea: [zscoder](https://codeforces.com/profile/zscoder "International Grandmaster zscoder")

Preparation: [zscoder](https://codeforces.com/profile/zscoder "International Grandmaster zscoder")

 
### [1392I - Kevin and Grid](../problems/I._Kevin_and_Grid.md "Codeforces Global Round 10")

An obvious solution would be to do DFS, but it is $O(nmq)$.

Firstly we focus on answering a single question.

We represent our input with two graphs (one for cells with temperature less than X and other for temperatures greater than X), in which we add an edge between two neigbouring cells.

As it is a subgraph of the grid graph, this means that this graph is planar and thus we may apply Euler's formula on both graphs:

$V_1+F_1=E_1+C_1$, where V1 is the number of vertices in graph 1, F1 is the number of faces in graph 1, $\dots$.

However, some faces are not interesting, namely the $2 \times 2$ square of adjacent cells. Let $Q_1$ be the number of such squares.

Similarly, $V_2+F_2=E_2+1+C_2$.

We see that interesting faces in graph 1 represent connected components in graph 2 that cannot reach the border, and vice-versa. In this way, if we subtract the equations, we get $C_1-F_1+F_2-C_2=V_1-E_1+E_2-V_1+Q_1-Q_2$. We can observe that, because of this interpretation, the LHS of the equation is the answer.

We have to devise an algorithm to calculate efficiently the number of squares/edges. Letś calculate horizontal edges, and do the same for vertical edges.

Firstly, if $a_i+b_j \geq X$ and $a_i+b_{j+1} \geq X$ then $a_i+min(b_j,b_{j+1}) \geq X$. So we create array $B$ such that $B_j=min(b_j,b_{j+1})$.

The number of edges is the number of indexes $i,j$ such that $a_i+B_j \geq X$.

This trick can also be used to calculate edges in cold regions.

To have a more efficient solution, we must calculate faster the number of indexes $i,j$ such that $a_i+B_j \geq X$.

We can thus apply fast Fourier transform to arrays representing frequencies of $a$ and $B$ and multiply them, inverting the Fourier transform in order to get the answers quickly in O(1) with prefix sums.

By doing this we can calculate the number of edges, and the number of $2 \times 2 $ squares can be calculated in a similar way.

The final complexity is, thus, $O((n+m)log(n+m)+max(a_i,b_i)log(max(a_i,b_i)))$

 **Solution (C++) by KLPP**
```cpp
#include<bits/stdc++.h>

using namespace std;
#define MAX 262144
#define MAXN 1000000
long long int a[MAXN],b[MAXN];


using cd = complex<double>;
const double PI = acos(-1);
vector<cd> A(MAX),B(MAX);
vector<cd> Amx(MAX),Bmx(MAX);
vector<cd> Amn(MAX),Bmn(MAX);
vector<cd> E11(MAX),E12(MAX),E21(MAX),E22(MAX);
vector<cd> SQ1(MAX),SQ2(MAX);
vector<cd> V(MAX);
vector<long long int> A1(MAX),A2(MAX);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
void prod(vector<cd> &a, vector<cd> &b, vector<cd> &c){
  for(int i=0;i<a.size();i++){
    c[i]=a[i]*b[i];
  }
}

int main(){
  long long int n,m,q;
  scanf("%lld %lld %lld",&n,&m,&q);
  
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i=0;i<m;i++){
    scanf("%lld",&b[i]);
  }
  for(int i=0;i<MAX;i++){
    A[i]=cd(0,0);
    Amn[i]=cd(0,0);
    Amx[i]=cd(0,0);
    B[i]=cd(0,0);
    Bmn[i]=cd(0,0);
    Bmx[i]=cd(0,0);
  }
  for(int i=0;i<n;i++){
    A[a[i]]+=cd(1,0);
  }
  for(int i=0;i<n-1;i++){
    Amn[min(a[i],a[i+1])]+=cd(1,0);
  }
  for(int i=0;i<n-1;i++){
    Amx[max(a[i],a[i+1])]+=cd(1,0);
  }
  for(int i=0;i<m;i++){
    B[b[i]]+=cd(1,0);
  }
  for(int i=0;i<m-1;i++){
    Bmn[min(b[i],b[i+1])]+=cd(1,0);
  }
  for(int i=0;i<m-1;i++){
    Bmx[max(b[i],b[i+1])]+=cd(1,0);
  }
  
  fft(A,0);
  fft(Amn,0);
  fft(Amx,0);
  fft(B,0);
  fft(Bmn,0);
  fft(Bmx,0);
  prod(A,Bmn,E11);
  prod(Amn,B,E12);
  prod(Amx,B,E21);
  prod(A,Bmx,E22);
  prod(Amn,Bmn,SQ1);
  prod(Amx,Bmx,SQ2);
  prod(A,B,V);
  fft(E11,1);
  fft(E12,1);
  fft(E21,1);
  fft(E22,1);
  fft(SQ1,1);
  fft(SQ2,1);
  fft(V,1);
  for(int i=0;i<MAX;i++){
    A1[i]=round(SQ1[i].real())-round(E11[i].real())-round(E12[i].real())+round(V[i].real());
    A2[i]=round(SQ2[i].real())-round(E21[i].real())-round(E22[i].real())+round(V[i].real());
  }
  for(int i=1;i<MAX;i++){
    A2[i]+=A2[i-1];
  }
  for(int i=MAX-2;i>-1;i--){
    A1[i]+=A1[i+1];
  }
  for(int i=0;i<q;i++){
    int query;
    scanf("%d",&query);
    //cout<<A1[query]<<" "<<A2[query-1]<<endl;
    printf("%lldn",A1[query]-A2[query-1]);
  }
  return 0;
}
```
Idea: [KLPP](https://codeforces.com/profile/KLPP "Master KLPP")

Preparation: [KLPP](https://codeforces.com/profile/KLPP "Master KLPP")

