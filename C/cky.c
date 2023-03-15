
#include </home/burak/Desktop/CKY/C/operations.h>

int main (void)
{
  int b;

  char *s = "abaabaaabbabbaaabababaaabbabbaaabaaba";
//  char *s = "aaaaaaaaaaaabbbbbbbbbbbb";

  char *d;
  b = cky(s);
  if (b)
  {
    d = "yes";
  }
  else
  {
    d = "no";
  }
  printf("is \"%s\" in G = %s\n", s, d);

  return 0;
}
