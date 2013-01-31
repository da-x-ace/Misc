#include <stdio.h> 
main() 
{ 
  int flag=0; 
  int i; 
  int c,prev; 
  int chars[26]; 
  for(i=0;i<26;i++) 
    chars[i]=0; 
 while((c=getchar())!=EOF) 
 { 
  if(flag==0) 
  { 
    prev=c; 
    flag=1; 
  } 
 if(c==prev) 
 { 
  if(c>='a' && c<='z') 
     ++chars[c-'a']; 
 } 
 else{ 
  printf("%d %c ", chars[prev-'a'],prev); 
  chars[prev-'a']=0; 
  if(c>='a' && c<='z') 
     ++chars[c-'a']; 
 } 
 prev=c; 
} 
} 
