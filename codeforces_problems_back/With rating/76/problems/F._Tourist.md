<h1 style='text-align: center;'> F. Tourist</h1>

<h5 style='text-align: center;'>time limit per test: 0.5 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tourist walks along the *X* axis. He can choose either of two directions and any speed not exceeding *V*. He can also stand without moving anywhere. He knows from newspapers that at time *t*1 in the point with coordinate *x*1 an interesting event will occur, at time *t*2 in the point with coordinate *x*2 — another one, and so on up to (*x**n*, *t**n*). Interesting events are short so we can assume they are immediate. Event *i* counts visited if at time *t**i* tourist was at point with coordinate *x**i*.

Write program tourist that will find maximum number of events tourist if: 

* at the beginning (when time is equal to 0) tourist appears at point 0,
* tourist can choose initial point for himself.

Yes, you should answer on two similar but different questions.

## Input

The first line of input contains single integer number *N* (1 ≤ *N* ≤ 100000) — number of interesting events. The following *N* lines contain two integers *x**i* and *t**i* — coordinate and time of the *i*-th event. The last line of the input contains integer *V* — maximum speed of the tourist. All *x**i* will be within range  - 2·108 ≤ *x**i* ≤ 2·108, all *t**i* will be between 1 and 2·106 inclusive. *V* will be positive and will not exceed 1000. The input may contain events that happen at the same time or in the same place but not in the same place at the same time.

## Output

The only line of the output should contain two space-sepatated integers — maximum number of events tourist can visit in he starts moving from point 0 at time 0, and maximum number of events tourist can visit if he chooses the initial point for himself.

## Examples

## Input


```
3  
-1 1  
42 7  
40 8  
2  

```
## Output


```
1 2  

```


#### tags 

#2300 #binary_search #data_structures #dp 