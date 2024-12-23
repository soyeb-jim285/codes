<h1 style='text-align: center;'> G. Flowers and Chocolate</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It's Piegirl's birthday soon, and Pieguy has decided to buy her a bouquet of flowers and a basket of chocolates.

The flower shop has *F* different types of flowers available. The *i*-th type of flower always has exactly *p**i* petals. Pieguy has decided to buy a bouquet consisting of exactly *N* flowers. He may buy the same type of flower multiple times. The *N* flowers are then arranged into a bouquet. The position of the flowers within a bouquet matters. You can think of a bouquet as an ordered list of flower types.

The chocolate shop sells chocolates in boxes. There are *B* different types of boxes available. The *i*-th type of box contains *c**i* pieces of chocolate. Pieguy can buy any number of boxes, and can buy the same type of box multiple times. He will then place these boxes into a basket. The position of the boxes within the basket matters. You can think of the basket as an ordered list of box types.

Pieguy knows that Piegirl likes to pluck a petal from a flower before eating each piece of chocolate. He would like to ensure that she eats the last piece of chocolate from the last box just after plucking the last petal from the last flower. That is, the total number of petals on all the flowers in the bouquet should equal the total number of pieces of chocolate in all the boxes in the basket.

How many different bouquet+basket combinations can Pieguy buy? The answer may be very large, so compute it modulo 1000000007 = 109 + 7.

## Input

The first line of input will contain integers *F*, *B*, and *N* (1 ≤ *F* ≤ 10, 1 ≤ *B* ≤ 100, 1 ≤ *N* ≤ 1018), the number of types of flowers, the number of types of boxes, and the number of flowers that must go into the bouquet, respectively.

The second line of input will contain *F* integers *p*1, *p*2, ..., *p**F* (1 ≤ *p**i* ≤ 109), the numbers of petals on each of the flower types.

The third line of input will contain *B* integers *c*1, *c*2, ..., *c**B* (1 ≤ *c**i* ≤ 250), the number of pieces of chocolate in each of the box types.

## Output

Print the number of bouquet+basket combinations Pieguy can buy, modulo 1000000007 = 109 + 7.

## Examples

## Input


```
2 3 3  
3 5  
10 3 7  

```
## Output


```
17  

```
## Input


```
6 5 10  
9 3 3 4 9 9  
9 9 1 6 4  

```
## Output


```
31415926  

```
## Note

In the first example, there is 1 way to make a bouquet with 9 petals (3 + 3 + 3), and 1 way to make a basket with 9 pieces of chocolate (3 + 3 + 3), for 1 possible combination. There are 3 ways to make a bouquet with 13 petals (3 + 5 + 5, 5 + 3 + 5, 5 + 5 + 3), and 5 ways to make a basket with 13 pieces of chocolate (3 + 10, 10 + 3, 3 + 3 + 7, 3 + 7 + 3, 7 + 3 + 3), for 15 more combinations. Finally there is 1 way to make a bouquet with 15 petals (5 + 5 + 5) and 1 way to make a basket with 15 pieces of chocolate (3 + 3 + 3 + 3 + 3), for 1 more combination.

## Note

 that it is possible for multiple types of flowers to have the same number of petals. Such types are still considered different. Similarly different types of boxes may contain the same number of pieces of chocolate, but are still considered different.



#### tags 

#3300 #combinatorics #math #matrices 