# Tutorial_(en)

Will we, will you...  
Can we, can you, can we change? 

[1562A - The Miracle and the Sleeper](../problems/A._The_Miracle_and_the_Sleeper.md "Codeforces Round 741 (Div. 2)")

 **Hint 1**Try to consider such segments where l≤⌊r2⌋+1.

 **Hint 2**Now think about what to do if this condition is not satisfied.

 **Solution**
### [1562A - The Miracle and the Sleeper](../problems/A._The_Miracle_and_the_Sleeper.md "Codeforces Round 741 (Div. 2)")

It's not hard to see that if $l \le \lfloor \frac{r}{2} \rfloor + 1$, then $r \bmod (\lfloor \frac{r}{2} \rfloor + 1) = \lfloor \frac{r-1}{2} \rfloor$. It can be shown that the maximal possible answer.

At the same time, let the segment not contain number $\lfloor \frac{r}{2} \rfloor + 1$, that is, $l > \lfloor \frac{r}{2} \rfloor + 1$. Then we can show that the maximal answer is $r \bmod l = r-l$.

Asymptotics: $O(1)$ per test case.

 **Code C++ (Wind_Eagle)**
```cpp
#include <iostream>

using namespace std;

int l, r;

void solve() {
    if (r < l * 2) {
        cout << r - l << endl;
    }
    else {
        cout << (r - 1) / 2 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        solve();
    }
}
```
[1562B - Scenes From a Memory](../problems/B._Scenes_From_a_Memory.md "Codeforces Round 741 (Div. 2)")

 **Hint 1**Try to consider small numbers, such as those consisting of three digits.

 **Hint 2**Now think about what the maximum number of digits can be in the optimal answer.

 **Solution**
### [1562B - Scenes From a Memory](../problems/B._Scenes_From_a_Memory.md "Codeforces Round 741 (Div. 2)")

Let's show that if a number has three digits, you can always remove at least one from it to get a number that is not prime. This can be proved by a simple brute-force search of all numbers with three digits, but we'll try to do it without a brute-force search.

In fact, if a number contains the digits '1', '4', '6', '8' or '9', then that one digit is the answer, because $1$, $4$, $6$, $8$ and $9$ are not prime numbers.

Now let's see what happens if the number doesn't have those digits. Then, if the number has two identical digits, we have found an answer of size two — the number of two identical digits ($22$, $33$, $55$, or $77$) is divisible by $11$. Also, if the digits $2$ or $5$ are not at the beginning of the number, we again have found an answer of size two — the number of two digits ending in $2$ or $5$ is not prime.

If none of the above cases worked, then we find that a three-digit number has one of the following values: $237$, $273$, $537$, $573$. It is not difficult to see that these numbers have two digits, which form a number, that is divisible by three.

Thus, the maximum answer is two, that is, you can leave no more than two digits in the number. You can find these digits by considering the above cases, or you can just try.

It can be shown that such a brute-force solution will work for $O(k)$.

Asymptotics: $O(k)$ per test case.

 **Code C++ (Wind_Eagle)**
```cpp
#include <iostream>

using namespace std;

int n;

string s;

bool prime[100];

void solve() {
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
            cout << 1 << endl;
            cout << s[i] << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!prime[(s[i] - '0') * 10 + (s[j] - '0')]) {
                cout << 2 << endl;
                cout << s[i] << s[j] << endl;
                return;
            }
        }
    }
    exit(42);
}

int main() {
    for (int i = 2; i < 100; i++) {
        prime[i] = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime[i] = false;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        solve();
    }
}
```
 **Additional Problem 1**Try to prove that the author's solution works for O(k) for one test case.

 **Solution of Additional Problem 1**Finding an answer consisting of one digit works in O(k). Now let's see how long the loop takes to complete. Indeed, it is easy to see that once the pairs of indexes (0,1), (0,2), and (1,2) are considered, an answer will always be found. This is so because in any number of three digits you can find an answer consisting of two digits (this was proved earlier). So this is equivalent to removing all but the first three digits, and then solving the problem for them (assuming that the length of the optimal answer is two).

 **Additional Problem 2**Try to think of a way to search index pairs and a test such that this search works for O(k2) per test case.

 **Solution of Additional Problem 2**Let's take the string \t{3737 \ldots 37} as a string. We will search pairs of indices in the following way: first we will search all pairs of indices with different parities, and then all pairs of indices with the same parity. It is easy to see that such a search will work for O(k2) for one test case, because all pairs of indices with different parity will give numbers 37 and 73, which are prime, and there are O(k2) such pairs.

