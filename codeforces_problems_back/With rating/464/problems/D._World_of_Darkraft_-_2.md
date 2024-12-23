<h1 style='text-align: center;'> D. World of Darkraft - 2</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Roma found a new character in the game "World of Darkraft - 2". In this game the character fights monsters, finds the more and more advanced stuff that lets him fight stronger monsters.

The character can equip himself with *k* distinct types of items. Power of each item depends on its level (positive integer number). Initially the character has one 1-level item of each of the *k* types.

After the victory over the monster the character finds exactly one new randomly generated item. The generation process looks as follows. Firstly the type of the item is defined; each of the *k* types has the same probability. Then the level of the new item is defined. Let's assume that the level of player's item of the chosen type is equal to *t* at the moment. Level of the new item will be chosen uniformly among integers from segment [1; *t* + 1].

From the new item and the current player's item of the same type Roma chooses the best one (i.e. the one with greater level) and equips it (if both of them has the same level Roma choses any). The remaining item is sold for coins. Roma sells an item of level *x* of any type for *x* coins.

Help Roma determine the expected number of earned coins after the victory over *n* monsters.

## Input

The first line contains two integers, *n* and *k* (1 ≤ *n* ≤ 105; 1 ≤ *k* ≤ 100).

## Output

Print a real number — expected number of earned coins after victory over *n* monsters. The answer is considered correct if its relative or absolute error doesn't exceed 10- 9.

## Examples

## Input


```
1 3  

```
## Output


```
1.0000000000  

```
## Input


```
2 1  

```
## Output


```
2.3333333333  

```
## Input


```
10 2  

```
## Output


```
15.9380768924  

```


#### tags 

#2700 #dp #probabilities 