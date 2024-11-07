# Editorial_(en)

[1420A - Cubes Sorting](../problems/A._Cubes_Sorting.md "Codeforces Round 672 (Div. 2)")

 **Hint**Any array can be sorted using no more than n(n−1)2 operations. Think or guess when we need exactly n(n−1)2 operations.

 **Solution**
### [1420A - Cubes Sorting](../problems/A._Cubes_Sorting.md "Codeforces Round 672 (Div. 2)")

It is not difficult to see that the answer «NO» in this task is possible when and only when all $a_i$ are different and sorted in descending order. In this case we need $\frac{n \cdot (n-1)}{2}$ operations. Otherwise the answer is always «YES».

Why does this solution work? Let's define number of inversions as the number of pairs $1 \le i < j \le n$ such as $a_i > a_j$. Note that if the number of inversions is zero, the $a$ array is sorted in non-decreasing order. If the array is not sorted, we can always choose two neighboring elements such that $a_i > a_{i+1}$ and swap them. In this case, the number of inversions is reduced by one. In this case, we cannot reduce the number of inversions by more than one, so it is equal to the minimum number of operations we must perform.

Now, all we have to do is notice that the number of inversions does not exceed $\frac{n(n-1)}2$, and the maximum is only reached when $a_i > a_j$ for all pairs $1 \le i < j \le n$. It follows that in this case the array must be strictly descending.

Thus, we have a solution with a time of $O(n)$.

 **Code in C++ (Wind_Eagle)**
```cpp
#include<iostream>

using namespace std;

int a[1000000+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        bool can=false;
        for (int i=1; i<n; i++)
        {
            if (a[i]>=a[i-1])
            {
                can=true;
                break;
            }
        }
        if (can) cout<<"YES"<<'n';
        else cout<<"NO"<<'n';
    }
}
```
[1420B - Rock and Lever](../problems/B._Rock_and_Lever.md "Codeforces Round 672 (Div. 2)")

 **Hint**Think of a simple criteria when `a_i & a_j >= a_i ^ a_j` by considering the bits from highest to lowest. Apply your observations to calculate the answer fast.

 **Solution**
### [1420B - Rock and Lever](../problems/B._Rock_and_Lever.md "Codeforces Round 672 (Div. 2)")

Let's take a pair $(a_i, a_j)$ and see in which case $a_i\ \\&\ a_j \ge a_i \oplus a_j$ will hold. For this we will follow the bits $a_i$ and $a_j$ from highest to lowest. If we meet two zero bits, the values of $a_i\ \\&\ a_j$ and $a_i \oplus a_j$ will match in this bit, so we move on. If we meet a zero bit in $a_i$ and in $a_j$ —one bit(or vice versa), then we get $a_i\ \\&\ a_j < a_i \oplus a_j$, and we can immediately say that the required condition is false. And if we meet two one bits, then the required condition is fulfilled,  e. $a_i\ \\&\ a_j > a_i \oplus a_j$, and then the bits can no longer be considered.

Now let's consider the highest one bit in the number of $a_i$ (let it stand at $p_i$ position) and the highest single bit in the number of $a_j$ (let it stand at $p_j$ position). (Here, we consider that the bits are numbered in order of lowest to highest.) Then, $p_i = p_j$ must hold. If $p_i > p_j$, then there is zero in the $a_j$ position and one unit in the $a_i$ position. But then from the reasoning above we get that $a_i\ \\&\ a_j < a_i \oplus a_j$. The case of $p_i < p_j$ is treated in a similar way.

It is also easy to see that if $p_i = p_j$ then we automatically get the condition $a_i\ \\&\ a_j > a_i \oplus a_j$.

From here the problem is solved. For each number we find the position of the highest one bit $p_i$. Then we need to calculate the number of pairs of numbers, for which $p_i = p_j$. You may notice that the answer is $\sum\limits_\ell \frac{k_\ell\cdot(k_\ell-1)}2$, where $k_\ell$ — the number of numbers for which $p_i = p_j$.

