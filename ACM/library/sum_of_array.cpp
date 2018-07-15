double sum(int *arr,int len){
    double result = 0;
    for (int i = 0; i < len;i++)
        result += *(arr + i);
    return result;
}