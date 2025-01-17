<h1 style='text-align: center;'> E. Kojiro and Furrari</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Motorist Kojiro spent 10 years saving up for his favorite car brand, Furrari. Finally Kojiro's dream came true! Kojiro now wants to get to his girlfriend Johanna to show off his car to her.

Kojiro wants to get to his girlfriend, so he will go to her along a coordinate line. For simplicity, we can assume that Kojiro is at the point *f* of a coordinate line, and Johanna is at point *e*. Some points of the coordinate line have gas stations. Every gas station fills with only one type of fuel: Regular-92, Premium-95 or Super-98. Thus, each gas station is characterized by a pair of integers *t**i* and *x**i* — the number of the gas type and its position.

One liter of fuel is enough to drive for exactly 1 km (this value does not depend on the type of fuel). Fuels of three types differ only in quality, according to the research, that affects the lifetime of the vehicle motor. A Furrari tank holds exactly *s* liters of fuel (regardless of the type of fuel). At the moment of departure from point *f* Kojiro's tank is completely filled with fuel Super-98. At each gas station Kojiro can fill the tank with any amount of fuel, but of course, at no point in time, the amount of fuel in the tank can be more than *s* liters. Note that the tank can simultaneously have different types of fuel. The car can moves both left and right.

To extend the lifetime of the engine Kojiro seeks primarily to minimize the amount of fuel of type Regular-92. If there are several strategies to go from *f* to *e*, using the minimum amount of fuel of type Regular-92, it is necessary to travel so as to minimize the amount of used fuel of type Premium-95.

Write a program that can for the *m* possible positions of the start *f**i* minimize firstly, the amount of used fuel of type Regular-92 and secondly, the amount of used fuel of type Premium-95.

## Input

The first line of the input contains four positive integers *e*, *s*, *n*, *m* (1 ≤ *e*, *s* ≤ 109, 1 ≤ *n*, *m* ≤ 2·105) — the coordinate of the point where Johanna is, the capacity of a Furrari tank, the number of gas stations and the number of starting points. 

Next *n* lines contain two integers each *t**i*, *x**i* (1 ≤ *t**i* ≤ 3,  - 109 ≤ *x**i* ≤ 109), representing the type of the *i*-th gas station (1 represents Regular-92, 2 — Premium-95 and 3 — Super-98) and the position on a coordinate line of the *i*-th gas station. Gas stations don't necessarily follow in order from left to right.

The last line contains *m* integers *f**i* ( - 109 ≤ *f**i* < *e*). Start positions don't necessarily follow in order from left to right.

No point of the coordinate line contains more than one gas station. It is possible that some of points *f**i* or point *e* coincide with a gas station.

## Output

Print exactly *m* lines. The *i*-th of them should contain two integers — the minimum amount of gas of type Regular-92 and type Premium-95, if Kojiro starts at point *f**i*. First you need to minimize the first value. If there are multiple ways to do it, you need to also minimize the second value.

If there is no way to get to Johanna from point *f**i*, the *i*-th line should look like that "-1 -1" (two numbers minus one without the quotes).

## Examples

## Input


```
8 4 1 1  
2 4  
0  

```
## Output


```
0 4  

```
## Input


```
9 3 2 3  
2 3  
1 6  
-1 0 1  

```
## Output


```
-1 -1  
3 3  
3 2  

```
## Input


```
20 9 2 4  
1 5  
2 10  
-1 0 1 2  

```
## Output


```
-1 -1  
-1 -1  
-1 -1  
-1 -1  

```


#### tags 

#2800 #dp #greedy 