[1562C - Rings](../problems/C._Rings.md "Codeforces Round 741 (Div. 2)")

 **Hint 1**Think about whether a suitable k (such that f(t)=f(w)⋅k) can be made small? What small k is easy to multiply binary numbers by?

 **Hint 2**Such k can be the numbers 0, 1, and 2~--- multiplying by 0 gives 0, multiplying by 1 leaves the number as is, and multiplying by 2 adds a zero to the end. Think about how you can take advantage of this.

 **Solution**
### [1562C - Rings](../problems/C._Rings.md "Codeforces Round 741 (Div. 2)")

Let us first consider the boundary case. Let a string (hereafter we will assume that the string length $n$) consists of only ones. Then we can output the numbers $1$ $n-1$ $2$ $n$ as the answer, since there will be the same substrings.

Now let's figure out what to do in the other case. Let's call the substring [$1$ ... $\lfloor\frac{n}{2}\rfloor$] the left half of the string, and the substring [$\lfloor\frac{n}{2}\rfloor+1$ ... $n$] the right half of the string. Then there are two cases:

* There is $0$ in the left half of the row, and its position is $k$. Then we can take the numbers $k$ $n$ $k+1$ $n$ as the answer, since they are the same numbers, just the second number has an extra leading zero.
* There is $0$ in the right half of the row, and its position is $k$. Then you can take the numbers $1$ $k$ $1$ $k-1$ as the answer, since the second number — is the first number multiplied by two (multiplying by two in binary is equivalent to adding one zero to the right).

Asymptotics: $O(n)$ per test case.

 **Code C++ (Wind_Eagle)**
```cpp
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool solved = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                solved = true;
                if (i >= n / 2) {
                    cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
                    break;
                } else {
                    cout << i + 2 << " " << n << " " << i + 1 << " " << n << endl;
                    break;
                }
            }
        }
        if (!solved) {
            cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
        }
    }
}
```
 **Additional Problem 1**Think about how the problem would be solved if any other number system was chosen, given all the previous conditions (the string consists of the digits 0 and 1, the string contains at least one one).

 **Solution of Additional Problem 1**The solution would not change in any way. In fact, in a number system with base k, adding a zero to the left side does not change the number (multiplication by 1), but adding a zero to the right side increases the number k times (multiplication by k).

 **Additional Problem 2**Think about how the problem would be solved if the condition sounded like this: \textit{it is necessary that f(t) is divisible by f(w). There are at least one one in the array. Zero is divisible by all numbers, but no number is divisible by zero. Zero is not divisible by zero.}

 **Solution of Additional Problem 2**In fact, the problem gets a little more complicated. For example, consider this test: \t{111000000}. In this case, we could not output 4 9 5 9 because zero is not divisible by zero.

We will perform the old solution, but check that we are not trying to divide zero by zero (if we divide something by zero, we will swap the numbers). And if the answer is not found, then either the whole left half of the string consists of zeros, or the whole right half. Let the leftmost unit have position p1, and the rightmost unit ~--- position p2. Then in the first case you can output 1 p2 2 p2, and in the second case~--- p1 n p1 n−1. 

It is not hard to see that such a solution will always find the answer.

In fact, we can solve the problem even simpler: when we meet zero in the left half, we additionally check whether there is at least one one among the characters on the right. If there is, we print the answer, otherwise we move on. Similarly, when we encounter zero in the right half, we additionally check if there is at least one one among the characters on the left. We can show that this solution will also always find the answer.

It is interesting that we have solved \textbf{a stronger version of the problem}, since the solution we obtained works correctly for the old problem as well.

[1562D1 - Two Hundred Twenty One (easy version)](../problems/D1._Two_Hundred_Twenty_One_(easy_version).md "Codeforces Round 741 (Div. 2)")

 **Hint 1**Think about: how is the parity of the length of the segment and the parity of the number of elements to be removed related?

 **Hint 2**Think about how much and how the value of the sign-variable sum differs when only one element is removed, and when only its neighbor is removed.

 **Hint 3**Consider odd-length segments. Try to take small segments and for each element find out what the sign-variable sum will be after it is removed. After that you may notice something interesting.

 **Solution**
