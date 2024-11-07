<h1 style='text-align: center;'> A. Two 0-1 Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

AquaMoon has two binary sequences $a$ and $b$, which contain only $0$ and $1$. AquaMoon can perform the following two operations any number of times ($a_1$ is the first element of $a$, $a_2$ is the second element of $a$, and so on):

* Operation 1: if $a$ contains at least two elements, change $a_2$ to $\operatorname{min}(a_1,a_2)$, and remove the first element of $a$.
* Operation 2: if $a$ contains at least two elements, change $a_2$ to $\operatorname{max}(a_1,a_2)$, and remove the first element of $a$.

## Note

 that after a removal of the first element of $a$, the former $a_2$ becomes the first element of $a$, the former $a_3$ becomes the second element of $a$ and so on, and the length of $a$ reduces by one.

Determine if AquaMoon can make $a$ equal to $b$ by using these operations.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 2\,000$) — the number of test cases. Description of test cases follows.

The first line of each test case contains two integers $n$, $m$ ($1 \leq n,m \leq 50$, $m \leq n$) — the lengths of $a$ and $b$ respectively.

The second line of each test case contains a string $a$ of length $n$, consisting only $0$ and $1$.

The third line of each test case contains a string $b$ of length $m$, consisting only $0$ and $1$.

### Output

For each test case, output "YES" if AquaMoon can change $a$ to $b$ by using these options; otherwise, output "NO".

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as a positive answer).

## Example

### Input


```text
106 2001001116 2110111016 2000001116 2111111018 510000101110107 4101000110018 6010100100100108 40101010110018 41010101001107 5101110011100
```
### Output

```text

YES
YES
NO
NO
NO
YES
YES
NO
NO
YES

```
## Note

In the first test case, you can use Operation 2 four times to make $a$ equals to $b$.

In the second test case, you can use Operation 1 four times to make $a$ equals to $b$.

In the third test case, it can be proved that no matter how we use the operations, it is impossible to make $a$ equal to $b$.

In the fourth test case, it can be proved that no matter how we use the operations, it is impossible to make $a$ equal to $b$.

In the fifth test case, you can use Operation 2 three times to make $a$ become $10101$, so the first element of $a$ equals to the first element of $b$, but it can be proved that no matter how to operate, the second to the fifth elements of $a$ can't be the same as $b$.



#### Tags 

#800 #OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../CodeTON_Round_2_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [CodeTON Round 2 (en)](../blogs/CodeTON_Round_2_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
