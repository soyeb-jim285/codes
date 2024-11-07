<h1 style='text-align: center;'> B. Swap and Delete</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $s$ (a string consisting only of 0-s and 1-s).

You can perform two types of operations on $s$: 

1. delete one character from $s$. This operation costs $1$ coin;
2. swap any pair of characters in $s$. This operation is free (costs $0$ coins).

You can perform these operations any number of times and in any order.

Let's name a string you've got after performing operations above as $t$. The string $t$ is good if for each $i$ from $1$ to $|t|$ $t_i \neq s_i$ ($|t|$ is the length of the string $t$). The empty string is always good. ## Note

 that you are comparing the resulting string $t$ with the initial string $s$.

What is the minimum total cost to make the string $t$ good?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then $t$ test cases follow.

The only line of each test case contains a binary string $s$ ($1 \le |s| \le 2 \cdot 10^5$; $s_i \in \{$0, 1$\}$) — the initial string, consisting of characters 0 and/or 1.

Additional constraint on the input: the total length of all strings $s$ doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, print one integer — the minimum total cost to make string $t$ good.

## Example

## Input


```

400110101110001111100
```
## Output


```

1
1
0
4

```
## Note

In the first test case, you have to delete a character from $s$ to get the empty string $t$. Only then $t$ becomes good. One deletion costs $1$ coin.

In the second test case, you can, for example, delete the second character from $s$ to get the string 01, and then swap the first and second characters to get the string $t$ $=$ 10. String $t$ is good, since $t_1 \neq s_1$ and $t_2 \neq s_2$. The total cost is $1$ coin.

In the third test case, you can, for example, swap $s_1$ with $s_2$, swap $s_3$ with $s_4$, swap $s_5$ with $s_7$, $s_6$ with $s_8$ and $s_9$ with $s_{10}$. You'll get $t$ $=$ 1010001110. All swap operations are free, so the total cost is $0$.



#### tags 

#1000 #strings 