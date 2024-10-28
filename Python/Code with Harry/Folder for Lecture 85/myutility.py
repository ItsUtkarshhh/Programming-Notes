# ------------------------------------------------------------------- Lecture 85 - Creating Command Line Utility in Python -------------------------------------------------------------------------------------------------------------->
# Command Line Utility : A program designed to be run from the CLI. Examples include ls (list directory contents), grep (search text), and curl (transfer data).
# Basic Structure : Typically involves a script that can accept arguments and options.
#                 : Python’s argparse module is commonly used for this purpose.

# Creating a command-line utility in Python can be simple and straightforward using the argparse module, which is part of Python's standard library. Here is a step-by-step guide to create a basic command-line utility.
# Step 1 : Create a new Python file for your utility, e.g., my_utility.py.
# Step 2 : Import the argparse module to handle command-line arguments.
# Step 3 : Create a function to encapsulate your script’s main logic.
# Step 4 : Use argparse to define what command-line arguments your utility accepts.
# Step 5 : Use a standard Python if __name__ == "__main__": block to call your main function.

# Example : A Simple calculator utility!
import argparse

def main():
    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Simple Calculator")

    # Add arguments for the two numbers and the operation
    parser.add_argument("num1", type=float, help="First number")
    parser.add_argument("num2", type=float, help="Second number")
    parser.add_argument(
        "operation", 
        type=str, 
        choices=["add", "subtract", "multiply", "divide"], 
        help="Operation to perform"
    )

    # Parse the arguments
    args = parser.parse_args()

    # Perform the requested operation
    if args.operation == "add":
        result = args.num1 + args.num2
    elif args.operation == "subtract":
        result = args.num1 - args.num2
    elif args.operation == "multiply":
        result = args.num1 * args.num2
    elif args.operation == "divide":
        if args.num2 == 0:
            result = "Error: Division by zero is not allowed"
        else:
            result = args.num1 / args.num2

    # Print the result
    print(f"The result is: {result}")

if __name__ == "__main__":
    main()

# Explaination of all methods and arguments and their meanings :
# Parser : A parser is a tool or a piece of code that takes input (like text, commands, or code) and analyzes its structure. In simpler terms, it reads the input and makes sense of it by breaking it down into manageable parts.
# The argparse.ArgumentParser in Python is an object that helps you define the structure of the command-line arguments your program expects. It then processes (or parses) the actual arguments provided by the user when they run the program.

# Parsing : Parsing is the process of analyzing a string of symbols, either in natural language or in computer languages. The goal is to convert this string into a structured format that a program can understand and work with.
# When you use parser.parse_args(), the argparse module takes the command-line arguments given by the user, breaks them down according to the definitions you provided with add_argument, and stores them in a structured format (usually a namespace object). This allows your program to access and use these arguments easily.

# argparse.ArgumentParser() :
# What it does : When you use parser.parse_args(), the argparse module takes the command-line arguments given by the user, breaks them down according to the definitions you provided with add_argument, and stores them in a structured format (usually a namespace object). This allows your program to access and use these arguments easily.
# Arguments : description (optional) : A brief description of what your program does. This is shown when the user uses the --help option.
# Returns : An ArgumentParser object which you can use to add arguments and parse the command line.

# add_argument() :
# What it does : Adds an argument to the parser object. Each argument you add defines what the command line input should look like.
# Arguments : name or flags : The name of the argument. If it doesn't start with a dash, it's a positional argument. If it starts with a dash, it's an optional argument.
# type : The type of the argument (e.g., int, float, str). It converts the input value to this type.
# help (optional) : A brief description of what this argument is.
# choices (optional) : A list of valid values that this argument can take (useful for limiting input to specific options).
# Example : parser.add_argument("num1", type=float, help="First number")

# parse_args() :
# What it does : Parses the command line arguments according to the arguments defined with add_argument(). It checks if the input provided matches the expected types and formats.
# Returns : An object containing the parsed arguments as attributes.
# Example : args = parser.parse_args()

# Now, we have just wrote the if-else conditions ki aisa ho toh aisa krdo and aisa ho toh aisa krdo! and then usko result me store krke print do command line me!

# if __name__ = "__main__" : Checks if the script is being run directly (not imported as a module). If true, it runs the code inside the block.
# Returns : None. It just runs the code within the block if the condition is met.

# There are more variations of commands we can make for command line utility! using argparse module!
# try it out!