<h1 style='text-align: center;'> E. Gifts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once upon a time an old man and his wife lived by the great blue sea. One day the old man went fishing and caught a real live gold fish. The fish said: "Oh ye, old fisherman! Pray set me free to the ocean and I will grant you with *n* gifts, any gifts you wish!". Then the fish gave the old man a list of gifts and their prices. Some gifts on the list can have the same names but distinct prices. However, there can't be two gifts with the same names and the same prices. Also, there can be gifts with distinct names and the same prices. The old man can ask for *n* names of items from the list. If the fish's list has *p* occurrences of the given name, then the old man can't ask for this name of item more than *p* times.

The old man knows that if he asks for *s* gifts of the same name, the fish will randomly (i.e. uniformly amongst all possible choices) choose *s* gifts of distinct prices with such name from the list. The old man wants to please his greedy wife, so he will choose the *n* names in such a way that he can get *n* gifts with the maximum price. Besides, he isn't the brightest of fishermen, so if there are several such ways, he chooses one of them uniformly.

The old man wondered, what is the probability that he can get *n* most expensive gifts. As the old man isn't good at probability theory, he asks you to help him.

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 1000) — the number of the old man's wishes and the number of distinct names in the goldfish's list, correspondingly. Then *m* lines follow: the *i*-th line first contains integer *k**i* (*k**i* > 0) — the number of distinct prices of gifts with the *i*-th name, then *k**i* distinct space-separated integers *c**ij* (1 ≤ *c**ij* ≤ 109), the gifts' prices. 

It is guaranteed that the sum of all *k**i* doesn't exceed 1000. It is guaranteed that *n* is not greater than the total number of the gifts.

## Output

On a single line print one real number — the probability of getting *n* most valuable gifts. The answer will be considered correct if its absolute or relative error does not exceed 10- 9.

## Examples

## Input


```
3 1  
3 10 20 30  

```
## Output


```
1.000000000  

```
## Input


```
3 2  
1 40  
4 10 20 30 40  

```
## Output


```
0.166666667  

```


#### tags 

#2600 #combinatorics #dp #math #probabilities 