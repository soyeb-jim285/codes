<h1 style='text-align: center;'> B. Borze</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ternary numeric notation is quite popular in Berland. To telegraph the ternary number the Borze alphabet is used. Digit 0 is transmitted as «.», 1 as «-.» and 2 as «--». You are to decode the Borze code, i.e. to find out the ternary number given its representation in Borze alphabet.

## Input

The first line contains a number in Borze code. The length of the string is between 1 and 200 characters. It's guaranteed that the given string is a valid Borze code of some ternary number (this number can have leading zeroes).

## Output

## Output

 the decoded ternary number. It can have leading zeroes.

## Examples

## Input


```
.-.--  

```
## Output


```
012
```
## Input


```
--.  

```
## Output


```
20
```
## Input


```
-..-.--  

```
## Output


```
1012
```


#### tags 

#800 #expression_parsing #implementation 