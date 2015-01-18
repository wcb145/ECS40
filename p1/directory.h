#ifndef DIRECTORY_H
  #define DIRECTORY_H

#define MAX_CHILDREN 3
#include "permissions.h"

typedef struct Dir
{
  char *DirectoryName;
  int time; 
  struct Dir *children; // subdirectories
  int numChildren;
  struct Dir *parent; // parent directory
  Permissions *perm;
 
} Directory;

void createDirectory(Directory *newDirectory, Directory *parentDir, 
  const char *DirectoryName, int time, int umask);
void showPath(Directory *currentDirectory);
void DIRmkdir(Directory *newDirectory, Directory *parent, int numChildren, 
  char *DirectoryName, int time, int umask);
void DIRls(Directory *children, char *option, int numChildren);
void DIRcd(Directory *currentDirectory, char *target);

#endif
