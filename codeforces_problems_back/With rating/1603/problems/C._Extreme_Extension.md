<h1 style='text-align: center;'> C. Extreme Extension</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For an array $b$ of $n$ integers, the extreme value of this array is the minimum number of times (possibly, zero) the following operation has to be performed to make $b$ non-decreasing: 

* Select an index $i$ such that $1 \le i \le |b|$, where $|b|$ is the current length of $b$.
* Replace $b_i$ with two elements $x$ and $y$ such that $x$ and $y$ both are positive integers and $x + y = b_i$.
* This way, the array $b$ changes and the next operation is performed on this modified array.

For example, if $b = [2, 4, 3]$ and index $2$ gets selected, then the possible arrays after this operation are $[2, \underline{1}, \underline{3}, 3]$, $[2, \underline{2}, \underline{2}, 3]$, or $[2, \underline{3}, \underline{1}, 3]$. And consequently, for this array, this single operation is enough to make it non-decreasing: $[2, 4, 3] \rightarrow [2, \underline{2}, \underline{2}, 3]$.

It's easy to see that every array of positive integers can be made non-decreasing this way.

YouKn0wWho has an array $a$ of $n$ integers. Help him find the sum of extreme values of all nonempty subarrays of $a$ modulo $998\,244\,353$. If a subarray appears in $a$ multiple times, its extreme value should be counted the number of times it appears.

An array $d$ is a subarray of an array $c$ if $d$ can be obtained from $c$ by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10\,000$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^5$).

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $10^5$.

## Output

For each test case, print a single integer  — the sum of extreme values of all subarrays of $a$ modulo $998\,244\,353$.

## Example

## Input


```

4
3
5 4 3
4
3 2 1 4
1
69
8
7264 40515 28226 92776 35285 21709 75124 48163

```
## Output


```

5
9
0
117

```
## Note

Let $f(l, r)$ denote the extreme value of $[a_l, a_{l+1}, \ldots, a_r]$.

In the first test case, 

* $f(1, 3) = 3$, because YouKn0wWho can perform the following operations on the subarray $[5, 4, 3]$ (the newly inserted elements are underlined):$[5, 4, 3] \rightarrow [\underline{3}, \underline{2}, 4, 3] \rightarrow [3, 2, \underline{2}, \underline{2}, 3] \rightarrow [\underline{1}, \underline{2}, 2, 2, 2, 3]$;
* $f(1, 2) = 1$, because $[5, 4] \rightarrow [\underline{2}, \underline{3}, 4]$;
* $f(2, 3) = 1$, because $[4, 3] \rightarrow [\underline{1}, \underline{3}, 3]$;
* $f(1, 1) = f(2, 2) = f(3, 3) = 0$, because they are already non-decreasing.

So the total sum of extreme values of all subarrays of $a = 3 + 1 + 1 + 0 + 0 + 0 = 5$.



#### tags 

#2300 #dp #greedy #math #number_theory 