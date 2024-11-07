<h1 style='text-align: center;'> G. Partitions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a set of *n* elements indexed from 1 to *n*. The weight of *i*-th element is *w**i*. The weight of some subset of a given set is denoted as ![](images/dab8d9210e9882924b03a521d4eb19fed5b2bc74.png). The weight of some partition *R* of a given set into *k* subsets is ![](images/d79871cc5728032baa39fd4a9461918c62d2ac58.png) (recall that a partition of a given set is a set of its subsets such that every element of the given set belongs to exactly one subset in partition).

Calculate the sum of weights of all partitions of a given set into exactly *k* non-empty subsets, and print it modulo 109 + 7. Two partitions are considered different iff there exist two elements *x* and *y* such that they belong to the same set in one of the partitions, and to different sets in another partition.

## Input

The first line contains two integers *n* and *k* (1 ≤ *k* ≤ *n* ≤ 2·105) — the number of elements and the number of subsets in each partition, respectively.

The second line contains *n* integers *w**i* (1 ≤ *w**i* ≤ 109)— weights of elements of the set.

## Output

Print one integer — the sum of weights of all partitions of a given set into *k* non-empty subsets, taken modulo 109 + 7.

## Examples

## Input


```
4 2  
2 3 2 3  

```
## Output


```
160  

```
## Input


```
5 2  
1 2 3 4 5  

```
## Output


```
645  

```
## Note

Possible partitions in the first sample:

1. {{1, 2, 3}, {4}}, *W*(*R*) = 3·(*w*1 + *w*2 + *w*3) + 1·*w*4 = 24;
2. {{1, 2, 4}, {3}}, *W*(*R*) = 26;
3. {{1, 3, 4}, {2}}, *W*(*R*) = 24;
4. {{1, 2}, {3, 4}}, *W*(*R*) = 2·(*w*1 + *w*2) + 2·(*w*3 + *w*4) = 20;
5. {{1, 3}, {2, 4}}, *W*(*R*) = 20;
6. {{1, 4}, {2, 3}}, *W*(*R*) = 20;
7. {{1}, {2, 3, 4}}, *W*(*R*) = 26;

Possible partitions in the second sample:

1. {{1, 2, 3, 4}, {5}}, *W*(*R*) = 45;
2. {{1, 2, 3, 5}, {4}}, *W*(*R*) = 48;
3. {{1, 2, 4, 5}, {3}}, *W*(*R*) = 51;
4. {{1, 3, 4, 5}, {2}}, *W*(*R*) = 54;
5. {{2, 3, 4, 5}, {1}}, *W*(*R*) = 57;
6. {{1, 2, 3}, {4, 5}}, *W*(*R*) = 36;
7. {{1, 2, 4}, {3, 5}}, *W*(*R*) = 37;
8. {{1, 2, 5}, {3, 4}}, *W*(*R*) = 38;
9. {{1, 3, 4}, {2, 5}}, *W*(*R*) = 38;
10. {{1, 3, 5}, {2, 4}}, *W*(*R*) = 39;
11. {{1, 4, 5}, {2, 3}}, *W*(*R*) = 40;
12. {{2, 3, 4}, {1, 5}}, *W*(*R*) = 39;
13. {{2, 3, 5}, {1, 4}}, *W*(*R*) = 40;
14. {{2, 4, 5}, {1, 3}}, *W*(*R*) = 41;
15. {{3, 4, 5}, {1, 2}}, *W*(*R*) = 42.


#### tags 

#2700 #combinatorics #math #number_theory 