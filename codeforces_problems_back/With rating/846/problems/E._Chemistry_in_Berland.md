<h1 style='text-align: center;'> E. Chemistry in Berland</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Igor is a post-graduate student of chemistry faculty in Berland State University (BerSU). He needs to conduct a complicated experiment to write his thesis, but laboratory of BerSU doesn't contain all the materials required for this experiment.

Fortunately, chemical laws allow material transformations (yes, chemistry in Berland differs from ours). But the rules of transformation are a bit strange.

Berland chemists are aware of *n* materials, numbered in the order they were discovered. Each material can be transformed into some other material (or vice versa). Formally, for each *i* (2 ≤ *i* ≤ *n*) there exist two numbers *x**i* and *k**i* that denote a possible transformation: *k**i* kilograms of material *x**i* can be transformed into 1 kilogram of material *i*, and 1 kilogram of material *i* can be transformed into 1 kilogram of material *x**i*. Chemical processing equipment in BerSU allows only such transformation that the amount of resulting material is always an integer number of kilograms.

For each *i* (1 ≤ *i* ≤ *n*) Igor knows that the experiment requires *a**i* kilograms of material *i*, and the laboratory contains *b**i* kilograms of this material. Is it possible to conduct an experiment after transforming some materials (or none)?

## Input

The first line contains one integer number *n* (1 ≤ *n* ≤ 105) — the number of materials discovered by Berland chemists.

The second line contains *n* integer numbers *b*1, *b*2... *b**n* (1 ≤ *b**i* ≤ 1012) — supplies of BerSU laboratory.

The third line contains *n* integer numbers *a*1, *a*2... *a**n* (1 ≤ *a**i* ≤ 1012) — the amounts required for the experiment.

Then *n* - 1 lines follow. *j*-th of them contains two numbers *x**j* + 1 and *k**j* + 1 that denote transformation of (*j* + 1)-th material (1 ≤ *x**j* + 1 ≤ *j*, 1 ≤ *k**j* + 1 ≤ 109).

## Output

Print YES if it is possible to conduct an experiment. Otherwise print NO.

## Examples

## Input


```
3  
1 2 3  
3 2 1  
1 1  
1 1  

```
## Output


```
YES  

```
## Input


```
3  
3 2 1  
1 2 3  
1 1  
1 2  

```
## Output


```
NO  

```


#### tags 

#2300 #dfs_and_similar #greedy #trees 