<h1 style='text-align: center;'> D. Savior</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Misha decided to help Pasha and Akim be friends again. He had a cunning plan — to destroy all the laughy mushrooms. He knows that the laughy mushrooms can easily burst when they laugh. Mushrooms grow on the lawns. There are *a*[*t*] mushrooms on the *t*-th lawn.

Misha knows that the lawns where the mushrooms grow have a unique ability. A lawn (say, *i*) can transfer laugh to other lawn (say, *j*) if there exists an integer (say, *b*) such, that some permutation of numbers *a*[*i*], *a*[*j*] and *b* is a beautiful triple (*i* ≠ *j*). A beautiful triple is such three pairwise coprime numbers *x*, *y*, *z*, which satisfy the following condition: *x*2 + *y*2 = *z*2.

Misha wants to know on which minimal number of lawns he should laugh for all the laughy mushrooms to burst.

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 106) which is the number of lawns. The next line contains *n* integers *a**i* which are the number of mushrooms on the *i*-lawn (1 ≤ *a**i* ≤ 107). All the numbers are different.

## Output

Print a single number — the minimal number of lawns on which Misha should laugh for all the mushrooms to burst.

## Examples

## Input


```
1  
2  

```
## Output


```
1  

```
## Input


```
2  
1 2  

```
## Output


```
2  

```
## Input


```
2  
3 5  

```
## Output


```
1  

```


#### tags 

#2500 #brute_force #dsu #math 