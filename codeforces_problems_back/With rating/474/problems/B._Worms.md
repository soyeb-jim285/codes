<h1 style='text-align: center;'> B. Worms</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It is lunch time for Mole. His friend, Marmot, prepared him a nice game for lunch.

Marmot brought Mole *n* ordered piles of worms such that *i*-th pile contains *a**i* worms. He labeled all these worms with consecutive integers: worms in first pile are labeled with numbers 1 to *a*1, worms in second pile are labeled with numbers *a*1 + 1 to *a*1 + *a*2 and so on. See the example for a better understanding.

Mole can't eat all the worms (Marmot brought a lot) and, as we all know, Mole is blind, so Marmot tells him the labels of the best juicy worms. Marmot will only give Mole a worm if Mole says correctly in which pile this worm is contained.

Poor Mole asks for your help. For all juicy worms said by Marmot, tell Mole the correct answers.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 105), the number of piles.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 103, *a*1 + *a*2 + ... + *a**n* ≤ 106), where *a**i* is the number of worms in the *i*-th pile.

The third line contains single integer *m* (1 ≤ *m* ≤ 105), the number of juicy worms said by Marmot.

The fourth line contains *m* integers *q*1, *q*2, ..., *q**m* (1 ≤ *q**i* ≤ *a*1 + *a*2 + ... + *a**n*), the labels of the juicy worms.

## Output

Print *m* lines to the standard output. The *i*-th line should contain an integer, representing the number of the pile where the worm labeled with the number *q**i* is.

## Examples

## Input


```
5  
2 7 3 4 9  
3  
1 25 11  

```
## Output


```
1  
5  
3  

```
## Note

For the sample input:

* The worms with labels from [1, 2] are in the first pile.
* The worms with labels from [3, 9] are in the second pile.
* The worms with labels from [10, 12] are in the third pile.
* The worms with labels from [13, 16] are in the fourth pile.
* The worms with labels from [17, 25] are in the fifth pile.


#### tags 

#1200 #binary_search #implementation 