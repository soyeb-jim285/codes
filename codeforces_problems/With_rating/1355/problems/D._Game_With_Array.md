<h1 style='text-align: center;'> D. Game With Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya and Vasya are competing with each other in a new interesting game as they always do.

At the beginning of the game Petya has to come up with an array of $N$ positive integers. Sum of all elements in his array should be equal to $S$. Then Petya has to select an integer $K$ such that $0 \leq K \leq S$.

In order to win, Vasya has to find a non-empty subarray in Petya's array such that the sum of all selected elements equals to either $K$ or $S - K$. Otherwise Vasya loses.

You are given integers $N$ and $S$. You should determine if Petya can win, considering Vasya plays optimally. If Petya can win, help him to do that.

##### Input

The first line contains two integers $N$ and $S$ ($1 \leq N \leq S \leq 10^{6}$) — the required length of the array and the required sum of its elements.

##### Output

If Petya can win, print "YES" (without quotes) in the first line. Then print Petya's array in the second line. The array should contain $N$ positive integers with sum equal to $S$. In the third line print $K$. If there are many correct answers, you can print any of them.

If Petya can't win, print "NO" (without quotes).

You can print each letter in any register (lowercase or uppercase).

## Examples

##### Input


```text
1 4
```
##### Output


```text
YES
4
2
```
##### Input

```text

3 4

```
##### Output


```text
NO
```
##### Input

```text

3 8

```
##### Output


```text

YES
2 1 5
4
```


#### Tags 

#1400 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_643_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
