using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithm
{
    public static class XuanZhuan
    {
        /// <summary>
        /// 移动x[0]到临时变量tmp，然后移动x[i]至x[0]，x[2i]至x[i]，依次类推
        /// </summary>
        /// <param name="chs">要旋转的数组</param>
        /// <param name="num">要旋转的个数，旋转是从0开始的。</param>
        public static void XuanZhuan1(char[] chs, int num)
        {
            int index = 0;
            int len = chs.Length;
            char tmp;
            int gcd = bcd.bcd1(len, num); //最大公约数
            int pos = 0;
            int npos = 0;
            for (; index < gcd; index++)//根据最大公约数来确定循环次数.
            {
                pos = npos = index;
                tmp = chs[index];
                npos += num;
                while ((npos %= len) != index)//循环结束条件：位置回到原来的index位置
                {
                    chs[pos] = chs[npos];
                    pos = npos;
                    npos += num;
                }
                chs[pos] = tmp;
            }
        }

        /// <summary>
        /// 先把要旋转的前面逆置，再把后面的逆置，在把所有的逆置。
        /// </summary>
        /// <param name="chs"></param>
        /// <param name="num"></param>
        public static void XuanZhuan2(char[] chs, int num)
        {
            reverse(chs, 0, num - 1);
            reverse(chs, num, chs.Length - 1);
            reverse(chs, 0, chs.Length);
        }

        /// <summary>
        /// 把chs的start到end的元素逆置
        /// </summary>
        /// <param name="chs"></param>
        /// <param name="start">0开始</param>
        /// <param name="end">0开始</param>
        private static void reverse(char[] chs, int start, int end)
        {
            char tmp;
            while (end > start)
            {
                tmp = chs[start];
                chs[start] = chs[end];
                chs[end] = tmp;
                start++;
                end--;
            }
        }
    }
}
