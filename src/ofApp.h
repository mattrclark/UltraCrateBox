#pragma once

#include "ofMain.h"
#include "GameObject/Entity/Player/Player.h"
#include "GameObject/Entity/Enemy/Enemy.h"
#include "GameObject/Tile/Platform/Platform.h"
#include "Level/Level.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //Main control functions
    void entityControls();
    void collisions();

    //Checks collisions between entity and tiles
    void checkCollisions(Tile *_platform, Entity *_entity);
    void damageEnemies(Projectile &_projectile);

    //Creates objects in world from level
    void createLevel();
    
    //Resets the level
    void reset();

    //Signature of a test player and an enemy
    Player player;
    vector<Enemy*> enemies;

    //Text for testing purposes
    ofTrueTypeFont text;

    //Vector of Tile type objects
    vector<Tile*> platforms;

    //Level
    Level level;

    //Position offset
    ofVec2f posOffset;

    bool gameOver;
    int state;
    bool up;
};