The complexity of the solution is $O(n)$.

 **Code in C++ (Wind_Eagle)**
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<random>

using namespace std;

mt19937 rnd(time(NULL));

int a[1000000+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int64_t ans=0;
        for (int j=29; j>=0; j--)
        {
            int64_t cnt=0;
            for (int i=0; i<n; i++)
            {
                if (a[i]>=(1<<j)&&a[i]<(1<<(j+1)))
                {
                    cnt++;
                }
            }
            ans+=cnt*(cnt-1)/2;
        }
        cout<<ans<<'n';
    }
}
```
[1420C1 - Pokémon Army (easy version)](../problems/C1._Pokémon_Army_(easy_version).md "Codeforces Round 672 (Div. 2)")

 **Hint**Use dynamic programming.

 **Solution**
### [1420C1 - Pokémon Army (easy version)](../problems/C1._Pokémon_Army_(easy_version).md "Codeforces Round 672 (Div. 2)")

The easy version of the task can be solved in different ways. For example, you can use the dynamic programming method.

Let $d1_i$ – be the maximum possible sum of a subsequence on a prefix from the first $i$ elements, provided that the length of the subsequence is odd. Similarly enter $d2_i$, only for subsequences of even length. Then $d1_i$ and $d2_i$ are easy to recalculate: $$d1_{i+1} = \max(d1_i,\ d2_i + a_i),$$. $$d2_{i+1} = \max(d2_i,\ d1_i - a_i).$$. The initial values are $d1_0 = -\infty,\ d2_0 = 0$. The answer will be stored in $\max(d1_n, d2_n)$.

This solution works for $O(n)$ in time. Its main drawback is that it cannot be used to solve a complex version of a task where a different approach is needed.

 **Code in C++ (gepardo)**
```cpp
#include <iostream>
#include <vector>

using namespace std;

inline int64_t calc(const vector<int> &a) {
	int n = a.size();
	vector<int64_t> d1(n+1), d2(n+1);
	d1[0] = -static_cast<int64_t>(1e18);
	d2[0] = 0;
	for (int i = 0; i < n; ++i) {
		d1[i+1] = max(d1[i], d2[i] + a[i]);
		d2[i+1] = max(d2[i], d1[i] - a[i]);
	}
	return max(d1.back(), d2.back());
}

int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cout << calc(a) << "n";
		for (int i = 0; i < q; ++i) {
			int l, r; cin >> l >> r; --l; --r;
			swap(a[l], a[r]);
			cout << calc(a) << "n";
		}
	}
	return 0;
}
```
[1420C2 - Pokémon Army (hard version)](../problems/C2._Pokémon_Army_(hard_version).md "Codeforces Round 672 (Div. 2)")

 **Hint**The dynamic programming doesn't work here. Consider taking only local minima and maxima and think whether we need to take something else.

 **Solution**
### [1420C2 - Pokémon Army (hard version)](../problems/C2._Pokémon_Army_(hard_version).md "Codeforces Round 672 (Div. 2)")

Let's give a solution for a fixed array and then prove its optimality.

Let us name the element $a_i$ a local maximum if $a_i > a_{i-1}$ and $a_i > a_{i+1}$. Similarly let's call the element $a_i$ a local minimum if $a_i < a_{i-1}$ and $a_i < a_{i+1}$. If any of the $a_{i-1}$ or $a_{i+1}$ does not exist in the definitions above, we assume it is equal to $-\infty$.

Note that the optimal subsequence will always be an odd length (otherwise we can delete the last element and increase the response). Elements with odd numbers shall be located at local maximums, and elements with even numbers — at local minimums.

It is not difficult to see that the first local maximum is always placed earlier than the first local minimum (otherwise it would happen that the initial permutation decreases from the first element to the local minimum, in which case the first element itself is the local maximum). Similarly, you may notice that the last local maximum always costs later than the last local minimum. Given that the local maximums and minimums alternate, you can simply take a subsequence of all the local maximums and minimums and get the best response.

Let's show that this construction is alpways optimal. Let's start with the case when an element with an odd number is not a local maximum. In this case, it shall be replaced with a bigger neighbor, and if the bigger neighbor is already in the sub-set, just delete both of these elements. After that, the response shall always increase. The same shall apply if the even-numbered element is not a local minimum. In this case, it may still happen that we cannot move the element downwards because it is on the edge. But then it is the last one in the subsequence, and it can be easily removed.

Thus, it is optimal to take only local highs and lows into the subsequence (considering that highs are on odd positions and lows — on even positions). It remains to be shown that it is profitable to take all local maximums and minimums. Indeed, if not all of them are involved, then there is a pair of standing local highs and lows. By adding them to the subsequence, we will increase the answer.

Okay. We know how to solve a problem for an initial array by reducing it to the sum of all local maximums and minimums. We will now learn how to process requests quickly. To do this, we will store whether an element is a local minimum or maximum and recalculate this information when exchanging elements. Suddenly it turns out that a single request will change the state of no more than six elements, so we can easily recalculate the response for $O(1)$ per request.

Thus, we have a solution with an asymptotic $O(n + q)$ in time.

 **Code in Java (gepardo)**
```cpp
import java.io.*;
import java.util.*;

