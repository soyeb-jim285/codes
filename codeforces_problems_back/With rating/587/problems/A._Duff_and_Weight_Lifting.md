<h1 style='text-align: center;'> A. Duff and Weight Lifting</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently, Duff has been practicing weight lifting. As a hard practice, Malek gave her a task. He gave her a sequence of weights. Weight of *i*-th of them is 2*w**i* pounds. In each step, Duff can lift some of the remaining weights and throw them away. She does this until there's no more weight left. Malek asked her to minimize the number of steps.

 ![](images/4002499135930d4cb8a8030e1a64f4ab3871af06.png) Duff is a competitive programming fan. That's why in each step, she can only lift and throw away a sequence of weights 2*a*1, ..., 2*a**k* if and only if there exists a non-negative integer *x* such that 2*a*1 + 2*a*2 + ... + 2*a**k* = 2*x*, i. e. the sum of those numbers is a power of two.

Duff is a competitive programming fan, but not a programmer. That's why she asked for your help. Help her minimize the number of steps. 

## Input

The first line of input contains integer *n* (1 ≤ *n* ≤ 106), the number of weights.

The second line contains *n* integers *w*1, ..., *w**n* separated by spaces (0 ≤ *w**i* ≤ 106 for each 1 ≤ *i* ≤ *n*), the powers of two forming the weights values.

## Output

Print the minimum number of steps in a single line.

## Examples

## Input


```
5  
1 1 2 3 3  

```
## Output


```
2  

```
## Input


```
4  
0 1 2 3  

```
## Output


```
4  

```
## Note

In the first sample case: One optimal way would be to throw away the first three in the first step and the rest in the second step. Also, it's not possible to do it in one step because their sum is not a power of two.

In the second sample case: The only optimal way is to throw away one weight in each step. It's not possible to do it in less than 4 steps because there's no subset of weights with more than one weight and sum equal to a power of two.



#### tags 

#1500 #greedy 