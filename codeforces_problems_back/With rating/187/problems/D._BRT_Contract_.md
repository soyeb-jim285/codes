<h1 style='text-align: center;'> D. BRT Contract </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the last war of PMP, he defeated all his opponents and advanced to the final round. But after the end of semi-final round evil attacked him from behind and killed him! God bless him. 

Before his death, PMP signed a contract with the bus rapid transit (BRT) that improves public transportations by optimizing time of travel estimation. You should help PMP finish his last contract.

Each BRT line is straight line that passes *n* intersecting on its ways. At each intersection there is traffic light that periodically cycles between green and red. It starts illuminating green at time zero. During the green phase which lasts for *g* seconds, traffic is allowed to proceed. After the green phase the light changes to red and remains in this color for *r* seconds. During the red phase traffic is prohibited from proceeding. If a vehicle reaches the intersection exactly at a time when the light changes to red, it should stop, but the vehicle is clear to proceed if the light has just changed to green.

 ![](images/79dff3220a4c52ca0f70759fae993e4f08d17dc3.png) All traffic lights have the same timing and are synchronized. In other words the period of red (and green) phase is the same for all of traffic lights and they all start illuminating green at time zero.

The BRT Company has calculated the time that a bus requires to pass each road segment. A road segment is the distance between two consecutive traffic lights or between a traffic light and source (or destination) station. More precisely BRT specialists provide *n* + 1 positive integers *l**i*, the time in seconds that a bus needs to traverse *i*-th road segment in the path from source to destination. The *l*1 value denotes the time that a bus needs to pass the distance between source and the first intersection. The *l**n* + 1 value denotes the time between the last intersection and destination.

In one day *q* buses leave the source station. The *i*-th bus starts from source at time *t**i* (in seconds). Decision makers of BRT Company want to know what time a bus gets to destination?

The bus is considered as point. A bus will always move if it can. The buses do not interfere with each other. 

## Input

The first line of input contains three space-separated positive integers *n*, *g*, *r* (1 ≤ *n* ≤ 105, 2 ≤ *g* + *r* ≤ 109) — the number of intersections, duration of green phase and duration of red phase. Next line contains *n* + 1 integers *l**i* (1 ≤ *l**i* ≤ 109) — the time to pass the *i*-th road segment in the path from source to destination. 

Next line contains a single integer *q* (1 ≤ *q* ≤ 105) — the number of buses in a day. The *i*-th of next *q* lines contains a single integer *t**i* (1 ≤ *t**i* ≤ 109) — the time when *i*-th bus leaves the source station.

## Output

In the *i*-th line of output you should print a single integer — the time that *i*-th bus gets to destination.

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d specifier.

## Examples

## Input


```
1 3 2  
5 2  
5  
1  
2  
3  
4  
5  

```
## Output


```
8  
9  
12  
12  
12  

```
## Input


```
5 3 7  
10 1 1 8 900000005 1000000000  
3  
1  
10  
1000000000  

```
## Output


```
1900000040  
1900000040  
2900000030  

```
## Note

In the first sample, buses #1, #2 and #5 will reach the destination without waiting behind the red light. But buses #3 and #4 should wait.

In the second sample, first bus should wait at third, fourth and fifth intersections. Second and third buses should wait only at the fifth intersection.



#### tags 

#2800 #data_structures 