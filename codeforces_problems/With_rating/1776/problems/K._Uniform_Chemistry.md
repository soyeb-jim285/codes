<h1 style='text-align: center;'> K. Uniform Chemistry</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a parallel universe there are $n$ chemical elements, numbered from $1$ to $n$. The element number $n$ has not been discovered so far, and its discovery would be a pinnacle of research and would bring the person who does it eternal fame and the so-called SWERC prize.

There are $m$ independent researchers, numbered from $1$ to $m$, that are trying to discover it. Currently, the $i$-th researcher has a sample of the element $s_i$. Every year, each researcher independently does one fusion experiment. In a fusion experiment, if the researcher currently has a sample of element $a$, they produce a sample of an element $b$ that is chosen uniformly at random between $a+1$ and $n$, and they lose the sample of element $a$. The elements discovered by different researchers or in different years are completely independent.

The first researcher to discover element $n$ will get the SWERC prize. If several researchers discover the element in the same year, they all get the prize. For each $i = 1, \, 2, \, \dots, \, m$, you need to compute the probability that the $i$-th researcher wins the prize.

###### Input

The first line contains two integers $n$ and $m$ ($2 \le n \le 10^{18}$, $1 \le m \le 100$) — the number of elements and the number of researchers.

The second line contains $m$ integers $s_1, \, s_2, \, \dots, \, s_m$ ($1 \le s_i < n$) — the elements that the researchers currently have.

###### Output

Print $m$ floating-point numbers. The $i$-th number should be the probability that the $i$-th researcher wins the SWERC prize. Your answer is accepted if each number differs from the correct number by at most $10^{-8}$.

## Examples

###### Input


```text
2 3
1 1 1
```
###### Output


```text
1.0 1.0 1.0
```
###### Input


```text
3 3
1 1 2
```
###### Output


```text
0.5 0.5 1.0
```
###### Input


```text
3 3
1 1 1
```
###### Output


```text
0.625 0.625 0.625
```
###### Input


```text
100 7
1 2 4 8 16 32 64
```
###### Output


```text
0.178593469 0.179810455 0.182306771
0.187565366 0.199300430 0.229356322
0.348722518
```
## Note

In the first sample, all researchers will discover element $2$ in the first year and win the SWERC prize.

In the second sample, the last researcher will definitely discover element $3$ in the first year and win the SWERC prize. The first two researchers have a $50\%$ chance of discovering element $2$ and a $50\%$ chance of discovering element $3$, and only element $3$ will bring them the prize.

In the third sample, each researcher has an independent $50\%$ chance of discovering element $3$ in the first year, in which case they definitely win the SWERC prize. Additionally, if they all discover element $2$ in the first year, which is a $12.5\%$ chance, then they will all discover element $3$ in the second year and all win the prize.



#### Tags 

#3200 #NOT OK #dp #math 

## Blogs
- [All Contest Problems](../SWERC_2022-2023_-_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
