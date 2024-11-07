<h1 style='text-align: center;'> A. Bitwise Operation Wizard</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

There is a secret sequence $p_0, p_1, \ldots, p_{n-1}$, which is a permutation of $\{0,1,\ldots,n-1\}$.

You need to find any two indices $i$ and $j$ such that $p_i \oplus p_j$ is maximized, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

To do this, you can ask queries. Each query has the following form: you pick arbitrary indices $a$, $b$, $c$, and $d$ ($0 \le a,b,c,d < n$). Next, the jury calculates $x = (p_a \mid p_b)$ and $y = (p_c \mid p_d)$, where $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR). Finally, you receive the result of comparison between $x$ and $y$. In other words, you are told if $x < y$, $x > y$, or $x = y$.

Please find any two indices $i$ and $j$ ($0 \le i,j < n$) such that $p_i \oplus p_j$ is maximum among all such pairs, using at most $3n$ queries. If there are multiple pairs of indices satisfying the condition, you may output any one of them.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^3$). The description of the test cases follows.

## Interaction

The first line of each test case contains one integer $n$ ($2 \le n \le 10^4$). At this moment, the permutation $p_0, p_1, \ldots, p_{n-1}$ is chosen. The interactor in this task is not adaptive. In other words, the sequence $p$ is fixed in every test case and does not change during the interaction.

To ask a query, you need to pick four indices $a$, $b$, $c$, and $d$ ($0 \le a,b,c,d < n$) and print the line of the following form:

* "? a b c d"

After that, you receive:

* "<" if $(p_a \mid p_b) < (p_c \mid p_d)$;
* "=" if $(p_a \mid p_b) = (p_c \mid p_d)$;
* ">" if $(p_a \mid p_b) > (p_c \mid p_d)$.

You can make at most $3n$ queries of this form.

Next, if your program has found a pair of indices $i$ and $j$ ($0 \le i, j < n$) such that $p_i \oplus p_j$ is maximized, print the line of the following form:

* "! i j"

## Note

 that this line is not considered a query and is not taken into account when counting the number of queries asked.

After this, proceed to the next test case.

If you make more than $3n$ queries during an interaction, your program must terminate immediately, and you will receive the Wrong Answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

After printing a query or the answer for a test case, do not forget to output the end of line and flush the output. Otherwise, you will get the verdict Idleness Limit Exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^4$.

Hacks

To hack, follow the test format below.

The first line contains the number of test cases $t$ ($1 \le t \le 10^3$). The description of the test cases follows.

The first line of each test case contains one integer $n$ ($2 \le n \le 10^4$).

The second line of each test case contains $n$ integers $p_0,p_1,\ldots,p_{n-1}$, which represent a permutation of integers from $0$ to $n - 1$.

The sum of $n$ over all test cases should not exceed $10^4$.

## Example

### Input


```text
2
4

<

=

>

2
```
#Output
```text


? 0 2 3 1

? 1 1 2 3

? 1 2 0 3

! 3 2

! 0 1
```
## Note

In the first test case, the hidden permutation is $p=[0,3,1,2]$.

For the query "? 0 2 3 1", the jury return "<" because $(p_0 \mid p_2) = (0 \mid 1) =1 < (p_3 \mid p_1) = (2 \mid 3) = 3$.

For the query "? 1 1 2 3", the jury return "=" because $(p_1 \mid p_1) = (3\mid 3)= 3 = (p_2 \mid p_3) = (1 \mid 2)=3$.

For the query "? 1 2 0 3", the jury return ">" because $(p_1 \mid p_2) = (3 \mid 1) = 3 > (p_0 \mid p_3) = (0\mid 2)=2$.

The answer $i = 3$ and $j = 2$ is valid: $(p_3 \oplus p_2) = (2 \oplus 1) = 3$ is indeed equal to the maximum possible value of $p_i \oplus p_j$. Another valid answer would be $i=0$ and $j=1$. As the number of queries does not exceed $3n=12$, the answer is considered correct.

In the second test case, $n = 2$, so $p$ is either $[0, 1]$ or $[1, 0]$. In any case, $p_0 \oplus p_1 = 1$ is maximum possible.



#### Tags 

#1700 #NOT OK #bitmasks #constructive_algorithms #greedy #interactive #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_930_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
