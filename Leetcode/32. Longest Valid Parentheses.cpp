int longestValidParentheses(char* s) {
    int stack[100000];
    int top=-1;
    stack[++top]=-1;
    int max=0;
    
    for(int i=0;s[i];i++){
        if(s[i]=='(') stack[++top]=i;
        else{
            top--;
            if(top==-1) stack[++top]=i;
            else{
                int len=i-stack[top];
                if(len>max) max=len;
            }
        }
    }
    return max;
}
