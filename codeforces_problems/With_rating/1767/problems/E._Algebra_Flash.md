<h1 style='text-align: center;'> E. Algebra Flash</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 Algebra Flash 2.2 has just been released!Changelog:

* New gamemode!

Thank you for the continued support of the game! 

Huh, is that it? Slightly disappointed, you boot up the game and click on the new gamemode. It says "Colored platforms".

There are $n$ platforms, numbered from $1$ to $n$, placed one after another. There are $m$ colors available in the game, numbered from $1$ to $m$. The $i$-th platform is colored $c_i$.

You start on the platform $1$ and want to reach platform $n$. In one move, you can jump from some platform $i$ to platforms $i + 1$ or $i + 2$.

All platforms are initially deactivated (including platforms $1$ and $n$). For each color $j$, you can pay $x_j$ coins to activate all platforms of that color.

You want to activate some platforms so that you could start on an activated platform $1$, jump through some activated platforms and reach an activated platform $n$.

What's the smallest amount of coins you can spend to achieve that?

###### Input

The first line contains two integers $n$ and $m$ ($2 \le n \le 3 \cdot 10^5$; $1 \le m \le 40$) — the number of platforms and the number of colors, respectively.

The second line contains $n$ integers $c_1, c_2, \dots, c_n$ ($1 \le c_i \le m$) — the colors of the platforms.

The third line contains $m$ integers $x_1, x_2, \dots, x_m$ ($1 \le x_i \le 10^7$) — the cost of activating all platforms of each color.

###### Output

Print the smallest amount of coins you can spend to activate some platforms so that you could start on an activated platform $1$, jump through some activated platforms and reach an activated platform $n$.

## Examples

###### Input


```text
5 3
1 3 2 3 1
1 10 100
```
###### Output


```text
11
```
###### Input


```text
5 3
1 3 2 3 1
1 200 20
```
###### Output


```text
21
```
###### Input


```text
4 2
2 2 1 1
5 5
```
###### Output


```text
10
```
###### Input


```text
10 10
3 8 6 2 10 5 2 3 7 3
9 7 4 2 1 8 2 6 2 2
```
###### Output


```text
15
```


#### Tags 

#2500 #NOT OK #bitmasks #brute_force #dp #graphs #math #meet-in-the-middle #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_140_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
