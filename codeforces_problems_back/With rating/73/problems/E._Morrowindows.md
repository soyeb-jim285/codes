<h1 style='text-align: center;'> E. Morrowindows</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya plays The Elder Trolls III: Morrowindows. He has a huge list of items in the inventory, however, there is no limits on the size of things. Vasya does not know the total amount of items but he is sure that are not more than *x* and not less than 2 items in his inventory. A new patch for the game appeared to view inventory in *n* different modes. Displaying in mode *i* is a partition of all inventory items on pages, each of which (except for maybe the last one) shows exactly *a**i* items. In addition, each mode shows how many pages *b**i* is in a complete list. Great! Perhaps this information will be enough for Vasya to find the required number. Moreover, it is very interesting, what is the fewest number of modes in which Vasya can see inventory to determine the number of items in it?

Vasya cannot use the information that was received while looking on inventory in some mode for selection of next actions. I. e. Vasya chooses some set of modes first, and then sees all the results and determines the size.

Knowing the number of *a**i*, *x* and assuming that Vasya is very smart, check whether he can uniquely determine the number of items in his inventory, and how many modes he will need to do that if he knows numbers *a**i*, *x* and he is able to know number *b**i* after viewing items in mode *i*.

## Input

The first line contains two integers *n* and *x* (0 ≤ *n* ≤ 105, 2 ≤ *x* ≤ 109). The second line contains integers *a**i* (1 ≤ *a**i* ≤ 109). Some numbers among all *a**i* may be equal.

## Output

## Output

 the fewest amount of modes required to uniquely determine amount of items in the inventory. If there is no solution output  - 1.

## Examples

## Input


```
2 4  
2 3  

```
## Output


```
2  

```
## Input


```
1 4  
2  

```
## Output


```
-1  

```
## Note

In the second example Vasya is not able to determine items count uniquely because 3 items, as well as 4 items, can be displayed on two pages.



#### tags 

#2400 #math #number_theory 