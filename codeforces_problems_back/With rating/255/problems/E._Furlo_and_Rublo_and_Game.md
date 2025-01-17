<h1 style='text-align: center;'> E. Furlo and Rublo and Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Furlo and Rublo play a game. The table has *n* piles of coins lying on it, the *i*-th pile has *a**i* coins. Furlo and Rublo move in turns, Furlo moves first. In one move you are allowed to:

* choose some pile, let's denote the current number of coins in it as *x*;
* choose some integer *y* (0 ≤ *y* < *x*; *x*1 / 4 ≤ *y* ≤ *x*1 / 2) and decrease the number of coins in this pile to *y*. In other words, after the described move the pile will have *y* coins left.

The player who can't make a move, loses. 

Your task is to find out, who wins in the given game if both Furlo and Rublo play optimally well.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 77777) — the number of piles. The next line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 777777777777) — the sizes of piles. The numbers are separated by single spaces.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Output

If both players play optimally well and Furlo wins, print "Furlo", otherwise print "Rublo". Print the answers without the quotes.

## Examples

## Input


```
1  
1  

```
## Output


```
Rublo  

```
## Input


```
2  
1 2  

```
## Output


```
Rublo  

```
## Input


```
10  
1 2 3 4 5 6 7 8 9 10  

```
## Output


```
Furlo  

```


#### tags 

#2200 #games #implementation #math 