#include <stdio.h>
#include <string.h>

int main ()
{
   char str1[15];
   char str2[15];
   int ret;


   strcpy(str1, "bcdef");
   strcpy(str2, "bdDEF");

   ret = strcmp(str1, str2);
   // 依次比较，获取不一样的字符的差值
   printf("ret: %d\n", ret);
   if(ret < 0)
   {
      printf("str1 小于 str2");
   }
   else if(ret > 0) 
   {
      printf("str2 小于 str1");
   }
   else 
   {
      printf("str1 等于 str2");
   }
   
   return(0);
}