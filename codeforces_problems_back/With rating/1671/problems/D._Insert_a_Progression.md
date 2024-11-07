<h1 style='text-align: center;'> D. Insert a Progression</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence of $n$ integers $a_1, a_2, \dots, a_n$. You are also given $x$ integers $1, 2, \dots, x$.

You are asked to insert each of the extra integers into the sequence $a$. Each integer can be inserted at the beginning of the sequence, at the end of the sequence, or between any elements of the sequence.

The score of the resulting sequence $a'$ is the sum of absolute differences of adjacent elements in it $\left(\sum \limits_{i=1}^{n+x-1} |a'_i - a'_{i+1}|\right)$.

What is the smallest possible score of the resulting sequence $a'$?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains two integers $n$ and $x$ ($1 \le n, x \le 2 \cdot 10^5$) — the length of the sequence and the number of extra integers.

The second line of each testcase contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 2 \cdot 10^5$).

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

For each testcase, print a single integer — the smallest sum of absolute differences of adjacent elements of the sequence after you insert the extra integers into it.

## Example

## Input


```

41 5103 87 2 1010 26 1 5 7 3 3 9 10 10 14 101 3 1 2
```
## Output


```

9
15
31
13

```
## Note

Here are the sequences with the smallest scores for the example. The underlined elements are the extra integers. ## Note

 that there exist other sequences with this smallest score. 

* $\underline{1}, \underline{2}, \underline{3}, \underline{4}, \underline{5}, 10$
* $\underline{7}, 7, \underline{6}, \underline{4}, 2, \underline{2}, \underline{1}, \underline{3}, \underline{5}, \underline{8}, 10$
* $6, \underline{1}, 1, \underline{2}, 5, 7, 3, 3, 9, 10, 10, 1$
* $1, 3, \underline{1}, 1, 2, \underline{2}, \underline{3}, \underline{4}, \underline{5}, \underline{6}, \underline{7}, \underline{8}, \underline{9}, \underline{10}$


#### tags 

#1600 #brute_force #constructive_algorithms #greedy 