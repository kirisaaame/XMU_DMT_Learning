#include "ComputerLab.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::vector<ComputerLab> labs = {
        ComputerLab(1, 5),
        ComputerLab(2, 6),
        ComputerLab(3, 4),
        ComputerLab(4, 3)
    };

    std::vector<User> users;

    std::string input;
    while (std::getline(std::cin, input) && input != "=") {
        char op;
        std::string course;
        int labNumber, stationNumber;
        std::istringstream iss(input);
        iss >> op;
        if (op == '+') {
            iss >> course >> labNumber >> stationNumber;
            users.emplace_back(course);
            labs[labNumber - 1].login(users.back(), stationNumber);
        } else if (op == '-') {
            iss >> course >> labNumber;
            bool found = false;
            for (auto it = users.begin(); it != users.end(); ++it) {
                if (it->getUserID() == course) {
                    labs[labNumber - 1].logout(*it);
                    users.erase(it);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Invalid logoff" << std::endl;
            }
        }

        for (const auto& lab : labs) {
            std::cout << lab << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
