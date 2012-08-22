using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithm
{
    class Program
    {
        public static int bcd(int n1, int n2)
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

        /// <summary>
        /// 移动x[0]到临时变量tmp，然后移动x[i]至x[0]，x[2i]至x[i]，依次类推
        /// </summary>
        /// <param name="chs">要旋转的数组</param>
        /// <param name="num">要旋转的个数</param>
        public static void XuanZhuan1(char[] chs, int num)
        {
            int index = 0;
            int len = chs.Length;
            char tmp;
            int gcd = bcd(len, num); //最大公约数
            int pos = 0;
            int npos = 0;
            for (; index < gcd; index++)
            {
                pos = npos = index;
                tmp = chs[index];
                npos += num;
                while ((npos %= len) != index)
                {
                    chs[pos] = chs[npos];
                    pos = npos;
                    npos += num;
                }
                chs[pos] = tmp;
            }
        }

        static void Main(string[] args)
        {
            char[] chs = new char[] { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
            XuanZhuan1(chs, 2);
            foreach(char ch in chs)
            {
                Console.Write(ch + "  ");
            }
            Console.WriteLine();
        }
    }
}
