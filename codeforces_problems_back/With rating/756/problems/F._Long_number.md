<h1 style='text-align: center;'> F. Long number</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Consider the following grammar:

* <expression> ::= <term> | <expression> '+' <term>
* <term> ::= <number> | <number> '-' <number> | <number> '(' <expression> ')'
* <number> ::= <pos_digit> | <number> <digit>
* <digit> ::= '0' | <pos_digit>
* <pos_digit> ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

This grammar describes a number in decimal system using the following rules:

* <number> describes itself,
* <number>-<number> (l-r, *l* ≤ *r*) describes integer which is concatenation of all integers from *l* to *r*, written without leading zeros. For example, 8-11 describes 891011,
* <number>(<expression>) describes integer which is concatenation of <number> copies of integer described by <expression>,
* <expression>+<term> describes integer which is concatenation of integers described by <expression> and <term>.

For example, 2(2-4+1)+2(2(17)) describes the integer 2341234117171717.

You are given an expression in the given grammar. Print the integer described by it modulo 109 + 7.

## Input

The only line contains a non-empty string at most 105 characters long which is valid according to the given grammar. In particular, it means that in terms l-r *l* ≤ *r* holds.

## Output

Print single integer — the number described by the expression modulo 109 + 7.

## Examples

## Input


```
8-11  

```
## Output


```
891011  

```
## Input


```
2(2-4+1)+2(2(17))  

```
## Output


```
100783079  

```
## Input


```
1234-5678  

```
## Output


```
745428774  

```
## Input


```
1+2+3+4-5+6+7-9  

```
## Output


```
123456789  

```


#### tags 

#3400 #expression_parsing #math #number_theory 