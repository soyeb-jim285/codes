<h1 style='text-align: center;'> E. Well played!</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently Max has got himself into popular CCG "BrainStone". As "BrainStone" is a pretty intellectual game, Max has to solve numerous hard problems during the gameplay. Here is one of them:

Max owns *n* creatures, *i*-th of them can be described with two numbers — its health *hp**i* and its damage *dmg**i*. Max also has two types of spells in stock:

1. Doubles health of the creature (*hp**i* := *hp**i*·2);
2. Assigns value of health of the creature to its damage (*dmg**i* := *hp**i*).

Spell of first type can be used no more than *a* times in total, of the second type — no more than *b* times in total. Spell can be used on a certain creature multiple times. Spells can be used in arbitrary order. It isn't necessary to use all the spells.

Max is really busy preparing for his final exams, so he asks you to determine what is the maximal total damage of all creatures he can achieve if he uses spells in most optimal way.

#### Input

The first line contains three integers *n*, *a*, *b* (1 ≤ *n* ≤ 2·105, 0 ≤ *a* ≤ 20, 0 ≤ *b* ≤ 2·105) — the number of creatures, spells of the first type and spells of the second type, respectively.

The *i*-th of the next *n* lines contain two number *hp**i* and *dmg**i* (1 ≤ *hp**i*, *dmg**i* ≤ 109) — description of the *i*-th creature.

#### Output

Print single integer — maximum total damage creatures can deal.

## Examples

#### Input


```text
2 1 1  
10 15  
6 1  

```
#### Output


```text
27  

```
#### Input


```text
3 0 3  
10 8  
7 11  
5 2  

```
#### Output


```text
26  

```
## Note

In the first example Max should use the spell of the first type on the second creature, then the spell of the second type on the same creature. Then total damage will be equal to 15 + 6·2 = 27.

In the second example Max should use the spell of the second type on the first creature, then the spell of the second type on the third creature. Total damage will be equal to 10 + 11 + 5 = 26.



#### Tags 

#2100 #NOT OK #greedy #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_43_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
