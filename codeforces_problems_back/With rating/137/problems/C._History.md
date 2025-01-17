<h1 style='text-align: center;'> C. History</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarpus likes studying at school a lot and he is always diligent about his homework. Polycarpus has never had any problems with natural sciences as his great-great-grandfather was the great physicist Seinstein. On the other hand though, Polycarpus has never had an easy time with history.

Everybody knows that the World history encompasses exactly *n* events: the *i*-th event had continued from the year *a**i* to the year *b**i* inclusive (*a**i* < *b**i*). Polycarpus easily learned the dates when each of *n* events started and ended (Polycarpus inherited excellent memory from his great-great-granddad). But the teacher gave him a more complicated task: Polycaprus should know when all events began and ended and he should also find out for each event whether it includes another event. Polycarpus' teacher thinks that an event *j* includes an event *i* if *a**j* < *a**i* and *b**i* < *b**j*. Your task is simpler: find the number of events that are included in some other event.

## Input

The first input line contains integer *n* (1 ≤ *n* ≤ 105) which represents the number of events. Next *n* lines contain descriptions of the historical events, one event per line. The *i* + 1 line contains two integers *a**i* and *b**i* (1 ≤ *a**i* < *b**i* ≤ 109) — the beginning and the end of the *i*-th event. No two events start or finish in the same year, that is, *a**i* ≠ *a**j*, *a**i* ≠ *b**j*, *b**i* ≠ *a**j*, *b**i* ≠ *b**j* for all *i*, *j* (where *i* ≠ *j*). Events are given in arbitrary order.

## Output

Print the only integer — the answer to the problem.

## Examples

## Input


```
5  
1 10  
2 9  
3 8  
4 7  
5 6  

```
## Output


```
4  

```
## Input


```
5  
1 100  
2 50  
51 99  
52 98  
10 60  

```
## Output


```
4  

```
## Input


```
1  
1 1000000000  

```
## Output


```
0  

```
## Note

In the first example the fifth event is contained in the fourth. Similarly, the fourth event is contained in the third, the third — in the second and the second — in the first.

In the second example all events except the first one are contained in the first.

In the third example only one event, so the answer is 0.



#### tags 

#1500 #sortings 