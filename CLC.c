// Alex Nickerson - 110103310
// November 18, 2022
// Simple Calculator Program

#include <stdio.h>
#include <stdlib.h>

// Initializing functions
char show_options(char selection);
int option_B(float num1, float num2, char operation);
int option_U(float num1, char operation);
void option_E();

int main(void) {

  // Welcome Statement
  printf("Welcome to my Command-Line Calculator (CLC)\n");
  printf("Developer: Alex Nickerson\n");
  printf("Version: 1\n");
  printf("Date: November 18, 2022\n");
  printf("-------------------------------------\n\n");

  // Give the user a selection of options to choose from
  printf("Select one of the following items:\n");
  printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
  printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
  printf("A) - Advances Mathematical Operations, using variables, arrays.\n");
  printf("V) – Define variables and assign them values.\n");
  printf("E) - Exit\n");

  // Initialize variables
  float num1 = 0, num2 = 0, solution = 0, variable_value;
  char selection, operation = '_', variable_name;
  float variables[] = {0, 0, 0, 0, 0}, temp_array[] = {0,0,0,0,0};

  // Calls the show_options function to get the users selection
  selection = show_options(selection);

  // Program while run while user doesn't want to exit (option E)
  while (selection != 'E') {

    // Set variables to be used to 0 so the numbers from a previous calculation don't get saved
    num1 = 0, num2 = 0, solution = 0, operation = '_';
    
    // Set cases for the users possible selections
    switch (selection) {

    // If user selected B
    case 'B':

        printf("Please enter the first number:\n");
        // Checks for invalid input
        while (!scanf("%f", &num1)) {
          printf("Please enter a valid number.\n");
          printf("Please enter the first number:\n");
        }
      
        printf("Please enter the operation ( + , - , * , /, %, P, X, I):\n");
        // Checks for invalid input
        while (!scanf(" %c", &operation) ||
               (operation != '+' && operation != '-' && operation != '*' &&
                operation != '/' && operation != '%' && operation != 'P' &&
                operation != 'X' && operation != 'I')) {
          printf("Please enter a valid character.\n");
          printf("Please enter the operation ( + , - , * , /, %, P, X, I):\n");
        }
      
        printf("Please enter the second number:\n");
        // Checks for invalid input and makes sure if the user is dividing it can't be by 0
        while (!scanf("%f", &num2) || (num2 == 0 && operation == '/')) {
          printf("Please enter a valid non-zero number.\n");
          printf("Please enter the second number:\n");
        }

      // Calls the function to make the calculations
      solution = option_B(num1,num2,operation);
      // Show the user the result
      printf("The result is %.3f\n", solution);
      break;

    // If the user selected U
    case 'U':

        printf("Please enter the number: \n");
        // Checks for invalid input
        while (!scanf("%f", &num1)) {
          printf("Please enter a valid number.");
          printf("Please enter the number:\n");
        }
      
        printf("Please enter the operation (S, L, E, C, F): \n");
        // Checks for invalid input
        while (!scanf(" %c", &operation) ||
               (operation != 'S' && operation != 'L' && operation != 'E' &&
                operation != 'C' && operation != 'F') ||
               ((num1 < 0 && operation == 'S') || (num1 <= 0 && operation == 'L'))) {
          printf("Please enter a valid operation.");
          printf("Please enter the operation:\n");
        }

      // Calls the function to make the calculations
      solution = option_U(num1, operation);
      // Show the user the result
      printf("The result is %.3f\n", solution);
      break;

    // If the user selected A
    case 'A':

      printf("Please select your option ( B , U , E )\n");
      // Checks if the user entered an invalid input
      while (!scanf(" %c", &selection) ||
             (selection != 'B' && selection != 'U' && selection != 'E')){
        printf("Please enter a valid character.");
        printf("Please select your option ( B , U , E )\n");
      }

      if (selection == 'B') {

        // Initialize temporary value
        char temp;
        printf("Please enter the first number:\n");
        // Checks for invalid input
        while (!scanf("%f", &num1)) {
          // Gets invalid input and puts it in a temporary variable to check if it is a user defined varialbe
          scanf(" %c",&temp);
          if (temp == 'a' || temp == 'b' || temp == 'c' || temp == 'd' || temp == 'e') {
      
            // Set cases for the temporary user input
            switch (temp) {
      
            // If the user selected a
            case 'a':
              num1 = variables[0];
              break;
            // If the user selected b
            case 'b': 
              num1 = variables[1];
              break;
            // If the user selected c
            case 'c': 
              num1 = variables[2];
              break;
            // If the user selected d
            case 'd': 
              num1 = variables[3]; 
              break;
            // If the user selected e
            case 'e':
              num1 = variables[4];
              break;
            }
            break;
          }
          printf("Please enter a valid number.\n");
          printf("Please enter the first number:\n");
        }
      
        printf("Please enter the operation ( + , - , * , /, %, P, X, I):\n");
        // Checks for invalid input
        while (!scanf(" %c", &operation) ||
               (operation != '+' && operation != '-' && operation != '*' &&
                operation != '/' && operation != '%' && operation != 'P' &&
                operation != 'X' && operation != 'I')) {
          printf("Please enter a valid character.\n");
          printf("Please enter the operation ( + , - , * , /, %, P, X, I):\n");
        }
      
        printf("Please enter the second number:\n");
        // Checks for invalid input and makes sure if the user is dividing it can't be by 0
        while (!scanf("%f", &num2) || (num2 == 0 && operation == '/')) {
          scanf(" %c",&temp);
          if (temp == 'a' || temp == 'b' || temp == 'c' || temp == 'd' || temp == 'e') {
      
            // Set cases for the temporary user input
            switch (temp) {
      
            // If the user selected a
            case 'a':
              num2 = variables[0];
              break;
            // If the user selected b
            case 'b': 
              num2 = variables[1];
              break;
            // If the user selected c
            case 'c': 
              num2 = variables[2];
              break;
            // If the user selected d
            case 'd': 
              num2 = variables[3]; 
              break;
            // If the user selected e
            case 'e':
              num2 = variables[4];
              break;
            }
            if (! (operation == '/' && num2 == 0)) {
              break;
            }
          }
          printf("Please enter a valid non-zero number.\n");
          printf("Please enter the second number:\n");
        }
        // Call the function to make the calculations
        solution = option_B(num1, num2, operation);
        // Show the user the result
        printf("The result is %.3f\n", solution);
        
      } else if (selection == 'U') {

        // Initialize temporary value
        char temp;
        printf("Please enter the number: \n");
        // Checks for invalid input
        while (!scanf("%f", &num1)) {
          scanf(" %c",&temp);
          if (temp == 'a' || temp == 'b' || temp == 'c' || temp == 'd' || temp == 'e') {
      
            // Set cases for the temporary variable
            switch (temp) {
      
            // If user selected a
            case 'a':
              num1 = variables[0];
              break;
            // If user selected b
            case 'b': 
              num1 = variables[1];
              break;
            // If user selected c
            case 'c': 
              num1 = variables[2];
              break;
            // If user selected d
            case 'd': 
              num1 = variables[3]; 
              break;
            // If user selected e
            case 'e':
              num1 = variables[4];
              break;
            }
            break;
          }
          printf("Please enter a valid number.");
          printf("Please enter the number:\n");
        }
      
        printf("Please enter the operation (S, L, E, C, F): \n");
        // Checks for invalid input
        while (!scanf(" %c", &operation) ||
               (operation != 'S' && operation != 'L' && operation != 'E' &&
                operation != 'C' && operation != 'F') ||
               ((num1 < 0 && operation == 'S') || (num1 <= 0 && operation == 'L'))) {
          printf("Please enter a valid operation.");
          printf("Please enter the operation:\n");
        }
        
        // Call the function to make the calculations
        solution = option_U(num1, operation);
        // Show the user the result
        printf("The result is %.3f\n", solution);
      } else {
        // If user selected E then print a goodbye message and end the program
        printf("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!");
        // Ends the program
        return 0;
      }
      break;

    // If user selected V
    case 'V':

      printf("Enter a alphebetical character from a-e to for the variable name:\n");
      // Checks for invalid input
      while (!scanf(" %c", &variable_name) ||
             (variable_name != 'a' && variable_name != 'b' &&
              variable_name != 'c' && variable_name != 'd' &&
              variable_name != 'e')) {
        printf("Please enter a valid alphebetical character.");
        printf("Enter a alphebetical character from a-e to for the variable name:\n");
      }

      printf("Enter a number to assign to the variable:\n");
      // Checks for invalid input
      while (! scanf("%f", &variable_value)) {
        printf("Please enter a valid number.");
        // Gets invalid input
        getchar();
        printf("Please enter the number:\n");
      }
      
      // Set cases for possible variables names to assign the value to the correct position in the array
      switch (variable_name) {

      // If user selected a
      case 'a':
        // First number in array = users number
        variables[0] = variable_value;
        break;
      // If user selected b
      case 'b':
        // Second number in array = users number
        variables[1] = variable_value;
        break;
      // If user selected c
      case 'c':
        // Third number in array = users number
        variables[2] = variable_value;
        break;
      // If user selected d
      case 'd':
        // Fourth number in array = users number
        variables[3] = variable_value;
        break;
      // If user selected e
      case 'e':
        // Fifth number in array = users number
        variables[4] = variable_value;
        break;
      }
      break;

    case 'E':
      // Calls the function option_E
      option_E();
      // Ends the program
      return 0;
    }
    
    printf("Please select your option ( B , U , A , V, E )\n");
    // Checks for invalid input
    if (!scanf(" %c", &selection) ||
        (selection != 'B' && selection != 'U' && selection != 'A' &&
         selection != 'V' && selection != 'E')) {
      printf("Please enter a valid character.\n");
    }
  }

  // If option is E, show the user a goodbye message and end the program
  printf("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!\n");
  // Ends the program
  return 0;
}

