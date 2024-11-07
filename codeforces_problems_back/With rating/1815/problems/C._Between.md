<h1 style='text-align: center;'> C. Between</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $n$, as well as $m$ pairs of integers $(a_i,b_i)$, where $1\leq a_i , b_i \leq n$, $a_i \ne b_i$.

You want to construct a sequence satisfying the following requirements:

* All elements in the sequence are integers between $1$ and $n$.
* There is exactly one element with value $1$ in the sequence.
* For each $i$ ($1 \le i \le m$), between any two elements (on different positions) in the sequence with value $a_i$, there is at least one element with value $b_i$.
* The sequence constructed has the maximum length among all possible sequences satisfying the above properties.

Sometimes, it is possible that such a sequence can be arbitrarily long, in which case you should output "INFINITE". Otherwise, you should output "FINITE" and the sequence itself. If there are multiple possible constructions that yield the maximum length, output any.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 300$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n \le 1500$, $0 \le m \le 5000$) — the maximum possible value of the element of the sequence and the number of pairs.

The $i$-th of the next $m$ lines contain two integers $a_i$ and $b_i$ ($1 \le a_i , b_i \le n$, $a_i \ne b_i$).

$(a_i, b_i) \ne (a_j, b_j)$ for all $1 \le i < j \le m$.

It is guaranteed that sum of $n$ over all test cases doesn't exceed $1500$ and the sum of $m$ over all test cases doesn't exceed $5000$.

## Output

For each test case, on the first line output "INFINITE" if the sequence can be arbitrarily long, and "FINITE" otherwise.

If you have outputted "FINITE", then your output should be followed by $2$ lines.

The first line contains an integer $s$, the maximum length of the sequence.

The second line contains $s$ integers, each are between $1$ and $n$ inclusive, representing the elements of the sequence.

If there are multiple sequences with the maximum length, output any of them.

It can be shown that, for all test cases with answer "FINITE", then under the constraints, the maximum possible sum of sequence lengths of those test cases does not exceed $2\cdot10^6$.

## Example

## Input


```

53 23 12 11 02 02 21 22 15 52 13 14 24 55 1
```
## Output


```

FINITE
5
2 3 1 2 3 
FINITE
1
1 
INFINITE
FINITE
3
2 1 2 
FINITE
10
4 2 3 5 4 1 3 2 5 4 
```
## Note

In the first test case, there is an element $1$ between two elements with value $3$ and an element $1$ between two elements with value $2$. It can be shown that there is no suitable sequences of length more than $5$.

In the second case, $[1]$ is the only possible sequence because there should be exactly one element with value $1$ in the sequence.

In the third case, we can get an arbitrary long sequence like $1, 2, 2, 2, \ldots$.



#### tags 

#2200 #constructive_algorithms #dfs_and_similar #graphs #greedy 