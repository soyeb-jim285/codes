<h1 style='text-align: center;'> C. Mushroom Gnomes - 2</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day Natalia was walking in the woods when she met a little mushroom gnome. The gnome told her the following story:

Everybody knows that the mushroom gnomes' power lies in the magic mushrooms that grow in the native woods of the gnomes. There are *n* trees and *m* magic mushrooms in the woods: the *i*-th tree grows at a point on a straight line with coordinates *a**i* and has the height of *h**i*, the *j*-th mushroom grows at the point with coordinates *b**j* and has magical powers *z**j*.

But one day wild mushroommunchers, the sworn enemies of mushroom gnomes unleashed a terrible storm on their home forest. As a result, some of the trees began to fall and crush the magic mushrooms. The supreme oracle of mushroom gnomes calculated in advance the probability for each tree that it will fall to the left, to the right or will stand on. If the tree with the coordinate *x* and height *h* falls to the left, then all the mushrooms that belong to the right-open interval [*x* - *h*, *x*), are destroyed. If a tree falls to the right, then the mushrooms that belong to the left-open interval (*x*, *x* + *h*] are destroyed. Only those mushrooms that are not hit by a single tree survive.

Knowing that all the trees fall independently of each other (i.e., all the events are mutually independent, and besides, the trees do not interfere with other trees falling in an arbitrary direction), the supreme oracle was also able to quickly calculate what would be the expectation of the total power of the mushrooms which survived after the storm. His calculations ultimately saved the mushroom gnomes from imminent death.

Natalia, as a good Olympiad programmer, got interested in this story, and she decided to come up with a way to quickly calculate the expectation of the sum of the surviving mushrooms' power.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 105, 1 ≤ *m* ≤ 104) — the number of trees and mushrooms, respectively.

Each of the next *n* lines contain four integers — *a**i*, *h**i*, *l**i*, *r**i* (|*a**i*| ≤ 109, 1 ≤ *h**i* ≤ 109, 0 ≤ *l**i*, *r**i*, *l**i* + *r**i* ≤ 100) which represent the coordinate of the *i*-th tree, its height, the percentage of the probabilities that the tree falls to the left and to the right, respectively (the remaining percentage is the probability that the tree will stand on).

Each of next *m* lines contain two integers *b**j*, *z**j* (|*b**j*| ≤ 109, 1 ≤ *z**j* ≤ 103) which represent the coordinate and the magical power of the *j*-th mushroom, respectively.

An arbitrary number of trees and mushrooms can grow in one point.

## Output

Print a real number — the expectation of the total magical power of the surviving mushrooms. The result is accepted with relative or absolute accuracy 10- 4.

## Examples

## Input


```
1 1  
2 2 50 50  
1 1  

```
## Output


```
0.5000000000  

```
## Input


```
2 1  
2 2 50 50  
4 2 50 50  
3 1  

```
## Output


```
0.2500000000  

```
## Note

It is believed that the mushroom with the coordinate *x* belongs to the right-open interval [*l*, *r*) if and only if *l* ≤ *x* < *r*. Similarly, the mushroom with the coordinate *x* belongs to the left-open interval (*l*, *r*] if and only if *l* < *x* ≤ *r*.

In the first test the mushroom survives with the probability of 50%, depending on where the single tree falls.

In the second test the mushroom survives only if neither of the two trees falls on it. It occurs with the probability of 50%  ×  50% = 25%.

Pretest №12 is the large test with 105 trees and one mushroom.



#### tags 

#2200 #binary_search #data_structures #probabilities #sortings 