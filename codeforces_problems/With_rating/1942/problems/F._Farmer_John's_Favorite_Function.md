<h1 style='text-align: center;'> F. Farmer John's Favorite Function</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[ΩΩPARTS - Camellia](https://soundcloud.com/user-838515264/camellia-parts-ooparts)⠀Farmer John has an array $a$ of length $n$. He also has a function $f$ with the following recurrence: 

* $f(1) = \sqrt{a_1}$;
* For all $i > 1$, $f(i) = \sqrt{f(i-1)+a_i}$.

## Note

 that $f(i)$ is not necessarily an integer.

He plans to do $q$ updates to the array. Each update, he gives you two integers $k$ and $x$ and he wants you to set $a_k = x$. After each update, he wants to know $\lfloor f(n) \rfloor$, where $\lfloor t \rfloor$ denotes the value of $t$ rounded down to the nearest integer.

###### Input

The first line contains $n$ and $q$ ($1 \leq n, q \leq 2 \cdot 10^5$), the length of $a$ and the number of updates he will perform.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 10^{18}$).

The next $q$ lines each contain two integers $k$ and $x$ ($1 \leq k \leq n$, $0 \leq x \leq 10^{18}$), the index of the update and the element he will replace $a_k$ with.

###### Output

For each update, output an integer, $\lfloor f(n) \rfloor$, on a new line.

## Examples

###### Input


```text
5 60 14 0 7 61 41 32 154 15 25 8
```
###### Output

```text

3
2
3
2
1
3

```
###### Input


```text
15 103364 1623 5435 7 6232 245 7903 3880 9738 577 4598 1868 1112 8066 19914 428414 80666 926 2452 9252 16235 1765 62323 11573 5435
```
###### Output

```text

16
17
16
17
16
17
16
17
16
17

```
###### Input


```text
2 2386056082462833225 9239510854080434211 3860560824628332251 386056082462833224
```
###### Output

```text

961223744
961223743

```
###### Input


```text
13 1031487697732100 446330174221392699 283918145228010533 619870471872432389 11918456891794188 247842810542459080 140542974216802552 698742782599365547 533363381213535498 92488084424940128 401887157851719898 128798321287952855 1373768483581840693 2839181452280105323 2839181452280105331 218372893031213 100000000000000000010 10000000000000000009 10000000000000000008 10000000000000000007 10000000000000000006 10000000000000000005 1000000000000000000
```
###### Output

```text

370643829
370643830
370643829
1000000000
1000000000
1000000000
1000000000
1000000000
1000000000
1000000000

```
## Note

In the first test case, the array after the first update is $[4, 14, 0, 7, 6]$. The values of $f$ are:

* $f(1)=2$;
* $f(2)=4$;
* $f(3)=2$;
* $f(4)=3$;
* $f(5)=3$.

Since $\lfloor f(5) \rfloor = 3$, we output $3$.

The array after the second update is $[3, 14, 0, 7, 6]$. The values of $f$, rounded to $6$ decimal places, are:

* $f(1)\approx 1.732051$;
* $f(2)\approx 3.966365$;
* $f(3)\approx 1.991573$;
* $f(4)\approx 2.998595$;
* $f(5)\approx 2.999766$.

Since $\lfloor f(5) \rfloor = 2$, we output $2$.



#### Tags 

#2700 #NOT OK #brute_force #data_structures #implementation #math 

## Blogs
- [All Contest Problems](../CodeTON_Round_8_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
