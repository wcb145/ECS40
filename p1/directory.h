#ifndef DIRECTORY_H
  #define DIRECTORY_H

#define MAX_CHILDREN 3
#include "permissions.h"

typedef struct Dir
{
  char *DirectoryName;
  int time; 
  Dir *children; // subdirectories
  int numSubDirs;
  Dir *parent; // parent directory
  Permissions *perm;
 
} Directory;

#include "funix.h"

void createDirectory(char *DirectoryName, int time, int umask,
  Directory *newDirectory, Directory *parentDir);
void showPath(Directory *currentDirectory);
void DIRmkdir(Directory *parentDir, char *DirectoryName);
void DIRls(Directory *currentDirectory, char *option);
void DIRcd(Directory *currentDirectory, char *target);

#endif
