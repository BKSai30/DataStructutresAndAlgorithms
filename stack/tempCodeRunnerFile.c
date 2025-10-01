#include<stdio.h>
#include<ctype.h>// for isdigit(char) function
#include<string.h>// for strlen(string) and strcspn(string) function
int stack[200];
int top=-1;
void push(int value){
    stack[++top]=value;
}
int pop(){
    return stack[top--];
}
// you can also write a function to check if the given symbol is there in the list of symbols ( like + - * / )
int main(){
    char string[200];
    fgets(string,200,stdin);
    string[strcspn(string,"\n")]=0; // removes any newline character , but the string might still have '\0'( end of line) in it
    int n=strlen(string);
    for(int i=0;i<n;i++){
        if(isdigit(string[i])){
            push(string[i]-'0');
        }
        else if(string[i]!='\n'&&string[i]!='\0'&&string[i]!=' '){
            int o2=pop(); // the first pop(o2) would be the top most element in the stack as of that moment 
            int o1=pop();/* this pop would be the element below the o2 element 
                         now when we want to do any operation , it is the [ o1 (operator) o2 ] */
                        
            switch(string[i]){
                case '*': push(o1*o2);break;
                case '/':push(o1/o2);break;
                case '+':push(o1+o2);break;
                case '-':push(o1-o2);break;
            }
        }
    }
    printf("%d",stack[top]);/* this will print the element in stack
                            (stack if successfully done should be having only 1 element left in it at the end of all operations)*/
}
// this code works for single digit numbers like 1 2 3 4 5 6 7 8 ... and not multi digit number like 34 32 1233 
