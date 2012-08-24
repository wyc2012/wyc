using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithm
{
    public static class Date
    {
        /// <summary>
        /// 日期2在日期1后面，计算两个日期的间隔天数
        /// </summary>
        /// <param name="year1"></param>
        /// <param name="month1"></param>
        /// <param name="day1"></param>
        /// <param name="year2"></param>
        /// <param name="month2"></param>
        /// <param name="day2"></param>
        /// <returns></returns>
        public static int DaysBetweenTwoDate(int year1, int month1, int day1, int year2, int month2, int day2)
        {
            int n1 = DaysFrom11(year1, month1, day1);
            int n2 = DaysFrom11(year2, month2, day2);
            int n = 0;
            for (int i = year1; i < year2; i++)
            {
                if (leap(i))
                    n += 366;
                else
                    n += 365;
            }
            return n + n2 - n1;
        }

        /// <summary>
        /// 计算日期是周几 1-7
        /// </summary>
        /// <param name="year"></param>
        /// <param name="month"></param>
        /// <param name="day"></param>
        /// <returns></returns>
        public static int WeekOfDate(int year, int month, int day)
        {
            //已知2000-1-1是周六；应该可以计算此日期以前的日期。
            int days = DaysBetweenTwoDate(2000, 1, 1, year, month, day);
            days = (days + 6) % 7;
            if (days == 0)
                return 7;
            else
                return days;
        }

        #region "private"
        /// <summary>
        /// 计算日期从1月1日算起的天数
        /// </summary>
        /// <param name="year"></param>
        /// <param name="month"></param>
        /// <param name="day"></param>
        /// <returns></returns>
        private static int DaysFrom11(int year, int month, int day)
        {
            int n = 0;
            int[] days = new int[] {32, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            for (int i = 0; i < month - 1; i++)
                n += days[i];
            if (month > 2)
            {
                if (leap(year))
                    n += 1;
            }
            return n;
        }

        /// <summary>
        /// 判断是否是闰年
        /// </summary>
        /// <param name="year"></param>
        /// <returns></returns>
        private static bool leap(int year)
        {
            if (year % 100 == 0)
                return year % 400 == 0;
            else
                return year % 4 == 0;
        }
        #endregion "private"
    }
}
