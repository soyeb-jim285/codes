<h1 style='text-align: center;'> D. Magic Breeding</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Nikita and Sasha play a computer game where you have to breed some magical creatures. Initially, they have *k* creatures numbered from 1 to *k*. Creatures have *n* different characteristics.

Sasha has a spell that allows to create a new creature from two given creatures. Each of its characteristics will be equal to the maximum of the corresponding characteristics of used creatures. Nikita has a similar spell, but in his spell, each characteristic of the new creature is equal to the minimum of the corresponding characteristics of used creatures. A new creature gets the smallest unused number.

They use their spells and are interested in some characteristics of their new creatures. Help them find out these characteristics.

## Input

The first line contains integers *n*, *k* and *q* (1 ≤ *n* ≤ 105, 1 ≤ *k* ≤ 12, 1 ≤ *q* ≤ 105) — number of characteristics, creatures and queries.

Next *k* lines describe original creatures. The line *i* contains *n* numbers *a**i*1, *a**i*2, ..., *a**in* (1 ≤ *a**ij* ≤ 109) — characteristics of the *i*-th creature.

Each of the next *q* lines contains a query. The *i*-th of these lines contains numbers *t**i*, *x**i* and *y**i* (1 ≤ *t**i* ≤ 3). They denote a query: 

* *t**i* = 1 means that Sasha used his spell to the creatures *x**i* and *y**i*.
* *t**i* = 2 means that Nikita used his spell to the creatures *x**i* and *y**i*.
* *t**i* = 3 means that they want to know the *y**i*-th characteristic of the *x**i*-th creature. In this case 1 ≤ *y**i* ≤ *n*.

It's guaranteed that all creatures' numbers are valid, that means that they are created before any of the queries involving them.

## Output

For each query with *t**i* = 3 output the corresponding characteristic.

## Examples

## Input


```
2 2 4  
1 2  
2 1  
1 1 2  
2 1 2  
3 3 1  
3 4 2  

```
## Output


```
2  
1  

```
## Input


```
5 3 8  
1 2 3 4 5  
5 1 2 3 4  
4 5 1 2 3  
1 1 2  
1 2 3  
2 4 5  
3 6 1  
3 6 2  
3 6 3  
3 6 4  
3 6 5  

```
## Output


```
5  
2  
2  
3  
4  

```
## Note

In the first sample, Sasha makes a creature with number 3 and characteristics (2, 2). Nikita makes a creature with number 4 and characteristics (1, 1). After that they find out the first characteristic for the creature 3 and the second characteristic for the creature 4.



#### tags 

#2900 #bitmasks 