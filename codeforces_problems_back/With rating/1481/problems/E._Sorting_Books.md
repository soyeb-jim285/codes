<h1 style='text-align: center;'> E. Sorting Books</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day you wanted to read something, so you went to your bookshelf to grab some book. But when you saw how messy the bookshelf was you decided to clean it up first.

 ![](images/a37803034df2ffc7e57977dbac2dfc697cd9df09.png) There are $n$ books standing in a row on the shelf, the $i$-th book has color $a_i$.

You'd like to rearrange the books to make the shelf look beautiful. The shelf is considered beautiful if all books of the same color are next to each other.

In one operation you can take one book from any position on the shelf and move it to the right end of the shelf.

What is the minimum number of operations you need to make the shelf beautiful?

## Input

The first line contains one integer $n$ ($1 \le n \le 5 \cdot 10^5$) — the number of books.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$) — the book colors.

## Output

## Output

 the minimum number of operations to make the shelf beautiful.

## Examples

## Input


```

5
1 2 2 1 3

```
## Output


```

2

```
## Input


```

5
1 2 2 1 1

```
## Output


```

1

```
## Note

In the first example, we have the bookshelf $[1, 2, 2, 1, 3]$ and can, for example: 

1. take a book on position $4$ and move to the right end: we'll get $[1, 2, 2, 3, 1]$;
2. take a book on position $1$ and move to the right end: we'll get $[2, 2, 3, 1, 1]$.

In the second example, we can move the first book to the end of the bookshelf and get $[2,2,1,1,1]$.



#### tags 

#2500 #data_structures #dp #greedy 