char show_options(char selection) {
  while (!scanf(" %c", &selection) ||
         (selection != 'B' && selection != 'U' && selection != 'A' &&
          selection != 'V' && selection != 'E')) {
    // while the input is invalid:
    printf("Please enter a valid character.");
    printf("Please select your option ( B , U , A , V, E )\n");
  }
  return selection;
}

// Function for the option B
int option_B(float num1, float num2, char operation) {
  
  float solution;
  // Set cases for the users desired operation
  switch (operation) {

  // If user selected +
  case '+':
    solution = num1 + num2;
    break;
  // If user selected -
  case '-':
    solution = num1 - num2;
    break;
  // If user selected *
  case '*':
    solution = num1 * num2;
    break;
  // If user selected /
  case '/':
    solution = num1 / num2;
    break;
  // If user selected %
  case '%':
    solution = (int)num1 % (int)num2;
    break;
  // If user selected P
  case 'P':
    solution = pow(num1, num2);
    break;
  case 'X':
  // If user selected X
    solution = num1;
    if (num2 > num1) {
      solution = num2;
    }
    break;
  case 'I':
  // If user selected I
    solution = num1;
    if (num2 < num1) {
      solution = num2;
    }
    break;
  }
  // Return the solution to the main program
  return solution;
}

// Function for the option U
int option_U(float num1, char operation) {
  
  float solution;
  // Set cases for the users desired operation
  switch (operation) {

  // If user selected S
  case 'S':
    solution = sqrt(num1);
    break;

  // If user selected L
  case 'L':
    solution = log(num1);
    break;

  // If user selected E
  case 'E':
    solution = exp(num1);
    break;

  // If user selected C
  case 'C':
    solution = ceil(num1);
    break;

  // If user selected F
  case 'F':
    solution = floor(num1);
    break;
  }
  // Return the solution to the main program
  return solution;
}

// Function for the option E
void option_E() {
  // If option is E, show the user a goodbye message and end the program
  printf("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!");
}