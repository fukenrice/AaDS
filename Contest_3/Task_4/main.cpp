#include <iostream>
#include <string>

std::string AddZeros(__int64 num) {
    if (num < 10) {
        return "0" + std::to_string(num);
    } else {
        return std::to_string(num);
    }
}

__int64 ConvertTimeToSeconds(std::string time_str) {
    __int64 time_in_secs = 0;
    int colons_count = 0;
    for (int i = 0; i < time_str.length(); ++i) {
        if (time_str.at(i) == ':') {
            colons_count++;
        }
    }

    if (colons_count == 0) {
        time_in_secs += std::stoll(time_str);
    }
    if (colons_count == 1) {
        std::string mins;
        while (time_str.at(0) != ':') {
            mins += time_str.at(0);
            time_str.erase(0, 1);
        }
        time_str.erase(0, 1);
        time_in_secs += std::stoll(time_str);
        time_in_secs += std::stoll(mins) * 60;
    }
    if (colons_count == 2) {
        std::string hours, mins;
        while (time_str.at(0) != ':') {
            hours += time_str.at(0);
            time_str.erase(0, 1);
        }
        time_str.erase(0, 1);
        while (time_str.at(0) != ':') {
            mins += time_str.at(0);
            time_str.erase(0, 1);
        }
        time_str.erase(0, 1);
        time_in_secs += std::stoll(time_str);
        time_in_secs += std::stoll(mins) * 60;
        time_in_secs += std::stoll(hours) * 3600;
    }
    return time_in_secs;
}

std::string GetSignalTime(std::string current_time, std::string time_delta) {
    __int64 current_time_in_secs = 0;
    current_time_in_secs += std::stoll(current_time.substr(0, 2)) * 3600;
    current_time_in_secs += std::stoll(current_time.substr(3, 2)) * 60;
    current_time_in_secs += std::stoll(current_time.substr(6, 2));

    current_time_in_secs += ConvertTimeToSeconds(time_delta);

    __int64 days = current_time_in_secs / 86400;
    current_time_in_secs %= 86400;
    std::string hours, mins, secs;
    hours = AddZeros(current_time_in_secs / 3600);
    current_time_in_secs %= 3600;
    mins = AddZeros((current_time_in_secs / 60));
    current_time_in_secs %= 60;
    secs = AddZeros(current_time_in_secs);

    if (days == 0) {
        return hours + ':' + mins + ':' + secs;
    } else {
        return hours + ':' + mins + ':' + secs + '+' + std::to_string(days) + " days";
    }
}


int main() {
    std::string current_time, time_delta;
    std::cin >> current_time >> time_delta;
    std::cout << GetSignalTime(current_time, time_delta);
    return 0;
}
