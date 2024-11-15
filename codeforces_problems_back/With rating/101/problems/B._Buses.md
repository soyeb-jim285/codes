<h1 style='text-align: center;'> B. Buses</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 265 megabytes</h5>

Little boy Gerald studies at school which is quite far from his house. That's why he has to go there by bus every day. The way from home to school is represented by a segment of a straight line; the segment contains exactly *n* + 1 bus stops. All of them are numbered with integers from 0 to *n* in the order in which they follow from Gerald's home. The bus stop by Gerald's home has number 0 and the bus stop by the school has number *n*.

There are *m* buses running between the house and the school: the *i*-th bus goes from stop *s**i* to *t**i* (*s**i* < *t**i*), visiting all the intermediate stops in the order in which they follow on the segment. Besides, Gerald's no idiot and he wouldn't get off the bus until it is still possible to ride on it closer to the school (obviously, getting off would be completely pointless). In other words, Gerald can get on the *i*-th bus on any stop numbered from *s**i* to *t**i* - 1 inclusive, but he can get off the *i*-th bus only on the bus stop *t**i*.

Gerald can't walk between the bus stops and he also can't move in the direction from the school to the house.

Gerald wants to know how many ways he has to get from home to school. Tell him this number. Two ways are considered different if Gerald crosses some segment between the stops on different buses. As the number of ways can be too much, find the remainder of a division of this number by 1000000007 (109 + 7).

## Input

The first line contains two space-separated integers: *n* and *m* (1 ≤ *n* ≤ 109, 0 ≤ *m* ≤ 105). Then follow *m* lines each containing two integers *s**i*, *t**i*. They are the numbers of starting stops and end stops of the buses (0 ≤ *s**i* < *t**i* ≤ *n*).

## Output

Print the only number — the number of ways to get to the school modulo 1000000007 (109 + 7).

## Examples

## Input


```
2 2  
0 1  
1 2  

```
## Output


```
1  

```
## Input


```
3 2  
0 1  
1 2  

```
## Output


```
0  

```
## Input


```
5 5  
0 1  
0 2  
0 3  
0 4  
0 5  

```
## Output


```
16  

```
## Note

The first test has the only variant to get to school: first on bus number one to the bus stop number one; then on bus number two to the bus stop number two.

In the second test no bus goes to the third bus stop, where the school is positioned. Thus, the correct answer is 0.

In the third test Gerald can either get or not on any of the first four buses to get closer to the school. Thus, the correct answer is 24 = 16.



#### tags 

#1700 #binary_search #data_structures #dp 