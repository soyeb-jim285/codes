<h1 style='text-align: center;'> G. The Sum of Good Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call a positive integer good if there is no digit 0 in its decimal representation.

For an array of a good numbers $a$, one found out that the sum of some two neighboring elements is equal to $x$ (i.e. $x = a_i + a_{i + 1}$ for some $i$). $x$ had turned out to be a good number as well.

Then the elements of the array $a$ were written out one after another without separators into one string $s$. For example, if $a = [12, 5, 6, 133]$, then $s = 1256133$.

You are given a string $s$ and a number $x$. Your task is to determine the positions in the string that correspond to the adjacent elements of the array that have sum $x$. If there are several possible answers, you can print any of them.

###### Input

The first line contains the string $s$ ($2 \le |s| \le 5 \cdot 10^5$).

The second line contains an integer $x$ ($2 \le x < 10^{200000}$).

An additional constraint on the input: the answer always exists, i.e you can always select two adjacent substrings of the string $s$ so that if you convert these substrings to integers, their sum is equal to $x$.

###### Output

In the first line, print two integers $l_1$, $r_1$, meaning that the first term of the sum ($a_i$) is in the string $s$ from position $l_1$ to position $r_1$.

In the second line, print two integers $l_2$, $r_2$, meaning that the second term of the sum ($a_{i + 1}$) is in the string $s$ from position $l_2$ to position $r_2$.

## Examples

###### Input


```text
1256133
17
```
###### Output


```text
1 2
3 3
```
###### Input


```text
9544715561
525
```
###### Output


```text
2 3
4 6
```
###### Input


```text
239923
5
```
###### Output


```text
1 1
2 2
```
###### Input


```text
1218633757639
976272
```
###### Output


```text
2 7
8 13
```
## Note

In the first example $s[1;2] = 12$ and $s[3;3] = 5$, $12+5=17$.

In the second example $s[2;3] = 54$ and $s[4;6] = 471$, $54+471=525$.

In the third example $s[1;1] = 2$ and $s[2;2] = 3$, $2+3=5$.

In the fourth example $s[2;7] = 218633$ and $s[8;13] = 757639$, $218633+757639=976272$.



#### Tags 

#3200 #NOT OK #hashing #math #string_suffix_structures #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_115_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
