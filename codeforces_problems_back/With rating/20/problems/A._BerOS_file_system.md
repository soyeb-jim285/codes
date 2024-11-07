<h1 style='text-align: center;'> A. BerOS file system</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

The new operating system BerOS has a nice feature. It is possible to use any number of characters '/' as a delimiter in path instead of one traditional '/'. For example, strings //usr///local//nginx/sbin// and /usr/local/nginx///sbin are equivalent. The character '/' (or some sequence of such characters) at the end of the path is required only in case of the path to the root directory, which can be represented as single character '/'.

A path called normalized if it contains the smallest possible number of characters '/'.

Your task is to transform a given path to the normalized form.

## Input

The first line of the input contains only lowercase Latin letters and character '/' — the path to some directory. All paths start with at least one character '/'. The length of the given line is no more than 100 characters, it is not empty.

## Output

The path in normalized form.

## Examples

## Input


```
//usr///local//nginx/sbin  

```
## Output


```
/usr/local/nginx/sbin  

```


#### tags 

#1700 #implementation 