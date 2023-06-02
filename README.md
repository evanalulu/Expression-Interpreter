# Expression Interpreter

The Expression Interpreter is a command-line tool developed in C for parsing and evaluating mathematical expressions. It supports a variety of arithmetic and bitwise operations and binary and hexadecimal numbers, providing a flexible and efficient solution for evaluating complex mathematical expressions.

## Features
- Parsing: The interpreter uses a recursive descent parsing technique to parse expressions defined in an extended Backus-Naur Form (EBNF). It supports operators such as addition, subtraction, multiplication, division, bitwise AND/OR/XOR, logical NOT, and bit shifting.
- Evaluation: Once parsed, the expressions are evaluated using a depth-first search algorithm on the parse tree, providing accurate results for the given expressions.
- Command-Line Interface: The interpreter provides a simple command-line interface for inputting expressions and specifying additional options such as the number base and width for displaying the result.
- Customization: The interpreter can be easily extended to support additional operators or functionality by modifying the parsing and evaluation logic.

## Getting Started
To use the Expression Interpreter, follow these steps:
1. Clone the repository to your local machine.
2. Compile the source code using a C compiler.
3. Run the compiled binary with the desired expression and options.

## Examples
Here are some examples of expressions that can be evaluated using the Expression Interpreter:
- Arithmetic expression: "2 * (3 + 4)"
- Bitwise expression: "5 & 3 | 7 ^ 2"
- Unary operation: "-8 + ~4"

## Usage
The Expression Interpreter accepts the following command-line arguments:
- `-e "expr"`: Specifies the expression to be evaluated. Replace `"expr"` with your desired expression enclosed in quotes.
- `-b`: (Optional) Specifies the base for the output result. By default, the base is set to 10. You can change it to 2 for binary or 16 for hexadecimal output.
- Decimal or hexadecimal numbers in the expression can be formatted with the prefix `0b` and `0x` respectively.

`./prog -e "2 * (3 + 4)" -b 2` will evaluate the expression `2 * (3 + 4)` and display the result in the specified base 2.

## License

This project is licensed under the MIT License.

## Acknowledgments

This project was developed as part of my coursework (CS221 at USFCA). Special thanks to Professor Phil Peterson for guidance and support.


