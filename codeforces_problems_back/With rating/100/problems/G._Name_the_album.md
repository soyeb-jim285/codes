<h1 style='text-align: center;'> G. Name the album</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

The famous singer, Aryo, is going to publish a new album of his great work!

Unfortunately these days, there are many albums, Aryo wants to choose a new name for his album, a name that has not been used or at least has not been used recently.

He has a list of all used album names together with the year the albums were published. He also has a list of suitable names for his album.

If he finds a suitable name which has not been used before, he'll use it. Otherwise he will use the name which was used as long ago as possible. If two such names are found (that haven't been used or were used at the same year), he uses the name that is alphabetically latest.

Help him name his album.

## Input

The first line contains a single integer *n* (0 ≤ *n* ≤ 105), the number of used names. 

The following *n* lines each contain a string (the album name) and an integer (the year album was published). Album names are made of lowercase Latin letters and contain at most 14 letters. The year is in range [1900, 2011].

The following line contains a single integer *m* (1 ≤ *m* ≤ 104), the number of suitable album names.

The following *m* lines each contain a string — a suitable name. It contains at most 14 lowercase Latin letters.

All album names and suitable names are non-empty.

## Output

Write a single string. The name of the new album.

## Examples

## Input


```
3  
eyesonme 2008  
anewdayhascome 2002  
oneheart 2003  
2  
oneheart  
bienbien  

```
## Output


```
bienbien  

```
## Input


```
2  
nasimevasl 2003  
basetareha 2006  
2  
nasimevasl  
basetareha  

```
## Output


```
nasimevasl  

```


#### tags 

#1800 #*special #data_structures #implementation 