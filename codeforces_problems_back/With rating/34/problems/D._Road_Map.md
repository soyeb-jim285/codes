<h1 style='text-align: center;'> D. Road Map</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* cities in Berland. Each city has its index — an integer number from 1 to *n*. The capital has index *r*1. All the roads in Berland are two-way. The road system is such that there is exactly one path from the capital to each city, i.e. the road map looks like a tree. In Berland's chronicles the road map is kept in the following way: for each city *i*, different from the capital, there is kept number *p**i* — index of the last city on the way from the capital to *i*.

Once the king of Berland Berl XXXIV decided to move the capital from city *r*1 to city *r*2. Naturally, after this the old representation of the road map in Berland's chronicles became incorrect. Please, help the king find out a new representation of the road map in the way described above.

## Input

The first line contains three space-separated integers *n*, *r*1, *r*2 (2 ≤ *n* ≤ 5·104, 1 ≤ *r*1 ≠ *r*2 ≤ *n*) — amount of cities in Berland, index of the old capital and index of the new one, correspondingly.

The following line contains *n* - 1 space-separated integers — the old representation of the road map. For each city, apart from *r*1, there is given integer *p**i* — index of the last city on the way from the capital to city *i*. All the cities are described in order of increasing indexes.

## Output

## Output

 *n* - 1 numbers — new representation of the road map in the same format.

## Examples

## Input


```
3 2 3  
2 2  

```
## Output


```
2 3 
```
## Input


```
6 2 4  
6 1 2 4 2  

```
## Output


```
6 4 1 4 2 
```


#### tags 

#1600 #dfs_and_similar #graphs 