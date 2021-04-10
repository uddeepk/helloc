#include <stdio.h>

int main()
{
  char c;
  int nc[256] ;
  for ( int i = 0 ; i < 256 ; ++i )
    nc[i] = 0;

  while ( (c = getchar()) != EOF) {
    ++nc[c];
  }

  for ( int i = 0 ; i < 256 ; ++i) {
    if(nc[i] != 0) {
      if(i == '\0')
	printf("\\0");
      else if(i == ' ')
	printf("[space]");
      else if(i == '\t')
	printf("\\t");
      else if(i == '\n')
	printf("\\n");
      else
	printf("%c",i);
      printf("\t%d\n", nc[i]);
    }
  }
  return 0;
}
