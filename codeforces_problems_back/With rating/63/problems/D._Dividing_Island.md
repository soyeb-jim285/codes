<h1 style='text-align: center;'> D. Dividing Island</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A revolution took place on the Buka Island. New government replaced the old one. The new government includes *n* parties and each of them is entitled to some part of the island according to their contribution to the revolution. However, they can't divide the island.

The island can be conventionally represented as two rectangles *a* × *b* and *c* × *d* unit squares in size correspondingly. The rectangles are located close to each other. At that, one of the sides with the length of *a* and one of the sides with the length of *c* lie on one line. You can see this in more details on the picture.

 ![](images/c919851573257c51c49fd0bc2857509b3d8bc159.png) The *i*-th party is entitled to a part of the island equal to *x**i* unit squares. Every such part should fully cover several squares of the island (it is not allowed to cover the squares partially) and be a connected figure. A "connected figure" presupposes that from any square of this party one can move to any other square of the same party moving through edge-adjacent squares also belonging to that party.

Your task is to divide the island between parties.

## Input

The first line contains 5 space-separated integers — *a*, *b*, *c*, *d* and *n* (1 ≤ *a*, *b*, *c*, *d* ≤ 50, *b* ≠ *d*, 1 ≤ *n* ≤ 26). The second line contains *n* space-separated numbers. The *i*-th of them is equal to number *x**i* (1 ≤ *x**i* ≤ *a* × *b* + *c* × *d*). It is guaranteed that ![](images/35d7a672005b7ad5e3d4935e2cb8334465a0bee4.png).

## Output

If dividing the island between parties in the required manner is impossible, print "NO" (without the quotes). Otherwise, print "YES" (also without the quotes) and, starting from the next line, print *max*(*b*, *d*) lines each containing *a* + *c* characters. To mark what square should belong to what party, use lowercase Latin letters. For the party that is first in order in the input data, use "a", for the second one use "b" and so on. Use "." for the squares that belong to the sea. The first symbol of the second line of the output data should correspond to the square that belongs to the rectangle *a* × *b*. The last symbol of the second line should correspond to the square that belongs to the rectangle *c* × *d*.

If there are several solutions output any.

## Examples

## Input


```
3 4 2 2 3  
5 8 3  

```
## Output


```
YES  
aaabb  
aabbb  
cbb..  
ccb..  

```
## Input


```
3 2 1 4 4  
1 2 3 4  

```
## Output


```
YES  
abbd  
cccd  
...d  
...d  

```


#### tags 

#1900 #constructive_algorithms 