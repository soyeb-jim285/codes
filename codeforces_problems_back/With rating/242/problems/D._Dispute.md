<h1 style='text-align: center;'> D. Dispute</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valera has *n* counters numbered from 1 to *n*. Some of them are connected by wires, and each of the counters has a special button.

Initially, all the counters contain number 0. When you press a button on a certain counter, the value it has increases by one. Also, the values recorded in all the counters, directly connected to it by a wire, increase by one.

Valera and Ignat started having a dispute, the dispute is as follows. Ignat thought of a sequence of *n* integers *a*1, *a*2, ..., *a**n*. Valera should choose some set of distinct counters and press buttons on each of them exactly once (on other counters the buttons won't be pressed). If after that there is a counter with the number *i*, which has value *a**i*, then Valera loses the dispute, otherwise he wins the dispute.

Help Valera to determine on which counters he needs to press a button to win the dispute.

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 105), that denote the number of counters Valera has and the number of pairs of counters connected by wires.

Each of the following *m* lines contains two space-separated integers *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*, *u**i* ≠ *v**i*), that mean that counters with numbers *u**i* and *v**i* are connected by a wire. It is guaranteed that each pair of connected counters occurs exactly once in the input.

The last line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 105), where *a**i* is the value that Ignat choose for the *i*-th counter.

## Output

If Valera can't win the dispute print in the first line -1.

Otherwise, print in the first line integer *k* (0 ≤ *k* ≤ *n*). In the second line print *k* distinct space-separated integers — the numbers of the counters, where Valera should push buttons to win the dispute, in arbitrary order.

If there exists multiple answers, you are allowed to print any of them.

## Examples

## Input


```
5 5  
2 3  
4 1  
1 5  
5 3  
2 1  
1 1 2 0 2  

```
## Output


```
2  
1 2  

```
## Input


```
4 2  
1 2  
3 4  
0 0 0 0  

```
## Output


```
3  
1 3 4  

```


#### tags 

#2100 #dfs_and_similar #graphs #greedy 