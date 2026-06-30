#pragma once
#pragma warning(disable : 4996)
#include <iostream>

namespace clsGlobalTypes
{
    enum enBeforAfter
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    enum enDateFormat
    {
        DayMonthYearSlash = 1,
        MonthDayYearSlash = 2,
        YearMonthDaySlash = 3,
        FullDateText = 4,
        YearDayMonthSlash = 5,
        MonthDayYearDash = 6,
        DayMonthYearDash = 7,
        NamedCustom = 8
    };
}
