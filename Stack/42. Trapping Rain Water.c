#define MIN(a,b) ((a) < (b) ? (a) : (b))

struct stack_t
{
    int *val;
    int top;
    int *index;
};

int trap(int* height, int heightSize){
    long int rsl = 0;
    int i = 0;
    long int top = 0;
    long int temp = 0;
    int distance = 0;
    struct stack_t st;
    
    if(heightSize == 0)
    {
        return rsl;
    }
    
    st.val = (int*)malloc(heightSize * sizeof(int) + 1);
    if(st.val == NULL)
    {
        return rsl;
    }
    
    st.index = (int*)malloc(heightSize * sizeof(int) + 1);
    if(st.index == NULL)
    {
        return rsl;
    }
    st.top = -1;
    
    for(i = 0; i < heightSize; i++)
    {
        while((st.top >= 0) && (height[i] > st.val[st.top]))
        {
            top = st.val[st.top];
            st.top--;
            if(st.top < 0)
            {
                break;
            }
           
            distance = i - st.index[st.top] - 1;
            temp = MIN(st.val[st.top],height[i]);
            rsl += distance * (temp - top);
        }
        st.top++;
        st.val[st.top] = height[i];
        st.index[st.top] = i;
    }
    
    free(st.val);
    free(st.index);
    return rsl;
}