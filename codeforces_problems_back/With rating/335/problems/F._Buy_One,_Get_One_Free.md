<h1 style='text-align: center;'> F. Buy One, Get One Free</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A nearby pie shop is having a special sale. For each pie you pay full price for, you may select one pie of a strictly lesser value to get for free. Given the prices of all the pies you wish to acquire, determine the minimum total amount you must pay for all of the pies.

## Input

## Input

 will begin with an integer *n* (1 ≤ *n* ≤ 500000), the number of pies you wish to acquire. Following this is a line with *n* integers, each indicating the cost of a pie. All costs are positive integers not exceeding 109.

## Output

Print the minimum cost to acquire all the pies.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
6  
3 4 5 3 4 5  

```
## Output


```
14  

```
## Input


```
5  
5 5 5 5 5  

```
## Output


```
25  

```
## Input


```
4  
309999 6000 2080 2080  

```
## Output


```
314159  

```
## Note

In the first test case you can pay for a pie with cost 5 and get a pie with cost 4 for free, then pay for a pie with cost 5 and get a pie with cost 3 for free, then pay for a pie with cost 4 and get a pie with cost 3 for free.

In the second test case you have to pay full price for every pie.



#### tags 

#3000 #dp #greedy 