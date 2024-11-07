<h1 style='text-align: center;'> L. Prime Divisors Selection</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Suppose you have a sequence of $k$ integers $A = [a_1, a_2, \dots , a_k]$ where each $a_i \geq 2$. A sequence of prime integers $P = [p_1, p_2, \dots, p_k]$ is called suitable for the sequence $A$ if $a_1$ is divisible by $p_1$, $a_2$ is divisible by $p_2$ and so on. 

A sequence of prime integers $P$ is called friendly if there are no unique integers in this sequence. 

A sequence $A$ is called ideal, if each sequence $P$ that is suitable for $A$ is friendly as well (i. e. there is no sequence $P$ that is suitable for $A$, but not friendly). For example, the sequence $[2, 4, 16]$ is ideal, while the sequence $[2, 4, 6]$ is not ideal (there exists a sequence $P = [2, 2, 3]$ which is suitable for $A$, but not friendly).

You are given $n$ different integers $x_1$, $x_2$, ..., $x_n$. You have to choose exactly $k$ of them in such a way that they form an ideal sequence, or report that it is impossible. Note that no integer can be chosen more than once.

## Input

The first line contains two integers $n$ and $k$ ($1 \leq k \leq n \leq 1000$). 

The second line contains $n$ pairwise distinct integers $x_1$, $x_2$, ..., $x_n$ ($2 \leq x_i \leq 10^{18}$).

## Output

If it is impossible to choose exactly $k$ integers from $x_1$, $x_2$, ..., $x_n$ in such a way that the chosen integers form an ideal sequence, print $0$.

Otherwise, print $k$ pairwise distinct integers — the elements of the chosen ideal sequence. If there are multiple answers, print any of them.

## Examples

## Input


```
3 3  
2 4 6  

```
## Output


```
0  

```
## Input


```
3 3  
2 4 16  

```
## Output


```
2 4 16   

```
## Input


```
4 3  
2 4 6 16  

```
## Output


```
2 4 16   

```


#### tags 

#2700 #binary_search #greedy #math #number_theory 