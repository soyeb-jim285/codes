<h1 style='text-align: center;'> B. Weakened Common Divisor</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

During the research on properties of the greatest common divisor (GCD) of a set of numbers, Ildar, a famous mathematician, introduced a brand new concept of the weakened common divisor (WCD) of a list of pairs of integers.

For a given list of pairs of integers $(a_1, b_1)$, $(a_2, b_2)$, ..., $(a_n, b_n)$ their WCD is arbitrary integer greater than $1$, such that it divides at least one element in each pair. WCD may not exist for some lists.

For example, if the list looks like $[(12, 15), (25, 18), (10, 24)]$, then their WCD can be equal to $2$, $3$, $5$ or $6$ (each of these numbers is strictly greater than $1$ and divides at least one number in each pair).

You're currently pursuing your PhD degree under Ildar's mentorship, and that's why this problem was delegated to you. Your task is to calculate WCD efficiently.

##### Input

The first line contains a single integer $n$ ($1 \le n \le 150\,000$) — the number of pairs.

Each of the next $n$ lines contains two integer values $a_i$, $b_i$ ($2 \le a_i, b_i \le 2 \cdot 10^9$).

##### Output

Print a single integer — the WCD of the set of pairs. 

If there are multiple possible answers, output any; if there is no answer, print $-1$.

## Examples

##### Input


```text
3  
17 18  
15 24  
12 15  

```
##### Output


```text
6
```
##### Input


```text
2  
10 16  
7 17  

```
##### Output


```text
-1  

```
##### Input


```text
5  
90 108  
45 105  
75 40  
165 175  
33 30  

```
##### Output


```text
5  

```
## Note

In the first example the answer is $6$ since it divides $18$ from the first pair, $24$ from the second and $12$ from the third ones. 
## Note

 that other valid answers will also be accepted.

In the second example there are no integers greater than $1$ satisfying the conditions.

In the third example one of the possible answers is $5$. 
## Note

 that, for example, $15$ is also allowed, but it's not necessary to maximize the output.



#### Tags 

#1600 #NOT OK #brute_force #greedy #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_505_(rated,_Div._1_+_Div._2,_based_on_VK_Cup_2018_Final).md)
- [A (en)](../blogs/A_(en).md)
- [Tutorial](../blogs/Tutorial.md)
