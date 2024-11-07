<h1 style='text-align: center;'> B. Patchouli's Magical Talisman</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

She is skilled in all kinds of magics, and is keen on inventing new one.—Perfect Memento in Strict SensePatchouli is making a magical talisman. She initially has $n$ magical tokens. Their magical power can be represented with positive integers $a_1, a_2, \ldots, a_n$. 

Patchouli may perform the following two operations on the tokens.

* Fusion: Patchouli chooses two tokens, removes them, and creates a new token with magical power equal to the sum of the two chosen tokens.
* Reduction: Patchouli chooses a token with an even value of magical power $x$, removes it and creates a new token with magical power equal to $\frac{x}{2}$.

Tokens are more effective when their magical powers are odd values. Please help Patchouli to find the minimum number of operations she needs to make magical powers of all tokens odd values.

## Input

Each test contains multiple test cases. 

The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases. The description of the test cases follows.

For each test case, the first line contains one integer $n$ ($1 \leq n\leq 2\cdot 10^5$) — the initial number of tokens.

The second line contains $n$ intergers $a_1,a_2,\ldots,a_n$ ($1 \leq a_i \leq 10^9$) — the initial magical power of the $n$ tokens.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print a single integer — the minimum number of operations Patchouli needs to make all tokens have an odd value of magical power.

It can be shown that under such restrictions the required sequence of operations exists. 

## Example

## Input


```

421 931 1 232 4 831049600 33792 1280
```
## Output


```

0
1
3
10

```
## Note

Test case 1:

$a$ consists solely of odd numbers initially.

Test case 2:

Choose the tokens with magical power of $1$ and $2$ and perform Fusion. Now $a=[1,3]$, both are odd numbers.

Test case 3:

Choose the tokens with magical power of $2$ and $8$ and perform Fusion. Now $a=[4,10]$.

Choose the token with magical power of $10$ and perform Reduction. Now $a=[4,5]$.

Choose the tokens with magical power of $4$ and $5$ and perform Fusion. Now $a=[9]$, and $9$ is an odd number.

It can be shown that you can not make all the magical powers odd numbers in less than $3$ moves, so the answer is $3$.



#### tags 

#800 #bitmasks #constructive_algorithms #greedy #sortings 