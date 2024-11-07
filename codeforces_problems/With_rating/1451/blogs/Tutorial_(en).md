# Tutorial_(en)

[1451A - Subtract or Divide](../problems/A._Subtract_or_Divide.md "Codeforces Round 685 (Div. 2)")

 **Tutorial**
### [1451A - Subtract or Divide](../problems/A._Subtract_or_Divide.md "Codeforces Round 685 (Div. 2)")

Key Idea:

For $n > 3$, the answer is $2$ when $n$ is even and $3$ when $n$ is odd. Cases when $n \leq 3$ can be handled separately.

Solution:

Case 1: $n \leq 3$

For $n = 1, 2, 3$, it can be shown that the minimum number of operations required are $0$, $1$, $2$ respectively.

Case 2: $n > 3$ and $n$ is even

If $n$ is even and greater than $2$, then $\frac{n}{2}$ is a proper divisor. So we can divide $n$ by $\frac{n}{2}$ to make it $2$ and then subtract $1$. This requires $2$ operations.

Case 3: $n > 3$ and $n$ is odd

In this case, $n$ can be made even by subtracting $1$. From case 2, it can be seen that it will take $2$ more operations. Thus a total of $3$ operations are required.

Time complexity: $O(1)$ per case

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (n <= 3? n-1 : 2 + (n&1)) << 'n';
    }
    return 0;
}
```
 **Code (Java)**
```cpp
import java.util.*;
import java.util.ArrayList;
public class Main {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i = 0; i < t; i++)
        {
            int n = sc.nextInt();
            System.out.println(Math.min(2 + (n & 1), n - 1));
        }
    }
}
```
Idea by [ridbit10](https://codeforces.com/profile/ridbit10 "Expert ridbit10")

[1451B - Non-Substring Subsequence](../problems/B._Non-Substring_Subsequence.md "Codeforces Round 685 (Div. 2)")

 **Tutorial**
### [1451B - Non-Substring Subsequence](../problems/B._Non-Substring_Subsequence.md "Codeforces Round 685 (Div. 2)")

Key Idea:

In each query, the answer is YES iff the first character of the given substring is not the first occurence of that character or the last character of the given substring is not the last occurrence of that character in the string.

Solution:

The condition stated above is both necessary and sufficient.

Proof that it is necessary:

Assume that a non-contiguous subsequence exists when the condition is false. If the first character of the substring is the first occurrence of its kind, then the subsequence cannot start before it. Similarly, if the last character of the substring is the last occurrence of its kind, then the subsequence cannot end after it. In such a case, the only subsequence that is of the same length as the given substring and equal to it, is the substring itself. However, this subsequence is contiguous  — which is a contradiction.

Thus, it is a necessary condition.

Proof that it is sufficient:

If the first character of the substring $s[l_i...r_i]$ occurs at some index $j$ $(j < l_i)$, then the subsequence $s_js_{l_i+1}...s_{r_i}$ is good.

If the last character of the substring $s[l_i...r_i]$ occurs at some index $j$ $(j > r_i)$, then the subsequence $s_{l_i}...s_{r_i-1}s_j$ is good.

Thus it is sufficient.

Time complexity: $O(nq)$ or $O(n+q)$ for each case depending on implementation.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, n, Q; string s;
        cin >> n >> Q >> s;
        while(Q--) {
            int l, r; cin >> l >> r; --l; --r;
            bool bad = true;
            for(i = 0; i < l and bad; i++)
                if(s[i] == s[l]) bad = false;
            for(i = r+1; i < n and bad; i++)
                if(s[i] == s[r]) bad = false;
            cout << (bad? "NO" : "YES") << 'n';
        }
    }
    return 0;
}
```
 **Code (Java)**