### [1562D1 - Two Hundred Twenty One (easy version)](../problems/D1._Two_Hundred_Twenty_One_(easy_version).md "Codeforces Round 741 (Div. 2)")

Let's prove everything for a particular segment of length $n$. And at the end, we'll show how to quickly solve the problem for many segments. Let $n$ — the length of the segment, and let $a$ — the array corresponding to the segment ($a_i = 1$ if "+" is at the $i$th position in the segment, and $a_i = -1$ if "-" is at the $i$th position in the segment).

Introduce a new array $b$, with $b_i$ being equal to the signed sum on the whole array if the $i$-th element was removed from it.

Then:

* The parity of the length of the segment and the parity of the number of elements to be removed from it are the same.
* It is not difficult to show that $|b_i - b_{i+1}| = 0$ if $a_i = a_{i+1}$, or $|b_i - b_{i+1}| = 2$ otherwise. Proof of this fact: Let $a_i = a_{i+1}$. Then it is easy to see that when $a_i$ is removed, the segment will look exactly the same as when $a_{i+1}$ is removed. So $|b_i - b_{i+1}| = 0$. Now let $a_i \neq a_{i+1}$. Denote by $f(l,r)$ the sign-variable sum on the interval $l$ to $r$, taking into account the sign (i.e. if $l$ is odd, the first number is taken with the plus sign, otherwise with the minus sign). Then it is easy to see that $b_i = f(1,i-1) \pm a_{i+1} \mp f(i+2,n)$, and $b_{i+1} = f(1,i) \mp f(i+2,n)$. Hence, if we consider the two cases ($a_{i+1} = 1$ and $a_{i+1} = -1$), we see that $|b_i - b_{i+1}| = 2$.
* If $n$ is odd, then there exists such $k$ that $b_k = 0$. Let us prove this: If $b_1 = 0$ or $b_n = 0$, then the statement is proved. Now let $b_1 < 0$ and $b_n > 0$. Then, since the neighboring values in the array $b$ differ by no more than $2$, and all elements are even, then there is bound to be zero between the first and last element. The case $b_1 > 0, b_n < 0$ is proved similarly. If $n > 1$, then there cannot be such a case that $b_1 > 0$ and $b_n >0$, and there cannot be such a case that $b_1 < 0$ and $b_n < 0$. In fact, let the sign-variable sum of the whole segment be $s$. Then $b_1 = -s \pm 1$ and $b_n = s \pm 1$. Since $b_1$ and $b_n$ are even numbers, therefore either at least one of them is zero, or they are of different signs.

Thus the final result is: if the sign-variable sum is already zero, output zero; otherwise, if the segment is of odd length, output $1$; otherwise, output $2$.

To quickly determine the sign-variable sum, we use the prefix-sum.

Asymptotics: $O(n + q)$ per test case.

 **Code C++ (Wind_Eagle)**
```cpp
#include <iostream>

using namespace std;

int a[1000000 + 5], p[1000000 + 5];

int get_sum(int l, int r) {
    if (l > r) {
        return 0;
    }
    return (l % 2 == 1) ? p[r] - p[l - 1] : p[l - 1] - p[r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string ss;
        cin >> ss;
        for (int i = 1; i <= n; i++) {
            a[i] = (ss[i - 1] == '+' ? 1 : -1);
        }
        p[0] = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + (i % 2 == 1 ? a[i] : -a[i]);
        }
        for (int o = 0; o < q; o++) {
            int l, r;
            cin >> l >> r;
            if (get_sum(l, r) == 0) {
                cout << "0n";
                continue;
            }
            if ((r - l + 1) % 2 == 0) {
                cout << "2n";
            }
            else {
                cout << "1n";
            }
        }
    }
}
```
[1562D2 - Two Hundred Twenty One (hard version)](../problems/D2._Two_Hundred_Twenty_One_(hard_version).md "Codeforces Round 741 (Div. 2)")

 **Hints 1-3**See the corresponding hints from Problem D1.

 **Hint 4**Consider how to quickly check the value of a sign-variable sum on a segment if you know that exactly one element is removed from it (and know the number of that element).

 **Hint 5**From the solution of Problem D1 it is clear that for any odd segment only one element has to be removed. Consider how to find such an element, based on the proof of its existence given above.

 **Solution**
