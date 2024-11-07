<h1 style='text-align: center;'> D. Dividing Kingdom II</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Long time ago, there was a great kingdom and it was being ruled by The Great Arya and Pari The Great. These two had some problems about the numbers they like, so they decided to divide the great kingdom between themselves.

The great kingdom consisted of *n* cities numbered from 1 to *n* and *m* bidirectional roads between these cities, numbered from 1 to *m*. The *i*-th road had length equal to *w**i*. The Great Arya and Pari The Great were discussing about destructing some prefix (all road with numbers less than some *x*) and suffix (all roads with numbers greater than some *x*) of the roads so there will remain only the roads with numbers *l*, *l* + 1, ..., *r* - 1 and *r*.

After that they will divide the great kingdom into two pieces (with each city belonging to exactly one piece) such that the hardness of the division is minimized. The hardness of a division is the maximum length of a road such that its both endpoints are in the same piece of the kingdom. In case there is no such road, the hardness of the division is considered to be equal to  - 1.

Historians found the map of the great kingdom, and they have *q* guesses about the *l* and *r* chosen by those great rulers. Given these data, for each guess *l**i* and *r**i* print the minimum possible hardness of the division of the kingdom.

## Input

The first line of the input contains three integers *n*, *m* and *q* (1 ≤ *n*, *q* ≤ 1000, ![](images/35f3aad2494424c9e12bd0da665aab328b1f30a9.png)) — the number of cities and roads in the great kingdom, and the number of guesses, respectively.

The *i*-th line of the following *m* lines contains three integers *u**i*, *v**i* and *w**i* (1  ≤  *u**i*,  *v**i*  ≤  *n*, 0 ≤ *w**i* ≤ 109), denoting the road number *i* connects cities *u**i* and *v**i* and its length is equal *w**i*. It's guaranteed that no road connects the city to itself and no pair of cities is connected by more than one road.

Each of the next *q* lines contains a pair of integers *l**i* and *r**i* (1  ≤ *l**i* ≤ *r**i* ≤ *m*) — a guess from the historians about the remaining roads in the kingdom.

## Output

For each guess print the minimum possible hardness of the division in described scenario.

## Example

## Input


```
5 6 5  
5 4 86  
5 1 0  
1 3 38  
2 1 33  
2 4 28  
2 3 40  
3 5  
2 6  
1 3  
2 3  
1 6  

```
## Output


```
-1  
33  
-1  
-1  
33  

```


#### tags 

#2500 #brute_force #data_structures #dsu #graphs #sortings 