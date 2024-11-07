<h1 style='text-align: center;'> A. NIT orz!</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

NIT, the cleaver, is new in town! Thousands of people line up to orz him. To keep his orzers entertained, NIT decided to let them solve the following problem related to $\operatorname{or} z$. Can you solve this problem too?

You are given a 1-indexed array of $n$ integers, $a$, and an integer $z$. You can do the following operation any number (possibly zero) of times:

* Select a positive integer $i$ such that $1\le i\le n$. Then, simutaneously set $a_i$ to $(a_i\operatorname{or} z)$ and set $z$ to $(a_i\operatorname{and} z)$. In other words, let $x$ and $y$ respectively be the current values of $a_i$ and $z$. Then set $a_i$ to $(x\operatorname{or}y)$ and set $z$ to $(x\operatorname{and}y)$.

Here $\operatorname{or}$ and $\operatorname{and}$ denote the [bitwise operations OR and AND](https://en.wikipedia.org/wiki/Bitwise_operation) respectively.

Find the maximum possible value of the maximum value in $a$ after any number (possibly zero) of operations.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $z$ ($1\le n\le 2000$, $0\le z<2^{30}$).

The second line of each test case contains $n$ integers $a_1$,$a_2$,$\ldots$,$a_n$ ($0\le a_i<2^{30}$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^4$.

### Output

For each test case, print one integer — the answer to the problem.

## Example

### Input


```text
52 33 45 50 2 4 6 81 9105 77 15 30 29 273 3954874310293834 10284344 13635445
```
### Output

```text

7
13
11
31
48234367

```
## Note

In the first test case of the sample, one optimal sequence of operations is:

* Do the operation with $i=1$. Now $a_1$ becomes $(3\operatorname{or}3)=3$ and $z$ becomes $(3\operatorname{and}3)=3$.
* Do the operation with $i=2$. Now $a_2$ becomes $(4\operatorname{or}3)=7$ and $z$ becomes $(4\operatorname{and}3)=0$.
* Do the operation with $i=1$. Now $a_1$ becomes $(3\operatorname{or}0)=3$ and $z$ becomes $(3\operatorname{and}0)=0$.

After these operations, the sequence $a$ becomes $[3,7]$, and the maximum value in it is $7$. We can prove that the maximum value in $a$ can never exceed $7$, so the answer is $7$.

In the fourth test case of the sample, one optimal sequence of operations is:

* Do the operation with $i=1$. Now $a_1$ becomes $(7\operatorname{or}7)=7$ and $z$ becomes $(7\operatorname{and}7)=7$.
* Do the operation with $i=3$. Now $a_3$ becomes $(30\operatorname{or}7)=31$ and $z$ becomes $(30\operatorname{and}7)=6$.
* Do the operation with $i=5$. Now $a_5$ becomes $(27\operatorname{or}6)=31$ and $z$ becomes $(27\operatorname{and}6)=2$.


#### Tags 

#800 #OK #bitmasks #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_21.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
