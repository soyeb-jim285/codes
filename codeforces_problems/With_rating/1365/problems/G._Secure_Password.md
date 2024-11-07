<h1 style='text-align: center;'> G. Secure Password</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Ayush devised yet another scheme to set the password of his lock. The lock has $n$ slots where each slot can hold any non-negative integer. The password $P$ is a sequence of $n$ integers, $i$-th element of which goes into the $i$-th slot of the lock.

To set the password, Ayush comes up with an array $A$ of $n$ integers each in the range $[0, 2^{63}-1]$. He then sets the $i$-th element of $P$ as the [bitwise OR](https://en.wikipedia.org/wiki/Bitwise_operation#OR) of all integers in the array except $A_i$.

You need to guess the password. To make a query, you can choose a non-empty subset of indices of the array and ask the bitwise OR all elements of the array with index in this subset. You can ask no more than 13 queries.

### Input

The first line of input contains one integer $n$ $(2 \le n \le 1000)$ — the number of slots in the lock.

## Interaction

To ask a query print a single line: 

* In the beginning print "? c " (without quotes) where $c$ $(1 \leq c \leq n)$ denotes the size of the subset of indices being queried, followed by $c$ distinct space-separated integers in the range $[1, n]$.

For each query, you will receive an integer $x$ — the bitwise OR of values in the array among all the indices queried. If the subset of indices queried is invalid or you exceeded the number of queries then you will get $x = -1$. In this case, you should terminate the program immediately.

When you have guessed the password, print a single line "! " (without quotes), followed by $n$ space-separated integers  — the password sequence.

Guessing the password does not count towards the number of queries asked.

The interactor is not adaptive. The array $A$ does not change with queries.

After printing a query do not forget to output the end of the line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

Hacks

To hack the solution, use the following test format:

On the first line print a single integer $n$ $(2 \le n \le 1000)$ — the number of slots in the lock. The next line should contain $n$ space-separated integers in the range $[0, 2^{63} - 1]$ — the array $A$.

## Example

### Input


```text
3

1

2

4

```
#Output
```text
? 1 1

? 1 2

? 1 3

! 6 5 3
```
## Note

The array $A$ in the example is $\{{1, 2, 4\}}$. The first element of the password is bitwise OR of $A_2$ and $A_3$, the second element is bitwise OR of $A_1$ and $A_3$ and the third element is bitwise OR of $A_1$ and $A_2$. Hence the password sequence is $\{{6, 5, 3\}}$.



#### Tags 

#2800 #NOT OK #bitmasks #combinatorics #constructive_algorithms #interactive #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_648_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
