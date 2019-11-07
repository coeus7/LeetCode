struct stack {
        char *stack;
        int top;
    };

bool isValid(char * s){
    struct stack st;
    int len;
    
    st.top = -1;
    len = strlen(s);
    
    st.stack = (char*)malloc(len + 1);
    
    memset(st.stack,'a',len+1);
   
    while(s && *s != '\0')
    {
        if((*s == '(') || (*s == '[') || (*s == '{'))
        {
            st.top += 1;
            if((st.top >= 0) && (st.top < len))
                st.stack[st.top] = *s;
        }
        else
        {
            if(st.top == -1)
            {
                free(st.stack);
                return 0;
            }
            switch(*s)
            {    
                case ')':
                    if(st.stack[st.top] != '(')
                     {
                        free(st.stack);
                        return 0;
                    }
                    else
                    {
                        st.stack[st.top] = 'a';
                        st.top -= 1;
                    }
                    break;
                    
                case ']':
                    if(st.stack[st.top] != '[')
                    {
                        free(st.stack);
                        return 0;
                    }
                    else
                    {
                        st.stack[st.top] = 'a';
                         st.top -= 1;
                    }
                    break;
                    
                case '}':
                    if(st.stack[st.top] != '{')
                     {
                        free(st.stack);
                        return 0;
                    }
                    else
                    {
                        st.stack[st.top] = 'a';
                        st.top -= 1;
                    }
                    break;
                default:
                    break;
            }
        }
        s++;
    }
    
    free(st.stack);
    
    if(st.top == -1)
    {
        return 1;
    }
    else
    {
         return 0;
    }

}