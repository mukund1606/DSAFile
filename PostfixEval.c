//Postfi Eval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define arrSize 100

struct Node{
  struct Node* left;
  char value;
  struct Node* right;
};
typedef struct Node node;

struct Stack{
  unsigned int size;
  int top;
  node **arr;
};
typedef struct Stack stack;

int getSize(char arr[]){
  int i = 0;
  while(arr[i] != '\0'){
    i++;
  }
  return i;
}


stack * createStack(unsigned int size){
  stack * st = (stack *)malloc(sizeof(stack));
  st->size = size;
  st->top = -1;
  st->arr = (node **)malloc(size*sizeof(node));
  return st;
}

void push(stack *st, node *elem){
  st->top++;
  st->arr[st->top] = elem;
}

node * pop(stack *st){
  node * temp;
  if(st->top == -1){
    return NULL;
  }
  else{
    temp = st->arr[st->top];
    st->top--;
    return temp;
  }
}

void display(node *elem){
  if(elem != NULL){
    if(elem->left && elem->right){
      printf("(");
      display(elem->left);
      printf("%c", elem->value);
      display(elem->right);
      printf(")");
    }
    else{
      display(elem->left);
      printf("%c", elem->value);
      display(elem->right);
    }
  }
}

int operator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
    return 1;
  }
  else{
    return 0;
  }
}

stack * postEval(char infix[], unsigned int size){
  stack *st;
  node *a, *b, *temp;
  int i;
  st = createStack(size);
  for(i = 0; infix[i] != '\0'; i++){
    if(operator(infix[i]) == 0){
      temp = (node *)malloc(sizeof(node));
      temp->value = infix[i];
      temp->left = temp->right = NULL;
      push(st, temp);
    }
    else if(operator(infix[i]) == 1){
      a = pop(st);
      b = pop(st);
      temp = (node *)malloc(sizeof(node));
      temp->value = infix[i];
      temp->left = b;
      temp->right = a;
      push(st, temp);
    }
  }
  return st;
}

int main(){
  char postfix[arrSize];
  stack *infix;
  int size, i;
  printf("Enter Postfix Expression:");
  gets(postfix);
  size = getSize(postfix);
  infix = postEval(postfix, size);
  display(pop(infix));
  getch();
  clrscr();
  return 0;
}