### [1562D2 - Two Hundred Twenty One (hard version)](../problems/D2._Two_Hundred_Twenty_One_(hard_version).md "Codeforces Round 741 (Div. 2)")

We will use the facts already obtained, given in the solution of problem D1.

To quickly check the value of the sign-variable sum on the segment with deletion of one element, slightly modify the prefix-sum. We will not concentrate on this in detail; you can see how to make it in the solution.

Now let's see how to search for a matching element inside an odd-length segment. We will do this with a binary search. Suppose initially $l = 1$, $r = n$, and we know that the numbers $b_1$ and $b_n$ are different signs, or one of them is zero.

Now consider the following algorithm:

* Find $m$ equal to $\lfloor\frac{l+r}{2}\rfloor$.
* If $b_l = 0$, or $b_m = 0$, or $b_r = 0$, then the answer is found.
* Otherwise, either the numbers $b_l$ and $b_m$ have different signs, or the numbers $b_m$ and $b_r$ have different signs. In the first case, assign $r$ to $m$, in the second case, assign $l$ to $m$.

This algorithm will stop sooner or later and produce an answer, since we know that the matching item exactly exists. This can be shown using the fact that $|b_i - b_{i+1}| \le 2$, and all $b_i$ are even.

So finally we have the following solution: if the sign-variable sum is already zero, output zero; otherwise, if the segment is of odd length, search for a suitable element by the above algorithm; otherwise, take, for example, the left boundary of the segment as the first element to remove, and search for the second element using the above algorithm on the segment without a left element.

Asymptotics: $O(n + q \cdot log(n))$ per test case.

 **Code C++ (Wind_Eagle)**
```cpp
#include <iostream>

using namespace std;

int a[1000000 + 5], p[1000000 + 5];

int get_sum(int l, int r) {
    if (l > r) {
        return 0;
    }
    return (l % 2 == 1) ? p[r] - p[l - 1] : p[l - 1] - p[r];
}

int check_elimination(int l, int r, int m) {
    return ((m - l + 1) % 2 == 1)
    ? get_sum(l, m - 1) + get_sum(m + 1, r)
    : get_sum(l, m - 1) - get_sum(m + 1, r);
}

int get_sign(int m) {
    return m > 0 ? 1 : -1;
}

int calculate_odd_segment(int l, int r) {
    if (l == r) {
        return l;
    }
    int pos = 0;
    int lb = l;
    int rb = r;
    while (lb < rb) {
        int mb = (lb + rb) / 2;
        int lq = check_elimination(l,r,lb);
        int mq = check_elimination(l,r,mb);
        int rq = check_elimination(l,r,rb);
        if (lq == 0) {
            pos = lb;
            break;
        }
        if (mq == 0) {
            pos = mb;
            break;
        }
        if (rq == 0) {
            pos = rb;
            break;
        }
        if (get_sign(lq) == get_sign(mq)) {
            lb = mb;
        } else {
            rb = mb;
        }
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string ss;
        cin >> ss;
        for (int i = 1; i <= n; i++) {
            a[i] = (ss[i - 1] == '+' ? 1 : -1);
        }
        p[0] = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + (i % 2 == 1 ? a[i] : -a[i]);
        }
        for (int o = 0; o < q; o++) {
            int l, r;
            cin >> l >> r;
            if (get_sum(l, r) == 0) {
                cout << "0n";
                continue;
            }
            bool even = false;
            if ((r - l + 1) % 2 == 0) {
                even = true;
                l++;
            }
            int pos = calculate_odd_segment(l, r);
            if (even) {
                cout << "2n" << l - 1 << " "<< pos << 'n';
            } else {
                cout << "1n" << pos << 'n';
            }
        }
    }
}
```
 **Interesting question**Is there a solution with asymptotics O(n+q) for a single test case?

[1562E - Rescue Niwen!](../problems/E._Rescue_Niwen!.md "Codeforces Round 741 (Div. 2)")

 **Hint 1**To solve it, you will need to quickly (in O(1)) find the largest common prefix of two substring.

 **Hint 2**Take some small strings and try to build the largest increasing subsequence. Maybe there's something special about it.

 **Hint 3**Use dynamic programming.

 **Solution**
