<h1 style='text-align: center;'> A. Generate plus state or minus state</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a qubit in state ![](images/c1f9019c20fc8a9610d31c36ba7860cef0b7c55c.png) and an integer *sign*. 

Your task is to convert the given qubit to state ![](images/d92593c6760aba7602b98b147630fe99f3ba55f1.png) if *sign* = 1 or ![](images/84838ca6c00c18d1930add5214964c1673061c43.png) if *sign* =  - 1.

## Input

You have to implement an operation which takes a qubit and an integer as an input and has no output. The "output" of your solution is the state in which it left the input qubit.

Your code should have the following signature:


```
namespace Solution {  
    open Microsoft.Quantum.Primitive;  
    open Microsoft.Quantum.Canon;  
  
    operation Solve (q : Qubit, sign : Int) : ()  
    {  
        body  
        {  
            // your code here  
        }  
    }  
}
```


#### tags 

#1100 #*special 