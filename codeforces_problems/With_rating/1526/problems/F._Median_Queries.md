<h1 style='text-align: center;'> F. Median Queries</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

There is a secret permutation $p$ ($1$-indexed) of numbers from $1$ to $n$. More formally, for $1 \leq i \leq n$, $1 \leq p[i] \leq n$ and for $1 \leq i < j \leq n$, $p[i] \neq p[j]$. It is known that $p[1]<p[2]$.

In $1$ query, you give $3$ distinct integers $a,b,c$ ($1 \leq a,b,c \leq n$), and receive the median of $\{|p[a]-p[b]|,|p[b]-p[c]|,|p[a]-p[c]|\}$.

In this case, the median is the $2$-nd element ($1$-indexed) of the sequence when sorted in non-decreasing order. The median of $\{4,6,2\}$ is $4$ and the median of $\{0,123,33\}$ is $33$.

Can you find the secret permutation in not more than $2n+420$ queries?

## Note

: the grader is not adaptive: the permutation is fixed before any queries are made.

### Input

The first line of input contains a single integer $t$ $(1 \leq t \leq 1000)$ — the number of testcases.

The first line of each testcase consists of a single integer $n$ $(20 \leq n \leq 100000)$ — the length of the secret permutation.

It is guaranteed that the sum of $n$ over all test cases does not exceed $100000$.

## Interaction

For each testcase, you begin the interaction by reading $n$.

To perform a query, output "? a b c" where $a,b,c$ is the $3$ indices you want to use for the query.

Numbers have to satisfy $1 \leq a,b,c \leq n$ and $a \neq b$,$b \neq c$,$a \neq c$.

For each query, you will receive a single integer $x$: the median of $\{|p[a]-p[b]|,|p[b]-p[c]|,|p[a]-p[c]|\}$.

In case your query is invalid or you asked more than $2n+420$ queries, the interactor will print "−1" and will finish interaction. You will receive Wrong answer verdict. Make sure to exit immediately to avoid getting other verdicts.

When you have determined the secret permutation, output "! p[1] p[2] ... p[n]". If the secret permutation is correct, the interactor will print "1". Otherwise, the interactor will print "-1" and will finish interaction. You will receive Wrong answer verdict. Make sure to exit immediately to avoid getting other verdicts.

After printing a query do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded verdict.

To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks:

To hack, use the following format of test:

 The first line should contain a single integer $t$ ($1 \leq t \leq 1000$) — the number of testcases.

The first line of each testcase should contain a single integer $n$ ($20 \leq n \leq 100000$) — the length of the secret permutation.

The following line of should contain $n$ integers $p[1],p[2],p[3],\ldots,p[n]$. $p[1]<p[2]$ and $p$ must be a permutation of integers from $1$ to $n$.

You must ensure that the sum of $n$ over all testcases does not exceed $100000$.

## Example

### Input


```text
1
20

6

9

1
```
#Output
```text



? 1 5 2

? 20 19 2

! 9 10 19 7 16 18 11 14 15 6 20 8 17 4 5 3 12 2 13 1

```
## Note

The secret permutation is $\{9,10,19,7,16,18,11,14,15,6,20,8,17,4,5,3,12,2,13,1\}$.

For the first query, the values of $(a,b,c)$ is $(1,5,2)$. Since $p[1]=9$, $p[5]=16$ and $p[2]=10$. The return value is the median of $\{|9-16|,|16-10|,|9-10|\}$ which is $6$.

For the second query, the values of $(a,b,c)$ is $(20,19,2)$. Since $p[20]=1$, $p[19]=13$ and $p[2]=10$. The return value is the median of $\{|1-13|,|13-10|,|1-10|\}$ which is $9$.

By some miracle, we have figured out that the secret permutation is $\{9,10,19,7,16,18,11,14,15,6,20,8,17,4,5,3,12,2,13,1\}$. We output it and receive $1$ from the interactor, meaning that we have guessed the secret permutation correctly.



#### Tags 

#3000 #NOT OK #constructive_algorithms #interactive #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_723_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