### [1562E - Rescue Niwen!](../problems/E._Rescue_Niwen!.md "Codeforces Round 741 (Div. 2)")

The constraints on the problem were chosen so that solutions slower than $O(n^2 \cdot log(n))$ would not get AC, or would get with difficulty. The solution could be, for example, to sort all substrings by assigning numbers to them, and then find the largest increasing subsequence in the resulting array.

Let us describe the solution for $O(n^2)$. The most important thing required for the solution is to understand what the largest increasing subsequence should look like.

Let $s$ — a string, and $n$ — the length of the string $s$.

It can be shown that if the largest increasing subsequence has a substring [$l$ ... $r$], then it also has a substring [$l$ ... $n$]. I will not give a formal proof, I will only give the key idea. Let the increasing subsequence first have the string [$l_1$ ... $r_1$], and then the substring [$l_2$ ... $r_2$], with $r_1 \neq n$. It can be understood that if suffixes [$l_1$ ... $n$] and [$l_2$ ... $n$] have some common prefix, and it has already been included in the largest increasing subsequence, then we can «drop» the prefixes of the suffix [$l_1$ . . $n$], and instead of them write exactly the same suffix prefixes of [$l_2$ ... $n$], and the size of the increasing subsequence will not change, and the condition above will be satisfied. If, however, the suffixes [$l_1$ ... $n$] and [$l_2$ ... $n$] have no common prefix, then we could take the suffix itself [$l_2$ ... $n$] together with its prefixes, and the answer would only improve.

Thus, the largest increasing subsequence looks like this: first comes some substring [$l_1$ ... $r_1$], followed by a substring [$l_1$ ... $r_1 + 1$], and so on, ending with the suffix [$l_1$ ... $n$]. After that comes some substring [$l_2$ ... $r_2$], followed by a substring [$l_2$ ... $r_2 + 1$], and so on, ending with the suffix [$l_2$ ... $n$], and so on. Moreover, knowing which suffixes are included in this subsequence, we can establish all other substrings. Indeed, let the suffixes [$l_1$ ... $n$] and [$l_2$ ... $n$] be included in the sequence, and $l_1$ < $l_2$. Then it is not difficult to see that the suffix prefixes [$l_2$ ... $n$] can be typed greedily, namely, to take all substring [$l_2$ ... $k$] such that they are larger than the suffix [$l_1$ ... $n$].

Note that if the substring [$l_2$ ... $m$] is larger than the suffix [$l_1$ ... $n$], then the substring [$l_2$ ... $m+1$] is also larger than the suffix [$l_1$ ... $n$]. And so, we can use the following algorithm to find out $r_2$, that is, to find out which suffix prefix [$l_2$ ... $n$] to start typing the subsequence. Let $d_{l_1,l_2}$ — be the size of the largest common prefix of suffixes [$l_1$ ... $n$] and [$l_2$ ... $n$]. Then it is easy to see that if the suffix [$l_2$ ... $n$] is larger than the suffix [$l_1$ ... $n$], then the appropriate $r_2$ is $d_{l_1,l_2} + l_2$, which means that you must start typing all substrings, starting from the one that differs from the largest common prefix of the two suffixes.

So now we are left with two problems. The first is — you have to learn to quickly recognize the greatest common prefix of the two suffixes. The second is — to write a DP that would allow you to recognize the answer.

Let's see how to solve the first problem. You can use different string algorties, such as a suffix array. Or we can write a simple DP that calculates an array $d$ of the largest common prefixes over $O(n^2)$. The transitions in this DP and its implementation can be seen in the author's solution code (lines 37-48).

Now about the DP that calculates the answer. Let us use the facts above and do the following. Let $dp_i$ denote the size of the answer if the last substring in it is the suffix [$i$ ... $n$]. Let $dp_1 = n$, and then $dp_i = n - i + 1$. Now let's do the following. We will go through $i$ from $2$ to $n$, doing the following simple steps: for each $j$ from $1$ to $i-1$ ($j$ denotes the previous suffix in the answer) we will check how many substring of the suffix [$i$ ... $n$] we can take: if the suffix [$i$ ... $n$] is larger than the suffix [$j$ ... $n$], we calculate this number with the above described algorithm, using the $d$ array of largest common prefixes. Otherwise, we will not update, because the suffix [$i$ ... $n$] is less than or equal to the suffix [$j$ ... $n$], we cannot take it in response. It is not difficult to guess that the answer is maximal in all $dp_i$.

