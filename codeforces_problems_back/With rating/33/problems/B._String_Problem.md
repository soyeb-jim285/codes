<h1 style='text-align: center;'> B. String Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Boy Valera likes strings. And even more he likes them, when they are identical. That's why in his spare time Valera plays the following game. He takes any two strings, consisting of lower case Latin letters, and tries to make them identical. According to the game rules, with each move Valera can change one arbitrary character *A**i* in one of the strings into arbitrary character *B**i*, but he has to pay for every move a particular sum of money, equal to *W**i*. He is allowed to make as many moves as he needs. Since Valera is a very economical boy and never wastes his money, he asked you, an experienced programmer, to help him answer the question: what minimum amount of money should Valera have to get identical strings. 

## Input

The first input line contains two initial non-empty strings *s* and *t*, consisting of lower case Latin letters. The length of each string doesn't exceed 105. The following line contains integer *n* (0 ≤ *n* ≤ 500) — amount of possible changings. Then follow *n* lines, each containing characters *A**i* and *B**i* (lower case Latin letters) and integer *W**i* (0 ≤ *W**i* ≤ 100), saying that it's allowed to change character *A**i* into character *B**i* in any of the strings and spend sum of money *W**i*.

## Output

If the answer exists, output the answer to the problem, and the resulting string. Otherwise output -1 in the only line. If the answer is not unique, output any.

## Examples

## Input


```
uayd  
uxxd  
3  
a x 8  
x y 13  
d c 3  

```
## Output


```
21  
uxyd  

```
## Input


```
a  
b  
3  
a b 2  
a b 3  
b a 5  

```
## Output


```
2  
b  

```
## Input


```
abc  
ab  
6  
a b 4  
a b 7  
b a 8  
c b 11  
c a 3  
a c 0  

```
## Output


```
-1  

```


#### tags 

#1800 #shortest_paths 