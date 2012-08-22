using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithm
{
    public static class bcd
    {
        public static int bcd1(int n1, int n2)
        {
            int temp = Math.Max(n1, n2);
            n2 = Math.Min(n1, n2);//n2中存放两个数中最小的
            n1 = temp;//n1中存放两个数中最大的
            while (n2 != 0)
            {
                n1 = n1 > n2 ? n1 : n2;//使n1中的数大于n2中的数
                int m = n1 % n2;
                n1 = n2;
                n2 = m;
            }
            return n1;
        }

        public static int bcd2(int n1, int n2)
        {
            if (n1 == 0 || n2 == 0)
                return 0;
            else
            {
                while (n1 != n2)
                {
                    if (n1 > n2)
                        n1 -= n2;
                    else
                        n2 -= n1;
                }
                return n1;//或n2，最后两者相同。
            }
        }
    }
}
