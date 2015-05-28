#!/usr/bin/python

import cwrap as c


year = 2001
month= 1
day  = 28
print "year ", year, "month", month, "day", day

yearday = c.day_of_year(year, month, day);
print "the ", yearday, "day of year", year

month, day = c.month_day(year, yearday);
print "month", month, "day", day
