<h1 style='text-align: center;'> B. Letter</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya decided to write an anonymous letter cutting the letters out of a newspaper heading. He knows heading *s*1 and text *s*2 that he wants to send. Vasya can use every single heading letter no more than once. Vasya doesn't have to cut the spaces out of the heading — he just leaves some blank space to mark them. Help him; find out if he will manage to compose the needed text.

## Input

The first line contains a newspaper heading *s*1. The second line contains the letter text *s*2. *s*1 и *s*2 are non-empty lines consisting of spaces, uppercase and lowercase Latin letters, whose lengths do not exceed 200 symbols. The uppercase and lowercase letters should be differentiated. Vasya does not cut spaces out of the heading.

## Output

If Vasya can write the given anonymous letter, print YES, otherwise print NO

## Examples

## Input


```
Instead of dogging Your footsteps it disappears but you dont notice anything  
where is your dog  

```
## Output


```
NO  

```
## Input


```
Instead of dogging Your footsteps it disappears but you dont notice anything  
Your dog is upstears  

```
## Output


```
YES  

```
## Input


```
Instead of dogging your footsteps it disappears but you dont notice anything  
Your dog is upstears  

```
## Output


```
NO  

```
## Input


```
abcdefg hijk  
k j i h g f e d c b a  

```
## Output


```
YES  

```


#### tags 

#1100 #implementation #strings 