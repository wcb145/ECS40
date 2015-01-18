#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directory.h"

void createDirectory(Directory *newDirectory, Directory *parentDir, 
  const char *DirectoryName, int time, int umask)
{
  newDirectory->DirectoryName = (char *) malloc(strlen(DirectoryName) + 1);
  strcpy(newDirectory->DirectoryName, DirectoryName);
  newDirectory->time = time;
  newDirectory->perm = (Permissions *) malloc(sizeof(Permissions));
  createPermissions(newDirectory->perm, umask);
  newDirectory->parent = parentDir;
  newDirectory->numChildren = 0; 
  
} // creates a directory, used in init() function in funix.cpp

void showPath(Directory *currentDirectory)
{
  //printf("%s", (*funix).currentDirectory->DirectoryName);
}  // shows the path of the current Directory

void DIRmkdir(Directory *newDirectory, Directory *parent, int numChildren, 
  char *DirectoryName, int time, int umask)
{  
  if(numChildren > 0) 
  {
    free(newDirectory);
  } // no subdirectories, numChildren == 0 

  if(numChildren < MAX_CHILDREN)
  {
    numChildren++;
    newDirectory = (Directory *) malloc(sizeof(Directory) * numChildren);
    createDirectory(newDirectory, parent, DirectoryName, time, umask);
  } // checks that there are not just too many subdirs
  else 
  {
    printf("mkdir ");
    showPath(parent);
    printf("already contains the maximum number of directories\n");
  } // if 3 subdirs exist already
   
} // creates new directory

void DIRls(Directory *children, char *option, int numChildren)
{
  int i;
  if(numChildren == 0) // if no children directories
    printf("\n");

  if(numChildren > 0)
  {
    for(i = 0; i <= numChildren; i++)
      printf("%s\n", children[i].DirectoryName);
  } // if there are subdirs
} // processes the ls command and displays the directories

void DIRcd(Directory *currentDirectory, char *target)
{
  
} // changes to target directory
