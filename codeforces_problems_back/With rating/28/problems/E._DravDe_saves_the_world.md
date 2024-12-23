<h1 style='text-align: center;'> E. DravDe saves the world</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

How horrible! The empire of galactic chickens tries to conquer a beautiful city "Z", they have built a huge incubator that produces millions of chicken soldiers a day, and fenced it around. The huge incubator looks like a polygon on the plane *Oxy* with *n* vertices. Naturally, DravDe can't keep still, he wants to destroy the chicken empire. For sure, he will start with the incubator.

DravDe is strictly outside the incubator's territory in point *A*(*x**a*, *y**a*), and wants to get inside and kill all the chickens working there. But it takes a lot of doing! The problem is that recently DravDe went roller skating and has broken both his legs. He will get to the incubator's territory in his jet airplane LEVAP-41.

LEVAP-41 flies at speed *V*(*x**v*, *y**v*, *z**v*). DravDe can get on the plane in point *A*, fly for some time, and then air drop himself. DravDe is very heavy, that's why he falls vertically at speed *F**down*, but in each point of his free fall DravDe can open his parachute, and from that moment he starts to fall at the wind speed *U*(*x**u*, *y**u*, *z**u*) until he lands. Unfortunately, DravDe isn't good at mathematics. Would you help poor world's saviour find such an air dropping plan, that allows him to land on the incubator's territory? If the answer is not unique, DravDe wants to find the plan with the minimum time of his flight on the plane. If the answers are still multiple, he wants to find the one with the minimum time of his free fall before opening his parachute

## Input

The first line contains the number *n* (3 ≤ *n* ≤ 104) — the amount of vertices of the fence. Then there follow *n* lines containing the coordinates of these vertices (two integer numbers *x**i*, *y**i*) in clockwise or counter-clockwise order. It's guaranteed, that the fence does not contain self-intersections.

The following four lines contain coordinates of point *A*(*x**a*, *y**a*), speeds *V*(*x**v*, *y**v*, *z**v*), *F**down* and speed *U*(*x**u*, *y**u*, *z**u*). All the input numbers are integer. All the coordinates don't exceed 104 in absolute value. It's guaranteed, that *z**v* > 0 and *F**down*, *z**u* < 0, and point *A* is strictly outside the incubator's territory.

## Output

In the first line output two numbers *t*1, *t*2 such, that if DravDe air drops at time *t*1 (counting from the beginning of the flight), he lands on the incubator's territory (landing on the border is regarder as landing on the territory). If DravDe doesn't open his parachute, the second number should be equal to the duration of DravDe's falling down. If it's impossible for DravDe to get to the incubator's territory, output -1 -1. If the answer is not unique, output the answer with the minimum *t*1. If the answers are still multiple, output the answer with the minimum *t*2. Your answer must have an absolute or relative error less than 10- 6.

## Examples

## Input


```
4  
0 0  
1 0  
1 1  
0 1  
0 -1  
1 0 1  
-1  
0 1 -1  

```
## Output


```
1.00000000 0.00000000  

```
## Input


```
4  
0 0  
0 1  
1 1  
1 0  
0 -1  
-1 -1 1  
-1  
0 1 -1  

```
## Output


```
-1.00000000 -1.00000000  

```
## Input


```
4  
0 0  
1 0  
1 1  
0 1  
0 -1  
1 1 1  
-1  
1 1 -1  

```
## Output


```
0.50000000 0.00000000  

```


#### tags 

#2800 #geometry #math 