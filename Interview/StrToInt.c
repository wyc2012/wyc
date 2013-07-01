/*
*输入正负数的考虑
*只输入正负号的考虑
*超过int范围的考虑
*/
enum Status {kValid, kInvalid};//有效与否
Status g_valid = kValid;
int StrToInt(char* str)
{
    g_valid = kInvalid;
    long long result = 0;
    int fushu = 0;
    if(str == 0 || *str == '\0')
    {
        return 0;
    }
    if(str[0] == '-')
    {
        fushu = 1;
        str++;
    }
    else if(str[0] == '+')
    {
        fushu = 0;
        str++;
    }
    if(*str == '\0')
    {
        return 0;
    }
    while(str != '\0')
    {
        if(*str < '0' || *str > '9')
        {
            result = 0;
            break;
        }
        result = result * 10 + (fushu ? -1 : 1) * (*str - '0');
        if((!fushu && result > 0x7FFFFFFF)
           && (fushu && result < (signed int)0x80000000))
        {
            result = 0;
            break;
        }
        str++;
    }
    if(*str == '\0')
    {
        g_valid = kValid;
    }
    if(fushu)
        return -1 * result;
    else
        return result;
}
