# $0M

This project was developed by me and my college friends as a computer lab project, and is basically a Stack-oriented programming language interpreter. The program reads commands from stdin or a file, interprets them, and prints the contents of the Stack to stdout


***List of commands:***

*Mathematical expressions*

    + - * /                 Add, subtract, multiply and divide
    ( )                     Decrement and increment a value
    %                       Module
    #                       Exponentiation
    & | ^~                  E, or, xor and not (bitwise) for integers


*Stack*
    _                       Duplicate
    ;                       Pop
    \                       Swap the top two elements of the stack
    @                       Rotate the top 3 elements of the stack
    n $                     Copy n-th element to top of stack, 0 is top of stack


*Logic*

    =                       Iqual to
    <                       Less than
    >                       Greater than
    !                       Not
    e&                      E (with shortcut)
    and|                    Or (with shortcut)
    e<                      Put the smaller of the 2 values on the stack
    e>                      Put the larger of the 2 values on the stack
    ?                       If-Then-Else