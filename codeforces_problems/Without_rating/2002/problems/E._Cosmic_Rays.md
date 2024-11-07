<h1 style='text-align: center;'> E. Cosmic Rays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Given an array of integers $s_1, s_2, \ldots, s_l$, every second, cosmic rays will cause all $s_i$ such that $i=1$ or $s_i\neq s_{i-1}$ to be deleted simultaneously, and the remaining parts will be concatenated together in order to form the new array $s_1, s_2, \ldots, s_{l'}$.

Define the strength of an array as the number of seconds it takes to become empty.

You are given an array of integers compressed in the form of $n$ pairs that describe the array left to right. Each pair $(a_i,b_i)$ represents $a_i$ copies of $b_i$, i.e. $\underbrace{b_i,b_i,\cdots,b_i}_{a_i\textrm{ times}}$.

For each $i=1,2,\dots,n$, please find the strength of the sequence described by the first $i$ pairs.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\le t\le10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1\le n\le3\cdot10^5$) — the length of sequence $a$.

The next $n$ lines contain two integers each $a_i$, $b_i$ ($1\le a_i\le10^9,0\le b_i\le n$) — the pairs which describe the sequence.

It is guaranteed that the sum of all $n$ does not exceed $3\cdot10^5$.

It is guaranteed that for all $1\le i<n$, $b_i\neq b_{i+1}$ holds.

### Output

For each test case, print one line containing $n$ integers — the answer for each prefix of pairs.

## Example

### Input

```text
442 01 13 05 164 61 34 64 07 66 379 07 15 07 19 01 12 01010 74 92 27 92 88 511 715 512 74 0
```

### Output

```text

2 2 4 5
4 4 7 7 10 10
9 9 9 9 9 9 10
10 10 10 10 10 10 12 15 15 15

```

## Note

In the first test case, for the prefix of length $4$, the changes will be $[0,0,1,0,0,0,1,1,1,1,1]\rightarrow[0,0,0,1,1,1,1]\rightarrow[0,0,1,1,1]\rightarrow[0,1,1]\rightarrow[1]\rightarrow[]$, so the array becomes empty after $5$ seconds.

In the second test case, for the prefix of length $4$, the changes will be $[6,6,6,6,3,6,6,6,6,0,0,0,0]\rightarrow[6,6,6,6,6,6,0,0,0]\rightarrow[6,6,6,6,6,0,0]\rightarrow[6,6,6,6,0]\rightarrow[6,6,6]\rightarrow[6,6]\rightarrow[6]\rightarrow[]$, so the array becomes empty after $7$ seconds.

#### Tags

#NOT OK #data_structures #greedy #implementation

## Blogs

- [All Contest Problems](<../EPIC_Institute_of_Technology_Round_August_2024_(Div._1_+_Div._2).md>)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](<../blogs/Tutorial_(en).md>)
