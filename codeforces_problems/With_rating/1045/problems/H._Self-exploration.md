<h1 style='text-align: center;'> H. Self-exploration</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Being bored of exploring the Moon over and over again Wall-B decided to explore something he is made of — binary numbers. He took a binary number and decided to count how many times different substrings of length two appeared. He stored those values in $c_{00}$, $c_{01}$, $c_{10}$ and $c_{11}$, representing how many times substrings 00, 01, 10 and 11 appear in the number respectively. For example:

 $10111100 \rightarrow c_{00} = 1, \ c_{01} = 1,\ c_{10} = 2,\ c_{11} = 3$

 $10000 \rightarrow c_{00} = 3,\ c_{01} = 0,\ c_{10} = 1,\ c_{11} = 0$

 $10101001 \rightarrow c_{00} = 1,\ c_{01} = 3,\ c_{10} = 3,\ c_{11} = 0$

 $1 \rightarrow c_{00} = 0,\ c_{01} = 0,\ c_{10} = 0,\ c_{11} = 0$

Wall-B noticed that there can be multiple binary numbers satisfying the same $c_{00}$, $c_{01}$, $c_{10}$ and $c_{11}$ constraints. Because of that he wanted to count how many binary numbers satisfy the constraints $c_{xy}$ given the interval $[A, B]$. Unfortunately, his processing power wasn't strong enough to handle large intervals he was curious about. Can you help him? Since this number can be large print it modulo $10^9 + 7$.

#### Input

First two lines contain two positive binary numbers $A$ and $B$ ($1 \leq A \leq B < 2^{100\,000}$), representing the start and the end of the interval respectively. Binary numbers $A$ and $B$ have no leading zeroes.

Next four lines contain decimal numbers $c_{00}$, $c_{01}$, $c_{10}$ and $c_{11}$ ($0 \leq c_{00}, c_{01}, c_{10}, c_{11} \leq 100\,000$) representing the count of two-digit substrings 00, 01, 10 and 11 respectively. 

#### Output

#### Output

 one integer number representing how many binary numbers in the interval $[A, B]$ satisfy the constraints mod $10^9 + 7$.

## Examples

#### Input


```text
10  
1001  
0  
0  
1  
1  

```
#### Output


```text
1  

```
#### Input


```text
10  
10001  
1  
2  
3  
4  

```
#### Output


```text
0  

```
## Note

Example 1: The binary numbers in the interval $[10,1001]$ are $10,11,100,101,110,111,1000,1001$. Only number 110 satisfies the constraints: $c_{00} = 0, c_{01} = 0, c_{10} = 1, c_{11} = 1$.

Example 2: No number in the interval satisfies the constraints



#### Tags 

#2400 #NOT OK #math 

## Blogs
- [All Contest Problems](../Bubble_Cup_11_-_Finals_[Online_Mirror,_Div._1].md)
- [Announcement (en)](../blogs/Announcement_(en).md)
