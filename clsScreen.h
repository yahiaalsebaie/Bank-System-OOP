#pragma once
#include <iostream>
#include <string>
#include "clsUtil.h"
#include "clsDate.h"

class clsScreen
{
protected:

    static void _DrawScreenHeader(std::string Title, std::string SubTitle = "")
    {
        //Date
        std::cout << "\n\t\t\t\t\t\t\t\t[" << clsUtil::ColorText(clsDate::GetSystemDateToString(), clsUtil::enColor::BRIGHT_GREEN) << "]\n";
      //  std::cout << "\n\t\t\t\t\t[" << clsUtil::ColorText(clsDate::GetSystemDateToString(), clsUtil::enColor::BRIGHT_GREEN) << "]\n";



        std::cout << "\t\t\t\t\t______________________________________";
       
        std::cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
            std::cout << "\n\t\t\t\t\t  " << SubTitle;

        std::cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

};