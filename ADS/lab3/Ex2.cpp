
/*
In this problem, we try to implement the undo/redo mechanism using two stacks.
Choose one method to implement a Stack data structure (Array-based Stack or
Stack using Linked List) to implement the above problem.

- String of characters are stored in the Stack data structure;
- If a character is popped from Undo stack, then it is immediately pushed into Redo stack; and vice-versa;

Write the main function for testing all written functions (init(), display(), push(), pop(),...).
*/

#include <iostream>
using namespace std;

/*
   Initialize Stack datatype
      string with size of 1000 chars
      int top
*/
struct _Stack
{
    string texts[1000];
    int top;
};
typedef struct _Stack Stack;

/*
pseudocode

   function init():
      initialize a new stack with top = 0
   
   function isEmpty():
      check if the stack is empty (top < 0)
   
   function size():
      return the size of the stack (top + 1)
   
   function isFull():
      check if the stack is full (top > 1000)
*/
void init (Stack *st)
{
    st->top = 0;
}
int isEmpty(Stack *st)
{
    return (st->top <= 0);
}
int size(Stack *st)
{
    return st->top + 1;
}
int isFull(Stack *st)
{
   return(st->top > 1000);
}

/* 
pseudocode

   function write():
      if the stack is full
         print "the stack is full"
      else
         top++
         insert new character into the texts array
         push the new char into undoStack

*/
void write(Stack *st, Stack *undo, char character)
{
   if(isFull(st))
   {
      cout << "The stack is full" << endl;
   }
   else
   {
      st->top++;
      undo->top++;

      st->texts[st->top] = character;
      undo->texts[undo->top] = character;
   }
}

/*
pseudocode:
   If a character is popped from Undo stack, then it is immediately pushed into
   Redo stack; and vice-versa;

   function undo(Stack *main, Stack *undo, Stack *redo):
      revert the change to the text by pop the top element
      push the character to redoStack
      pop the top element of undoStack

   function redo(Stack *main, Stack *undo, Stack *redo):
      restore changes that were undo'd by push the top element
      push the character to undoStack
      pop the top element of redoStack
   
   function displayTexts(Stack st):
      display all characters in st

*/
void undo(Stack *main, Stack *undo, Stack *redo)
{
   redo->top++;
   redo->texts[redo->top] = main->texts[main->top];
   
   undo->top--;
   main->top--;
}
void redo(Stack *main, Stack *undo, Stack *redo)
{
   main->top++;
   main->texts[main->top] = redo->texts[redo->top];

   undo->top++;
   undo->texts[undo->top] = redo->texts[redo->top];

   redo->top--;
}
void displayTexts(Stack *st)
{
   for(int i = 0; i <= st->top; i++)
   {
      cout << st->texts[i];
   }
   cout << endl;
}  

int main() 
{
   // Initialize 3 new stacks: mainText, undo, redo
   Stack *mainTexts = new Stack();
   Stack *undoStack = new Stack();
   Stack *redoStack = new Stack();

   // Write 2 characters into the mainText, as well as push them into undoStack
   write(mainTexts, undoStack, 'A');   
   write(mainTexts, undoStack, 'B');

   // Display Text: AB
   cout << "Texts before Undoing: " << endl;
   displayTexts(mainTexts);

   // Undo one character: A
   cout << "Texts after Undoing: " << endl;
   undo(mainTexts, undoStack, redoStack);
   displayTexts(mainTexts);

   // Redo one character: AB
   cout << "Texts after Redoing: " << endl;
   redo(mainTexts, undoStack, redoStack);
   displayTexts(mainTexts);

   //Free the memory
   delete mainTexts;
   delete undoStack;
   delete redoStack;

   return 0;
}