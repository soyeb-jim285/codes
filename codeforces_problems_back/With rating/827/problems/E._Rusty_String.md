<h1 style='text-align: center;'> E. Rusty String</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Grigory loves strings. Recently he found a metal strip on a loft. The strip had length *n* and consisted of letters "V" and "K". Unfortunately, rust has eaten some of the letters so that it's now impossible to understand which letter was written.

Grigory couldn't understand for a long time what these letters remind him of, so he became interested in the following question: if we put a letter "V" or "K" on each unreadable position, which values can the period of the resulting string be equal to?

A period of a string is such an integer *d* from 1 to the length of the string that if we put the string shifted by *d* positions to the right on itself, then all overlapping letters coincide. For example, 3 and 5 are periods of "VKKVK".

## Input

There are several (at least one) test cases in the input. The first line contains single integer — the number of test cases.

There is an empty line before each test case. Each test case is described in two lines: the first line contains single integer *n* (1 ≤ *n* ≤ 5·105) — the length of the string, the second line contains the string of length *n*, consisting of letters "V", "K" and characters "?". The latter means the letter on its position is unreadable.

It is guaranteed that the sum of lengths among all test cases doesn't exceed 5·105.

For hacks you can only use tests with one test case.

## Output

For each test case print two lines. In the first line print the number of possible periods after we replace each unreadable letter with "V" or "K". In the next line print all these values in increasing order.

## Example

## Input


```
3  
   
5  
V??VK  
   
6  
??????  
   
4  
?VK?  

```
## Output


```
2  
3 5  
6  
1 2 3 4 5 6  
3  
2 3 4  

```
## Note

In the first test case from example we can obtain, for example, "VKKVK", which has periods 3 and 5.

In the second test case we can obtain "VVVVVV" which has all periods from 1 to 6.

In the third test case string "KVKV" has periods 2 and 4, and string "KVKK" has periods 3 and 4.



#### tags 

#2700 #fft #math #strings 