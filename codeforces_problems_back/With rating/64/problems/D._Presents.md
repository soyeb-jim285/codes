<h1 style='text-align: center;'> D. Presents</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

You are given the prices of three presents. Also there are three sisters. It is known that the most valuable present is for the eldest sister. The second (by price) is for the second sister. And the less valuable present is for the youngest sister. If two (or three) presents have the same price, corresponding sisters may get the in a random way.

## Input

The only line contains three integer numbers *a*1, *a*2, *a*3 (1 ≤ *a*1, *a*2, *a*3 ≤ 100) — the prices of the presents.

## Output

Print three numbers *i*1, *i*2, *i*3 (1 ≤ *i*1, *i*2, *i*3 ≤ 3), all of them should be distinct. The first number stands for the seniority of the sister which will get the first present (1 stands for the eldest, 3 for the youngest). The second and third numbers mean the seniority of the sisters which get the second and the third present respectively.

If there are multiple answers, print any of them.

## Examples

## Input


```
11 13 1  

```
## Output


```
2 1 3 
```
## Input


```
30 10 30  

```
## Output


```
1 3 2 
```
## Note

In the second sample another possible answer is "2 3 1".



#### tags 

#1800 #*special #greedy 