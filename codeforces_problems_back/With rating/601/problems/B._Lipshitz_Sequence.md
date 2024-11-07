<h1 style='text-align: center;'> B. Lipshitz Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A function ![](images/2f07df5c4af1af0378cc7859607253a89e341f3b.png) is called Lipschitz continuous if there is a real constant *K* such that the inequality |*f*(*x*) - *f*(*y*)| ≤ *K*·|*x* - *y*| holds for all ![](images/38cf78ee7e5e196f47739d8e2f90ad8196eef553.png). We'll deal with a more... discrete version of this term.

For an array ![](images/ff64cafd17d3b049f6048c69500dfcb615d3f375.png), we define it's Lipschitz constant ![](images/539010632b4d4ca811bfa977e7820e3abe5f2fae.png) as follows:

* if *n* < 2, ![](images/4408c649f3ff72675e50b77c47abde2338612a63.png)
* if *n* ≥ 2, ![](images/96a21f7d56a33aed6c08988a969895ed2788f932.png) over all 1 ≤ *i* < *j* ≤ *n*

In other words, ![](images/dc5c983dd5ec31fcb548359077409fdc9f959ad1.png) is the smallest non-negative integer such that |*h*[*i*] - *h*[*j*]| ≤ *L*·|*i* - *j*| holds for all 1 ≤ *i*, *j* ≤ *n*.

You are given an array ![](images/515376bdf4e0cb52e5c7435e579cb212490e9db2.png) of size *n* and *q* queries of the form [*l*, *r*]. For each query, consider the subarray ![](images/c884fec5726a1dc470ccf9dcdbdb93e48641ba63.png); determine the sum of Lipschitz constants of all subarrays of ![](images/63c2fec5ac52e647308cdc25e4089eaabd2d4bea.png).

## Input

The first line of the input contains two space-separated integers *n* and *q* (2 ≤ *n* ≤ 100 000 and 1 ≤ *q* ≤ 100) — the number of elements in array ![](images/515376bdf4e0cb52e5c7435e579cb212490e9db2.png) and the number of queries respectively.

The second line contains *n* space-separated integers ![](images/870bb36b2ac35fdc7e1ba3db60a75eaf804c5d2d.png) (![](images/25f4eda9373a97ed7c6fd3cfd5fe1e70baccdf01.png)).

The following *q* lines describe queries. The *i*-th of those lines contains two space-separated integers *l**i* and *r**i* (1 ≤ *l**i* < *r**i* ≤ *n*).

## Output

Print the answers to all queries in the order in which they are given in the input. For the *i*-th query, print one line containing a single integer — the sum of Lipschitz constants of all subarrays of ![](images/7436332d0ff76523fd4bdfcfd4cbc42df6b75dac.png).

## Examples

## Input


```
10 4  
1 5 2 9 1 3 4 2 1 7  
2 4  
3 8  
7 10  
1 9  

```
## Output


```
17  
82  
23  
210  

```
## Input


```
7 6  
5 7 7 4 6 6 2  
1 2  
2 3  
2 6  
1 7  
4 7  
3 5  

```
## Output


```
2  
0  
22  
59  
16  
8  

```
## Note

In the first query of the first sample, the Lipschitz constants of subarrays of ![](images/ddadffaf9e222576b1abb771dcd83dbad588d7fe.png) with length at least 2 are:

* ![](images/887651f76ac57b8f2b2dbd46c6ac2335ac2a270a.png)
* ![](images/e9eed4a49028e9bd234162d9da74fd4f86481378.png)
* ![](images/16eff35d7bd22d3e34c55fc95cc6c59212d5b1c8.png)

The answer to the query is their sum.



#### tags 

#2100 #data_structures #math 