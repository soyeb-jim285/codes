<h1 style='text-align: center;'> A. The Very Beautiful Blanket</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kirill wants to weave the very beautiful blanket consisting of $n \times m$ of the same size square patches of some colors. He matched some non-negative integer to each color. Thus, in our problem, the blanket can be considered a $B$ matrix of size $n \times m$ consisting of non-negative integers.

Kirill considers that the blanket is very beautiful, if for each submatrix $A$ of size $4 \times 4$ of the matrix $B$ is true:

* $A_{11} \oplus A_{12} \oplus A_{21} \oplus A_{22} = A_{33} \oplus A_{34} \oplus A_{43} \oplus A_{44},$
* $A_{13} \oplus A_{14} \oplus A_{23} \oplus A_{24} = A_{31} \oplus A_{32} \oplus A_{41} \oplus A_{42},$

where $\oplus$ means [bitwise exclusive OR](https://en.wikipedia.org/wiki/Exclusive_or)

Kirill asks you to help her weave a very beautiful blanket, and as colorful as possible!

He gives you two integers $n$ and $m$. 

Your task is to generate a matrix $B$ of size $n \times m$, which corresponds to a very beautiful blanket and in which the number of different numbers maximized.

## Input

The first line of input data contains one integer number $t$ ($1 \le t \le 1000$) — the number of test cases.

The single line of each test case contains two integers $n$ and $m$ $(4 \le n, \, m \le 200)$ — the size of matrix $B$.

It is guaranteed that the sum of $n \cdot m$ does not exceed $2 \cdot 10^5$.

## Output

For each test case, in first line output one integer $cnt$ $(1 \le cnt \le n \cdot m)$ — the maximum number of different numbers in the matrix.

Then output the matrix $B$ $(0 \le B_{ij} < 2^{63})$ of size $n \times m$. If there are several correct matrices, it is allowed to output any one.

It can be shown that if there exists a matrix with an optimal number of distinct numbers, then there exists among suitable matrices such a $B$ that $(0 \le B_{ij} < 2^{63})$.

## Example

## Input


```

45 54 44 66 6
```
## Output


```

25
9740 1549 9744 1553 9748
1550 1551 1554 1555 1558
10252 2061 10256 2065 10260
2062 2063 2066 2067 2070
10764 2573 10768 2577 10772
16
3108 3109 3112 3113
3110 3111 3114 3115
3620 3621 3624 3625
3622 3623 3626 3627
24
548 549 552 553 556 557
550 551 554 555 558 559
1060 1061 1064 1065 1068 1069
1062 1063 1066 1067 1070 1071
36
25800 25801 25804 25805 25808 25809
25802 4294993099 25806 4294993103 25810 4294993107
26312 26313 26316 26317 26320 26321
26314 4294993611 26318 4294993615 26322 4294993619
26824 26825 26828 26829 26832 26833
26826 4294994123 26830 4294994127 26834 4294994131

```
## Note

In the first test case, there is only 4 submatrix of size $4 \times 4$. Consider a submatrix whose upper-left corner coincides with the upper-left corner of the matrix $B$:

$ \left[ {\begin{array}{cccc} 9740 & 1549 & 9744 & 1553 \\\ 1550 & 1551 & 1554 & 1555 \\\ 10252 & 2061 & 10256 & 2065 \\\ 2062 & 2063 & 2066 & 2067 \\\ \end{array} } \right] $

$9740 \oplus 1549 \oplus 1550 \oplus 1551$ $=$ $10256 \oplus 2065 \oplus 2066 \oplus 2067$ $=$ $8192$;

$10252 \oplus 2061 \oplus 2062 \oplus 2063$ $=$ $9744 \oplus 1553 \oplus 1554 \oplus 1555$ $=$ $8192$.

So, chosen submatrix fits the condition. Similarly, you can make sure that the other three submatrices also fit the condition.



#### tags 

#1600 #bitmasks #constructive_algorithms 