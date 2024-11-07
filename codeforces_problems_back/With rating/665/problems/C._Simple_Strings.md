<h1 style='text-align: center;'> C. Simple Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

zscoder loves simple strings! A string *t* is called simple if every pair of adjacent characters are distinct. For example ab, aba, zscoder are simple whereas aa, add are not simple.

zscoder is given a string *s*. He wants to change a minimum number of characters so that the string *s* becomes simple. Help him with this task!

## Input

The only line contains the string *s* (1 ≤ |*s*| ≤ 2·105) — the string given to zscoder. The string *s* consists of only lowercase English letters.

## Output

Print the simple string *s*' — the string *s* after the minimal number of changes. If there are multiple solutions, you may output any of them.

Note that the string *s*' should also consist of only lowercase English letters.

## Examples

## Input


```
aab  

```
## Output


```
bab  

```
## Input


```
caaab  

```
## Output


```
cabab  

```
## Input


```
zscoder  

```
## Output


```
zscoder  

```


#### tags 

#1300 #dp #greedy #strings 