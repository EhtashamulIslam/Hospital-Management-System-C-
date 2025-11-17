#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <iostream>
#include <string>
#include <limits>

inline int readInt(const std::string& prompt)
{
    int v;
    for (;;)
    {
        std::cout << prompt;
        if (std::cin >> v) { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); return v; }
        std::cout << ">> Invalid number. Please try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

inline std::string readLine(const std::string& prompt)
{
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

inline void pressEnterToContinue()
{
    std::cout << "\n(Press ENTER to continue...)";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif // INPUT_UTILS_H
