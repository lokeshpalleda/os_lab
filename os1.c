#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(){
char buff[100];
DIR *dirp;
struct dirent *dptr;
printf("\n\nEnter directory name:");
scanf("%s",buff);
dirp=opendir(buff);
if(dirp==NULL){
	printf("the given directory does not eists.\n");
	exit(1);
}
printf("contents of directory %s:\n",buff);
while((dptr=readdir(dirp))!=NULL){
	printf("%s\n",dptr->d_name);
}
closedir(dirp);
return 0;
}
