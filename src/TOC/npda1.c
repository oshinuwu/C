#include <stdio.h>
#include <string.h>
#define MAX 100
#define N 5

enum states
{
  q0,
  q1,
  qf,
  dead
};

void push(char ch);
void pop();
char get_stack_top();
enum states delta(enum states, const char *, int *);
enum states determine_final_state(const char *input, int length);

struct stack
{
  char symbols[MAX];
  int top;
};
struct stack s;

int main()
{

  printf("NPDA");
  printf("\nEnter a string: ");
  char* inputs[50];
  scanf("%s",inputs);
  // printf("\nEnter a string of form a^n b^3n: ");
  // scanf("%[^\n]%*c", input);
  int n = sizeof(inputs) / sizeof(inputs[0]);
  for (int i = 0; i < n; i++)
  {
    const char *input = inputs[i];
    enum states final_state = determine_final_state(input, strlen(input));

    if (final_state == qf)
    {
      
      printf("\nThe string %s is accepted.", input);
      
    }
    else
    {
      
      printf("\nThe string %s is not accepted.", input);
      
    }

    while (s.top > -1)
    {
      pop();
    }
  }

  printf("\nName:Oshin Pant\nRoll no:23\nLab no:3-b\n Sec:A");
  getchar();
  getchar();
  return 0;
}

// Delta function for anbn
enum states delta(enum states curr_state, const char *input, int *charIndex)
{
  char st_top = get_stack_top();
  char ch = input[*charIndex];

  switch (curr_state)
  {
  case q0:
    // Push 'A's onto the stack
    if (ch == 'a')
    {
      push('A');
      (*charIndex)++;
      return q0;
    }
    if (ch == 'b')
    {
      return q1;
    }
    if (ch == '\0' && st_top == '$')
    {
      return qf;
    }
    return dead;

  case q1:
    if (st_top == 'A')
    {
      if (strlen(input) < *charIndex + 2)
      {
        
        printf("Not enough string, %d > %d", strlen(input), *charIndex + 2);
        
        return dead;
      }

      // we have enough inputs

      char ch_next = input[*charIndex + 1];
      char ch_next_next = input[*charIndex + 2];

      // if current, next and after it is b aka 3b
      if (ch == 'b' && ch == ch_next && ch_next == ch_next_next)
      {
        *charIndex += 3;

        pop();
        return q1;
      }
      else
      {
        return dead;
      }
    }
    if (ch == '\0' && st_top == '$')
    {
      pop();
      return qf;
    }
    return dead;
  case qf:
    return qf;
  default:
    return dead;
  }
}

enum states determine_final_state(const char *input, int length)
{
  enum states curr_state = q0;
  s.top = -1;

  // Initial epsilon transition: push $ as stack bottom
  push('$');

  int c = 0;
  while (1)
  {
    curr_state = delta(curr_state, input, &c);
    if (curr_state == dead || curr_state == qf)
      break;
  }

  return curr_state;
}

// Function to get stack top symbol
char get_stack_top()
{
  if (s.top == -1)
    return 'e'; // empty stack
  return s.symbols[s.top];
}

// Push function
void push(char ch)
{
  if (s.top < MAX - 1)
  {
    s.symbols[++s.top] = ch;
  }
  else
  {
    printf("\nStack Full.");
  }
}

// Pop function
void pop()
{
  if (s.top > -1)
  {
    s.symbols[s.top] = ' ';
    s.top--;
  }
  else
  {
    printf("\nStack Empty.");
  }
}

