<h1 style='text-align: center;'> B. Sail</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The polar bears are going fishing. They plan to sail from (*s**x*, *s**y*) to (*e**x*, *e**y*). However, the boat can only sail by wind. At each second, the wind blows in one of these directions: east, south, west or north. Assume the boat is currently at (*x*, *y*).

* If the wind blows to the east, the boat will move to (*x* + 1, *y*).
* If the wind blows to the south, the boat will move to (*x*, *y* - 1).
* If the wind blows to the west, the boat will move to (*x* - 1, *y*).
* If the wind blows to the north, the boat will move to (*x*, *y* + 1).

Alternatively, they can hold the boat by the anchor. In this case, the boat stays at (*x*, *y*). Given the wind direction for *t* seconds, what is the earliest time they sail to (*e**x*, *e**y*)?

## Input

The first line contains five integers *t*, *s**x*, *s**y*, *e**x*, *e**y* (1 ≤ *t* ≤ 105,  - 109 ≤ *s**x*, *s**y*, *e**x*, *e**y* ≤ 109). The starting location and the ending location will be different.

The second line contains *t* characters, the *i*-th character is the wind blowing direction at the *i*-th second. It will be one of the four possibilities: "E" (east), "S" (south), "W" (west) and "N" (north).

## Output

If they can reach (*e**x*, *e**y*) within *t* seconds, print the earliest time they can achieve it. Otherwise, print "-1" (without quotes).

## Examples

## Input


```
5 0 0 1 1  
SESNW  

```
## Output


```
4  

```
## Input


```
10 5 3 3 6  
NENSWESNEE  

```
## Output


```
-1  

```
## Note

In the first sample, they can stay at seconds 1, 3, and move at seconds 2, 4.

In the second sample, they cannot sail to the destination.



#### tags 

#1200 #brute_force #greedy #implementation 