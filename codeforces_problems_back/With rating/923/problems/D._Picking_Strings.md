<h1 style='text-align: center;'> D. Picking Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice has a string consisting of characters 'A', 'B' and 'C'. Bob can use the following transitions on any substring of our string in any order any number of times: 

* A ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) BC
* B ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) AC
* C ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) AB
* AAA ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) empty string

## Note

 that a substring is one or more consecutive characters. For given queries, determine whether it is possible to obtain the target string from source.

## Input

The first line contains a string *S* (1 ≤ |*S*| ≤ 105). The second line contains a string *T* (1 ≤ |*T*| ≤ 105), each of these strings consists only of uppercase English letters 'A', 'B' and 'C'.

The third line contains the number of queries *Q* (1 ≤ *Q* ≤ 105).

The following *Q* lines describe queries. The *i*-th of these lines contains four space separated integers *a**i*, *b**i*, *c**i*, *d**i*. These represent the *i*-th query: is it possible to create *T*[*c**i*..*d**i*] from *S*[*a**i*..*b**i*] by applying the above transitions finite amount of times?

Here, *U*[*x*..*y*] is a substring of *U* that begins at index *x* (indexed from 1) and ends at index *y*. In particular, *U*[1..|*U*|] is the whole string *U*.

It is guaranteed that 1 ≤ *a* ≤ *b* ≤ |*S*| and 1 ≤ *c* ≤ *d* ≤ |*T*|.

## Output

Print a string of *Q* characters, where the *i*-th character is '1' if the answer to the *i*-th query is positive, and '0' otherwise.

## Example

## Input


```
AABCCBAAB  
ABCB  
5  
1 3 1 2  
2 2 2 4  
7 9 1 1  
3 4 2 3  
4 5 1 3  

```
## Output


```
10011  

```
## Note

In the first query we can achieve the result, for instance, by using transitions ![](images/2c164f8b6e335aa51b97bbd019ca0d7326927314.png).

The third query asks for changing AAB to A — but in this case we are not able to get rid of the character 'B'.



#### tags 

#2500 #constructive_algorithms #implementation #strings 