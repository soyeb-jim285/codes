<h1 style='text-align: center;'> E. Test</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sometimes it is hard to prepare tests for programming problems. Now Bob is preparing tests to new problem about strings — input data to his problem is one string. Bob has 3 wrong solutions to this problem. The first gives the wrong answer if the input data contains the substring *s*1, the second enters an infinite loop if the input data contains the substring *s*2, and the third requires too much memory if the input data contains the substring *s*3. Bob wants these solutions to fail single test. What is the minimal length of test, which couldn't be passed by all three Bob's solutions?

## Input

There are exactly 3 lines in the input data. The *i*-th line contains string *s**i*. All the strings are non-empty, consists of lowercase Latin letters, the length of each string doesn't exceed 105.

## Output

## Output

 one number — what is minimal length of the string, containing *s*1, *s*2 and *s*3 as substrings.

## Examples

## Input


```
ab  
bc  
cd  

```
## Output


```
4  

```
## Input


```
abacaba  
abaaba  
x  

```
## Output


```
11  

```


#### tags 

#2200 #hashing #strings 