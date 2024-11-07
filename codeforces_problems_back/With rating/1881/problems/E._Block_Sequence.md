<h1 style='text-align: center;'> E. Block Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a sequence of integers $a$ of length $n$.

A sequence is called beautiful if it has the form of a series of blocks, each starting with its length, i.e., first comes the length of the block, and then its elements. For example, the sequences [$\color{red}{3},\ \color{red}{3},\ \color{red}{4},\ \color{red}{5},\ \color{green}{2},\ \color{green}{6},\ \color{green}{1}$] and [$\color{red}{1},\ \color{red}{8},\ \color{green}{4},\ \color{green}{5},\ \color{green}{2},\ \color{green}{6},\ \color{green}{1}$] are beautiful (different blocks are colored differently), while [$1$], [$1,\ 4,\ 3$], [$3,\ 2,\ 1$] are not.

In one operation, you can remove any element from the sequence. What is the minimum number of operations required to make the given sequence beautiful?

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then follows the descriptions of the test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the sequence $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$) — the elements of the sequence $a$.

It is guaranteed that the sum of the values of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single number — the minimum number of deletions required to make the sequence $a$ beautiful.

## Example

## Input


```

773 3 4 5 2 6 145 6 3 263 4 1 6 7 731 4 351 2 3 4 551 2 3 1 254 5 5 1 5
```
## Output


```

0
4
1
1
2
1
0

```
## Note

In the first test case of the example, the given sequence is already beautiful, as shown in the statement.

In the second test case of the example, the sequence can only be made beautiful by removing all elements from it.

In the fifth test case of the example, the sequence can be made beautiful by removing the first and last elements. Then the sequence will become [$2,\ 3,\ 4$].



#### tags 

#1500 #dp 