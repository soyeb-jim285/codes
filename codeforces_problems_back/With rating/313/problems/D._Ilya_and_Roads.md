<h1 style='text-align: center;'> D. Ilya and Roads</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Everything is great about Ilya's city, except the roads. The thing is, the only ZooVille road is represented as *n* holes in a row. We will consider the holes numbered from 1 to *n*, from left to right.

Ilya is really keep on helping his city. So, he wants to fix at least *k* holes (perharps he can fix more) on a single ZooVille road. 

The city has *m* building companies, the *i*-th company needs *c**i* money units to fix a road segment containing holes with numbers of at least *l**i* and at most *r**i*. The companies in ZooVille are very greedy, so, if they fix a segment containing some already fixed holes, they do not decrease the price for fixing the segment. 

Determine the minimum money Ilya will need to fix at least *k* holes.

## Input

The first line contains three integers *n*, *m*, *k* (1 ≤ *n* ≤ 300, 1 ≤ *m* ≤ 105, 1 ≤ *k* ≤ *n*). The next *m* lines contain the companies' description. The *i*-th line contains three integers *l**i*, *r**i*, *c**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*, 1 ≤ *c**i* ≤ 109).

## Output

Print a single integer — the minimum money Ilya needs to fix at least *k* holes. 

If it is impossible to fix at least *k* holes, print -1.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
10 4 6  
7 9 11  
6 9 13  
7 7 7  
3 5 6  

```
## Output


```
17  

```
## Input


```
10 7 1  
3 4 15  
8 9 8  
5 6 8  
9 10 6  
1 4 2  
1 4 10  
8 10 13  

```
## Output


```
2  

```
## Input


```
10 1 9  
5 10 14  

```
## Output


```
-1  

```


#### tags 

#2100 #dp 