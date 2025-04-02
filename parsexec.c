#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "parsexec.h"
#include "locations.c"


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
      else if (strcmp(verb, "look") == 0)
      {
         doLook(noun);
      }
      else if (strcmp(verb, "go") == 0)
      {
         printf("It's too dark to go anywhere.\n");
      }
      else
      {
         printf("I don't know how to '%s'.\n", verb);
      }
   }
   return true;
}