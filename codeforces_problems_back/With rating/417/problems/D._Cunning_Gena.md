<h1 style='text-align: center;'> D. Cunning Gena</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A boy named Gena really wants to get to the "Russian Code Cup" finals, or at least get a t-shirt. But the offered problems are too complex, so he made an arrangement with his *n* friends that they will solve the problems for him.

The participants are offered *m* problems on the contest. For each friend, Gena knows what problems he can solve. But Gena's friends won't agree to help Gena for nothing: the *i*-th friend asks Gena *x**i* rubles for his help in solving all the problems he can. Also, the friend agreed to write a code for Gena only if Gena's computer is connected to at least *k**i* monitors, each monitor costs *b* rubles.

Gena is careful with money, so he wants to spend as little money as possible to solve all the problems. Help Gena, tell him how to spend the smallest possible amount of money. Initially, there's no monitors connected to Gena's computer.

## Input

The first line contains three integers *n*, *m* and *b* (1 ≤ *n* ≤ 100; 1 ≤ *m* ≤ 20; 1 ≤ *b* ≤ 109) — the number of Gena's friends, the number of problems and the cost of a single monitor.

The following 2*n* lines describe the friends. Lines number 2*i* and (2*i* + 1) contain the information about the *i*-th friend. The 2*i*-th line contains three integers *x**i*, *k**i* and *m**i* (1 ≤ *x**i* ≤ 109; 1 ≤ *k**i* ≤ 109; 1 ≤ *m**i* ≤ *m*) — the desired amount of money, monitors and the number of problems the friend can solve. The (2*i* + 1)-th line contains *m**i* distinct positive integers — the numbers of problems that the *i*-th friend can solve. The problems are numbered from 1 to *m*.

## Output

Print the minimum amount of money Gena needs to spend to solve all the problems. Or print -1, if this cannot be achieved.

## Examples

## Input


```
2 2 1  
100 1 1  
2  
100 2 1  
1  

```
## Output


```
202  

```
## Input


```
3 2 5  
100 1 1  
1  
100 1 1  
2  
200 1 2  
1 2  

```
## Output


```
205  

```
## Input


```
1 2 1  
1 1 1  
1  

```
## Output


```
-1  

```


#### tags 

#1900 #bitmasks #dp #greedy #sortings 