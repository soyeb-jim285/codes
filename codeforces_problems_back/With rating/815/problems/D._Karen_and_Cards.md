<h1 style='text-align: center;'> D. Karen and Cards</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Karen just got home from the supermarket, and is getting ready to go to sleep.

 ![](images/904951333c08dfde5489085a22d92cb6bdb101d2.png) After taking a shower and changing into her pajamas, she looked at her shelf and saw an album. Curious, she opened it and saw a trading card collection.

She recalled that she used to play with those cards as a child, and, although she is now grown-up, she still wonders a few things about it.

Each card has three characteristics: strength, defense and speed. The values of all characteristics of all cards are positive integers. The maximum possible strength any card can have is *p*, the maximum possible defense is *q* and the maximum possible speed is *r*.

There are *n* cards in her collection. The *i*-th card has a strength *a**i*, defense *b**i* and speed *c**i*, respectively.

A card beats another card if at least two of its characteristics are strictly greater than the corresponding characteristics of the other card.

She now wonders how many different cards can beat all the cards in her collection. Two cards are considered different if at least one of their characteristics have different values.

## Input

The first line of input contains four integers, *n*, *p*, *q* and *r* (1 ≤ *n*, *p*, *q*, *r* ≤ 500000), the number of cards in the collection, the maximum possible strength, the maximum possible defense, and the maximum possible speed, respectively.

The next *n* lines each contain three integers. In particular, the *i*-th line contains *a**i*, *b**i* and *c**i* (1 ≤ *a**i* ≤ *p*, 1 ≤ *b**i* ≤ *q*, 1 ≤ *c**i* ≤ *r*), the strength, defense and speed of the *i*-th collection card, respectively.

## Output

## Output

 a single integer on a line by itself, the number of different cards that can beat all the cards in her collection.

## Examples

## Input


```
3 4 4 5  
2 2 5  
1 3 4  
4 1 1  

```
## Output


```
10  

```
## Input


```
5 10 10 10  
1 1 1  
1 1 1  
1 1 1  
1 1 1  
1 1 1  

```
## Output


```
972  

```
## Note

In the first test case, the maximum possible strength is 4, the maximum possible defense is 4 and the maximum possible speed is 5. Karen has three cards:

* The first card has strength 2, defense 2 and speed 5.
* The second card has strength 1, defense 3 and speed 4.
* The third card has strength 4, defense 1 and speed 1.

There are 10 cards that beat all the cards here:

1. The card with strength 3, defense 3 and speed 5.
2. The card with strength 3, defense 4 and speed 2.
3. The card with strength 3, defense 4 and speed 3.
4. The card with strength 3, defense 4 and speed 4.
5. The card with strength 3, defense 4 and speed 5.
6. The card with strength 4, defense 3 and speed 5.
7. The card with strength 4, defense 4 and speed 2.
8. The card with strength 4, defense 4 and speed 3.
9. The card with strength 4, defense 4 and speed 4.
10. The card with strength 4, defense 4 and speed 5.

In the second test case, the maximum possible strength is 10, the maximum possible defense is 10 and the maximum possible speed is 10. Karen has five cards, all with strength 1, defense 1 and speed 1.

Any of the 972 cards which have at least two characteristics greater than 1 can beat all of the cards in her collection.



#### tags 

#2800 #binary_search #combinatorics #data_structures #geometry 