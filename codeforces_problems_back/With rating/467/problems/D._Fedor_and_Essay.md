<h1 style='text-align: center;'> D. Fedor and Essay</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After you had helped Fedor to find friends in the «Call of Soldiers 3» game, he stopped studying completely. Today, the English teacher told him to prepare an essay. Fedor didn't want to prepare the essay, so he asked Alex for help. Alex came to help and wrote the essay for Fedor. But Fedor didn't like the essay at all. Now Fedor is going to change the essay using the synonym dictionary of the English language.

Fedor does not want to change the meaning of the essay. So the only change he would do: change a word from essay to one of its synonyms, basing on a replacement rule from the dictionary. Fedor may perform this operation any number of times.

As a result, Fedor wants to get an essay which contains as little letters «R» (the case doesn't matter) as possible. If there are multiple essays with minimum number of «R»s he wants to get the one with minimum length (length of essay is the sum of the lengths of all the words in it). Help Fedor get the required essay.

Please note that in this problem the case of letters doesn't matter. For example, if the synonym dictionary says that word cat can be replaced with word DOG, then it is allowed to replace the word Cat with the word doG.

## Input

The first line contains a single integer *m* (1 ≤ *m* ≤ 105) — the number of words in the initial essay. The second line contains words of the essay. The words are separated by a single space. It is guaranteed that the total length of the words won't exceed 105 characters.

The next line contains a single integer *n* (0 ≤ *n* ≤ 105) — the number of pairs of words in synonym dictionary. The *i*-th of the next *n* lines contains two space-separated non-empty words *x**i* and *y**i*. They mean that word *x**i* can be replaced with word *y**i* (but not vise versa). It is guaranteed that the total length of all pairs of synonyms doesn't exceed 5·105 characters.

All the words at input can only consist of uppercase and lowercase letters of the English alphabet.

## Output

Print two integers — the minimum number of letters «R» in an optimal essay and the minimum length of an optimal essay.

## Examples

## Input


```
3  
AbRb r Zz  
4  
xR abRb  
aA xr  
zz Z  
xr y  

```
## Output


```
2 6  

```
## Input


```
2  
RuruRu fedya  
1  
ruruRU fedor  

```
## Output


```
1 10  

```


#### tags 

#2400 #dfs_and_similar #dp #graphs #hashing #strings 