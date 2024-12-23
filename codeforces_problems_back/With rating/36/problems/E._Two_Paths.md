<h1 style='text-align: center;'> E. Two Paths</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

Once archaeologists found *m* mysterious papers, each of which had a pair of integers written on them. Ancient people were known to like writing down the indexes of the roads they walked along, as «*a* *b*» or «*b* *a*», where *a*, *b* are the indexes of two different cities joint by the road . It is also known that the mysterious papers are pages of two travel journals (those days a new journal was written for every new journey).

During one journey the traveler could walk along one and the same road several times in one or several directions but in that case he wrote a new entry for each time in his journal. Besides, the archaeologists think that the direction the traveler took on a road had no effect upon the entry: the entry that looks like «*a* *b*» could refer to the road from *a* to *b* as well as to the road from *b* to *a*.

The archaeologists want to put the pages in the right order and reconstruct the two travel paths but unfortunately, they are bad at programming. That’s where you come in. Go help them!

## Input

The first input line contains integer *m* (1 ≤ *m* ≤ 10000). Each of the following *m* lines describes one paper. Each description consists of two integers *a*, *b* (1 ≤ *a*, *b* ≤ 10000, *a* ≠ *b*).

## Output

In the first line output the number *L*1. That is the length of the first path, i.e. the amount of papers in its description. In the following line output *L*1 space-separated numbers — the indexes of the papers that describe the first path. In the third and fourth lines output similarly the length of the second path *L*2 and the path itself. Both paths must contain at least one road, i.e. condition *L*1 > 0 and *L*2 > 0 must be met. The papers are numbered from 1 to *m* according to the order of their appearance in the input file. The numbers should be output in the order in which the traveler passed the corresponding roads. If the answer is not unique, output any.

If it’s impossible to find such two paths, output «-1».

Don’t forget that each paper should be used exactly once, i.e *L*1 + *L*2 = *m*.

## Examples

## Input


```
2  
4 5  
4 3  

```
## Output


```
1  
2   
1  
1  

```
## Input


```
1  
1 2  

```
## Output


```
-1  

```


#### tags 

#2600 #constructive_algorithms #dsu #graphs #implementation 