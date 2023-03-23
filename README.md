# Credit-Card-Number-Verifier (School Project):
This program verifies whether a credit card number is valid or not using the Luhn algorithm.

Requirements:
This program requires a C++ compiler to run.

Usage:
Compile the program using your C++ compiler of choice.
Run the compiled executable file.
Enter the credit card number you wish to verify when prompted.
The program will output whether the credit card number is valid or not.
Algorithm
This program uses the Luhn algorithm to validate the credit card number. The algorithm works as follows:

Double every second digit, starting from the rightmost digit.
If the result of a doubling operation is greater than 9, add the two digits together.
Sum up all the digits in the modified number.
If the sum is a multiple of 10, the credit card number is valid.
Limitations
This program can only validate credit card numbers that are between 13 and 16 digits long.

Future Improvements:
Future improvements to this program could include:

Adding support for more credit card types
Allowing the user to input credit card type to help narrow down the possible numbers
Implementing a GUI for a more user-friendly experience

Author:
[a1leycat]
https://github.com/a1leycat

License
This program is licensed under the MIT License.
