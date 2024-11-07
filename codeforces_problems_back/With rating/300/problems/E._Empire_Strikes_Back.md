<h1 style='text-align: center;'> E. Empire Strikes Back</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

In a far away galaxy there is war again. The treacherous Republic made *k* precision strikes of power *a**i* on the Empire possessions. To cope with the republican threat, the Supreme Council decided to deal a decisive blow to the enemy forces. 

To successfully complete the conflict, the confrontation balance after the blow should be a positive integer. The balance of confrontation is a number that looks like ![](images/cb0172a656698061aefa8eb30b2dbcd1e31f508e.png), where *p* = *n*! (*n* is the power of the Imperial strike), ![](images/be803394f3ab1c18735553e728d31caeeea3bf83.png). After many years of war the Empire's resources are low. So to reduce the costs, *n* should be a minimum positive integer that is approved by the commanders.

Help the Empire, find the minimum positive integer *n*, where the described fraction is a positive integer.

## Input

The first line contains integer *k* (1 ≤ *k* ≤ 106). The second line contains *k* integers *a*1, *a*2, ..., *a**k* (1 ≤ *a**i* ≤ 107).

## Output

Print the minimum positive integer *n*, needed for the Empire to win.

Please, do not use the %lld to read or write 64-but integers in С++. It is preferred to use the cin, cout streams or the %I64d specificator.

## Examples

## Input


```
2  
1000 1000  

```
## Output


```
2000
```
## Input


```
1  
2  

```
## Output


```
2
```


#### tags 

#2300 #binary_search #math #number_theory 