Thus, the problem is solved using two uncomplicated dynamics.

Asymptotics: $O(n^2)$ per test case.

 **Code C++ (Wind_Eagle)**
```cpp
#include <iostream>

using namespace std;

int16_t lcp[10000 + 5][10000 + 5];

int dp[10000 + 5];

bool is_greater(const string& s, int x, int y) {
    if (lcp[x][y] == static_cast<int>(s.size()) - x) {
        return false;
    }
    return s[x + lcp[x][y]] > s[y + lcp[x][y]];
}

int get_score(const string& s, int x, int y) {
    if (is_greater(s, x, y)) {
        return dp[y] + static_cast<int>(s.size()) - x - lcp[x][y];
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.size() != n) return 42;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                lcp[i][j] = 0;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == j) {
                    lcp[i][j] = n - i;
                } else
                if (s[i] != s[j]) {
                    lcp[i][j] = 0;
                } else {
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
                }
            }
        }
        int ans = n;
        dp[0] = n;
        for (int i = 1; i < n; i++) {
            dp[i] = n - i;
            for (int j = 0; j < i; j++) {
                dp[i] = max (dp[i], get_score(s, i, j));
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << 'n';
    }
}
```
 **Interesting question**As far as I know, using trie, you can sort all substrings of a given string in O(n2). Also, as far as I know, in C++ programming language *std::lower_bound* works so fast that in an array of size 1.25⋅107 the same number of *std::lower_bound* operations is done in a little less than a second. It is also known that *std::lower_bound* can be used to write a search for the largest increasing subsequence in an array. The question is: can we use this to write a O(n2⋅log(n)) solution that passes the tests?

[1562F - Tubular Bells](../problems/F._Tubular_Bells.md "Codeforces Round 741 (Div. 2)")

 **Hint 1**Come up with a solution that uses n⋅(n−1)2 queries.

 **Hint 2**At n<100, apply a solution that uses n⋅(n−1)2 queries. Now suppose n≥100. Come up with a solution that would use ⌈3n2rceil queries.

 **Hint 3**When n<10000, apply a solution that uses 2n queries. Now suppose n≥5000. Most likely, in the 2n queries solution you come up with, you need to find the largest prime number on the segment. Think about it, do you really need **the largest** prime number? Maybe just **enough large** prime number would be enough? How can you find such a number?

 **Hint 4**Use probabilistic algorithms to find such a number. Use probabilistic algorithms to also make sure that you have found the right number.

 **Hint 5**Now use the prime number you have found to find the largest prime number. You will probably already know most of the numbers when you find it, and you can use the largest prime number to find the rest.

 **Solution**
### [1562F - Tubular Bells](../problems/F._Tubular_Bells.md "Codeforces Round 741 (Div. 2)")

As I know, there are simpler solutions to this problem, but I will describe my solution.

We can assume the whole array is randomly permutated, because we can make queries by renumbering it. We also pre-calculate all prime numbers smaller than $200000$.

Let us denote something: $n$ — the number of numbers in the array, $a$ — the array itself, $l$ — the smallest value in the array, $r$ — the largest value in the array.

So let's look at three cases:

