#ifndef COMPUTERLAB_H
#define COMPUTERLAB_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

class User; // Forward declaration

class ComputerLab {
public:
    ComputerLab(int labNumber, int maxStations);
    void login(User& user, int stationNumber);
    void logout(User& user);
    friend std::ostream& operator<<(std::ostream& os, const ComputerLab& lab);

private:
    int labNumber;
    int maxStations;
    std::map<int, std::string> stations;
};

class User {
public:
    User(const std::string& userID);
    const std::string& getUserID() const;

private:
    std::string userID;
};

#endif // COMPUTERLAB_H
