<h1 style='text-align: center;'> A. Rewards</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bizon the Champion is called the Champion for a reason. 

Bizon the Champion has recently got a present — a new glass cupboard with *n* shelves and he decided to put all his presents there. All the presents can be divided into two types: medals and cups. Bizon the Champion has *a*1 first prize cups, *a*2 second prize cups and *a*3 third prize cups. Besides, he has *b*1 first prize medals, *b*2 second prize medals and *b*3 third prize medals. 

Naturally, the rewards in the cupboard must look good, that's why Bizon the Champion decided to follow the rules:

* any shelf cannot contain both cups and medals at the same time;
* no shelf can contain more than five cups;
* no shelf can have more than ten medals.

Help Bizon the Champion find out if we can put all the rewards so that all the conditions are fulfilled.

## Input

The first line contains integers *a*1, *a*2 and *a*3 (0 ≤ *a*1, *a*2, *a*3 ≤ 100). The second line contains integers *b*1, *b*2 and *b*3 (0 ≤ *b*1, *b*2, *b*3 ≤ 100). The third line contains integer *n* (1 ≤ *n* ≤ 100).

The numbers in the lines are separated by single spaces.

## Output

Print "YES" (without the quotes) if all the rewards can be put on the shelves in the described manner. Otherwise, print "NO" (without the quotes).

## Examples

## Input


```
1 1 1  
1 1 1  
4  

```
## Output


```
YES  

```
## Input


```
1 1 3  
2 3 4  
2  

```
## Output


```
YES  

```
## Input


```
1 0 0  
1 0 0  
1  

```
## Output


```
NO  

```


#### tags 

#800 #implementation 