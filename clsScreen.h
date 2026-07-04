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
      
        std::cout << "\t\t\t\t\t______________________________________";
     //   std::cout << clsUtil::ColorText("\t\t\t\t\t______________________________________", clsUtil::enColor::BRIGHT_WHITE);
        std::cout << "\n\n\t\t\t\t\t  " << clsUtil::ColorText(Title, clsUtil::enColor::ORANGE);
        if (SubTitle != "")
        {
            std::cout << "\n\t\t\t\t\t  " << clsUtil::ColorText(SubTitle, clsUtil::enColor::BRIGHT_CYAN);
        }

        std::cout << "\n\t\t\t\t\t______________________________________";
       // std::cout << clsUtil::ColorText("\n\t\t\t\t\t______________________________________\n\n", clsUtil::enColor::BRIGHT_WHITE);
        std::cout << "\n\t\t\t\t\t\t\t\t[" << clsUtil::ColorText(clsDate::GetSystemDateToString(), clsUtil::enColor::BRIGHT_GREEN) << "]\n\n";
    }

};