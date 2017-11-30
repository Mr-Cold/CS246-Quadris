//
//  main.cpp
//  q5
//
//  Created by Katie on 2017/11/28.
//  Copyright © 2017年 Katie. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "board.h"
using namespace std;

int main(int argc, const char * argv[]) {
    for (int i = 1; i <= argc; i++) {
        string thearg = argv[i];
        if (thearg == "-test") {
            
        } else if (thearg == "-seed") {
            
        } else if (thearg == "-scriptfile") {
            
        } else if (thearg == "-startlevel") {
            i++;
            thearg = argv[i];
            int n;
            istringstream ss(thearg);
            ss >> n;
            setLevel(n);
        } else {
            continue;
        }
    }
    string command;
    while (cin >> command) {
        // check if command include num
        string n = command.substr(0, 1);
        int num;
        istringstream ss(n);
        if (ss >> num) {
            command = command.substr(1);
        } else {
            num = 1;
        }
        string left = "left";
        string right = "right";
        string down = "down";
        string clockwise = "clockwise";
        string counterclockwise = "counterclockwise";
        string drop = "drop";
        string levelup = "levelup";
        string leveldown = "leveldown";
        string norandom = "norandom";
        string random = "random";
        string sequence = "sequence";
        string I = "I";
        string J = "J";
        string L = "L";
        string O = "O";
        string S = "S";
        string Z = "Z";
        string T = "T";
        string restart = "restart";
        string hint = "hint";
        for (int i = 0; i < num; i++) {
            if (left.find(command) != string::npos) {
                
            } else if (right.find(command) != string::npos) {
                
            } else if (down.find(command) != string::npos) {
                
            } else if (clockwise.find(command) != string::npos) {
                
            } else if (counterclockwise.find(command) != string::npos) {
                
            } else if (drop.find(command) != string::npos) {
                
            } else if (levelup.find(command) != string::npos) {
                
            } else if (leveldown.find(command) != string::npos) {
                
            } else if (norandom.find(command) != string::npos) {
                
            } else if (random.find(command) != string::npos) {
                
            } else if (sequence.find(command) != string::npos) {
                
            } else if (I.find(command) != string::npos) {
                
            } else if (J.find(command) != string::npos) {
                
            } else if (L.find(command) != string::npos) {
                
            } else if (O.find(command) != string::npos) {
                
            } else if (S.find(command) != string::npos) {
                
            } else if (Z.find(command) != string::npos) {
                
            } else if (T.find(command) != string::npos) {
                
            } else if (restart.find(command) != string::npos) {
                
            } else if (hint.find(command) != string::npos) {
                
            } else {
                cout << "Invalid Input" << endl;
                continue;
            }
        }
    }
}

