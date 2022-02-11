#include <stdio.h>
#include <string.h>

#include "Stack.h"

int main(int argc, char **argv) {
  int i,j,value;
  STACK s;
  s.top=NULL;
  s.size=0;
  int c1=0, c2=0;

  for(i=1;i<argc;i++){
   
    for(j=0;j<strlen(argv[i]);j++){
      
      switch(argv[i][j]){
        case '{': push_s(&s,argv[i][j]); c1++; break;
        case '[': push_s(&s,argv[i][j]); c1++; break;

        case '}':
          if(s.size==0){
            c2++;
          }
          else if (s.top->data == '{'){
            if(c2==0) pop_s(&s); c1--;
          }
          else{
            c2++;
          }
          break;
            
        case ']':
          if(s.size==0){
            c2++;
          }
          else if (s.top->data == '['){
            if(c2==0) pop_s(&s); c1--;
            
          }
          else{
            c2++;
          }
        break;
      }
    }

    if(c1==0 && c2==0){
      printf("The parentheses match successfully for %s\n", argv[i]);
    }
    else{
      printf("The parentheses do not match successfully for %s\n", argv[i]);
      while(s.size!=0) {
        printf("popping %s\n", s.top);
        pop_s(&s);
      }
    }
    c1=0;
    c2=0;
  }
}

 /* if(strcmp(argv[i],"x")==0) {
        value= pop_s(&s);
          if(s.size!=0) printf("pop %d\n",value);
          else printf("The stack is empty\n");
      }
      else{
      value=atoi(argv[i]);
      push_s(&s, value);
      printf("push %d\n",value);
      }
  */