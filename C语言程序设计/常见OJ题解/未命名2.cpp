#include<stdio.h>
int shunum[10000];
float money[10000];
int numz[10000];
int numf[10000];
int numl[10000];
int main()
{
 int jishu = 0;
 for (int i = 0; i < 10000; i++)
 {
  scanf("%d", &shunum[i]);
  if (shunum[i] == 0)
  {
   jishu = i;
  }
  else 
  {
   for (int j = 0; j < shunum[i]; j++)
   {
    scanf("%f", &money[j]);
    if (money[j] > 0)
    {
     numz[i]++;
    }
    else if (money[j] == 0)
    {
     numl[i]++;
    }
    else if (money[j] < 0)
    {
     numf[i]++;
    } 
   }
  }
  for (int j = 0; j < jishu; j++)
  {
   printf("%d %d %d\n", numf[j], numl[j], numz[j]);
  }
 }
}