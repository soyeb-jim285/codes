<h1 style='text-align: center;'> F. Katya and Segments Sets</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

It is a very important day for Katya. She has a test in a programming class. As always, she was given an interesting problem that she solved very fast. Can you solve that problem?

You are given $n$ ordered segments sets. Each segment can be represented as a pair of two integers $[l, r]$ where $l\leq r$. Each set can contain an arbitrary number of segments (even $0$). It is possible that some segments are equal.

You are also given $m$ queries, each of them can be represented as four numbers: $a, b, x, y$. For each segment, find out whether it is true that each set $p$ ($a\leq p\leq b$) contains at least one segment $[l, r]$ that lies entirely on the segment $[x, y]$, that is $x\leq l\leq r\leq y$. 

Find out the answer to each query.

## Note

 that you need to solve this problem online. That is, you will get a new query only after you print the answer for the previous query.

## Input

The first line contains three integers $n$, $m$, and $k$ $(1\leq n,m\leq 10^5, 1\leq k\leq 3\cdot10^5)$ — the number of sets, queries, and segments respectively.

Each of the next $k$ lines contains three integers $l$, $r$, and $p$ $(1\leq l\leq r\leq 10^9, 1\leq p\leq n)$ — the limits of the segment and the index of a set, to which this segment belongs.

Each of the next $m$ lines contains four integers $a, b, x, y$ $(1\leq a\leq b\leq n, 1\leq x\leq y\leq 10^9)$ — the description of the query.

## Output

For each query, print "yes" or "no" in a new line.

## Interaction

After printing a query, do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.
## Example

## Input


```

5 5 9
3 6 3
1 3 1
2 4 2
1 2 3
4 6 5
2 5 3
7 9 4
2 3 1
4 10 4
1 2 2 3
1 2 2 4
1 3 1 5
2 3 3 6
2 4 2 9

```
## Output


```

no
yes
yes
no
yes

```
## Note

For the first query, the answer is negative since the second set does not contain a segment that lies on the segment $[2, 3]$.

In the second query, the first set contains $[2, 3]$, and the second set contains $[2, 4]$.

In the third query, the first set contains $[2, 3]$, the second set contains $[2, 4]$, and the third set contains $[2, 5]$.

In the fourth query, the second set does not contain a segment that lies on the segment $[3, 6]$.

In the fifth query, the second set contains $[2, 4]$, the third set contains $[2, 5]$, and the fourth contains $[7, 9]$.



#### tags 

#2400 #data_structures #interactive #sortings 