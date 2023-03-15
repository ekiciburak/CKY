#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
char *S[] = {"AC", "AB", NULL};
char *A[] = {"a", NULL};
char *B[] = {"b", NULL};
char *C[] = {"SB", NULL};
*/

char *S[] = {"CA", "DB", "AA", "BB", "a", "b", NULL};
char *A[] = {"a", NULL};
char *B[] = {"b", NULL};
char *C[] = {"AS", NULL};
char *D[] = {"BS", NULL};

char **(T[50][50]) = {NULL};
#define size 500

int lenc (char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; i++);
  return i;
}

int lencA (char *s[])
{
  int i;
  for (i = 0; s[i] != NULL; i++);
  return i;
}

char * clear (char *s)
{
  int l1 = 0;
  l1 = lenc(s);

  for (size_t i = 0; i < l1; i++)
  {
    s[i] = '\0';
  }
  return s;
}

char ** cleardp (char *s[])
{
  int l1 = 0;
  l1 = lencA(s);

  for (size_t i = 0; i < l1; i++)
  {
    *(s+i) = NULL;
  }
  return s;
}

void printdp (char **p)
{
  for (size_t i = 0; p[i]; i++)
  {
    printf("%s ", p[i]);   
  }  
  printf("\n"); 

}

int isIn (char *sa[], char *s)
{
  int k = 0;
  int l = lencA(sa);
  for (size_t i = 0; i < l; i++)
  {
    if(strcmp(sa[i], s) == 0)
    {
      k = 1;
      break;
    }
  }
  return k;
}

char* app (char *s1, char *s2)
{
  int l1 = 0;
  int l2 = 0;
  l1 = lenc(s1);
  l2 = lenc(s2);
  int j = 0;

  char *s = (char *) malloc((l1+l2+1) * sizeof(char));
  s = clear(s);

  if(l1 == 0)
    s = s2;
  else if (l2 == 0)
    s = s1;
  else
  {
    for (size_t i = 0; i < l1+l2; i++)
    {
      if(i < l1)
        s[i] = s1[i];
      else
      {
        s[i] = s2[j];
        j++;
      }
    } 
    return s;
  }
}

char ** append (char *s1[], char *s2[])
{
  int l1 = 0;
  int l2 = 0;
  l1 = lencA(s1);
  l2 = lencA(s2);
  int j = 0;

  char **s = (char **) malloc((l1+l2+1) * sizeof(char*));
  s = cleardp(s);

  if(l1 == 0)
    s = s2;
  else if(l2 == 0)
    s = s1;
  else
  {
    for (size_t i = 0; i < l1+l2; i++)
    {
      if(i < l1)
        *(s+i) = s1[i];
      else
      {
        *(s+i) = s2[j];
        j++;
      }
    } 
  }
  return s;
}

char ** concat (char *s1[], char *s2[])
{
  int l1 = 0;
  int l2 = 0;
  l1 = lencA(s1);
  l2 = lencA(s2);
  int k = 0;

  char **s = (char **) malloc((l1*l2+1) * sizeof(char*));
  s = cleardp(s);

  for (size_t i = 0; i < l1; i++)
  {
    for (size_t j = 0; j < l2; j++)
    {
      *(s+k) = app(s1[i], s2[j]);
      k++;
    }
  }
  return s;
}

char ** removeDups (char *s1[])
{
  int l1 = 0;
  l1 = lencA(s1);
  int k = 0;

  char **s = (char **) malloc((l1+1) * sizeof(char*));
  s = cleardp(s);

  for (size_t i = 0; i < l1; i++)
  {
    if(!isIn(s,s1[i]))
    {
      *(s+k) = s1[i];
      k++;
    }
  }
  return s;
}

char ** search (char *s1)
{
  int k = 0;
  int lS = 0;
  int lA = 0;
  int lB = 0;
  int lC = 0;
  int lD = 0;

  lS = lencA(S);
  lA = lencA(A);
  lB = lencA(B);
  lC = lencA(C);
  lD = lencA(D);

/*
  char *u1 = "S";
  char *u2 = "A";
  char *u3 = "B";
  char *u4 = "C";
  char *u5 = "D";
*/

  char **s = (char **) malloc(50* sizeof(char*));
  s = cleardp(s);

  for (size_t i = 0; i < lS; i++)
  {
    if(strcmp(s1, S[i]) == 0)
    {
      *(s+k) = "S";
      k++;
    }
  }

  for (size_t i = 0; i < lA; i++)
  {
    if(strcmp(s1, A[i]) == 0)
    {
      *(s+k) = "A";
      k++;
    }
  }

  for (size_t i = 0; i < lB; i++)
  {
    if(strcmp(s1, B[i]) == 0)
    {
      *(s+k) = "B";
      k++;
    }
  }

  for (size_t i = 0; i < lC; i++)
  {
    if(strcmp(s1, C[i]) == 0)
    {
      *(s+k) = "C";
      k++;
    }
  }

  for (size_t i = 0; i < lD; i++)
  {
    if(strcmp(s1, D[i]) == 0)
    {
      *(s+k) = "D";
      k++;
    }
  }

  return s;

}

char * toString (char c)
{
  char *s = (char *) malloc(2*sizeof(char*));
  s = clear(s);

  switch (c)
  {
    case 'a':
      s = "a";
      break;
    case 'b':
      s = "b";
      break;  
    default:
      printf("Error! operator is not correct");  
  }
  return s;
}

void copyContent (char **d, char **s)
{
  int l = lencA(s);
  for (size_t i = 0; *(s+i) != NULL; i++)
  {
    *(d+i) = *(s+i);
  } 
}

int cky (char *s)
{
  int l = 0;
  int l2 = 0;
  int index = 0;
  l = lenc(s);
  index = l+1;

  int b = 0;
  int k = 0;

  char **ACC = (char **) malloc(size* sizeof(char*));
  ACC = cleardp(ACC);

  char **ACC1 = (char **) malloc(size* sizeof(char*));
  ACC1 = cleardp(ACC1);

  char **ACC2 = (char **) malloc(size* sizeof(char*));
  ACC2 = cleardp(ACC2);

  char **BCC = (char **) malloc(size* sizeof(char*));
  BCC = cleardp(BCC);

  printf("length of %s = %d\n", s, l);

  for (size_t i = 0; i < l; i++) 
  {
    T[i][i+1] = search(toString(s[i]));
  }

  for (int u = 2; u < index; u++) 
  {
    for (int m = 0; m < index-u; m++) 
    {

      ACC = cleardp(ACC);
      for (int i = 1; i < u; i++) 
      {
        BCC = concat(T[m][m+i], T[m+i][m+u]);
        copyContent(ACC, append(ACC, BCC));
      }
      ACC2 = cleardp(ACC2);
      for (int i = 0; ACC[i] != NULL; i++) 
      {
        ACC1 = search(ACC[i]);
        if(ACC1[0] != NULL)
        {
          copyContent(ACC2, append(ACC2, ACC1));
          ACC1 = cleardp(ACC1);
        }
      }
      k = lencA(ACC2);
      T[m][m+u] = ACC2;
      ACC2 = ACC2+((k+1)*sizeof(char));
    }
  }
  printf("list of non-terminals generating s: ");
  printdp(T[0][l]);
  b = isIn(T[0][l], "S");
  return b;
}