public class C2_Java {
    int[] a;
    int n;
    long ans;
    
    void add(int i, int sign) {
        if (i == 0 || i == n+1) return;
        if (a[i-1] < a[i] && a[i] > a[i+1]) ans += sign * a[i];
        if (a[i-1] > a[i] && a[i] < a[i+1]) ans -= sign * a[i];
    }
    
    void addTwo(int l, int r, int sign) {
        if (l == r) return;
        if (l+1 == r) {
            add(l-1, sign);
            add(l, sign);
            add(r, sign);
            add(r+1, sign);
            return;
        }
        add(l-1, sign);
        add(l, sign);
        add(l+1, sign);
        if (l+2 != r) add(r-1, sign);
        add(r, sign);
        add(r+1, sign);
    }
    
    public void run() throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer tok = new StringTokenizer(in.readLine());
        int t = Integer.parseInt(tok.nextToken());
        while (t --> 0) {
            tok = new StringTokenizer(in.readLine());
            n = Integer.parseInt(tok.nextToken());
            int q = Integer.parseInt(tok.nextToken());
            a = new int[n + 2];
            tok = new StringTokenizer(in.readLine());
            for (int i = 1; i <= n; ++i) {
                a[i] = Integer.parseInt(tok.nextToken());
            }
            a[0] = -1;
            a[n+1] = -1;
            ans = 0;
            StringBuilder builder = new StringBuilder();
            for (int i = 1; i <= n; ++i) {
                if (a[i-1] < a[i] && a[i] > a[i+1]) ans += a[i];
                if (a[i-1] > a[i] && a[i] < a[i+1]) ans -= a[i];
            }
            builder.append(ans).append("n");
            while (q --> 0) {
                tok = new StringTokenizer(in.readLine());
                int l = Integer.parseInt(tok.nextToken());
                int r = Integer.parseInt(tok.nextToken());
                if (l == r) {
                    builder.append(ans).append("n");
                    continue;
                }
                addTwo(l, r, -1);
                int tmp = a[l];
                a[l] = a[r];
                a[r] = tmp;
                addTwo(l, r, +1);
                builder.append(ans).append("n");
            }
            out.write(builder.toString());   
        }
        
        in.close();
        out.close();        
    }

    public static void main(String[] args) throws IOException {
        (new C2_Java()).run();
    }
}
```
 **Code in C++ (Wind_Eagle)**
```cpp
#include<iostream>

using namespace std;

#define int long long

int a[1000000+5];

int n;

int ans=0;

inline void insert(int i)
{
    if (i==0||i==n+1) return;
    if (a[i-1]<a[i]&&a[i]>a[i+1]) ans+=a[i];
    if (a[i-1]>a[i]&&a[i]<a[i+1]) ans-=a[i];
}

