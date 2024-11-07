<h1 style='text-align: center;'> C. Two Movies</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A movie company has released $2$ movies. These $2$ movies were watched by $n$ people. For each person, we know their attitude towards the first movie (liked it, neutral, or disliked it) and towards the second movie.

If a person is asked to leave a review for the movie, then: 

* if that person liked the movie, they will leave a positive review, and the movie's rating will increase by $1$;
* if that person disliked the movie, they will leave a negative review, and the movie's rating will decrease by $1$;
* otherwise, they will leave a neutral review, and the movie's rating will not change.

Every person will review exactly one movie — and for every person, you can choose which movie they will review.

The company's rating is the minimum of the ratings of the two movies. Your task is to calculate the maximum possible rating of the company.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($-1 \le a_i \le 1$), where $a_i$ is equal to $-1$ if the first movie was disliked by the $i$-th viewer; equal to $1$ if the first movie was liked; and $0$ if the attitude is neutral.

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($-1 \le b_i \le 1$), where $b_i$ is equal to $-1$ if the second movie was disliked by the $i$-th viewer; equal to $1$ if the second movie was liked; and $0$ if the attitude is neutral.

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print a single integer — the maximum possible rating of the company, if for each person, choose which movie to leave a review on.

## Example

## Input


```

42-1 1-1 -11-1-150 -1 1 0 1-1 1 0 0 14-1 -1 -1 1-1 1 1 1
```
## Output


```

0
-1
1
1

```


#### tags 

#1400 #greedy #math 