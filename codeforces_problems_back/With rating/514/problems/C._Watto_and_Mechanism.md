<h1 style='text-align: center;'> C. Watto and Mechanism</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Watto, the owner of a spare parts store, has recently got an order for the mechanism that can process strings in a certain way. Initially the memory of the mechanism is filled with *n* strings. Then the mechanism should be able to process queries of the following type: "Given string *s*, determine if the memory of the mechanism contains string *t* that consists of the same number of characters as *s* and differs from *s* in exactly one position".

Watto has already compiled the mechanism, all that's left is to write a program for it and check it on the data consisting of *n* initial lines and *m* queries. He decided to entrust this job to you.

## Input

The first line contains two non-negative numbers *n* and *m* (0 ≤ *n* ≤ 3·105, 0 ≤ *m* ≤ 3·105) — the number of the initial strings and the number of queries, respectively.

Next follow *n* non-empty strings that are uploaded to the memory of the mechanism.

Next follow *m* non-empty strings that are the queries to the mechanism.

The total length of lines in the input doesn't exceed 6·105. Each line consists only of letters 'a', 'b', 'c'.

## Output

For each query print on a single line "YES" (without the quotes), if the memory of the mechanism contains the required string, otherwise print "NO" (without the quotes).

## Examples

## Input


```
2 3  
aaaaa  
acacaca  
aabaa  
ccacacc  
caaac  

```
## Output


```
YES  
NO  
NO  

```


#### tags 

#2000 #binary_search #data_structures #hashing #string_suffix_structures #strings 