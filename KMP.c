http://www.cppblog.com/oosky/archive/2006/07/06/9486.html
各种情况如下：
（1）next[0]= -1  意义：任何串的第一个字符的模式值规定为-1。
（2）next[j]= -1   意义：模式串T中下标为j的字符，如果与首字符
相同，且j的前面的1—k个字符与开头的1—k
个字符不等（或者相等但T[k]==T[j]）（1≤k<j）。
如：T=”abCabCad” 则 next[6]=-1，因T[3]=T[6]
（3）next[j]=k    意义：模式串T中下标为j的字符，如果j的前面k个
字符与开头的k个字符相等，且T[j] != T[k] （1≤k<j）。
                       即T[0]T[1]T[2]。。。T[k-1]==
T[j-k]T[j-k+1]T[j-k+2]…T[j-1]
且T[j] != T[k].（1≤k<j）;
(4) next[j]=0   意义：除（1）（2）（3）的其他情况。

//展开版函数
void next_set(char* T, int next[], int len)
{
  int k = -1;
  int j = 0;
  next[0] = -1;
  
  while(T[j] != '\0')
  {
    if(k == -1)//入口1//不存在前面与开头相等序列存在
    {
      k = 0;
      ++j;
      if(T[j] == T[0])//情况2，下面进入入口2
        next[j] = -1;
      else//情况4
        next[j] = 0;
    }
    else if(T[j] == T[k])//入口2
    {
      ++j;
      ++k;
      if(T[j] == T[k])//情况3的排除情况，下面进入入口2
        next[j] = next[k];
      else//情况3成立，下面进入入口3
        next[j] = j;
    }
    else//入口3
      k = next[k];
  }
}

//正常版函数
void next_set(char* T, int next[], int len)
{
  int k = -1;
  int j = 0;
  next[0] = -1;
  
  while(T[j] != '\0')
  {
    if(k == -1 || T[j] = T[k])
    {
      ++j;
      ++k;
      if(T[j] == T[k])
        next[j] = next[k];
      else
        next[j] = j;
    }
    else
      k = next[k];
  }
}

int kmp_search(char const* src, int slen, char const* patn, int plen, int const* nextval, int pos)
{
  int i = pos;
  int j = 0;
  while(i < slen && j < plen)
  {
    if(j == -1 || src[i] == patn[j])
    {
      ++i;
      ++j;
    }
    else
      j = next[j];
    if(j >= plen)
      return i - plen;
    return -1;
  }
}
