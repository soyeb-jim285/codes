<h1 style='text-align: center;'> B. Balancer</h1>

<h5 style='text-align: center;'>time limit per test: 0.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya has *k* matches, placed in *n* matchboxes lying in a line from left to right. We know that *k* is divisible by *n*. Petya wants all boxes to have the same number of matches inside. For that, he can move a match from its box to the adjacent one in one move. How many such moves does he need to achieve the desired configuration?

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 50000). The second line contains *n* non-negative numbers that do not exceed 109, the *i*-th written number is the number of matches in the *i*-th matchbox. It is guaranteed that the total number of matches is divisible by *n*.

## Output

Print the total minimum number of moves.

## Examples

## Input


```
6  
1 6 2 5 3 7  

```
## Output


```
12  

```


#### tags 

#1600 #greedy #implementation 