```cpp
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int t = Integer.parseInt(br.readLine());
        for(int cases = 0; cases < t; cases++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            String s = br.readLine();
            int fi[] = new int[2];
            int la[] = new int[2];
            for(int j = 0; j < 2; j++)
            {
                fi[j] = 2000000000;
                la[j] = -1;
            }
            for(int i = 0; i < s.length(); i++)
            {
                int cur = (s.charAt(i) - '0');
                fi[cur] = Math.min(fi[cur], i);
                la[cur] = i;
            }
            for(int i = 0; i < q; i++)
            {
                st = new StringTokenizer(br.readLine());
                int l = Integer.parseInt(st.nextToken()) - 1;
                int r = Integer.parseInt(st.nextToken()) - 1;
                int curl = (s.charAt(l) - '0');
                int curr = (s.charAt(r) - '0');
                if(fi[curl] < l || la[curr] > r)
                    System.out.println("YESn");
                else
                    System.out.println("NOn");
            }
        }
    }
}
```
Idea by [the_hyp0cr1t3](https://codeforces.com/profile/the_hyp0cr1t3 "Candidate Master the_hyp0cr1t3")

[1451C - String Equality](../problems/C._String_Equality.md "Codeforces Round 685 (Div. 2)")

 **Tutorial**
### [1451C - String Equality](../problems/C._String_Equality.md "Codeforces Round 685 (Div. 2)")

Key Idea:

For the answer to be YES, the frequencies of each character of the alphabet must match after performing some sequence of operations. Let $freq_{i, a}$ and $freq_{i, b}$ be the frequencies of the $i$-th character of the alphabet in strings $a$ and $b$ respectively. For each $i$ starting from "a", we keep exactly $freq_{i, b}$ of the occurrences and try to to convert the rest into the next character. If at any step, this is not possible, the answer is NO.

Solution:

Consider operations of the first type. It can be shown that after some finite sequence of swaps, we can reorder the string in any way we like. This is helpful because we do not have to worry about the characters being adjacent when we perform an operation of the second type (we can always reorder the string to allow it). In other words, only frequency of the characters matter.

To convert string $a$ into string $b$, we first make the frequencies of each character of the alphabet equal, then reorder the string using operations of the first type. The former can be done as described above. If for any $i$, there are an insufficient number of occurrences ($freq_{i, a} \lt freq_{i, b}$) or the remaining occurrences cannot all be converted into the next character, i.e. $(freq_{i, a} - freq_{i, b})$ is not a multiple of $k$, the answer is NO. Otherwise, the answer is YES.

Time complexity: $O(n)$

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, n, k; string a, b;
        cin >> n >> k >> a >> b;
        array<int, 27> have{}, need{};
        for(auto& c: a)
            have[c-'a']++;
        for(auto& c: b)
            need[c-'a']++;
     
        bool bad = false;
        for(i = 0; i < 26; i++) {
            if(have[i] < need[i] || (have[i] -= need[i]) % k)
                bad = true;
            have[i+1] += have[i];
        }
        cout << (bad? "No" : "Yes") << 'n';
    }
    return 0;
}
```
 **Code (Java)**
```cpp
import java.util.*;
import java.util.ArrayList;
public class Main {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int cases = 0; cases < t; cases++)
        {
            int n = sc.nextInt();
            int k = sc.nextInt();
            sc.nextLine();
            String a = sc.nextLine();
            String b = sc.nextLine();
            int have[] = new int[27];
            int need[] = new int[27];
            for(int i = 0; i < n; i++)
            {
                have[a.charAt(i) - 'a']++;
                need[b.charAt(i) - 'a']++;
            }
            boolean bad = false;
            for(int j = 25; j >= 0; j--)
            {
                have[j] += have[j + 1];
                need[j] += need[j + 1];
                if(have[j] > need[j] || (need[j] - have[j]) % k != 0)
                    bad = true;
            }
            if(bad)
                System.out.println("No");
            else
                System.out.println("Yes");
        }
    }
}
```
Idea by [Ashishgup](https://codeforces.com/profile/Ashishgup "Grandmaster Ashishgup")

[1451D - Circle Game](../problems/D._Circle_Game.md "Codeforces Round 685 (Div. 2)")

 **Tutorial**
### [1451D - Circle Game](../problems/D._Circle_Game.md "Codeforces Round 685 (Div. 2)")

Key Idea:

Let $z$ be the maximum integer such that the point $(kz, kz)$ is within the circle. If the point $(kz, k(z+1))$ is also within the circle, player 1 wins. Otherwise player 2 wins.

Solution:

Regardless of what move player 1 makes, player 2 can force the token to be at some point on the line $x = y$ at the end of his turn (if player 1 moves up, player 2 can move right and vice versa).

Case 1: $(kz, k(z+1))$ lies outside the circle

Player 2 can guarantee his victory in this fashion as player 1 will not have any moves left after reaching the point $(kz, kz)$. Player 2 wins.

Case 2: $(kz, k(z+1))$ lies within the circle

After player 1 makes his first move, player 2 finds himself in the same situation as player 1 did in the previous case. That is, player 1 can ensure that they reach either $(kz, k(z+1))$ or $(k(z+1), kz)$ in the same way. Points $(k(z+1), k(z+1))$ and $(kz, k(z+2))$ do not lie within the circle as by definition

 $d^2 \lt k^2(z+1)^2 + k^2(z+1)^2 \lt k^2z^2 + k^2(z+2)^2$. Thus player 2 will not have any moves left and player 1 wins.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int64_t d, k;
        cin >> d >> k;
        int64_t x = 0, y = 0;
        while(true) {
            if(x <= y && (x + k) * (x + k) + y * y <= d * d)
                x += k;
            else if(x > y && (y + k) * (y + k) + x * x <= d * d)
                y += k;
            else
                break;
        }
        if(x == y)
            cout << "Utkarsh" << endl;
        else
            cout << "Ashish" << endl;
    }
    return 0;
}
```
 **Code (Java)**