* $n < 100$. We use the following simple solution: find out the lcm of all pairs of numbers. The greatest of these values will give us the pair of numbers $r-1$ and $r$. It is easy to find out which number $r$ is: all pairs of lcms of this number with others will be divisible by $r$. Now exclude $r$ from the array, and exclude all pairwise lcms with it. The highest value will give us a pair $r-1$ and $r-2$. Repeat this algorithm until all numbers are found.
* $100 \le n < 10000$. Solve for $\lceil\frac{3n}{2}\rceil$ queries. We ask for lcms of pairs of numbers: the first with the second, the third with the fourth, etc. Now we will look for the maximal prime multiplier in each such lcm. We will do it by using pre-calculated prime numbers. Since the array is randomly permutated, this will work in a reasonable amount of time. When we will find a pair of numbers with the greatest prime number, we easily find out which of these two numbers is the greatest prime: ask the lcm of one of the numbers in the pair with any other number and check if that lcm contains that greatest prime number. Finding the largest prime number, we easily find out the remaining array: $a_i = lcm(a_i, p) / p$, where $p$ –that prime number.
* $10000 \le n \le 100000$. Let $c$ = $500$. This number is chosen so that $c^2 > 200000$. We will search the array for any prime number that is greater than $c$. Do the following: randomly ask pairs of numbers until we find one that has only two prime numbers in the factorization of the lcm, and both of these prime numbers are greater than $c$. Let it be $p_1$ and $p_2$. Then one of the numbers in the pair — $p_1$ and the other  — $p_2$. To find out which number is which, let's ask the lcm of one of them with some numbers chosen at random, and check what all those lcms are divisible by. If they are all divisible by $p_1$, then the chosen number is $p_1$, otherwise it is $p_2$. The chance of us guessing wrong is extremely small, because it requires that all the chosen numbers are divisible by $p_2$, and the chance of that is negligible.We have found a prime number greater than $c$. Let it be $p$. Now we can find out all the numbers that are not divisible by $p$ and greater than $c$. To do this, we ask all the NOCs of the number $p$ and the other numbers. And now, if $lcm(p, a_i) / p > c$, then $a_i = lcm(p, a_i) / p$. This is because if $a_i$ is divisible by $p$, then $lcm(p, a_i) / p = a_i / p \le c$. If $a_i$ is not divisible by $p$, then by dividing the lcm by $p$ we will find $a_i$, since the number $p$ is prime.

Find the largest prime among the found numbers, and use it to find the remaining numbers as described above. Since we only need to find all numbers divisible by $p$ and all numbers not exceeding $c$, such queries will be no more than $100000 / 500 + 500 = 700$.
 **Code C++ (Wind_Eagle)**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

#define int long long

mt19937 rnd(time(NULL));

int swnmb[1000000+5];

int swnmbr[1000000+5];

int b[1000000+5];

bool p[1000000+5];

vector<int> primes;

int get_lcm(int x, int y)
{
    cout<<"? "<<swnmb[x]<<" "<<swnmb[y]<<endl;
    int u;
    cin>>u;
    return u;
}

int max_fact(int d)
{
    for (int j=(int)primes.size()-1; j>=0; j--)
    {
        if (d%primes[j]==0) return primes[j];
    }
}

vector<int> fact(int d)
{
    vector<int> ans;
    for (auto j:primes)
    {
        if (d==1) break;
        while (d%j==0)
        {
            ans.push_back(j);
            d/=j;
        }
    }
    return ans;
}

bool is_prime(int d)
{
    for (int j=0; j<(int)primes.size(); j++)
    {
        if (primes[j]>500) return true;
        if (d%primes[j]==0) return false;
    }
    return true;
}

int paired_get_lcm[100+5][100+5];

void solve_quadric(int n)
{
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            paired_get_lcm[i][j]=get_lcm(i,j);
            paired_get_lcm[j][i]=paired_get_lcm[i][j];
        }
    }
    int m1=0;
    int m2=0;
    int mx=0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (paired_get_lcm[i][j]>mx)
            {
                mx=paired_get_lcm[i][j];
                m1=i;
                m2=j;
            }
        }
    }
    int u=0;
    for (int i=1; i<=200000; i++)
    {
        if (mx==i*(i+1))
        {
            u=i+1;
            break;
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (i==m1||i==m2) continue;
        if (paired_get_lcm[m1][i]%u!=0)
        {
            swap(m1,m2);
            break;
        }
    }
    b[m1]=u;
    int pos=m2;
    for (int v=u-1; v>u-n-1; v--)
    {
        int m0=0;
        int mx=0;
        for (int j=1; j<=n; j++) {
            if (b[j]!=0) continue;
            if (pos==j) continue;
            if (paired_get_lcm[pos][j]>mx)
            {
                mx=paired_get_lcm[pos][j];
                m0=j;
            }
        }
        b[pos]=v;
        pos=m0;
    }
    b[pos]=u-n+1;
}

