#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to represent a stack of characters
struct Stack {
int top;
unsigned capacity;
char* array;
};
// Function to create a stack with a given capacity
struct Stack* createStack(unsigned capacity) {
struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
stack->capacity = capacity;
stack->top = -1;
stack->array = (char*)malloc(stack->capacity * sizeof(char));
return stack;
}
// Function to check if the character is an operator
int isOperator(char ch) {
return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
// Function to return the precedence of an operator
int precedence(char ch) {
if (ch == '+' || ch == '-')
return 1;
if (ch == '*' || ch == '/')
return 2;
return 0;
}
// Function to push a character onto the stack
void push(struct Stack* stack, char item) {
stack->array[++stack->top] = item;
}
// Function to pop a character from the stack
char pop(struct Stack* stack) {
if (stack->top == -1)
return '\0';

return stack->array[stack->top--];
}
// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix) {
int length = strlen(infix);
struct Stack* stack = createStack(length);
int outputIndex = 0;
int i;
for ( i = 0; i < length; i++) {
char c = infix[i];
if (isalnum(c)) {
printf("%c", c); // Output operands directly
}
else if (c == '(') {
push(stack, c);
}
else if (c == ')') {
while (stack->top != -1 && stack->array[stack->top] != '(') {
printf("%c", pop(stack));
}
if (stack->top != -1 && stack->array[stack->top] != '(') {
printf("Invalid expression\n");
return;
}
else {
pop(stack);
}
}
else {
while (stack->top != -1 && precedence(c) <= precedence(stack->array[stack->top])) {
printf("%c", pop(stack));
}
push(stack, c);
}
}
// Pop any remaining operators from the stack
while (stack->top != -1) {
printf("%c", pop(stack));
}
}
int main() {
char infix_expression[100];
printf("Enter infix expression: ");
scanf("%s", infix_expression);

printf("Postfix expression: ");
infixToPostfix(infix_expression);
printf("\n");
return 0;
}
