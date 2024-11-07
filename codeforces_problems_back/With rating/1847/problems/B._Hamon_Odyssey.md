<h1 style='text-align: center;'> B. Hamon Odyssey</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jonathan is fighting against DIO's Vampire minions. There are $n$ of them with strengths $a_1, a_2, \dots, a_n$. $\def\and {{\,\texttt{&}\,}}$

Denote $(l, r)$ as the group consisting of the vampires with indices from $l$ to $r$. Jonathan realizes that the strength of any such group is in its weakest link, that is, the bitwise AND. More formally, the strength level of the group $(l, r)$ is defined as $$f(l,r) = a_l \and a_{l+1} \and a_{l+2} \and \ldots \and a_r.$$ Here, $\and$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND). 

Because Jonathan would like to defeat the vampire minions fast, he will divide the vampires into contiguous groups, such that each vampire is in exactly one group, and the sum of strengths of the groups is minimized. Among all ways to divide the vampires, he would like to find the way with the maximum number of groups.

Given the strengths of each of the $n$ vampires, find the maximum number of groups among all possible ways to divide the vampires with the smallest sum of strengths.

## Input

The first line contains a single integer $t$ $(1 \leq t \leq 10^4)$ — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the number of vampires.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($0 \leq a_i \leq 10^9$) — the individual strength of each vampire.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the maximum number of groups among all possible ways to divide the vampires with the smallest sum of strengths.

## Example

## Input


```

331 2 352 3 1 5 245 7 12 6
```
## Output


```

1
2
1

```
## Note

In the first test case, the optimal way is to take all the $n$ vampires as a group. So, $f(1,3) = 1 \and 2 \and 3 = 0$.

In the second test case, the optimal way is to make $2$ groups, $(2,3,1)$ and $(5,2)$. So, $f(1,3) + f(4,5) = (2 \and 3 \and 1) + (5 \and 2) = 0 + 0 = 0$.



#### tags 

#1000 #bitmasks #greedy #two_pointers 