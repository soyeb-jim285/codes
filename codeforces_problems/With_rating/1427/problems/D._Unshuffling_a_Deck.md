<h1 style='text-align: center;'> D. Unshuffling a Deck</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a deck of $n$ cards numbered from $1$ to $n$ (not necessarily in this order in the deck). You have to sort the deck by repeating the following operation. 

* Choose $2 \le k \le n$ and split the deck in $k$ nonempty contiguous parts $D_1, D_2,\dots, D_k$ ($D_1$ contains the first $|D_1|$ cards of the deck, $D_2$ contains the following $|D_2|$ cards and so on). Then reverse the order of the parts, transforming the deck into $D_k, D_{k-1}, \dots, D_2, D_1$ (so, the first $|D_k|$ cards of the new deck are $D_k$, the following $|D_{k-1}|$ cards are $D_{k-1}$ and so on). The internal order of each packet of cards $D_i$ is unchanged by the operation.

You have to obtain a sorted deck (i.e., a deck where the first card is $1$, the second is $2$ and so on) performing at most $n$ operations. It can be proven that it is always possible to sort the deck performing at most $n$ operations.

## Examples

 of operation: The following are three examples of valid operations (on three decks with different sizes). 

* If the deck is [3 6 2 1 4 5 7] (so $3$ is the first card and $7$ is the last card), we may apply the operation with $k=4$ and $D_1=$[3 6], $D_2=$[2 1 4], $D_3=$[5], $D_4=$[7]. Doing so, the deck becomes [7 5 2 1 4 3 6].
* If the deck is [3 1 2], we may apply the operation with $k=3$ and $D_1=$[3], $D_2=$[1], $D_3=$[2]. Doing so, the deck becomes [2 1 3].
* If the deck is [5 1 2 4 3 6], we may apply the operation with $k=2$ and $D_1=$[5 1], $D_2=$[2 4 3 6]. Doing so, the deck becomes [2 4 3 6 5 1].
##### Input

The first line of the input contains one integer $n$ ($1\le n\le 52$)  — the number of cards in the deck.

The second line contains $n$ integers $c_1, c_2, \dots, c_n$  — the cards in the deck. The first card is $c_1$, the second is $c_2$ and so on.

It is guaranteed that for all $i=1,\dots,n$ there is exactly one $j\in\{1,\dots,n\}$ such that $c_j = i$.

##### Output

On the first line, print the number $q$ of operations you perform (it must hold $0\le q\le n$).

Then, print $q$ lines, each describing one operation.

To describe an operation, print on a single line the number $k$ of parts you are going to split the deck in, followed by the size of the $k$ parts: $|D_1|, |D_2|, \dots , |D_k|$. 

It must hold $2\le k\le n$, and $|D_i|\ge 1$ for all $i=1,\dots,k$, and $|D_1|+|D_2|+\cdots + |D_k| = n$.

It can be proven that it is always possible to sort the deck performing at most $n$ operations. If there are several ways to sort the deck you can output any of them.

## Examples

##### Input


```text
4
3 1 2 4
```
##### Output


```text
2
3 1 2 1
2 1 3
```
##### Input


```text
6
6 5 4 3 2 1
```
##### Output


```text
1
6 1 1 1 1 1 1
```
##### Input


```text
1
1
```
##### Output


```text
0
```
## Note

Explanation of the first testcase: Initially the deck is [3 1 2 4]. 

* The first operation splits the deck as [(3) (1 2) (4)] and then transforms it into [4 1 2 3].
* The second operation splits the deck as [(4) (1 2 3)] and then transforms it into [1 2 3 4].

 Explanation of the second testcase: Initially the deck is [6 5 4 3 2 1]. * The first (and only) operation splits the deck as [(6) (5) (4) (3) (2) (1)] and then transforms it into [1 2 3 4 5 6].


#### Tags 

#2000 #NOT OK #constructive_algorithms #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_11.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
