#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "-I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "-I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "-I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "-This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string level)
{
    LevelFunction levelFunctions[] = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error
        };
        std::string levelStrings[] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR"
        };
        int index = -1;
        for (int i = 0; i < 4; ++i) {
            if (level == levelStrings[i]) {
                index = i;
                break;
            }
        }
        if (index != -1)
            (this->*levelFunctions[index])();
        else
            std::cout << "Invalid level" << std::endl;
}

void Harl::harlFilter(std::string level)
{
        LevelFunction levelFunctions[] = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error
        };
        std::string levelStrings[] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR"
        };
        int index = -1;
        for (int i = 0; i < 4; ++i) {
            if (level == levelStrings[i]) {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            switch (index)
            {
                case 0:
                    (this->*levelFunctions[0])();
                case 1:
                    (this->*levelFunctions[1])();
                case 2:
                    (this->*levelFunctions[2])();
                case 3:
                    (this->*levelFunctions[3])();
            }
        }
        else
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}
