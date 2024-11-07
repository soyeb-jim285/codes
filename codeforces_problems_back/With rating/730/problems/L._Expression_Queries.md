<h1 style='text-align: center;'> L. Expression Queries</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A simplified arithmetic expression (SAE) is an arithmetic expression defined by the following grammar:

* <SAE> ::= <Number> | <SAE>+<SAE> | <SAE>*<SAE> | (<SAE>)
* <Number> ::= <Digit> | <Digit><Number>
* <Digit> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

In other words it's a correct arithmetic expression that is allowed to contain brackets, numbers (possibly with leading zeros), multiplications and additions. For example expressions "(0+01)", "0" and "1*(0)" are simplified arithmetic expressions, but expressions "2-1", "+1" and "1+2)" are not.

Given a string *s*1*s*2...*s*|*s*| that represents a SAE; *s**i* denotes the *i*-th character of the string which can be either a digit ('0'-'9'), a plus sign ('+'), a multiplication sign ('*'), an opening round bracket '(' or a closing round bracket ')'.

A part *s**l**s**l* + 1...*s**r* of this string is called a sub-expression if and only if it is a SAE.

You task is to answer *m* queries, each of which is a pair of integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ |*s*|). For each query determine whether the corresponding part of the given string is a sub-expression and in case it's a sub-expression calculate its value modulo 1000000007 (109 + 7). The values should be calculated using standard operator priorities.

## Input

The first line of the input contains non-empty string *s* (1 ≤ |*s*| ≤ 4·105) which represents a correct SAE. Each character of the string can be one of the following characters: '*', '+', '(', ')' or a digit ('0'-'9'). The expression might contain extra-huge numbers.

The second line contains an integer *m* (1 ≤ *m* ≤ 4·105) which is the number of queries. Each of the next *m* lines contains two space-separated integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ |*s*|) — the *i*-th query.

## Output

The *i*-th number of output should be the answer for the *i*-th query. If the *i*-th query corresponds to a valid sub-expression output the value of the sub-expression modulo 1000000007 (109 + 7). Otherwise output -1 as an answer for the query. Print numbers on separate lines.

## Examples

## Input


```
((1+2)*3+101*2)  
6  
8 14  
1 6  
2 10  
11 14  
5 5  
4 5  

```
## Output


```
205  
-1  
10  
2  
2  
-1  

```
## Input


```
(01)  
1  
1 4  

```
## Output


```
1  

```


#### tags 

#3200 #data_structures 