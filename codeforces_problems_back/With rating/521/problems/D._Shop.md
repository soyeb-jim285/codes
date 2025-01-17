<h1 style='text-align: center;'> D. Shop</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya plays one very well-known and extremely popular MMORPG game. His game character has *k* skill; currently the *i*-th of them equals to *a**i*. Also this game has a common rating table in which the participants are ranked according to the product of all the skills of a hero in the descending order.

Vasya decided to 'upgrade' his character via the game store. This store offers *n* possible ways to improve the hero's skills; Each of these ways belongs to one of three types:

1. assign the *i*-th skill to *b*;
2. add *b* to the *i*-th skill;
3. multiply the *i*-th skill by *b*.

Unfortunately, a) every improvement can only be used once; b) the money on Vasya's card is enough only to purchase not more than *m* of the *n* improvements. Help Vasya to reach the highest ranking in the game. To do this tell Vasya which of improvements he has to purchase and in what order he should use them to make his rating become as high as possible. If there are several ways to achieve it, print any of them.

## Input

The first line contains three numbers — *k*, *n*, *m* (1 ≤ *k* ≤ 105, 0 ≤ *m* ≤ *n* ≤ 105) — the number of skills, the number of improvements on sale and the number of them Vasya can afford.

The second line contains *k* space-separated numbers *a**i* (1 ≤ *a**i* ≤ 106), the initial values of skills.

Next *n* lines contain 3 space-separated numbers *t**j*, *i**j*, *b**j* (1 ≤ *t**j* ≤ 3, 1 ≤ *i**j* ≤ *k*, 1 ≤ *b**j* ≤ 106) — the type of the *j*-th improvement (1 for assigning, 2 for adding, 3 for multiplying), the skill to which it can be applied and the value of *b* for this improvement.

## Output

The first line should contain a number *l* (0 ≤ *l* ≤ *m*) — the number of improvements you should use.

The second line should contain *l* distinct space-separated numbers *v**i* (1 ≤ *v**i* ≤ *n*) — the indices of improvements in the order in which they should be applied. The improvements are numbered starting from 1, in the order in which they appear in the input. 

## Examples

## Input


```
2 4 3  
13 20  
1 1 14  
1 2 30  
2 1 6  
3 2 2  

```
## Output


```
3  
2 3 4  

```


#### tags 

#2800 #greedy 