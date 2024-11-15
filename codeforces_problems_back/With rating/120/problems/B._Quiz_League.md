<h1 style='text-align: center;'> B. Quiz League</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A team quiz game called "What? Where? When?" is very popular in Berland. The game is centered on two teams competing. They are the team of six Experts versus the team of the Audience. A person from the audience asks a question and the experts are allowed a minute on brainstorming and finding the right answer to the question. All it takes to answer a typical question is general knowledge and common logic. The question sent be the audience are in envelops lain out in a circle on a round table. Each envelop is marked by the name of the asker's town. Each question is positioned in a separate sector. In the centre of the table is a spinning arrow. Thus, the table rather resembles a roulette table with no ball but with a spinning arrow instead. The host sets off the spinning arrow to choose a question for the experts: when the arrow stops spinning, the question it is pointing at is chosen. If the arrow points at the question that has already been asked, the host chooses the next unanswered question in the clockwise direction. Your task is to determine which will be the number of the next asked question if the arrow points at sector number *k*.

## Input

The first line contains two positive integers *n* and *k* (1 ≤ *n* ≤ 1000 and 1 ≤ *k* ≤ *n*) — the numbers of sectors on the table and the number of the sector where the arrow is pointing. The second line contains *n* numbers: *a**i* = 0 if the question from sector *i* has already been asked and *a**i* = 1 if the question from sector *i* hasn't been asked yet (1 ≤ *i* ≤ *n*). The sectors are given in the clockwise order, the first sector follows after the *n*-th one.

## Output

Print the single number — the number of the sector containing the question the experts will be asked. It is guaranteed that the answer exists, that is that not all the questions have already been asked.

## Examples

## Input


```
5 5  
0 1 0 1 0  

```
## Output


```
2  

```
## Input


```
2 1  
1 1  

```
## Output


```
1  

```


#### tags 

#1100 #implementation 