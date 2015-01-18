#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funix.h"

void cd(Funix *funix, int argCount, const char *arguments[])
{
  if(argCount == 2) //correct usage of cd
    DIRcd(funix->currentDirectory, (char *) arguments[1]);
  else // wrong usage of cd
    printf("usage: cd directoryName\n");
} // calls cd() with currentDirectory as one of its parameters

int eXit(Funix *funix, int argCount, const char *arguments[])
{
  if(argCount == 1)
    return 0;

  else
  {
    printf("usage: exit\n");
    return 1;
  } //incorrect usage of exit command

  return 0;
} // checks "exit" command, returns 0 on proper exit  

void getCommand(Funix *funix, char *command)
{
  int length;
  writePrompt(funix);
  funix->time++; // increments time every time a valid (or invalid) command is given
  if(strcmp(fgets(command, COMMAND_LENGTH, stdin), "\n") == 0)
    getCommand(funix, command);
  
  length = strlen(command) - 1;
  if(command[length] == '\n')
    command[length] = '\0'; // these three lines removes the newline (\n) character from the end

} // writes prompt and reads command

void init(Funix *funix)
{
  funix->time = 0;
  funix->umask = 0;

  Directory *rootDir = (Directory *) malloc(sizeof(Directory));
  funix->currentDirectory = rootDir;
  createDirectory(funix->currentDirectory, NULL, 
    "/", funix->time, funix->umask); // creates root directory  
  printf("Current Directory name: %s", 
    funix->currentDirectory->DirectoryName);
} // creates currentDirectory, and sets umask and time

void ls(Funix *funix, int argCount, const char *arguments[])
{
  DIRls(funix->currentDirectory, (char *) arguments[1], 
    funix->currentDirectory->numChildren);
} // calls ls() with currentDirectory as one of its parameters

void mkdir(Funix *funix, int argCount, const char *arguments[])
{

  if(argCount == 2) 
  {
    DIRmkdir(funix->currentDirectory->children, funix->currentDirectory,
      funix->currentDirectory->numChildren, (char *) arguments[1],
      funix->time, funix->umask);
  } //if proper use of mkdir function
  else //if incorrect use of mkdir
    printf("usage: mkdir directory_name\n");

} // calls mkdir() with currentDirectory as one of its parameters
  
int processCommand(Funix *funix, char *command)
{

  int j = 0, match = 0, argCount = 0;
  char *tok;
  const char *arguments[NUM_COMMANDS];
  const char *validCommands[] = {"ls","mkdir","cd","umask","exit"};
  
  tok = strtok(command, " ");

  while(tok != NULL)
  {
    arguments[argCount] = (char *) malloc(sizeof(char) * MAX_ARGUMENTS);
    strcpy((char *) arguments[argCount], tok);
    tok = strtok(NULL, " ");
    argCount++;
  } //counting the number of commands

  for(j = 0; j <= 4; j++)
  {
    if(strcmp((char *) validCommands[j], (char *) arguments[0]) == 0)
      match = 1;

    if(match == 1)
      break;
  } // for loop to determine if match was found for valid commands

  if(match == 0) // if no match, i = 5 so command not found
    j = 5;

  switch(j)
  {
    case 0:
      ls(funix, argCount, arguments);
      break;
    case 1:
      mkdir(funix, argCount, arguments);
      break;
    case 2:
      cd(funix, argCount, arguments);
      break;
    case 3:
      umask(funix, argCount, arguments);
      break;
    case 4:
      if(eXit(funix, argCount, arguments) == 0)
        return 0;

      break;
    case 5:
      printf("%s: Command not found.\n", arguments[0]);
      break;
  } // switch() statement determines which function is called

return 1;    
} // returns 0 on proper exit  

void run(Funix *funix)
{
  int exiting = 1;
  char *command = (char *) malloc(sizeof(char) * COMMAND_LENGTH);
  init(funix);
  while(exiting != 0)
  {
    getCommand(funix, command);
    exiting = processCommand(funix, command);
  } // while running funix, until a proper exit. proper exit is when eXit function returns 0
} // reads and processes commands in a loop until proper exit

void umask(Funix *funix, int argCount, const char *arguments[])
{
  int umaskVal = atoi(arguments[1]);
  if(argCount == 2)
  {
    if(umaskVal >=  1 && umaskVal <= 7) //if umask is between 1 and 7
      funix->umask = umaskVal;
    else // invalid umask value (not octal)
      printf("umask: octal must be between 0 and 7\n");
  } // checks to make sure number of arguments is correct
  else //if incorrect use of umask
    printf("usage: umask octal\n");
}  // checks "umask" command and executes it if it is proper

void writePrompt(Funix *funix)
{
  showPath(funix->currentDirectory);
  printf(" # ");
} // shows path and '#'
