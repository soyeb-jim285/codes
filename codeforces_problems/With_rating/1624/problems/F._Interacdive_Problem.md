<h1 style='text-align: center;'> F. Interacdive Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This problem is interactive.

We decided to play a game with you and guess the number $x$ ($1 \le x < n$), where you know the number $n$.

You can make queries like this:

* + c: this command assigns $x = x + c$ ($1 \le c < n$) and then returns you the value $\lfloor\frac{x}{n}\rfloor$ ($x$ divide by $n$ and round down).

You win if you guess the current number with no more than $10$ queries.

## Interaction

The interaction begins by reading an integer $n$ ($2 < n \le 1000$), which is written in the input data on its own line.

Then you can make no more than $10$ queries. To make a query, print on a separate line:

* + c: this command will assign $x = x + c$ ($1 \le c < n$) and then print $\lfloor\frac{x}{n}\rfloor$ (divide $x$ by $n$ and round down) on a separate line.

 Print the answer, like the queries, on a separate line. The answer doesn't count in number of queries. To output it, use the following format:

* ! x: the current value of $x$.

After that, your program should exit.

You have to use a flush operation right after printing each line. For example, in C++ you should use the function fflush(stdout), in Java — System.out.flush(), in Pascal — flush(output) and in Python — sys.stdout.flush().

## Note

 that the interactor is not responsive.

To make a hack, use the following format: a single line must contain two numbers $x$ and $n$, separated by a space.

## Examples

###Input
```text
3

1
```
###Output
```text

+ 1

! 3
```
###Input
```text

5

0

0

1
```
###Output
```text
+ 1

+ 1

+ 1

! 5
```
###Input
```text

10

0

0

1

2
```
###Output
```text


+ 2

+ 2

+ 3

+ 8

! 20
```
## Note

In the first sample initially $x = 2$. After the first query $x = 3$, $\lfloor\frac{x}{n}\rfloor = 1$.

In the second sample also initially $x = 2$. After the first query $x = 3$, $\lfloor\frac{x}{n}\rfloor = 0$. After the second query $x = 4$, $\lfloor\frac{x}{n}\rfloor = 0$. After the third query $x=5$, $\lfloor\frac{x}{n}\rfloor = 1$.



#### Tags 

#2000 #NOT OK #binary_search #constructive_algorithms #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_764_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
