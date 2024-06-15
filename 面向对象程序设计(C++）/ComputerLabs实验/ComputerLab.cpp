#include "ComputerLab.h"

ComputerLab::ComputerLab(int labNumber, int maxStations)
    : labNumber(labNumber), maxStations(maxStations) {
}

void ComputerLab::login(User& user, int stationNumber) {
    if (stations.find(stationNumber) != stations.end()) {
        std::cout << "Invalid login" << std::endl;
        return;
    }

    if (stationNumber > maxStations) {
        std::cout << "Invalid login" << std::endl;
        return;
    }

    stations[stationNumber] = user.getUserID();
}

void ComputerLab::logout(User& user) {
    for (auto it = stations.begin(); it != stations.end(); ++it) {
        if (it->second == user.getUserID()) {
            stations.erase(it);
            return;
        }
    }
    std::cout << "Invalid logoff" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ComputerLab& lab) {
    os << lab.labNumber << " ";
    for (int i = 1; i <= lab.maxStations; ++i) {
        os << i << ": ";
        auto it = lab.stations.find(i);
        if (it != lab.stations.end()) {
            os << it->second;
        } else {
            os << "empty";
        }
        if (i != lab.maxStations) {
            os << " ";
        }
    }
    return os;
}

User::User(const std::string& userID)
    : userID(userID) {
}

const std::string& User::getUserID() const {
    return userID;
}
