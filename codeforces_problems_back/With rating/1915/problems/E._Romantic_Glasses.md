<h1 style='text-align: center;'> E. Romantic Glasses</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Iulia has $n$ glasses arranged in a line. The $i$-th glass has $a_i$ units of juice in it. Iulia drinks only from odd-numbered glasses, while her date drinks only from even-numbered glasses.

To impress her date, Iulia wants to find a contiguous subarray of these glasses such that both Iulia and her date will have the same amount of juice in total if only the glasses in this subarray are considered. Please help her to do that.

More formally, find out if there exists two indices $l$, $r$ such that $1 \leq l \leq r \leq n$, and $a_l + a_{l + 2} + a_{l + 4} + \dots + a_{r} = a_{l + 1} + a_{l + 3} + \dots + a_{r-1}$ if $l$ and $r$ have the same parity and $a_l + a_{l + 2} + a_{l + 4} + \dots + a_{r - 1} = a_{l + 1} + a_{l + 3} + \dots + a_{r}$ otherwise.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the total number of glasses.

The second line of each test case contains $n$ integers $a_1, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the amount of juice in each glass.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output "YES" if there exists a subarray satisfying the condition, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

## Input


```

631 3 261 1 1 1 1 1101 6 9 8 55 3 14 2 7 281 2 11 4 1 5 1 262 6 1 5 7 892 5 10 4 4 9 6 7 8
```
## Output


```

YES
YES
NO
YES
NO
YES

```
## Note

In the first test case, Iulia can pick $l=1$ and $r=3$. Then she drinks $a_1+a_3=1+2=3$ units and her date drinks $a_2=3$ units of juice.

In the second test case, Iulia can pick $l=2$ and $r=5$. Then she drinks $a_3+a_5=1+1=2$ units and her date drinks $a_2+a_4=1+1=2$ units of juice.

In the third test case no such contiguous subarray works.

In the fourth test case, Iulia can pick $l=2$ and $r=8$. Then she drinks $a_3+a_5+a_7=11+1+1=13$ units and her date drinks $a_2+a_4+a_6+a_8=2+4+5+2=13$ units of juice.



#### tags 

#1300 #data_structures #greedy #math 