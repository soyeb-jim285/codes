<h1 style='text-align: center;'> A. Fight the Monster</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A monster is attacking the Cyberland!

Master Yang, a braver, is going to beat the monster. Yang and the monster each have 3 attributes: hitpoints (*HP*), offensive power (*ATK*) and defensive power (*DEF*).

During the battle, every second the monster's HP decrease by *max*(0, *ATK**Y* - *DEF**M*), while Yang's HP decreases by *max*(0, *ATK**M* - *DEF**Y*), where index *Y* denotes Master Yang and index *M* denotes monster. Both decreases happen simultaneously Once monster's *HP* ≤ 0 and the same time Master Yang's *HP* > 0, Master Yang wins.

Master Yang can buy attributes from the magic shop of Cyberland: *h* bitcoins per *HP*, *a* bitcoins per *ATK*, and *d* bitcoins per *DEF*.

Now Master Yang wants to know the minimum number of bitcoins he can spend in order to win.

## Input

The first line contains three integers *HP**Y*, *ATK**Y*, *DEF**Y*, separated by a space, denoting the initial *HP*, *ATK* and *DEF* of Master Yang.

The second line contains three integers *HP**M*, *ATK**M*, *DEF**M*, separated by a space, denoting the *HP*, *ATK* and *DEF* of the monster.

The third line contains three integers *h*, *a*, *d*, separated by a space, denoting the price of 1 *HP*, 1 *ATK* and 1 *DEF*.

All numbers in input are integer and lie between 1 and 100 inclusively.

## Output

The only output line should contain an integer, denoting the minimum bitcoins Master Yang should spend in order to win.

## Examples

## Input


```
1 2 1  
1 100 1  
1 100 100  

```
## Output


```
99  

```
## Input


```
100 100 100  
1 1 1  
1 1 1  

```
## Output


```
0  

```
## Note

For the first sample, prices for *ATK* and *DEF* are extremely high. Master Yang can buy 99 HP, then he can beat the monster with 1 HP left.

For the second sample, Master Yang is strong enough to beat the monster, so he doesn't need to buy anything.



#### tags 

#1800 #binary_search #brute_force #implementation 