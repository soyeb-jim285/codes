<h1 style='text-align: center;'> E. Three Horses</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are three horses living in a horse land: one gray, one white and one gray-and-white. The horses are really amusing animals, which is why they adore special cards. Each of those cards must contain two integers, the first one on top, the second one in the bottom of the card. Let's denote a card with *a* on the top and *b* in the bottom as (*a*, *b*).

Each of the three horses can paint the special cards. If you show an (*a*, *b*) card to the gray horse, then the horse can paint a new (*a* + 1, *b* + 1) card. If you show an (*a*, *b*) card, such that *a* and *b* are even integers, to the white horse, then the horse can paint a new ![](images/192ec3678af0f5ba2aacda0740464256169e6b63.png) card. If you show two cards (*a*, *b*) and (*b*, *c*) to the gray-and-white horse, then he can paint a new (*a*, *c*) card.

Polycarpus really wants to get *n* special cards (1, *a*1), (1, *a*2), ..., (1, *a**n*). For that he is going to the horse land. He can take exactly one (*x*, *y*) card to the horse land, such that 1 ≤ *x* < *y* ≤ *m*. How many ways are there to choose the card so that he can perform some actions in the horse land and get the required cards?

Polycarpus can get cards from the horses only as a result of the actions that are described above. Polycarpus is allowed to get additional cards besides the cards that he requires.

## Input

The first line contains two integers *n*, *m* (1 ≤ *n* ≤ 105, 2 ≤ *m* ≤ 109). The second line contains the sequence of integers *a*1, *a*2, ..., *a**n* (2 ≤ *a**i* ≤ 109). Note, that the numbers in the sequence can coincide.

The numbers in the lines are separated by single spaces.

## Output

Print a single integer — the answer to the problem. 

Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
1 6  
2  

```
## Output


```
11  

```
## Input


```
1 6  
7  

```
## Output


```
14  

```
## Input


```
2 10  
13 7  

```
## Output


```
36  

```


#### tags 

#2200 #constructive_algorithms #math #number_theory 