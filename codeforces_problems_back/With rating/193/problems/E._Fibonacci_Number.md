<h1 style='text-align: center;'> E. Fibonacci Number</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

John Doe has a list of all Fibonacci numbers modulo 1013. This list is infinite, it starts with numbers 0 and 1. Each number in the list, apart from the first two, is a sum of previous two modulo 1013. That is, John's list is made from the Fibonacci numbers' list by replacing each number there by the remainder when divided by 1013. 

John got interested in number *f* (0 ≤ *f* < 1013) and now wants to find its first occurrence in the list given above. Help John and find the number of the first occurence of number *f* in the list or otherwise state that number *f* does not occur in the list. 

The numeration in John's list starts from zero. There, the 0-th position is the number 0, the 1-st position is the number 1, the 2-nd position is the number 1, the 3-rd position is the number 2, the 4-th position is the number 3 and so on. Thus, the beginning of the list looks like this: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

## Input

The first line contains the single integer *f* (0 ≤ *f* < 1013) — the number, which position in the list we should find.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier. 

## Output

Print a single number — the number of the first occurrence of the given number in John's list. If this number doesn't occur in John's list, print -1.

## Examples

## Input


```
13  

```
## Output


```
7  

```
## Input


```
377  

```
## Output


```
14  

```


#### tags 

#2900 #brute_force #math #matrices 