<h1 style='text-align: center;'> B. Regular Bracket Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A bracket sequence is called regular if it is possible to obtain correct arithmetic expression by inserting characters «+» and «1» into this sequence. For example, sequences «(())()», «()» and «(()(()))» are regular, while «)(», «(()» and «(()))(» are not.

One day Johnny got bracket sequence. He decided to remove some of the brackets from it in order to obtain a regular bracket sequence. What is the maximum length of a regular bracket sequence which can be obtained?

## Input

## Input

 consists of a single line with non-empty string of «(» and «)» characters. Its length does not exceed 106.

## Output

## Output

 the maximum possible length of a regular bracket sequence.

## Examples

## Input


```
(()))(  

```
## Output


```
4  

```
## Input


```
((()())  

```
## Output


```
6  

```


#### tags 

#1400 #greedy 