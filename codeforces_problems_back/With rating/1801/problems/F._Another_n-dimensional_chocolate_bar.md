<h1 style='text-align: center;'> F. Another n-dimensional chocolate bar</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

 Mom bought the boy Vasya a $n$-dimensional chocolate bar, which is a $n$-dimensional cube with the length of each side equal to $1$. The chocolate is planned to be divided into slices. According to the $i$th dimension, it can be divided by hyperplanes into $a_i$ equal parts. Thus, the chocolate is divided in total into $a_1 \cdot a_2 \cdot a_3 \cdot \ldots \cdot a_n$ slices, each slice has a length of $i$-th dimension equal to $\frac{1}{a_i}$, respectively, the volume of each slice is $\frac{1}{a_1 a_2 \cdots a_n}$.Vasya and his friends want to cut a chocolate bar to get at least $k$ pieces, while Vasya wants to maximize the volume of the smallest of them. It is possible to cut the chocolate bar only at the junction of the lobules, and each incision must pass through the entire chocolate bar along some hyperplane involved in the formation of lobules. Only after making all the cuts, Vasya disassembles the chocolate into pieces.

More formally, Vasya wants to choose the numbers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le a_i$) — the number of parts into which Vasya will cut the chocolate bar along each dimension. The condition $b_1 \cdot b_2 \cdot \ldots \cdot b_n \ge k$ must be met to get at least $k$ pieces after all cuts. It can be noted that with optimal cutting with such parameters, the minimum piece will contain $\lfloor \frac{a_1}{b_1} \rfloor \dotsm \lfloor \frac{a_n}{b_n} \rfloor$ slices, and its volume will be equal to $\lfloor \frac{a_1}{b_1} \rfloor \dotsm \lfloor \frac{a_n}{b_n} \rfloor \cdot \frac{1}{a_1 a_2 \cdots a_n}$.

Vasya wants to get the maximum possible value of the volume of the minimum piece multiplied by $k$, that is, he wants to maximize the number of $\lfloor \frac{a_1}{b_1} \rfloor \dotsm \lfloor \frac{a_n}{b_n} \rfloor \cdot \frac{1}{a_1 a_2 \cdots a_n} \cdot k$. Help him with this. 

## Input

The first line contains two integers $n$ and $k$ $(1 \le n \le 100$, $1 \le k \le 10^7)$ — the dimension of the chocolate bar, and how many parts it needs to be divided into.

The second line contains $n$ integers $a_1,\ a_2,\ \dots,\ a_n$ $(1 \le a_i \le 10^7)$ — the number of pieces on which the chocolate is placed along each of the dimensions. 

## Output

Print one number  — the maximum possible volume of the smallest of the obtained pieces, multiplied by $k$, with an absolute or relative error of no more than $10^{-9}$.

If it is impossible to cut a chocolate bar into at least $k$ pieces under the given restrictions, output $0$. 

## Examples

 

## Input


```

1 2
5

```
## Output


```

0.8

```
## Input


```

2 6
5 10

```
## Output


```

0.72

```
## Input


```

2 7
4 4

```
## Output


```

0.875

```
## Input


```

2 3
4 5

```
## Output


```

0.75

```
## Input


```

4 444
57 179 239 2

```
## Output


```

0.97557326850704739751

```
## Input


```

2 5
2 2

```
## Output


```

0

```
 ## Note

In the first example, a one – dimensional chocolate bar can be divided as follows: 

![](images/a8d5d5d8f92d22c9db6bdb2bcf1f8cdee04c19f7.png)

Then the answer will be $\frac{2}{5} \cdot 2 = 0.8$

In the second example, the chocolate bar can be cut as follows:

![](images/75b3a21fab988c9d50869caa331ad2121036557c.png)

Then the answer will be $\frac{2}{5} \cdot \frac{3}{10} \cdot 6 = 0.72$

In the third example, the chocolate bar can be cut as follows:

![](images/392b48439bd086aedb63319e32cde4182b9da9bf.png) Then the answer will be $\frac{2}{4} \cdot \frac{1}{4} \cdot 7 = 0.875$ 



#### tags 

#2700 #dp #math #meet-in-the-middle #number_theory 