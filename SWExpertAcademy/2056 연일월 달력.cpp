//
//  2056 연일월 달력.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/27.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <math.h> // floor, ceil, round
#include <string>
using namespace std;

int main(void) {
    int test_case;
    int T;
    
    cin >> T;
    
    for (test_case = 1; test_case <= T; test_case++) {
        
        int num;
        cin >> num;
        
        int year = num / 10000;
        int month = (num - year * 10000) / 100;
        int day = (num - year * 10000 - month * 100);
        string days;
        if (day < 10) {
            days = "0" + to_string(day);
        } else {
            days = to_string(day);
        }
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
                cout << "#" << test_case << " ";
                if (day >= 1 && day <= 31) {
                    if (!(year / 10)) { // 한자리수
                        cout << "000" << year << "/" << "0" << month << "/" << days << "\n";
                    } else if (!(year / 100)) { // 두자리수
                        cout << "00" << year << "/" << "0" << month << "/" << days << "\n";
                    } else if (!(year / 1000)) { // 세자리수
                        cout << "0" << year << "/" << "0" << month << "/" << days << "\n";
                    } else {
                        cout << year << "/" << "0" << month << "/" << days << "\n";
                    }
                } else {
                    cout << "-1" << "\n";
                }
                break;
            case 10:
            case 12:
                cout << "#" << test_case << " ";
                if (day >= 1 && day <= 31) {
                    if (!(year / 10)) { // 한자리수
                        cout << "000" << year << "/" << month << "/" << days << "\n";
                    } else if (!(year / 100)) { // 두자리수
                        cout << "00" << year << "/" << month << "/" << days << "\n";
                    } else if (!(year / 1000)) { // 세자리수
                        cout << "0" << year << "/" << month << "/" << days << "\n";
                    } else {
                        cout << year << "/" << month << "/" << days << "\n";
                    }
                } else {
                    cout << "-1" << "\n";
                }
                break;
            case 2:
                cout << "#" << test_case << " ";
                if (day >= 1 && day <= 28) {
                    if (!(year / 10)) { // 한자리수
                        cout << "000" << year << "/" << "0" << month << "/" << days << "\n";
                    } else if (!(year / 100)) { // 두자리수
                        cout << "00" << year << "/" << "0" << month << "/" << days << "\n";
                    } else if (!(year / 1000)) { // 세자리수
                        cout << "0" << year << "/" << "0" << month << "/" << days << "\n";
                    } else {
                        cout << year << "/" << "0" << month << "/" << days << "\n";
                    }
                } else {
                    cout << "-1" << "\n";
                }
                break;
            case 4:
            case 6:
            case 9:
                cout << "#" << test_case << " ";
                if (day >= 1 && day <= 30) {
                    if (!(year / 10)) { // 한자리수
                        cout << "000" << year << "/" << "0" << month << "/" << days << "\n";
                    } else if (!(year / 100)) { // 두자리수
                        cout << "00" << year << "/" << "0" << month << "/" << days << "\n";
                    } else if (!(year / 1000)) { // 세자리수
                        cout << "0" << year << "/" << "0" << month << "/" << days << "\n";
                    } else {
                        cout << year << "/" << "0" << month << "/" << days << "\n";
                    }
                } else {
                    cout << "-1" << "\n";
                }
                break;
            case 11:
                cout << "#" << test_case << " ";
                if (day >= 1 && day <= 30) {
                    if (!(year / 10)) { // 한자리수
                        cout << "000" << year << "/" << month << "/" << days << "\n";
                    } else if (!(year / 100)) { // 두자리수
                        cout << "00" << year << "/" << month << "/" << days << "\n";
                    } else if (!(year / 1000)) { // 세자리수
                        cout << "0" << year << "/" << month << "/" << days << "\n";
                    } else {
                        cout << year << "/" << month << "/" << days << "\n";
                    }
                } else {
                    cout << "-1" << "\n";
                }
                break;
            default:
                cout << "#" << test_case << " -1" << "\n";
                break;
        }
        
    }
    
    return 0;
}


