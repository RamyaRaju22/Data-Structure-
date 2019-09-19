/*to write a program that will eveluate a postfix expression using stack
RAMYA R
18BBTCS098
Function used:push, pop, main
12/09/2019
output:
 Enter Postfix Expression:53*

 Given Postfix Expression: 53*
Result after evaluation:15
*/


#include<stdio.h>
#define size 50
#include<ctype.h>
int s[size];
int top=-1;
int push(int elem)
{
 	s[++top]=elem;
}
int pop()
{
	return(s[top--]);
} 
int main()
{
	char pofx[50], ch;
	int i=0, op1, op2;
	printf("\n Enter Postfix Expression:");
	scanf("%s",pofx);
	while((ch=pofx[i++])!='\0')
	{
		if(isdigit(ch)) push(ch-'0');
		else
		{
			op2=pop();//pop into 2nd operand
			op1=pop();//pop into 1st operand
			switch(ch)
			{
				case'+':push(op1+op2);
				break;
				case'-':push(op1-op2);
				break;
				case'*':push(op1*op2);
				break;
				case'/':push(op1/op2);
				break;
			}
		}
	}
	printf("\n Given Postfix Expression: %s",pofx);
	printf("\nResult after evaluation:%d",s[top]);
}

