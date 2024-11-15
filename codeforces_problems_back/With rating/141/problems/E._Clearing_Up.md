<h1 style='text-align: center;'> E. Clearing Up</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After Santa Claus and his assistant Elf delivered all the presents and made all the wishes come true, they returned to the North Pole and found out that it is all covered with snow. Both of them were quite tired and they decided only to remove the snow from the roads connecting huts. The North Pole has *n* huts connected with *m* roads. One can go along the roads in both directions. 

The Elf offered to split: Santa Claus will clear up the wide roads and the Elf will tread out the narrow roads. For each road they decided who will clear it: Santa Claus or the Elf. To minimize the efforts they decided to clear the road so as to fulfill both those conditions: 

* between any two huts should exist exactly one simple path along the cleared roads;
* Santa Claus and the Elf should clear the same number of roads.

At this point Santa Claus and his assistant Elf wondered which roads should they clear up?

## Input

The first input line contains two positive integers *n* and *m* (1 ≤ *n* ≤ 103, 1 ≤ *m* ≤ 105) — the number of huts and the number of roads. Then follow *m* lines, each of them contains a road description: the numbers of huts it connects — *x* and *y* (1 ≤ *x*, *y* ≤ *n*) and the person responsible for clearing out this road ("S" — for the Elf or "M" for Santa Claus). It is possible to go on each road in both directions. ## Note

 that there can be more than one road between two huts and a road can begin and end in the same hut.

## Output

Print "-1" without the quotes if it is impossible to choose the roads that will be cleared by the given rule. Otherwise print in the first line how many roads should be cleared and in the second line print the numbers of those roads (the roads are numbered from 1 in the order of occurrence in the input). It is allowed to print the numbers of the roads in any order. Each number should be printed exactly once. As you print the numbers, separate them with spaces.

## Examples

## Input


```
1 2  
1 1 S  
1 1 M  

```
## Output


```
0  
  

```
## Input


```
3 3  
1 2 S  
1 3 M  
2 3 S  

```
## Output


```
2  
2 1   

```
## Input


```
5 6  
1 1 S  
1 2 M  
1 3 S  
1 4 M  
1 5 M  
2 2 S  

```
## Output


```
-1  

```
## Note

A path is called simple if all huts on it are pairwise different.



#### tags 

#2300 #constructive_algorithms #dp #dsu #graphs 