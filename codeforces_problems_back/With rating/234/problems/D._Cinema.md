<h1 style='text-align: center;'> D. Cinema</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Overall there are *m* actors in Berland. Each actor has a personal identifier — an integer from 1 to *m* (distinct actors have distinct identifiers). Vasya likes to watch Berland movies with Berland actors, and he has *k* favorite actors. He watched the movie trailers for the next month and wrote the following information for every movie: the movie title, the number of actors who starred in it, and the identifiers of these actors. Besides, he managed to copy the movie titles and how many actors starred there, but he didn't manage to write down the identifiers of some actors. Vasya looks at his records and wonders which movies may be his favourite, and which ones may not be. Once Vasya learns the exact cast of all movies, his favorite movies will be determined as follows: a movie becomes favorite movie, if no other movie from Vasya's list has more favorite actors.

Help the boy to determine the following for each movie:

* whether it surely will be his favourite movie;
* whether it surely won't be his favourite movie;
* can either be favourite or not.
## Input

The first line of the input contains two integers *m* and *k* (1 ≤ *m* ≤ 100, 1 ≤ *k* ≤ *m*) — the number of actors in Berland and the number of Vasya's favourite actors. 

The second line contains *k* distinct integers *a**i* (1 ≤ *a**i* ≤ *m*) — the identifiers of Vasya's favourite actors.

The third line contains a single integer *n* (1 ≤ *n* ≤ 100) — the number of movies in Vasya's list.

Then follow *n* blocks of lines, each block contains a movie's description. The *i*-th movie's description contains three lines: 

* the first line contains string *s**i* (*s**i* consists of lowercase English letters and can have the length of from 1 to 10 characters, inclusive) — the movie's title,
* the second line contains a non-negative integer *d**i* (1 ≤ *d**i* ≤ *m*) — the number of actors who starred in this movie,
* the third line has *d**i* integers *b**i*, *j* (0 ≤ *b**i*, *j* ≤ *m*) — the identifiers of the actors who star in this movie. If *b**i*, *j* = 0, than Vasya doesn't remember the identifier of the *j*-th actor. It is guaranteed that the list of actors for a movie doesn't contain the same actors.

All movies have distinct names. The numbers on the lines are separated by single spaces.

## Output

Print *n* lines in the output. In the *i*-th line print: 

* 0, if the *i*-th movie will surely be the favourite;
* 1, if the *i*-th movie won't surely be the favourite;
* 2, if the *i*-th movie can either be favourite, or not favourite.
## Examples

## Input


```
5 3  
1 2 3  
6  
firstfilm  
3  
0 0 0  
secondfilm  
4  
0 0 4 5  
thirdfilm  
1  
2  
fourthfilm  
1  
5  
fifthfilm  
1  
4  
sixthfilm  
2  
1 0  

```
## Output


```
2  
2  
1  
1  
1  
2  

```
## Input


```
5 3  
1 3 5  
4  
jumanji  
3  
0 0 0  
theeagle  
5  
1 2 3 4 0  
matrix  
3  
2 4 0  
sourcecode  
2  
2 4  

```
## Output


```
2  
0  
1  
1  

```
## Note

## Note

 to the second sample: 

* Movie jumanji can theoretically have from 1 to 3 Vasya's favourite actors.
* Movie theeagle has all three favourite actors, as the actor Vasya failed to remember, can only have identifier 5.
* Movie matrix can have exactly one favourite actor.
* Movie sourcecode doesn't have any favourite actors.

Thus, movie theeagle will surely be favourite, movies matrix and sourcecode won't surely be favourite, and movie jumanji can be either favourite (if it has all three favourite actors), or not favourite.



#### tags 

#1600 #implementation 