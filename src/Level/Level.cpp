//
//  Level.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 15/11/2015.
//
//

#include "Level.h"

Level::Level(){
    //Sets size of level
    layout.resize(46);
    for (auto &i: layout){
        i.resize(33);
    }
    
    loadLevel();
    
//    for (int i=0; i<layout.size(); i++) {
//        for (int j=0; j<layout[i].size(); j++) {
//            if (j==32) {
//                 layout[i][j]=1;
//            }
//        }
//    }
}
   //Level dimensions = [33][46] at platform size = 20px
    /*
     0=air
     1=platform
     2=fire
     3=enemy Spawner
     4=Player spawn
    */

void Level::loadLevel(){
    ifstream file;
    string sub, textLine;
    int xCount;
    int yCount;
    xCount = 0;
    yCount = 0;
    
    file.open (ofToDataPath("levels/test.txt"));
    while(!file.eof()) // To get you all the lines.
    {
        getline(file,textLine); // Saves the line in STRING.
        sub = "";
        for(int i=0; i<textLine.length(); i++){
            if(textLine.at(i)==','){
                sub = "";
            }
            else{
                sub+=textLine.at(i);
                layout[xCount][yCount]=(stoi(sub));
                xCount++;
            }
        }
        yCount++;
        xCount=0;
    }
    file.close();
}

