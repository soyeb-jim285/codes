<h1 style='text-align: center;'> E. Fairy</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once upon a time there lived a good fairy A. One day a fine young man B came to her and asked to predict his future. The fairy looked into her magic ball and said that soon the fine young man will meet the most beautiful princess ever and will marry her. Then she drew on a sheet of paper *n* points and joined some of them with segments, each of the segments starts in some point and ends in some other point. Having drawn that picture, she asked the young man to erase one of the segments from the sheet. Then she tries to colour each point red or blue so, that there is no segment having points of the same colour as its ends. If she manages to do so, the prediction will come true. B wants to meet the most beautiful princess, that's why he asks you to help him. Find all the segments that will help him to meet the princess.

## Input

The first input line contains two integer numbers: *n* — amount of the drawn points and *m* — amount of the drawn segments (1 ≤ *n* ≤ 104, 0 ≤ *m* ≤ 104). The following *m* lines contain the descriptions of the segments. Each description contains two different space-separated integer numbers *v*, *u* (1 ≤ *v* ≤ *n*, 1 ≤ *u* ≤ *n*) — indexes of the points, joined by this segment. No segment is met in the description twice.

## Output

In the first line output number *k* — amount of the segments in the answer. In the second line output *k* space-separated numbers — indexes of these segments in ascending order. Each index should be output only once. Segments are numbered from 1 in the input order.

## Examples

## Input


```
4 4  
1 2  
1 3  
2 4  
3 4  

```
## Output


```
4  
1 2 3 4 
```
## Input


```
4 5  
1 2  
2 3  
3 4  
4 1  
1 3  

```
## Output


```
1  
5 
```


#### tags 

#2900 #dfs_and_similar #divide_and_conquer #dsu 