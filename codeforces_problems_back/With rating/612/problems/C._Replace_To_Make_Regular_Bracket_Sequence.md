<h1 style='text-align: center;'> C. Replace To Make Regular Bracket Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given string *s* consists of opening and closing brackets of four kinds <>, {}, [], (). There are two types of brackets: opening and closing. You can replace any bracket by another of the same type. For example, you can replace < by the bracket {, but you can't replace it by ) or >.

The following definition of a regular bracket sequence is well-known, so you can be familiar with it.

Let's define a regular bracket sequence (RBS). Empty string is RBS. Let *s*1 and *s*2 be a RBS then the strings <*s*1>*s*2, {*s*1}*s*2, [*s*1]*s*2, (*s*1)*s*2 are also RBS.

For example the string "[[(){}]<>]" is RBS, but the strings "[)()" and "][()()" are not.

Determine the least number of replaces to make the string *s* RBS.

## Input

The only line contains a non empty string *s*, consisting of only opening and closing brackets of four kinds. The length of *s* does not exceed 106.

## Output

If it's impossible to get RBS from *s* print Impossible.

Otherwise print the least number of replaces needed to get RBS from *s*.

## Examples

## Input


```
[<}){}  

```
## Output


```
2
```
## Input


```
{()}[]  

```
## Output


```
0
```
## Input


```
]]  

```
## Output


```
Impossible
```


#### tags 

#1400 #data_structures #expression_parsing #math 