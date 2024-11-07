<h1 style='text-align: center;'> C. Nastia and a Hidden Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem!

Nastia has a hidden permutation $p$ of length $n$ consisting of integers from $1$ to $n$. You, for some reason, want to figure out the permutation. To do that, you can give her an integer $t$ ($1 \le t \le 2$), two different indices $i$ and $j$ ($1 \le i, j \le n$, $i \neq j$), and an integer $x$ ($1 \le x \le n - 1$). 

Depending on $t$, she will answer: 

* $t = 1$: $\max{(\min{(x, p_i)}, \min{(x + 1, p_j)})}$;
* $t = 2$: $\min{(\max{(x, p_i)}, \max{(x + 1, p_j)})}$.

You can ask Nastia at most $\lfloor \frac {3 \cdot n} { 2} \rfloor + 30$ times. It is guaranteed that she will not change her permutation depending on your queries. Can you guess the permutation?

### Input

The input consists of several test cases. In the beginning, you receive the integer $T$ ($1 \le T \le 10\,000$) — the number of test cases.

At the beginning of each test case, you receive an integer $n$ ($3 \le n \le 10^4$) — the length of the permutation $p$.

It's guaranteed that the permutation is fixed beforehand and that the sum of $n$ in one test doesn't exceed $2 \cdot 10^4$.

## Interaction

To ask a question, print "? $t$ $i$ $j$ $x$" ($t = 1$ or $t = 2$, $1 \le i, j \le n$, $i \neq j$, $1 \le x \le n - 1$) Then, you should read the answer.

If we answer with $−1$ instead of a valid answer, that means you exceeded the number of queries or made an invalid query. Exit immediately after receiving $−1$ and you will see the Wrong Answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

To print the answer, print "! $p_1$ $p_2$ $\ldots$ $p_{n}$ (without quotes). 
## Note

 that answering doesn't count as one of the $\lfloor \frac {3 \cdot n} {2} \rfloor + 30$ queries.

After printing a query or printing the answer, do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* See the documentation for other languages.

Hacks

To hack the solution, use the following test format.

The first line should contain a single integer $T$ ($1 \le T \le 10\,000$) — the number of test cases.

For each test case in the first line print a single integer $n$ ($3 \le n \le 10^4$) — the length of the hidden permutation $p$.

In the second line print $n$ space-separated integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$), where $p$ is permutation.

## Note

 that the sum of $n$ over all test cases should not exceed $2 \cdot 10^4$.

## Example

### Input


```text
2
4

3

2

5

3
```
#Output
```text

? 2 4 1 3

? 1 2 4 2

! 3 1 4 2

? 2 3 4 2

! 2 5 3 4 1
```
## Note

Consider the first test case.

The hidden permutation is $[3, 1, 4, 2]$.

We print: "? $2$ $4$ $1$ $3$" and get back $\min{(\max{(3, p_4}), \max{(4, p_1)})} = 3$.

We print: "? $1$ $2$ $4$ $2$" and get back $\max{(\min{(2, p_2)}, \min{(3, p_4)})} = 2$.

Consider the second test case.

The hidden permutation is $[2, 5, 3, 4, 1]$.

We print: "? $2$ $3$ $4$ $2$" and get back $\min{(\max{(2, p_3}), \max{(3, p_4)})} = 3$.



#### Tags 

#2000 #NOT OK #constructive_algorithms #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_720_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
