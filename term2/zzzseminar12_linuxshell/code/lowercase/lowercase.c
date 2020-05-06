#include <stdio.h>
#define MAXSTRING 100
 int main()
 {
 char fname[MAXSTRING];
 int c;
 FILE *ifp;
 fprintf(stdin, "\n Input a filename: ");
 scanf("%s", fname);
 ifp= fopen(fname, "rb");/* binary mode for ms-dos */
 fseek(ifp, 0L, SEEK_END);/* move to end of the file */
 fseek(ifp, -1L, SEEK_CUR);/* back up one character */
 while (ftell(ifp)> 0)
 {
 c = fgetc(ifp);/* move ahead one character
*/
 putchar(c);
 fseek(ifp, -2L, SEEK_CUR);/* back up two
characters*/
 }

 } 