inline void erase(int i)
{
    if (i==0||i==n+1) return;
    if (a[i-1]<a[i]&&a[i]>a[i+1]) ans-=a[i];
    if (a[i-1]>a[i]&&a[i]<a[i+1]) ans+=a[i];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int q;
        cin>>n>>q;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        a[0]=-1;
        a[n+1]=-1;
        ans=0;
        for (int i=1; i<=n; i++)
        {
            if (a[i-1]<a[i]&&a[i]>a[i+1]) ans+=a[i];
            if (a[i-1]>a[i]&&a[i]<a[i+1]) ans-=a[i];
        }
        cout<<ans<<'n';
        while (q--)
        {
            int l,r;
            cin>>l>>r;
            erase(l-1);
            erase(l);
            erase(l+1);
            if (l!=r)
            {
                if (r-1!=l+1&&r-1!=l) erase(r-1);
                if (r!=l+1) erase(r);
                erase(r+1);
            }
            swap(a[l],a[r]);
            insert(l-1);
            insert(l);
            insert(l+1);
            if (l!=r)
            {
                if (r-1!=l+1&&r-1!=l) insert(r-1);
                if (r!=l+1) insert(r);
                insert(r+1);
            }
            cout<<ans<<'n';
        }
    }
}
```
[1420D - Rescue Nibel!](../problems/D._Rescue_Nibel!.md "Codeforces Round 672 (Div. 2)")

 **Hint**The intersection of any k segments is either empty or is a segment. Let's fix the left bound of the intersection and calculate the number of sets of k segments such that their intersection starts in this left bound.

 **Solution**
### [1420D - Rescue Nibel!](../problems/D._Rescue_Nibel!.md "Codeforces Round 672 (Div. 2)")

In this task, we need to find the number of sets of $k$ segments such that these $k$ segments intersect at least in one point.

Let's look at the starting point of the intersection. This point will always be the beginning of a segment. Let us find the number of sets of segments that their intersection begins at the point $x$. Let us denote $p(x)$ as number of segments that pass through this point, and $s(x)$ as numbers of segments that start at this point. Then all the $k$ segments must pass through $x$ and at least one segment must start at $x$. The number of sets of segments passing through $x$ is ${p(x) \choose k}$ and the number of sets of segments passing through $x$, none of which starts at $x$, is ${p(x) - s(x) \choose k}$. From here we obtain that the required number of piece sets is ${p(x) \choose k}. - {p(x) - s(x) \choose k}$. By summing up all possible $x$ values, we get the answer to the task.

It should be noted that $p(x)$ and $s(x)$ can be easily supported using the event method. Then, the total runtime will be $O(n\log n)$.

 **Code in Java (gepardo)**
```cpp
import java.io.*;
import java.util.*;

public class D_Java {
	public static final int MOD = 998244353;
	
	public static int mul(int a, int b) {
		return (int)((long)a * (long)b % MOD);
	}
	
	int[] f;
	int[] rf;
	
	public int C(int n, int k) {
		return (k < 0 || k > n) ? 0 : mul(f[n], mul(rf[n-k], rf[k]));
	}
	
	public static int pow(int a, int n) {
		int res = 1;
		while (n != 0) {
			if ((n & 1) == 1) {
				res = mul(res, a);
			}
			a = mul(a, a);
			n >>= 1;
		}
		return res;
	}
	
	static void shuffleArray(int[] a) {
		Random rnd = new Random();
		for (int i = a.length-1; i > 0; i--) {
			int index = rnd.nextInt(i + 1);
			int tmp = a[index];
			a[index] = a[i];
			a[i] = tmp;
		}
	}
	
	public static int inv(int a) {
		return pow(a, MOD-2);
	}
	
	public void doIt() throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer tok = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(tok.nextToken());
		int k = Integer.parseInt(tok.nextToken());
		
