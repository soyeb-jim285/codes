<h1 style='text-align: center;'> E. Magic Tricks</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Masha is going to participate in a talent show conducted by the university she studies at. She wants to impress the audience with lots of different magic tricks!

For one of her tricks, she uses $n$ sponge balls, one of which is a special one. First, she arranges the balls in a row in such a way that the special ball is put on position $k$ (positions are numbered from $1$ to $n$ from left to right). After that, she performs $m$ swaps: during the $i$-th swap, she chooses the ball on position $x_i$ and the ball on position $y_i$, and swaps them.

Since Masha is a magician, she fakes some of her actions to trick the audience — when she starts performing a swap, she may fake it, so it is not performed (but it looks like it is performed for the audience). There are no constraints on which swaps Masha should fake or should actually perform — for example, she may fake all of the swaps, or even not fake anything at all.

For the trick to work perfectly, the special ball should end up on a specific position — Masha has not decided yet, which position is perfect. Since faking swaps is difficult, for each position she wants to know the minimum number of swaps she has to fake so that the special ball ends up there. 

Unfortunately, Masha is a magician, neither a mathematician nor a programmer. So she needs your help in calculating what she wants!

##### Input

The first line contains three integers $n$, $m$ and $k$ ($2 \le n \le 2 \cdot 10^5$; $1 \le m \le 2 \cdot 10^5$; $1 \le k \le n$) — the number of balls, the number of swaps and the initial position of the special ball, respectively.

Then $m$ lines follow, the $i$-th line contains two integers $x_i$ and $y_i$ ($1 \le x_i, y_i \le n$; $x_i \ne y_i$) denoting the $i$-th swap.

##### Output

Print $n$ integers. The $i$-th integer should be the minimum number of swaps Masha has to fake so the special ball ends up on position $i$ (or $-1$, if Masha cannot put the special ball there).

## Examples

##### Input


```text
4 5 1
3 4
2 1
4 1
3 1
3 1
```
##### Output


```text
2 0 3 1 
```
##### Input


```text
5 7 4
3 2
3 2
4 2
3 4
4 1
3 2
5 2
```
##### Output


```text
2 2 0 3 1 
```
##### Input


```text
7 15 5
5 3
4 2
6 1
2 4
1 6
3 7
5 6
4 2
6 4
2 6
6 3
6 3
7 6
2 6
7 2
```
##### Output


```text
-1 1 1 1 2 1 0 
```


#### Tags 

#1700 #NOT OK #*special #dp #graphs 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_4.md)
- [Kotlin Heroes: Episode 4 (en)](../blogs/Kotlin_Heroes:_Episode_4_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