```cpp
import java.util.*;
import java.util.ArrayList;
public class Main {
    public static boolean is_within(long x, long y, long dsq, long k)
    {
        return dsq - k * k * x * x - k * k * y * y >= 0;
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int cases = 0; cases < t; cases++)
        {
            int d = sc.nextInt();
            long dsq = ((long) d) * d;
            int k = sc.nextInt();
            int cur = 0;
            while(is_within(cur + 1, cur + 1, dsq, k))
                cur++;
            if(is_within(cur + 1, cur, dsq, k))
                System.out.println("Ashish");
            else
                System.out.println("Utkarsh");
        }
    }
}
```
Idea by [Utkarsh.25dec](https://codeforces.com/profile/Utkarsh.25dec "Master Utkarsh.25dec")

[1451E1 - Bitwise Queries (Easy Version)](../problems/E1._Bitwise_Queries_(Easy_Version).md "Codeforces Round 685 (Div. 2)")

 **Tutorial**
### [1451E1 - Bitwise Queries (Easy Version)](../problems/E1._Bitwise_Queries_(Easy_Version).md "Codeforces Round 685 (Div. 2)")

Key Idea:

$a + b = (a \oplus b) + 2 * (a \\& b)$

Pick and distinct $i, j, k$ and find $a_{i} + a_{j} = x$, $a_{i} + a_{k} = y$ and $a_{j} + a_{k} = z$ by querying their XOR and AND values ($6$ queries). This is a system of linear equation with three equations and three variables and thus us a unique solution.

Solving it you get the values of $a_{i}$, $a_{j}$, and $a_{k}$. You can then get the remaining $n - 3$ values using $n - 3$ more queries. This uses a total of $n + 3$ queries. Realize that $a_{j}$ $\oplus$ $a_{k}$ $=$ ($a_{i}$ $\oplus$ $a_{j}$) $\oplus$ ($a_{i}$ $\oplus$ $a_{k}$) to reduce the number of initial queries from $6$ to $5$, for a total of $n + 2$ queries.

Solution:

Lets take a look at the properties of the 3 operations we have, specifically what information we can recover from it.

* AND - lossy in information about bits that are on, cant be used to recover the values
* OR - lossy in information about bits that are off, cant be used to recover the values
* XOR - lossless, a $\oplus$ (a $\oplus$ b) gives us b again.

So clearly xor operations are going to be the core of recovering the values. If we can find one of the values, we can find the remaining $n - 1$ values using xor queries.

But how do we get that first value?

Lets try to think about this for a operation for which we know how to obtain the individual values - addition. If we had $a + b = x$, $a + c = y$ and $b + c = z$, we could just solve the three linear equations to obtain the answer.

So what's the difference between xor and addition anyway?

* If the $i$-th bit is off in both the numbers, xor and addition both give 0.
* If the $i$-th bit is on in exactly oneof the numbers, xor and addition will both give $2^{i}$ .
* But what about if the $i$-th bit is on in the both the numbers? Then addition contributes $2 * 2^{i}$ to the answer while xor contributes 0.

Is there some way to recover this value? Well if $i$-th bit is on in the both the numbers, the AND will contribute $2^{i}$ to the answer. So we can realize that $a + b$ can be rewritten as (a $\oplus$ $b$) + $2 \times$ (a $\\&$ b).

So now if we just choose positions $1$, $2$ and $3$, we can obtain $x = a_{1} + a_{2}$, $y = a_{1} + a_{3}$ and $z = a_{2} + a_{3}$ using $3$ XOR and $3$ AND operations. Furthermore we can realize that $a_{2}$ $\oplus$ $a_{3}$ is just ($a_{1}$ $\oplus$ $a_{2}$) $\oplus$ ($a_{1}$ $\oplus$ $a_{3}$), so we can save one more operation.

Now solving the above simultaneous equations, we get $a_{1}$ = $\frac{x + y - z}{2}$. Now for $2 \leq i \leq n$, $a_{i}$ is just $a_{1}$ $\oplus$ ($a_{1}$ $\oplus$ $a_{i}$). We already calculated $a_{1}$ $\oplus$ $a_{2}$ and $a_{1}$ $\oplus$ $a_{3}$ for the previous step, and can calculate the remaining xor values in $n - 3$ steps.

So in total we use exactly $5 + (n - 3)$ = $n + 2$ queries, which is enough to get AC.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;
 
const int maxn = (1ll << 16) + 5, minn = 4, maxncheck = (1ll << 16);
 
int n, xorvals[maxn], ans[maxn];
 
void andqueries(string s, int& dest)
{
    cout << s << endl;
    cout.flush();
    cin >> dest;
    if(dest == -1)
        exit(0);
    return;
}
 
int32_t main()
{
    cin >> n;
    assert(n >= minn && n <= maxncheck && __builtin_popcount(n) == 1);
    for(int i = 2; i <= n; i++)
    {
        cout << "XOR 1 " << i << endl;
        cout.flush();
        cin >> xorvals[i];
        if(xorvals[i] == -1)
            return 0;
    }
    int xor12 = xorvals[2], xor13 = xorvals[3], xor23 = xorvals[2] ^ xorvals[3];
    int and12, and13, and23;
    andqueries("AND 1 2", and12);
    andqueries("AND 1 3", and13);
    andqueries("AND 2 3", and23);
    int x = xor12 + 2 * and12;
    int y = xor13 + 2 * and13;
    int z = xor23 + 2 * and23;
    assert((x + y - z) % 2 == 0);
    ans[1] = (x + y - z) / 2;
    for(int i = 2; i <= n; i++)
        ans[i] = (xorvals[i] ^ ans[1]);
    cout << "! ";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    cout.flush();
    return 0;
}
```
 **Code (Java)**
```cpp
import java.util.Scanner;
 
public class Main {
    public static int queries(String s, Scanner sc)
    {
        System.out.println(s);
        System.out.flush();
        int x = sc.nextInt();
        if(x == -1)
            System.exit(0);
        return x;
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int xorvals[] = new int[n + 1];
        int ans[] = new int[n + 1];
        for(int i = 2; i <= n; i++)
            xorvals[i] = queries("XOR 1 " + i, sc);
        int xor12 = xorvals[2], xor13 = xorvals[3], xor23 = xorvals[2] ^ xorvals[3];
        int and12, and13, and23;
        and12 = queries("AND 1 2", sc);
        and13 = queries("AND 1 3", sc);
        and23 = queries("AND 2 3", sc);
        int x = xor12 + 2 * and12;
        int y = xor13 + 2 * and13;
        int z = xor23 + 2 * and23;
        assert((x + y - z) % 2 == 0);
        ans[1] = (x + y - z) / 2;
        for(int i = 2; i <= n; i++)
            ans[i] = (xorvals[i] ^ ans[1]);
        System.out.print("! ");
        for(int i = 1; i <= n; i++)
            System.out.print(ans[i] + " ");
        System.out.println();
        System.out.flush();
    }
}
```
Idea by [Ashishgup](https://codeforces.com/profile/Ashishgup "Grandmaster Ashishgup") and [ridbit10](https://codeforces.com/profile/ridbit10 "Expert ridbit10")

[1451E2 - Bitwise Queries (Hard Version)](../problems/E2._Bitwise_Queries_(Hard_Version).md "Codeforces Round 685 (Div. 2)")

 **Tutorial**
### [1451E2 - Bitwise Queries (Hard Version)](../problems/E2._Bitwise_Queries_(Hard_Version).md "Codeforces Round 685 (Div. 2)")

Key Idea:

Query the $n - 1$ xor values of the form $(1, i)$, for $2 \leq i \leq n$ initially.

Since numbers lie in the range $[0, n - 1]$, one of two cases can arise:

1. There exists indices j, k such that $a_{j} = a_{k}$. This can be found as $a_{i}$ $\oplus$ $a_{j}$ $=$ $a_{i}$ $\oplus$ $a_{k}$. So we can just use the query $a_{j}$ $\\&$ $a_{k}$ to get the value of $a_{j}$. Now we can find the remaining values using the xor values previous queried in$ (n - 1) + 1 = n$ queries.

2. All integers in the range $[0, n - 1]$ are present. There exists (several) pairs $j, k$ such that $a_{j}$ $\oplus$ $a_{k}$ $=$ $n - 1$. This implies that neither of the numbers have any bits in common and as such $a_{j}$ $\\&$ $a_{k}$ $=$ $0$, allowing us to save one query compared to E1. Thus we need $(n - 1) + 3 - 1 = (n + 1)$ queries.

Solution:

Now we have to eliminate $1$ more query but we are yet to use the info that all values of a are in the range $[0, n - 1]$.

It may be tempting to try to remove a xor query, but it is unlikely this will work, as we would not be able differentiate between two arrays which are equal in $n - 1$ places and differ in the position we didn't check. As such it doesn't seem probable that we can recover the exact value if we don't use $n - 1$ xor operations.

Since we'll need them anyway, lets go ahead and find $a_{1}$ $\oplus$ $a_{i}$ for all $2 \leq i \leq n$.

Then clearly we have to eliminate $1$ of the $3$ AND queries.

Since numbers lie in the range $[0, n - 1]$, one of two cases must arise:

1. At least one value is repeated. Clearly if $a_{1}$ $\oplus$ $a_{j} = a_{1}$ $\oplus$ $a_{k}$, then $a_{j} = a_{k}$. So we can use the already queried xor values to check if there exists two such values. Its easy to see that $x$ $\\&$ $x$ is $x$ itself, so we can get the value of $a_{j}$ using the query $a_{j}$ $\\&$ $a_{k}$. Now we can just the xor values to find the remaining values. This needs $(n - 1) + 1 = n$ queries.
2. All integers in the range $[0, n - 1]$ are present.
	* We're trying to find a pair of values $(a_{j}, a_{k})$ for which we can find $a_{j}$ $\\&$ $a_{k}$ without needing to query it. However we don't have any equal pair like the last case.
	* The next easiest value that comes to mind would be $0$. Can we easily select a pair with AND value zero based on just the info we currently have? Well if the $i$-th bit of $a_{j}$ $\oplus$ $a_{k}$ is on, then it must undoubtedly have been on in either $a_{j}$ or $a_{k}$, not both. But we can't make any such statements about a bit being off, since the bit could be off in both (satisfying the condition), or on in both (doesn't satisfy nonzero AND).
	* So can we choose a pair $(a_{j}, a_{k})$ such that all bits are on? Yes we can, this value will be $n - 1$ since $n$ is a power of $2$ and there will be $\frac{n}{2}$ pairs which equal it ($(0, n - 1)$, $(1, n - 2)$, $(2, n - 3)$, etc). So we can just find any one pair such that $a_{j}$ $\oplus$ $a_{k}$ $=$ $n - 1$.
	* Now we know $a_{j}$ $\\&$ $a_{k}$ $=$ $0$ and can reduce the number of required AND queries by $1$. So we will need $(n - 1) + 3 - 1 = (n + 1)$ queries.

It is easy to see that these two cases cover all situations possible and in both cases we can find the answer in at max $(n + 1)$ queries which is enough to get AC.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;
 
const int maxn = (1ll << 16) + 5, minn = 4, maxncheck = (1ll << 16);
 
int n, xorvals[maxn], ans[maxn];
vector<int> pos[maxn];
 
int queries(string s, int i, int j)
{
    cout << s << " " << i << " " << j << endl;
    cout.flush();
    int dest;
    cin >> dest;
    if(dest == -1)
        exit(0);
    return dest;
}
 
int32_t main()
{
    cin >> n;
    assert(n >= minn && n <= maxncheck && __builtin_popcount(n) == 1);
    xorvals[1] = 0;
    pos[0].push_back(1);
    for(int i = 2; i <= n; i++)
    {
        xorvals[i] = queries("XOR", 1, i);
        pos[xorvals[i]].push_back(i);
    }
    int a = 1, b = -1, c = -1;
    int same = -1;
    for(int i = 0; i < n; i++)
        if(pos[i].size() > 1)
        {
            b = pos[i][0];
            c = pos[i][1];
            same = i;
        }
    if(same == -1)
    {
        // If a_b ^ a_c == n - 1, then a_b & a_c = 0 
        for(int i = 2; i <= 3; i++)
            for(int j = i + 1; j <= n; j++)
                if((xorvals[i] ^ xorvals[j]) == n - 1)
                {
                    b = i;
                    c = j;
                }
        int xorab = xorvals[a] ^ xorvals[b], xorac = xorvals[a] ^ xorvals[c], xorbc = xorvals[b] ^ xorvals[c];
        int andab = queries("AND", a, b);
        int andac = queries("AND", a, c);
        int andbc = 0;
        int x = xorab + 2 * andab;
        int y = xorac + 2 * andac;
        int z = xorbc + 2 * andbc;
        assert((x + y - z) % 2 == 0);
        ans[a] = (x + y - z) / 2;
    }
    else
    {
        // if a_1 ^ a_b == a_1 ^ a_c, then a_b = a_c = (a_b & a_c)
        ans[b] = queries("AND", b, c);
        ans[1] = xorvals[b] ^ ans[b];
    }
    for(int i = 2; i <= n; i++)
        ans[i] = (xorvals[i] ^ ans[1]);
    cout << "! ";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    cout.flush();
    return 0;
}
```
 **Code (Java)**
```cpp
import java.util.*;
import java.util.ArrayList;
public class Main {
    public static int queries(String s, int i, int j, Scanner sc)
    {
        System.out.println(s + " " + i + " " + j);
        System.out.flush();
        int x = sc.nextInt();
        if(x == -1)
            System.exit(0);
        return x;
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> pos[] = new ArrayList[n + 1];
        for(int i = 0; i <= n; i++)
            pos[i] = new ArrayList<Integer>();
        int xorvals[] = new int[n + 1];
        int ans[] = new int[n + 1];
        xorvals[1] = 0;
        pos[0].add(1);
        for(int i = 2; i <= n; i++)
        {
            xorvals[i] = queries("XOR", 1, i, sc);
            pos[xorvals[i]].add(i);
        }
        int a = 1, b = -1, c = -1;
        int same = -1;
        for(int i = 0; i < n; i++)
        if(pos[i].size() > 1)
            {
                b = pos[i].get(0);
                c = pos[i].get(1);
                same = i;
            }
        if(same == -1)
        {
            // If a_b ^ a_c == n - 1, then a_b & a_c = 0 
            for(int i = 2; i <= 3; i++)
                for(int j = i + 1; j <= n; j++)
                    if((xorvals[i] ^ xorvals[j]) == n - 1)
                    {
                        b = i;
                        c = j;
                    }
            assert(b != -1 && c != -1);
            int xorab = xorvals[a] ^ xorvals[b], xorac = xorvals[a] ^ xorvals[c], xorbc = xorvals[b] ^ xorvals[c];
            int andab = queries("AND", a, b, sc);
            int andac = queries("AND", a, c, sc);
            int andbc = 0;
            int x = xorab + 2 * andab;
            int y = xorac + 2 * andac;
            int z = xorbc + 2 * andbc;
            assert((x + y - z) % 2 == 0);
            ans[a] = (x + y - z) / 2;
        }
        else
        {
            // if a_1 ^ a_b == a_1 ^ a_c, then a_b = a_c = (a_b & a_c)
            ans[b] = queries("AND", b, c, sc);
            ans[1] = xorvals[b] ^ ans[b];
        }
        for(int i = 2; i <= n; i++)
            ans[i] = (xorvals[i] ^ ans[1]);
        System.out.print("! ");
        for(int i = 1; i <= n; i++)
            System.out.print(ans[i] + " ");
        System.out.println();
        System.out.flush();
    }
}
```
Idea by [FastestFinger](https://codeforces.com/profile/FastestFinger "Master FastestFinger"), [Ashishgup](https://codeforces.com/profile/Ashishgup "Grandmaster Ashishgup") and [ridbit10](https://codeforces.com/profile/ridbit10 "Expert ridbit10")

[1451F - Nullify The Matrix](../problems/F._Nullify_The_Matrix.md "Codeforces Round 685 (Div. 2)")

 **Tutorial**
### [1451F - Nullify The Matrix](../problems/F._Nullify_The_Matrix.md "Codeforces Round 685 (Div. 2)")

Let's consider diagonals $d$ of the form $r+c$ - the diagonals where the sum of row index $(r)$ and column index $(c)$ is constant. Then xor of a diagonal $d$ will be $xor(d) = a(r_1,c_1)\oplus a(r_2,c_2)\oplus...a(r_n,c_n)$, such that $r_1 + c_1 = d$, $r_2 + c_2 = d$, .... $r_n + c_n = d$.

$Solution:$ If $\forall d,\hspace{0.1cm}xor(d) = 0$ at the start of the game, then Jeel wins. Else, Ashish wins. 

$Proof:$ 

Let's define two states $S$ and $S'$:

$S$ : $\forall d,\hspace{0.1cm}xor(d) = 0$

$S'$ : $\exists d,\hspace{0.1cm}xor(d) \ne 0$

$Lemma\hspace{0.1cm}1:$ Any move on $S$ converts the matrix to $S'$.

$Proof:$ If we are in state $S$, $xor(r1 + c1)=0$. Since, we need to anyhow decrease value of $(r1, c1)$, $xor(r1 + c1)$ will become non-zero. Hence, any move on $S$ converts the matrix to $S'$.

$Lemma\hspace{0.1cm}2:$ There always exists a move on $S'$ to convert it to $S$.

$Proof:$ If we are given an $S'$ state, we can convert it into $S$ as follows: Note that the diagonals between $(r1 + c1)$ and $(r2 + c2)$ can be arbitrarily changed to any value. $(r1, c1)$ can only be decreased in value. Let $(r1 + c1)$ be such a diagonal that there is no diagonal $d < r1 + c1$ with $xor(d) != 0$. Also, in order to ensure that we can make $xor(r1 + c1) = 0$ by decreasing, we select such a cell $(r1, c1)$ whose largest set bit is equal to the largest set bit of $xor(r1 + c1)$. In this way, we ensure that diagonal $r1 + c1$ can be made $0$. Now, we need to fix $(r2, c2)$. Let's fix $(r2, c2)$ such that there is no diagonal $d > r2 + c2$, such that $xor(d) != 0$. Since, (r2, c2) can be increased as well as decreased, we can easily make $xor(r2 + c2) = 0$. The diagonals in between can be arbitarily changed, so making them $0$ is trivial. At the end of this move, all diagonals have become $0$. Hence, given a state $S'$, we can always convert it to $S$. 

Due to $Lemma\hspace{0.1cm}1$ and $Lemma\hspace{0.1cm}2$, a person starting on state $S'$ can always stay at $S'$ and can always force the opponent to start on state $S$. Since the state at the end of the game will be $S$, the opponent will always lose.

Complexity: $O(n * m)$

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "n"
#define int long long
 
const int N = 105;
 
int n, m;
int a[N][N], xorsum[2 * N];
 
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while(t--)
    {
        memset(xorsum, 0, sizeof(xorsum));
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                xorsum[i + j] ^= a[i][j];
            }
        }
        int flag = 1;
        for(int i = 1; i <= n + m; i++)
            flag &= (xorsum[i] == 0);
        if(!flag)
            cout << "Ashish" << endl;
        else
            cout << "Jeel" << endl;
    }
    return 0;
}
```
 **Code (Java)**
```cpp
import java.util.*;
 
public class NullifyTheMatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
 
        for(int x = 0; x < t; ++x) {
            int n = sc.nextInt();
            int m = sc.nextInt();
 
            int mat[][] = new int[n][m];
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j)
                    mat[i][j] = sc.nextInt();
            }
 
            int xors[] = new int[n + m - 1];
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j)
                    xors[i + j] ^= mat[i][j];
            }
 
            int flag = 0;
            for(int xor : xors) {
                flag |= xor != 0 ? 1 : 0;
            }
 
            if(flag == 1)
                System.out.println("Ashish");
            else
                System.out.println("Jeel");
        }
    }
}
```
Idea by [Jeel_Vaishnav](https://codeforces.com/profile/Jeel_Vaishnav "Grandmaster Jeel_Vaishnav")

