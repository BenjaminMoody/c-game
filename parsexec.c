#include <stdbool.h> // me libraries
#include <stdio.h>
#include <string.h>
#include "parsexec.h"
#include "locations.h"
#include "locations.c"

//function to parse and execute the user input
//this function takes the input and splits it into a verb and a noun, it then checks if the verb is valid and executes the corresponding function
//if the verb is not valid it prints an error message
bool parseAndExecute(char *input)
{
   char *verb = strtok(input, " \n");
   char *noun = strtok(NULL, " \n");
   if (verb != NULL)
   {
      
      if (strcmp(verb, "quit") == 0)
      {
         return false;
      }
      else if (strcmp(verb, "go") == 0)
      {
         doGo(noun);
      }
      else if (strcmp(verb, "grab") == 0)
      {
         doGrab(noun);
      }
      else if (strcmp(verb, "talk") == 0)
      {
         doTalk(noun);
      }
      else
      {
         printf("\nWhat even is '%s'.\n", verb);
      }
   }
   return true;
}