<h1 style='text-align: center;'> F. Oppa Funcan Style Remastered</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Surely you have seen insane videos by South Korean rapper PSY, such as "Gangnam Style", "Gentleman" and "Daddy". You might also hear that PSY has been recording video "Oppa Funcan Style" two years ago (unfortunately we couldn't find it on the internet). We will remind you what this hit looked like (you can find original description [here](http://acm.timus.ru/problem.aspx?space=1&num=2107&locale=en)):

On the ground there are $n$ platforms, which are numbered with integers from $1$ to $n$, on $i$-th platform there is a dancer with number $i$. Further, every second all the dancers standing on the platform with number $i$ jump to the platform with the number $f(i)$. The moving rule $f$ is selected in advance and is not changed throughout the clip.

The duration of the clip was $k$ seconds and the rule $f$ was chosen in such a way that after $k$ seconds all dancers were in their initial positions (i.e. the $i$-th dancer stood on the platform with the number $i$). That allowed to loop the clip and collect even more likes.

PSY knows that enhanced versions of old artworks become more and more popular every day. So he decided to release a remastered-version of his video.

In his case "enhanced version" means even more insanity, so the number of platforms can be up to $10^{18}$! But the video director said that if some dancer stays on the same platform all the time, then the viewer will get bored and will turn off the video immediately. Therefore, for all $x$ from $1$ to $n$ $f(x) \neq x$ must hold.

Big part of classic video's success was in that looping, so in the remastered version all dancers should return to their initial positions in the end of the clip as well.

PSY hasn't decided on the exact number of platforms and video duration yet, so he asks you to check if there is a good rule $f$ for different options.

## Input

In the first line of input there is one integer $t$ ($1 \le t \le 10^{4}$) — the number of options for $n$ and $k$ to check.

In the next $t$ lines the options are given: each option is described with two integers $n$ and $k$ ($1 \le n \le 10^{18}$, $1 \le k \le 10^{15}$) — the number of dancers and the duration in seconds.

It is guaranteed that the number of different values of $k$ in one test is not greater than $50$.

## Output

Print $t$ lines. If the $i$-th option of the video is feasible, print "YES" (without quotes) in $i$-th line, otherwise print "NO" (without quotes).

## Example

## Input


```
3  
7 7  
3 8  
5 6  

```
## Output


```
YES  
NO  
YES  

```


#### tags 

#3300 #graphs #math #number_theory #shortest_paths 