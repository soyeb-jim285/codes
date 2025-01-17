<h1 style='text-align: center;'> E. Rin and The Unknown Flower</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[MisoilePunch♪ - 彩](https://www.youtube.com/watch?v=5VleIdkEeak)This is an interactive problem!

On a normal day at the hidden office in A.R.C. Markland-N, Rin received an artifact, given to her by the exploration captain Sagar.

After much analysis, she now realizes that this artifact contains data about a strange flower, which has existed way before the New Age. However, the information about its chemical structure has been encrypted heavily.

The chemical structure of this flower can be represented as a string $p$. From the unencrypted papers included, Rin already knows the length $n$ of that string, and she can also conclude that the string contains at most three distinct letters: "C" (as in Carbon), "H" (as in Hydrogen), and "O" (as in Oxygen).

At each moment, Rin can input a string $s$ of an arbitrary length into the artifact's terminal, and it will return every starting position of $s$ as a substring of $p$.

However, the artifact has limited energy and cannot be recharged in any way, since the technology is way too ancient and is incompatible with any current A.R.C.'s devices. To be specific:

* The artifact only contains $\frac{7}{5}$ units of energy.
* For each time Rin inputs a string $s$ of length $t$, the artifact consumes $\frac{1}{t^2}$ units of energy.
* If the amount of energy reaches below zero, the task will be considered failed immediately, as the artifact will go black forever.

Since the artifact is so precious yet fragile, Rin is very nervous to attempt to crack the final data. Can you give her a helping hand?

## Interaction

The interaction starts with a single integer $t$ ($1 \le t \le 500$), the number of test cases. The interaction for each testcase is described below:

First, read an integer $n$ ($4 \le n \le 50$), the length of the string $p$.

Then you can make queries of type "? s" ($1 \le |s| \le n$) to find the occurrences of $s$ as a substring of $p$.

After the query, you need to read its result as a series of integers in a line:

* The first integer $k$ denotes the number of occurrences of $s$ as a substring of $p$ ($-1 \le k \le n$). If $k = -1$, it means you have exceeded the energy limit or printed an invalid query, and you need to terminate immediately, to guarantee a "Wrong answer" verdict, otherwise you might get an arbitrary verdict because your solution will continue to read from a closed stream.
* The following $k$ integers $a_1, a_2, \ldots, a_k$ ($1 \le a_1 < a_2 < \ldots < a_k \le n$) denote the starting positions of the substrings that match the string $s$.

When you find out the string $p$, print "! $p$" to finish a test case. This query doesn't consume any energy. The interactor will return an integer $1$ or $0$. If the interactor returns $1$, you can proceed to the next test case, or terminate the program if it was the last testcase.

If the interactor returns $0$, it means that your guess is incorrect, and you should to terminate to guarantee a "Wrong answer" verdict.

## Note

 that in every test case the string $p$ is fixed beforehand and will not change during the queries, i.e. the interactor is not adaptive.

After printing any query do not forget to print end of line and flush the output. Otherwise, you might get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

Hacks

For hack, use the following format. 
## Note

 that you can only hack with one test case:

The first line should contain a single integer $t$ ($t = 1$).

The second line should contain an integer $n$ ($4 \le n \le 50$) — the string's size.

The third line should contain a string of size $n$, consisting of characters "C", "H" and "O" only. This is the string contestants will have to find out.

## Examples

##Input
```text
1
4

2 1 2

1 2

0

1
```
##Output
```text



? C

? CH

? CCHO

! CCHH

```
##Input
```text
2
5

0

2 2 3

1
8

1 5

1 5

1 3

2 1 2

1
```
##Output
```text



? O

? HHH

! CHHHH


? COO

? COOH

? HCCOO

? HH

! HHHCCOOH

```
## Note

## Note

 that the example interaction contains extra empty lines so that it's easier to read. The real interaction doesn't contain any empty lines and you shouldn't print any extra empty lines as well.



#### Tags 

#3500 #NOT OK #constructive_algorithms #greedy #interactive #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_614_(Div._1).md)
- [Codeforces Round #614 (en)](../blogs/Codeforces_Round_614_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
