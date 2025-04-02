#include <stdbool.h>
#include <stdio.h>
#include "parsexec.h"
#include "parsexec.c"

static char input[100] = "look around";

static bool getInput(void)
{
   printf("\n--> ");
   return fgets(input, sizeof input, stdin) != NULL;
}

int main()
{
   printf("You wake up. Its a small room, a basket of dirty clothes holds the bathroom door open.\n");
   printf("The blind is down but the sunlight hits your eyes just as you sit up, not nice.\n");
   printf("A phone on the small table to your left plays music very quietly.\n");
   while (parseAndExecute(input) && getInput());
   printf("\nBye!\n");
   return 0;
}