<h1 style='text-align: center;'> H. Thanos Snap</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

[Piotr Rubik - Psalm dla Ciebie](https://youtu.be/3WWwuA6twKI)ඞThere is an array $a$ of size $2^k$ for some positive integer $k$, which is initially a permutation of values from $1$ to $2^k$. Alice and Bob play the following game on the array $a$. First, a value $t$ between $1$ and $k$ is shown to both Alice and Bob. Then, for exactly $t$ turns, the following happens: 

* Alice either does nothing, or chooses two distinct elements of the array $a$ and swaps them.
* Bob chooses either the left half or the right half of the array $a$ and erases it.

The score of the game is defined as the maximum value in $a$ after all $t$ turns have been played. Alice wants to maximize this score, while Bob wants to minimize it.

You need to output $k$ numbers: the score of the game if both Alice and Bob play optimally for $t$ from $1$ to $k$.

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $k$ ($1 \le k \le 20$) — the parameter of the size of $a$.

The second line of each test case contains $2^k$ integers $a_1, a_2, \ldots, a_{2^k}$ ($1 \le a_i \le 2^k$, $a_i$'s are pairwise distinct) — the given array $a$.

It is guaranteed that the sum of $2^k$ over all test cases does not exceed $2^{20}$.

## Output

For each test case, print $k$ numbers, where the $i$-th number is the score of the game if both Alice and Bob play optimally for $t = i$.

## Example

## Input


```

511 224 3 2 135 1 6 4 7 2 8 3410 15 6 12 1 3 4 9 13 5 7 16 14 11 2 8532 2 5 23 19 17 31 7 29 3 4 16 13 9 30 24 14 1 8 20 6 15 26 18 10 27 22 12 25 21 28 11
```
## Output


```

1
3 1
7 5 1
15 13 9 1
31 28 25 17 1

```
## Note

In the third test case, for $t = 2$, the game could have proceeded as follows: 

* Initially, $a = [5, 1, 6, 4, 7, 2, 8, 3]$.
* Alice swaps $a_6$ and $a_8$, $a$ becomes $[5, 1, 6, 4, 7, 3, 8, 2]$.
* Bob erases the right half of the array, $a$ becomes $[5, 1, 6, 4]$.
* Alice does nothing, $a$ remains as $[5, 1, 6, 4]$.
* Bob erases the right half of the array, $a$ becomes $[5, 1]$.
* The game ends with a score of $5$.


#### tags 

#3200 #binary_search #dp #games #greedy #trees 