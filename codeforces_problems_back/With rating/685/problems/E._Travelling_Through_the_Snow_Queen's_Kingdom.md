<h1 style='text-align: center;'> E. Travelling Through the Snow Queen's Kingdom</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gerda is travelling to the palace of the Snow Queen.

The road network consists of *n* intersections and *m* bidirectional roads. Roads are numbered from 1 to *m*. Snow Queen put a powerful spell on the roads to change the weather conditions there. Now, if Gerda steps on the road *i* at the moment of time less or equal to *i*, she will leave the road exactly at the moment *i*. In case she steps on the road *i* at the moment of time greater than *i*, she stays there forever.

Gerda starts at the moment of time *l* at the intersection number *s* and goes to the palace of the Snow Queen, located at the intersection number *t*. Moreover, she has to be there at the moment *r* (or earlier), before the arrival of the Queen.

Given the description of the road network, determine for *q* queries *l**i*, *r**i*, *s**i* and *t**i* if it's possible for Gerda to get to the palace on time.

## Input

The first line of the input contains integers *n*, *m* and *q* (2 ≤ *n* ≤ 1000, 1 ≤ *m*, *q* ≤ 200 000) — the number of intersections in the road network of Snow Queen's Kingdom, the number of roads and the number of queries you have to answer.

The *i*-th of the following *m* lines contains the description of the road number *i*. The description consists of two integers *v**i* and *u**i* (1 ≤ *v**i*, *u**i* ≤ *n*, *v**i* ≠ *u**i*) — the indices of the intersections connected by the *i*-th road. It's possible to get both from *v**i* to *u**i* and from *u**i* to *v**i* using only this road. Each pair of intersection may appear several times, meaning there are several roads connecting this pair.

Last *q* lines contain the queries descriptions. Each of them consists of four integers *l**i*, *r**i*, *s**i* and *t**i* (1 ≤ *l**i* ≤ *r**i* ≤ *m*, 1 ≤ *s**i*, *t**i* ≤ *n*, *s**i* ≠ *t**i*) — the moment of time Gerda starts her journey, the last moment of time she is allowed to arrive to the palace, the index of the starting intersection and the index of the intersection where palace is located.

## Output

For each query print "Yes" (without quotes) if Gerda can be at the Snow Queen palace on time (not later than *r**i*) or "No" (without quotes) otherwise.

## Example

## Input


```
5 4 6  
1 2  
2 3  
3 4  
3 5  
1 3 1 4  
1 3 2 4  
1 4 4 5  
1 4 4 1  
2 3 1 4  
2 2 2 3  

```
## Output


```
Yes  
Yes  
Yes  
No  
No  
Yes  

```


#### tags 

#2800 #bitmasks #brute_force #divide_and_conquer #graphs 