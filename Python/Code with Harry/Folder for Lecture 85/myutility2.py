# ------------------------------------------------------------------- Lecture 85 - Creating Command Line Utility in Python -------------------------------------------------------------------------------------------------------------->
# Command Line Utility : A program designed to be run from the CLI. Examples include ls (list directory contents), grep (search text), and curl (transfer data).
# Basic Structure : Typically involves a script that can accept arguments and options.
#                 : Python’s argparse module is commonly used for this purpose.

# Parsing : Understanding and Implementing : Parsing refers to analyzing and converting input data into a usable format. When building command line utilities, parsing typically involves interpreting command line arguments and options.
#         : 'argparse' module : Simplifies the creation of command line interfaces by parsing arguments and options.
#         : Key Functions and Methods : ArgumentParser(): Initializes the parser.
#                                     : add_argument() : Defines which arguments the utility accepts
#                                                      : Positional Arguments : Required arguments (e.g., name).
#                                                      : Optional Arguments : Optional flags (e.g., -g or --greet).
#                                     : parse_args() : Parses the provided arguments.

# Detailed Explaination of Functions and Modules : ArgumentParser(description=None, ...) : A brief explanation of what the utility does, shown when using the --help flag.
#                                                : add_argument(name or flags, ..., **kwargs) : Name or flags: Defines the argument name (e.g., name) or flags for options (e.g., -g, --greet).
#                                                                                             : Type : Specifies the type of the argument (e.g., str, int).
#                                                                                             : Help : Provides a help message for the argument.
#                                                                                             : Action: Defines how the argument should be handled ('store_true' stores True if the flag is present).
#                                                : parse_args(args=None, namespace=None) : Args : Takes the list of arguments to parse (defaults to sys.argv).
#                                                                                        : Namespace : Where to store the parsed arguments (default is a new empty namespace).

# Running the Script :
# To greet : python script.py Alice -g
# To say goodbye : python script.py Alice

# Code :
import argparse

# Initialize the argument parser
parser = argparse.ArgumentParser(description="Greet or say goodbye to the user.")

# Add arguments
parser.add_argument('name', type=str, help="Your name") # here name is just a variable or a place holder and type is telling ki kis type ka data input hone vaala hai! and help ki jo input data hai vo actually hai kya its just a descriptionn of the argument which we will be passing
parser.add_argument('-g', '--greet', action='store_true', help="Greet the user") # The reason both -g and --greet are provided is to give the user flexibility in how they choose to interact with the command line utility. Whether the user types -g or --greet, the script will understand that they want to enable the greeting functionality.

# Parse arguments
args = parser.parse_args()
# When the script is run from the command line, users provide various inputs, such as positional arguments and options (e.g., python script.py Alice -greet).
# The parse_args() method is responsible for capturing these inputs and interpreting them according to the rules you defined with add_argument().
# After parsing, parse_args() returns a namespace object (stored in the args variable).
# This namespace contains all the arguments and options provided by the user, each stored as an attribute of the args object. means jo saare namespace object aaye args me vo sab save hogye and then if condition me, .greet krke if condition check hui ki agar greet hai unn namespace arguments me aur uski value true hai toh Hello print krdo nhi toh goodbye!
# How the namespace object looks like....
# args = {
#     'name': 'Alice',
#     'greet': True # Here --greet and -g used interchangebly, dono me se koi bhi likhega user usko if me true return hojayega! kyunki yahaa pr -g and --greet dono same hi hai kyunki humne arguments me usko specify kiya hua hai! so yes they both are true here!
# }
# So now the overall thing is... jab user kuch input krega cmd line pr, toh uss poori string ko parse krke using parse_args(), ek namespace object me store krliya jayega and then usko, ab jab if else condition ayegi tab if args (jisme saare namespace objects ki info stored hai, mtlb ek tarah se isko ptaa hai ki user ne kya input kiya tha isne uss poori string ko parse krliya hai!) me greet ki value true hui (mtlb ki greet hai jo user ne jo string likhi thi cmd line me) toh simply if condition execute hojayegi and vrna nhi! 

# Main functionality
if args.greet:
    print(f"Hello, {args.name}!")
else:
    print(f"Goodbye, {args.name}!")

if __name__ == "__main__":
    # Run the main functionality
    pass
# Purpose : This checks whether the script is being run directly (as opposed to being imported as a module into another script).
# __name__: This is a built-in variable in Python that represents the name of the module.
# When a script is run directly, __name__ is set to "__main__". If the script is imported as a module into another script, __name__ is set to the name of the script (or module).

# To run this and the myutility.py files, you do two things, first is that go in cmd and nagivate to this folder and then run the commands as you made them! or else directly go to the folder and then righr click and go for "open in terminal" option, and then you can run the commands and choose which utility you want to run!
# Now try creating your own command line utility!