		f = new int[n+42];
		rf = new int[n+42];
		f[0] = rf[0] = 1;
		for (int i = 1; i < f.length; ++i) {
			f[i] = mul(f[i-1], i);
			rf[i] = mul(rf[i-1], inv(i));
		}
		
		int[] events = new int[2*n];
		for (int i = 0; i < n; ++i) {
			tok = new StringTokenizer(in.readLine());
			int le = Integer.parseInt(tok.nextToken());
			int ri = Integer.parseInt(tok.nextToken());
			events[i] = le*2;
			events[i + n] = ri*2 + 1;
		}
		shuffleArray(events);
		Arrays.sort(events);
		
		int ans = 0;
		int balance = 0;
		for (int r = 0; r < 2*n;) {
			int l = r;
			while (r < 2*n && events[l] == events[r]) {
				++r;
			}
			int added = r - l;
			if (events[l] % 2 == 0) {
				// Open event
				ans += C(balance + added, k);
				if (ans >= MOD) ans -= MOD;
				ans += MOD - C(balance, k);
				if (ans >= MOD) ans -= MOD;
				balance += added;
			} else {
				// Close event
				balance -= added;
			}
		}
		
		in.close();
		System.out.println(ans);
	}
	
	public static void main(String[] args) throws IOException {
		(new D_Java()).doIt();
	}
}
```
[1420E - Battle Lemmings](../problems/E._Battle_Lemmings.md "Codeforces Round 672 (Div. 2)")

 **Hint 1**Let's keep the number of zeroes between any pair consecutive ones instead of the original array of zeroes and ones. How will the swap operation look in this case. How to calculate the protection?

 **Hint 2**Suppose we have the initial array and the final array. Think of the number of operations you need to make the first one equal to the second one.

 **Hint 3**Join all your observations together and use DP.

 **Solution**
### [1420E - Battle Lemmings](../problems/E._Battle_Lemmings.md "Codeforces Round 672 (Div. 2)")

First, let us denote $f(A)$ as a conversion of the original sequence of $A$. In the beginning, we will write down the number of zeros before the the first one. Then, we write down the number of zeros standing between the first and second ones, then — between the second and third ones, and so on. For example, $f(011000101100) = \{1, 0, 3, 1, 0, 2\}$, because there is one zero before the first one, there are no zeros between the first and second ones, there are three zeros between the second and third ones, etc.  d. It is not difficult to see that the original sequence $A$ can be unambiguously recovered with $f(A)$.

Now, let us consider how $f(A)$ will change if we change two different adjacent elements in the original $A$ sequence. In this case, two neighboring numbers will change in $f(A)$, one of which will decrease by one and the other — will increase by one. The reversed statement is also true: if we choose two neighboring numbers in $f(A)$, one of them will increase by one, and the other — will decrease by one so that they both remain non-negative, this operation will correspond to an exchange of two neighboring elements in $A$. Let us name this operation (choosing two neighboring numbers, increasing one of them by one and reducing the other by one). pouring.

Let us consider such a task. We have two arrays $A = \{a_1, a_2, \dots, a_k\}$ and $B = \{b_1, b_2, \dots, b_k\}$. We have to calculate the minimum amount of pouring operations we can turn $A$ into $B$. (Obviously, the sum of the numbers in $A$ and in $B$ must be the same.) To solve this, let's try to split the array into two "barriers", standing after $i$-th position. Then, the $A$ array is split into two parts: the left (elements from $1$ to $i$) and the right (elements from $i+1$ to $n$). For the left part of the $A$ array to have the same number of elements as in $B$, you need $g_{A, B}(i) = \left|\sum_{j=1}^{i} a_i - \sum_{j=1}^i b_i\right|$ pouring operations involving $i$ and $i+1$ elements. To sum up the number of necessary pouring operations for each pair of neighboring elements, you have to sum $g_{A,B}(i)$ for all $i$ from $1$ to $n-1$. It can be shown that the sum obtained will be the required number of pouring operations, because  since it is equal to zero only in case of equal arrays, and each pouring operation will reduce it by no more than $1$ (and there is always a transfusion that reduces this sum by $1$).

So, this subtask has been sorted out, let's move on. We have to learn how to read security for the sequence $A$, knowing $f(A) = \{f_1, f_2, \dots, f_k\}$. It is not difficult to see that it is equal to $$p(A) = \sum_{1 \le i < j \le k} f_i\cdot f_j = \frac 12 \left( \sum_{1 \le i, j \le k} f_i\cdot f_j - \sum_{i=1}^k f_i^2 \right) = \frac 12 \left( \left(\sum_{i=1}^k f_i \right)^2 - \sum_{i=1}^k f_i^2 \right).$$ We already know the value of $\sum_{i=1}^k f_i$: it is equal to the number of zeroes in $A$. So, we have to minimize $\sum_{i=1}^k f_i^2$.

Now we can finally get down to the task. To do this, let's try to build an optimal sequence of $f(A) = \{f_1, f_2, \dots, f_k\}$ by applying no more than $k$ of transfusions. Of course, we need to use the dynamic programming of $dp_{i,\ s,\ k}$. This means that we have looked at the first $i$ elements in $f(A)$ and done with $k$ pouring operations so that $\sum_{i=1}^k f_i$ equals $s$. The DP itself will store the minimum possible value of $\sum_{i=1}^k f_i^2$.

To get the answer we need to refer to $dp_{i,\ c_0,\ k}$ where $c_0$ — is the number of zeros in the original sequence. And to recalculate the dynamics of $dp_{i,\ s,\ k}$ we have to go through what $f_{i+1}$ will be as a result. Let it be $h$. Then, the answer recovery happens in the following way:

$$dp_{i+1,\ s + h,\ k + \left|z_i - (s + h)\right|} \text{min=} dp_{i,\ s,\ k} + h^2.$$

Here $z_i$ denotes $\sum_{j=1}^i f_i$ in the original sequence $f(A)$.

The total asymptotic is $O(n^5)$ in time and $O(n^4)$ in memory, although with a correct implementation the constant is very small (the author's solution works for $\frac{n^5}{27}$). In this task, there are solutions for $O(n^4\log n)$, but I will not describe them here.

 **Code in C++ (gepardo)**
```cpp
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template<typename T>
inline void umin(T &a, const T &b) {
	a = min(a, b);
}

