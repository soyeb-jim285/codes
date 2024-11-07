<h1 style='text-align: center;'> C. Hyperregular Bracket Strings</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $n$ and $k$ intervals. The $i$-th interval is $[l_i,r_i]$ where $1 \leq l_i \leq r_i \leq n$.

Let us call a regular bracket sequence$^{\dagger,\ddagger}$ of length $n$ hyperregular if for each $i$ such that $1 \leq i \leq k$, the substring $\overline{s_{l_i} s_{l_{i}+1} \ldots s_{r_i}}$ is also a regular bracket sequence.

Your task is to count the number of hyperregular bracket sequences. Since this number can be really large, you are only required to find it modulo $998\,244\,353$.

$^\dagger$ A bracket sequence is a string containing only the characters "(" and ")".

$^\ddagger$ A bracket sequence is called regular if one can turn it into a valid math expression by adding characters + and 1. For example, sequences (())(), (), (()(())) and the empty string are regular, while )(, ((), and (()))( are not.

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 3 \cdot 10^5$, $0 \le k \le 3 \cdot 10^5$) — the length of the hyperregular bracket sequences and the number of intervals respectively.

The following $k$ lines of each test case contains two integers $l_i$ and $r_i$ ($1 \le l \le r \le n$).

It is guaranteed that the sum of $n$ across all test cases does not exceed $3 \cdot 10^5$ and the sum of $k$ across all test cases does not exceed $3 \cdot 10^5$.

## Output

For each test case, output the number of hyperregular bracket sequences modulo $998\,244\,353$.

## Example

## Input


```

76 05 08 11 310 23 46 91000 3100 701200 801300 90128 51 123 2011 144 918 194 31 41 41 4
```
## Output


```

5
0
0
4
839415253
140
2

```
## Note

* For the first testcase, the $5$ hyperregular bracket strings of length $6$ are: ((())), (()()), (())(), ()(()) and ()()().
* For the second testcase, there are no regular bracket strings of length $5$, and consequently, there are no hyperregular bracket strings of length $5$.
* For the third testcase, there are no hyperregular bracket strings of length $8$ for which the substring $[1 \ldots 3]$ is a regular bracket string.
* For the fourth testcase, there $4$ hyperregular bracket strings are: ((())(())), ((())()()), ()()((())) and ()()(()())


#### tags 

#2400 #combinatorics #greedy #hashing #math #number_theory #sortings 