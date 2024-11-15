<h1 style='text-align: center;'> E. Buses and People</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The main Bertown street is represented by a straight line. There are 109 bus stops located on the line. The stops are numbered with integers from 1 to 109 in the order in which they follow on the road. The city has *n* buses. Every day the *i*-th bus drives from stop number *s**i* to stop number *f**i* (*s**i* < *f**i*), it stops on all intermediate stops and returns only at night. The bus starts driving at time *t**i* and drives so fast that it finishes driving also at time *t**i*. The time *t**i* is different for all buses. The buses have infinite capacity.

Bertown has *m* citizens. Today the *i*-th person should get from stop number *l**i* to stop number *r**i* (*l**i* < *r**i*); the *i*-th citizen comes to his initial stop (*l**i*) at time *b**i*. Each person, on the one hand, wants to get to the destination point as quickly as possible, and on the other hand, definitely does not want to change the buses as he rides. More formally: the *i*-th person chooses bus *j*, with minimum time *t**j*, such that *s**j* ≤ *l**i*, *r**i* ≤ *f**j* and *b**i* ≤ *t**j*. 

Your task is to determine for each citizen whether he can ride to the destination point today and if he can, find the number of the bus on which the citizen will ride.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — the number of buses and the number of people. 

Then *n* lines follow, each of them contains three integers: *s**i*, *f**i*, *t**i* (1 ≤ *s**i*, *f**i*, *t**i* ≤ 109, *s**i* < *f**i*) — the description of the buses. It is guaranteed that all *t**i*-s are different.

Then *m* lines follow, each of them contains three integers: *l**i*, *r**i*, *b**i* (1 ≤ *l**i*, *r**i*, *b**i* ≤ 109, *l**i* < *r**i*) — the Bertown citizens' description. Some *b**i*-s could coincide.

## Output

In the first line print *m* space-separated integers: the *i*-th number should be equal either to -1, if the person number *i* can't get to the destination point, or to the number of the bus that will ride the person number *i*. The buses are numbered with integers from 1 to *n* in the input order.

## Examples

## Input


```
4 3  
1 10 10  
5 6 2  
6 7 3  
5 7 4  
5 7 1  
1 2 1  
1 10 11  

```
## Output


```
4 1 -1  

```
## Input


```
1 1  
1 1000000000 1000000000  
1 1000000000 1000000000  

```
## Output


```
1  

```


#### tags 

#2400 #binary_search #data_structures #sortings 