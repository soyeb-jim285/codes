<h1 style='text-align: center;'> G. Path Canonization</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

A path in some Unix-similar file system is given. The path consists of elements separated with characters "/". For example: "/usr/share/mysql/../tomcat6/conf/server.xml". The path starts with the root directory (i.e. starts with the character "/"). Each element means a name of file or directory, or it is one of two special elements: "." или "..". First of them stands for the current directory (for example, path "/./usr/././share" is equal to "/usr/share"). The second element ".." stands for the moving to the parent directory (for example, path "/usr/share/../lib" is equal to "/usr/lib").

You task is to convert the given path to such a path, which doesn't contain special elements "." and/or "..". If it is impossible, print "-1". The only reason for it is an attempt to move to the parent directory from the root.

## Input

The only line contains the given path. The path starts with "/" and consists of elements separated with "/". No two "/" follow one after another (consecutively). The only path which can end with "/" is the root directory path equal to "/".

Each element may contain "a"-"z", "0"-"9" and dots. Any element different from specials "." and ".." contains at least one character different from the dots.

The path length is between 1 and 1000 inclusively.

## Output

Print the required path or "-1".

## Examples

## Input


```
/usr/share/mysql/../tomcat6/conf/server.xml  

```
## Output


```
/usr/share/tomcat6/conf/server.xml  

```
  
## Input


```
/a/./././..  

```
## Output


```
/  

```
  


#### tags 

#2200 #*special 