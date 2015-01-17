#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directory.h"


void createDirectory(char *DirectoryName, int time, int umask, 
  Directory *newDirectory, Directory *parentDir)
{
  DirectoryName = (char *) malloc(strlen(DirectoryName) + 1);
  strcpy(newDirectory->DirectoryName, DirectoryName);
  newDirectory->time = time;
  newDirectory->perm = (Permissions *) malloc(sizeof(Permissions));
  createPermissions(newDirectory->perm, umask);
  newDirectory->parent = parentDir;
  newDirectory->numSubDirs = 0; 
} // creates a directory, used in init() function in funix.cpp

void showPath(Directory *currentDirectory)
{
  //printf("%s", (*funix).currentDirectory->DirectoryName);
}  // shows the path of the current Directory

void DIRmkdir(Directory *subDir, char *DirectoryName)
{
   
  subDir = (Directory *) malloc(sizeof(Directory));i
  
} // creates new directory

void DIRls(Directory *currentDirectory, char *option)
{
  
} // processes the ls command and displays the directories

void DIRcd(Directory *currentDirectory, char *target)
{
  
} // changes to target directory