template<typename T>
inline void umax(T &a, const T &b) {
	a = max(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	a.push_back(1);
	
	vector<int> gg;
	for (int i = 0; i <= n; ++i) {
		int s = i;
		while (a[i] == 0) ++i;
		gg.push_back(i - s);
	}
	
	vector<int> p = gg;
	partial_sum(begin(p), end(p), begin(p));
	
	constexpr int mx = 103;
	constexpr int dx = mx + 1, dy = mx + 1, dz = mx * (mx + 1) / 2 + 1;
	static int dp[dx][dy][dz] = {};
	
	for (int i = 0; i < dx; ++i) {
		for (int j = 0; j < dy; ++j) {
			for (int k = 0; k < dz; ++k) {
				dp[i][j][k] = INT_MAX;
			}
		}
	}
	dp[0][0][0] = 0;
	
	int k = gg.size(), l = p.back();
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j <= l; ++j) {
			for (int s = 0; s <= n * (n-1) / 2; ++s) {
				if (dp[i][j][s] == INT_MAX) continue;
				for (int q = j; q <= l; ++q) {
					umin(dp[i+1][q][s + abs(q - p[i])], dp[i][j][s] + (q-j)*(q-j));
				}
			}
		}
	}
	
	int mn = INT_MAX;
	for (int s = 0; s <= n * (n-1) / 2; ++s) {
		umin(mn, dp[k][l][s]);
		int val = l*l - mn;
		assert(val % 2 == 0);
		cout << val/2 << " ";
	}
	cout << endl;
	
	return 0;
}
```
