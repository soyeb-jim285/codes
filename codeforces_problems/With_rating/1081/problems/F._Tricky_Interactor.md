<h1 style='text-align: center;'> F. Tricky Interactor</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Chouti was tired of studying, so he opened the computer and started playing a puzzle game.

Long long ago, the boy found a sequence $s_1, s_2, \ldots, s_n$ of length $n$, kept by a tricky interactor. It consisted of $0$s and $1$s only and the number of $1$s is $t$. The boy knows nothing about this sequence except $n$ and $t$, but he can try to find it out with some queries with the interactor.

We define an operation called flipping. Flipping $[l,r]$ ($1 \leq l \leq r \leq n$) means for each $x \in [l,r]$, changing $s_x$ to $1-s_x$.

In each query, the boy can give the interactor two integers $l,r$ satisfying $1 \leq l \leq r \leq n$ and the interactor will either flip $[1,r]$ or $[l,n]$ (both outcomes have the same probability and all decisions made by interactor are independent from each other, see 
## Note

s section for more details). The interactor will tell the current number of $1$s after each operation. 
## Note

, that the sequence won't be restored after each operation.

Help the boy to find the original sequence in no more than $10000$ interactions.

"Weird legend, dumb game." he thought. However, after several tries, he is still stuck with it. Can you help him beat this game?

## Interaction

The interaction starts with a line containing two integers $n$ and $t$ ($1 \leq n \leq 300$, $0 \leq t \leq n$) — the length of the sequence and the number of $1$s in it.

After that, you can make queries.

To make a query, print a line "? l r" ($1 \leq l \leq r \leq n$), then flush the output.

After each query, read a single integer $t$ ($-1 \leq t \leq n$).

* If $t=-1$, it means that you're out of queries, you should terminate your program immediately, then you will get Wrong Answer, otherwise the judging result would be undefined because you will interact with a closed stream.
* If $t \geq 0$, it represents the current number of $1$s in the sequence.

When you found the original sequence, print a line "! s", flush the output and terminate. Print $s_1, s_2, \ldots, s_n$ as a binary string and do not print spaces in between.

Your solution will get Idleness Limit Exceeded if you don't print anything or forget to flush the output.

To flush you need to do the following right after printing a query and a line end: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

For hacks, use the following format:

In the first and only line, print a non-empty binary string. Its length will be $n$ and it will be treated as $s_1, s_2, \ldots, s_n$.

For example, the the test corresponding to the example contains a line "0011".

## Example

#Input
```text
4 2  
2  
2  
0
```
#Output
```text
? 1 1  
? 1 1  
? 3 4  
! 0011
```
## Note

For first query $1,1$, the interactor should flip $[1,1]$ or $[1,4]$. It chose to flip $[1,4]$, so the sequence became 1100.

For second query $1,1$, the interactor should flip $[1,1]$ or $[1,4]$. It again chose to flip $[1,4]$, so the sequence became 0011.

For third query $3,4$, the interactor should flip $[1,4]$ or $[3,4]$. It chose to flip $[3,4]$, so the sequence became 0000.

Q: How does interactor choose between $[1,r]$ and $[l,n]$? Is it really random?

A: The interactor will use a secret [pseudorandom number generator](https://en.wikipedia.org/wiki/Pseudorandom_number_generator). Only $s$ and your queries will be hashed and used as the seed. So if you give the same sequence of queries twice for the same secret string, you will get the same results. Except this, you can consider the choices fully random, like flipping a fair coin. You needn't (and shouldn't) exploit the exact generator to pass this problem.



#### Tags 

#2600 #NOT OK #constructive_algorithms #implementation #interactive 

## Blogs
- [All Contest Problems](../Avito_Cool_Challenge_2018.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