void solve_pair(int n)
{
    int maxnum=0;
    int maxpos=0;
    int notmaxpos=0;
    for (int i=1; i<=n; i+=2)
    {
        int u;
        if (i!=n) u=get_lcm(i,i+1);
        else u=get_lcm(i-1,i);
        int w=max_fact(u);
        if (w>maxnum)
        {
            maxnum=w;
            maxpos=min(i+1,n);
        } else {
            notmaxpos=i;
        }
    }
    int cur=get_lcm(notmaxpos,maxpos);
    if (cur%maxnum!=0) {
        maxpos--;
    }
    b[maxpos]=maxnum;
    for (int i=1; i<=n; i++)
    {
        if (i==maxpos) continue;
        int u=get_lcm(i,maxpos)/maxnum;
        b[i]=u;
    }
}

void print_ans(int n)
{
    cout<<"! ";
    for (int i=1; i<=n; i++) {
        cout<<b[swnmbr[i]];
        if (i!=n) cout<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    for (int i=2; i<=200000; i++)
    {
        if (p[i]) continue;
        for (int j=i*i; j<=200000; j+=i)
        {
            p[j]=true;
        }
        primes.push_back(i);
    }
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++) {
            swnmb[i]=0;
            swnmbr[i]=0;
            b[i]=0;
        }
        for (int i=1; i<=n; i++) {
            swnmb[i]=i;
        }
        for (int i=1; i<=n*5; i++) {
            swap(swnmb[rnd()%n+1], swnmb[rnd()%n+1]);
        }
        for (int i=1; i<=n; i++) {
            swnmbr[swnmb[i]]=i;
        }
        if (n<100) {
            solve_quadric(n);
            print_ans(n);
            continue;
        }
        if (n<10000) {
            solve_pair(n);
            print_ans(n);
            continue;
        }
        int t1=0;
        int t2=0;
        int pos1=0;
        int pos2=0;
        for (int i=1; i<=4000; i++)
        {
            int i1=rnd()%n+1;
            int i2=rnd()%n+1;
            while (i1 == i2) {
                i2=rnd()%n+1;
            }
            vector<int> f=fact(get_lcm(i1,i2));
            if (f.size()==2&&f[0]>500&&f[1]>500)
            {
                bool first1=true;
                bool first2=true;
                for (int j=0; j<100; j++)
                {
                    int t=rnd()%n+1;
                    while (t==i1||t==i2)
                    {
                        t=rnd()%n+1;
                    }
                    if (get_lcm(i1,t)%f[0]!=0)
                    {
                        first1=false;
                        break;
                    }
                }
                for (int j=0; j<100; j++)
                {
                    int t=rnd()%n+1;
                    while (t==i1||t==i2)
                    {
                        t=rnd()%n+1;
                    }
                    if (get_lcm(i1,t)%f[1]!=0)
                    {
                        first2=false;
                        break;
                    }
                }
                if (first1&&first2)
                {
                    bool second1=true;
                    for (int j=0; j<100; j++)
                    {
                        int t=rnd()%n+1;
                        while (t==i1||t==i2)
                        {
                            t=rnd()%n+1;
                        }
                        if (get_lcm(i2,t)%f[1]!=0)
                        {
                            second1=false;
                            break;
                        }
                    }
                    if (second1)
                    {
                        t2=f[0]*f[1];
                        t1=f[0];
                    }
                    else
                    {
                        t2=f[0]*f[1];
                        t1=f[1];
                    }
                    pos1=i2;
                    pos2=i1;
                }
                else
                {
                    if (!first1)
                    {
                        t1=f[1];
                        t2=f[0];
                    }
                    else
                    {
                        t1=f[0];
                        t2=f[1];
                    }
                    pos1=i1;
                    pos2=i2;
                }
                b[pos1]=t1;
                b[pos2]=t2;
                int posf=0;
                int maxf=0;
                for (int j=1; j<=n; j++)
                {
                    if (j==i1||j==i2) continue;
                    int u=get_lcm(pos1,j);
                    if (u/t1>500)
                    {
                        b[j]=u/t1;
                        if (is_prime(b[j]))
                        {
                            if (b[j]>maxf)
                            {
                                maxf=b[j];
                                posf=j;
                            }
                        }
                    }
                }
                for (int j=1; j<=n; j++)
                {
                    if (b[j]!=0) continue;
                    b[j]=get_lcm(posf,j)/b[posf];
                }
                break;
            }
        }
        print_ans(n);
    }
}
```
