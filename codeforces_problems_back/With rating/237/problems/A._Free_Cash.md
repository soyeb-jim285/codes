<h1 style='text-align: center;'> A. Free Cash</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valera runs a 24/7 fast food cafe. He magically learned that next day *n* people will visit his cafe. For each person we know the arrival time: the *i*-th person comes exactly at *h**i* hours *m**i* minutes. The cafe spends less than a minute to serve each client, but if a client comes in and sees that there is no free cash, than he doesn't want to wait and leaves the cafe immediately. 

Valera is very greedy, so he wants to serve all *n* customers next day (and get more profit). However, for that he needs to ensure that at each moment of time the number of working cashes is no less than the number of clients in the cafe. 

Help Valera count the minimum number of cashes to work at his cafe next day, so that they can serve all visitors.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 105), that is the number of cafe visitors.

Each of the following *n* lines has two space-separated integers *h**i* and *m**i* (0 ≤ *h**i* ≤ 23; 0 ≤ *m**i* ≤ 59), representing the time when the *i*-th person comes into the cafe. 

## Note

 that the time is given in the chronological order. All time is given within one 24-hour period.

## Output

Print a single integer — the minimum number of cashes, needed to serve all clients next day.

## Examples

## Input


```
4  
8 0  
8 10  
8 10  
8 45  

```
## Output


```
2  

```
## Input


```
3  
0 12  
10 11  
22 22  

```
## Output


```
1  

```
## Note

In the first sample it is not enough one cash to serve all clients, because two visitors will come into cafe in 8:10. Therefore, if there will be one cash in cafe, then one customer will be served by it, and another one will not wait and will go away.

In the second sample all visitors will come in different times, so it will be enough one cash.



#### tags 

#1000 #implementation 