# Concepts_of_Programming_Languages
 Repository to hold content of concepts of programming langauges content
 
 # Assignments
 ## Assignment 1
 Write the BNF grammar, in the syntax of our lecture, of an assignment statement such that:
- LHS is variable whose name is one of ```{A,B,C,D}```.
- RHS is an arithmetic expression which allows any combination of variables, parentheses, and the binary operators ```{*,<,^,%,+}``` subject to the following precedence and associativity rules:
- Parentheses have the highest precedence.
- `*` operator has the highest precedence after parentheses.
- `<` and `^` operators have equal precedence which is lower than `*`.
- `%` and `+` operators have equal precedence which is the lowest.
- The grammar should accept a statement like: `A=B%A+(B^C<A%C)*D`
 ## Assignment 2
 Get all possible subsets from given array with simulating the recursion (do not use the recursion)
 ## Assignment 3
Implement base struct Shape and derived struct Circle, Rectangle and Square simulating polymorphism without using the virtual keyword. Do not use the `C++` inheritance or polymorphism mechanisms but simulate them as described in our lecture. You are allowed to use some lecture code. Your code must be general.
Use standard `C++`, such that the following ```main()``` works. You are not allowed to modify the ```main()```.
You are not allowed to include any files or built-in libraries, except for output.
Submit your standard `C++` code in the textbox below. Do not write the ```main()``` again.

```c++
int main()
{
    Circle circle;
    CircleInitialize(&circle, 10); // circle with radius 10

    Rectangle rectangle;
    RectangleInitialize(&rectangle, 3, 5); // rectangle with width 3 and height 5

    Square square;
    SquareInitialize(&square, 7); // square with side length 7

    Shape* shapes[3];
    shapes[0]=(Shape*)&circle;
    shapes[1]=(Shape*)&rectangle;
    shapes[2]=(Shape*)&square;

    double total_area=0;

    int i;
    for(i=0;i<3;i++)
    {
        double d=GetArea(shapes[i]);
        total_area+=d;
    }
    
    cout<<total_area<<endl; // check if the value is correct

    return 0;
}
```
