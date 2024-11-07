<h1 style='text-align: center;'> E. Subordinates</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* workers in a company, each of them has a unique id from 1 to *n*. Exaclty one of them is a chief, his id is *s*. Each worker except the chief has exactly one immediate superior.

There was a request to each of the workers to tell how how many superiors (not only immediate). Worker's superiors are his immediate superior, the immediate superior of the his immediate superior, and so on. For example, if there are three workers in the company, from which the first is the chief, the second worker's immediate superior is the first, the third worker's immediate superior is the second, then the third worker has two superiors, one of them is immediate and one not immediate. The chief is a superior to all the workers except himself.

Some of the workers were in a hurry and made a mistake. You are to find the minimum number of workers that could make a mistake.

## Input

The first line contains two positive integers *n* and *s* (1 ≤ *n* ≤ 2·105, 1 ≤ *s* ≤ *n*) — the number of workers and the id of the chief.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ *n* - 1), where *a**i* is the number of superiors (not only immediate) the worker with id *i* reported about.

## Output

Print the minimum number of workers that could make a mistake.

## Examples

## Input


```
3 2  
2 0 2  

```
## Output


```
1  

```
## Input


```
5 3  
1 0 0 4 1  

```
## Output


```
2  

```
## Note

In the first example it is possible that only the first worker made a mistake. Then: 

* the immediate superior of the first worker is the second worker,
* the immediate superior of the third worker is the first worker,
* the second worker is the chief.


#### tags 

#1900 #constructive_algorithms #data_structures #graphs #greedy #sortings 