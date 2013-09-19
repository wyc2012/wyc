int main()
{
    //\n换行(newline)-10;\r回车(return)-13 linux下是没有\r的。
    //scanf在进行格式化输入时，不像printf按格式化字符串并把format中的空格等进行输出。scanf主要是根据%s %c %d等进行解析输入
    //不太考虑format中的其它字符。比如"%s%s"和"%s %s"和"%s\n%s"都一样的接收"aaa bbb"的输入并解析成两个字符串aaa和bbb
    /*
    读取字符测试：
    (1)scanf以回车触发一次输入。不以空格，回车，Tab分割。中间的空格，回车，Tab都当成字符输入不会舍弃。
    (2)getchar以回车触发一次输入。不以空格，回车，Tab分割。中间的空格，回车，Tab都当成字符输入不会舍弃。
    (3)scanf一行接收多个输入。以回车触发。且安装格式化字符串进行接收输入：如果格式化中间有space则输入中间的额space也会被对应起来。
    */
    /*
    char a, b;
    //scanf("%c", &a);
    //scanf("%c ", &b);
    //a = getchar();
    //b = getchar();
    scanf("%c %c", &a, &b);
    printf("%d %d\n", a, b);
    */

    /*
    读取整数测试：
    (1)scanf以回车触发一次输入。以空格，Tab，回车做为分割。中间的空格，回车，Tab都会被舍弃。
    */
    /*
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d %d\n", a, b);
    */

    /*
    读取字符串测试：
    (1)scanf格式化一个。以回车触发一次输入。以空格，回车，Tab分割。中间的空格，回车，Tab都会舍弃。
    (2)get以回车触发一次输入。不以空格，回车，Tab分割。中间的空格，回车，Tab都当成字符输入不会舍弃。
    (3)scanf格式化多个。以回车触发一次输入。以空格，回车，Tab分割。中间的空格，Tab都会舍弃。
    */

    char a[10], b[10];
    //scanf("%s", a);
    //scanf("%s", b);
    gets(a);
    gets(b);
    //scanf("%s%s", a, b);
    printf("%s\n%s\n", a, b);

    return 0;
}
