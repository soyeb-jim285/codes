<h1 style='text-align: center;'> C. Removal of Unattractive Pairs</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vlad found a string $s$ consisting of $n$ lowercase Latin letters, and he wants to make it as short as possible.

To do this, he can remove any pair of adjacent characters from $s$ any number of times, provided they are different. For example, if $s$=racoon, then by removing one pair of characters he can obtain the strings coon, roon, raon, and raco, but he cannot obtain racn (because the removed letters were the same) or rcon (because the removed letters were not adjacent).

What is the minimum length Vlad can achieve by applying any number of deletions?

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Descriptions of the test cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the string $s$.

The second line of each test case contains the string $s$ consisting of $n$ lowercase Latin letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single number—the minimum length of the string $s$, after removing pairs of adjacent characters with different values.

## Example

## Input


```

104aabc5abaca10avbvvcvvvd7abcdefg5dabbb8aacebeaa7bbbbacc6dacfcc6fdfcdc9dbdcfbbdc
```
## Output


```

0
1
2
1
1
0
1
0
0
1

```
## Note

In the first test case of the example, you need to act as follows: "aabc" $\rightarrow$ "ac" $\rightarrow$ "". ## Note

 that with a different order of deletions, the string will not become empty.



#### tags 

#1200 #constructive_algorithms #greedy #math #strings 