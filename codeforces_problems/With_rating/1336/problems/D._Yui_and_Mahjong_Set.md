<h1 style='text-align: center;'> D. Yui and Mahjong Set</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Yui is a girl who enjoys playing Mahjong.

![](images/52d3020384f00426f2e00e8e88039c5fc29bbdd8.png) She has a mysterious set which consists of tiles (this set can be empty). Each tile has an integer value between $1$ and $n$, and at most $n$ tiles in the set have the same value. So the set can contain at most $n^2$ tiles.

You want to figure out which values are on the tiles. But Yui is shy, she prefers to play a guessing game with you.

Let's call a set consisting of three tiles triplet if their values are the same. For example, $\{2,\,2,\,2\}$ is a triplet, but $\{2,\,3,\,3\}$ is not.

Let's call a set consisting of three tiles straight if their values are consecutive integers. For example, $\{2,\,3,\,4\}$ is a straight, but $\{1,\,3,\,5\}$ is not.

At first, Yui gives you the number of triplet subsets and straight subsets of the initial set respectively. After that, you can insert a tile with an integer value between $1$ and $n$ into the set at most $n$ times. Every time you insert a tile, you will get the number of triplet subsets and straight subsets of the current set as well.

## Note

 that two tiles with the same value are treated different. In other words, in the set $\{1,\,1,\,2,\,2,\,3\}$ you can find $4$ subsets $\{1,\,2,\,3\}$.

Try to guess the number of tiles in the initial set with value $i$ for all integers $i$ from $1$ to $n$.

### Input

The first line contains a single integer $n$ ($4 \le n \le 100$).

The second line contains two integers which represent the number of triplet subsets and straight subsets of the initial set respectively.

### Output

When you are ready to answer, print a single line of form "! $a_1$ $a_2$ $\ldots$ $a_n$" ($0 \le a_i \le n$), where $a_i$ is equal to the number of tiles in the initial set with value $i$.

## Interaction

To insert a tile, print a single line of form "+ $x$" ($1 \le x \le n$), where $x$ is the value of the tile you insert. Then you should read two integers which represent the number of triplet subsets and straight subsets of the current set respectively.

After printing a line, do not forget to flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

You will get Wrong answer if you insert more than $n$ tiles.

Hacks

To make a hack you should provide a test in such format:

The first line contains a single integer $n$ ($4 \le n \le 100$).

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($0 \le a_i \le n$)  — $a_i$ is equal to the number of tiles with value $i$ in the set.

## Example

### Input


```text
5
1 6
2 9
5 12
5 24
6 24
```
### Output


```text
+ 1
+ 1
+ 2
+ 5
! 2 1 3 0 2
```
## Note

In the first test, the initial set of tiles is $\{1, 1, 2, 3, 3, 3, 5, 5\}$. It has only one triplet subset $\{3, 3, 3\}$ and six straight subsets, all equal to $\{1, 2, 3\}$. After inserting a tile with value $1$ the set of tiles will be $\{1, 1, 1, 2, 3, 3, 3, 5, 5\}$ and will have two triplet subsets $\{1, 1, 1\}$, $\{3, 3, 3\}$ and nine straight subsets, all equal to $\{1, 2, 3\}$.



#### Tags 

#3200 #NOT OK #constructive_algorithms #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_635_(Div._1).md)
- [Codeforces Round #635 (en)](../blogs/Codeforces_Round_635_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
