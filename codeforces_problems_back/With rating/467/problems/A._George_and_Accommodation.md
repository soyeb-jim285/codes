<h1 style='text-align: center;'> A. George and Accommodation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

George has recently entered the BSUCP (Berland State University for Cool Programmers). George has a friend Alex who has also entered the university. Now they are moving into a dormitory. 

George and Alex want to live in the same room. The dormitory has *n* rooms in total. At the moment the *i*-th room has *p**i* people living in it and the room can accommodate *q**i* people in total (*p**i* ≤ *q**i*). Your task is to count how many rooms has free place for both George and Alex.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 100) — the number of rooms.

The *i*-th of the next *n* lines contains two integers *p**i* and *q**i* (0 ≤ *p**i* ≤ *q**i* ≤ 100) — the number of people who already live in the *i*-th room and the room's capacity.

## Output

Print a single integer — the number of rooms where George and Alex can move in.

## Examples

## Input


```
3  
1 1  
2 2  
3 3  

```
## Output


```
0  

```
## Input


```
3  
1 10  
0 10  
10 10  

```
## Output


```
2  

```


#### tags 

#800 #implementation 