# XML Validator Using Stack in C

## Description
This program checks whether an XML file has properly nested tags.  
It reads the XML content from a file named note.xml and verifies that every opening tag has a matching closing tag in the correct order.

## How It Works
The program uses a stack data structure to keep track of opening tags.

1. When an opening tag (e.g., <tag>) is found, it is pushed onto the stack.
2. When a closing tag (e.g., </tag>) is found, the program pops the top element from the stack.
3. The popped tag is compared with the closing tag:
   - If they match, the structure is correct.
   - If they do not match, the XML is invalid.
4. After processing the entire file:
   - If the stack is empty, the XML is valid.
   - Otherwise, the XML is invalid.

## Files Included
- xml_validator.c : Main C program
- note.xml : Sample XML input file

## How to Compile and Run

gcc xml_validator.c -o main.exe
./main.exe

## Sample Output

XML is valid

## Author
Student Assignment — Data Structures / Programming Course