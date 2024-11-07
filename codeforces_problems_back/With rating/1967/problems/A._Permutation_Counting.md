<h1 style='text-align: center;'> A. Permutation Counting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have some cards. An integer between $1$ and $n$ is written on each card: specifically, for each $i$ from $1$ to $n$, you have $a_i$ cards which have the number $i$ written on them.

There is also a shop which contains unlimited cards of each type. You have $k$ coins, so you can buy $k$ new cards in total, and the cards you buy can contain any integer between $1$ and $n$.

After buying the new cards, you rearrange all your cards in a line. The score of a rearrangement is the number of (contiguous) subarrays of length $n$ which are a permutation of $[1, 2, \ldots, n]$. What's the maximum score you can get?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t\ (1\le t\le 100)$. The description of the test cases follows.

The first line of each test case contains two integers $n$, $k$ ($1\le n \le 2 \cdot 10^5$, $0\le k \le 10^{12}$) — the number of distinct types of cards and the number of coins.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^{12}$) — the number of cards of type $i$ you have at the beginning.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^5$.

## Output

For each test case, output a single line containing an integer: the maximum score you can get.

## Example

## Input


```

81 1012 48 43 46 1 83 97 6 25 36 6 7 4 69 77 6 1 7 6 2 4 3 310 101 3 1 2 1 9 3 5 7 59 85 8 7 5 1 3 2 9 8
```
## Output


```

11
15
15
22
28
32
28
36

```
## Note

In the first test case, the final (and only) array we can get is $[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]$ (including $11$ single $1$s), which contains $11$ subarrays consisting of a permutation of $[1]$.

In the second test case, we can buy $0$ cards of type $1$ and $4$ cards of type $2$, and then we rearrange the cards as following: $[1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2]$. There are $8$ subarrays equal to $[1, 2]$ and $7$ subarrays equal to $[2, 1]$, which make a total of $15$ subarrays which are a permutation of $[1, 2]$. It can also be proved that this is the maximum score we can get.

In the third test case, one of the possible optimal rearrangements is $[3, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 3]$.



#### tags 

#1400 #binary_search #greedy #implementation #math #sortings 