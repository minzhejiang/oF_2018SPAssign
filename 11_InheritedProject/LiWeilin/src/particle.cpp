//
//  particle.cpp
//  bacteria_animation
//
//  Created by echo jiang on 3/15/18.
//

#include "particle.hpp"
#include "ofMain.h"

//-----------------------------------------------------

particle::particle(){
//    setInitialCondition(ofRandom(0,100), ofRandom(0,100), ofRandom(0,100), ofRandom(0,100));
    damping=ofRandom(0.01, 0.03);
}

//-----------------------------------------------------

void particle::resetForce(){
    //we reset the forces every frame
    frc.set(0,0);
}
//-----------------------------------------------------

void particle::addForce(float x, float y){
    //add in a force in X and Y for this frame
    frc.x=frc.x+x;
    frc.y=frc.y+y;
}
//-----------------------------------------------------
void particle::addDampingForce(){
    // the usual way to write this is  vel *= 0.99
    // basically, subtract some part of the velocity
    // damping is a force operating in the oposite direction of the
    // velocity vector
    
    frc.x=frc.x-vel.x*damping;
    frc.y=frc.y-vel.y*damping;
}
//-----------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
}
//-----------------------------------------------------
void particle::update(){
    vel=vel+frc;
    pos=pos+vel;
}
//-----------------------------------------------------
void particle::draw(){
    ofDrawCircle(pos.x, pos.y, ofMap(ofNoise(ofGetElapsedTimef(), 1000), 0, 1, 1, 5));
}



