//
//  Button.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 30/11/2015.
//
//

#include "Button.h"

Button::Button(ofVec2f _pos, ofVec2f _size, string _text):pos(_pos),size(_size),text(_text){
}

void Button::display(ofTrueTypeFont *_font){
    ofPushMatrix();
    ofTranslate(pos.x,pos.y);
    
    ofPushStyle();
    ofFill();
    ofSetColor(255,0,0);
    ofDrawRectangle(0,0, size.x, size.y);
    
    ofNoFill();
    ofSetColor(0);
        ofDrawRectangle(0,0, size.x, size.y);
    ofPopStyle();
    
        ofPushMatrix();
    ofTranslate(_font->getSize(),2*_font->getSize());
        ofPushStyle();
            ofSetColor(0);
            _font->drawString(text,0,0);
        ofPopStyle();
        ofPopMatrix();
    
    ofPopMatrix();
}

void Button::setText(string _text){
    text = _text;
}

void Button::setFont(int _fontSize){
    
}

bool Button::clicked(float _mouseX, float _mouseY){
    if(_mouseX-pos.x<size.x &&
       _mouseX-pos.x>0 &&
       _mouseY-pos.y<size.y &&
       _mouseY-pos.y>0){
        return true;
    }
    return false;
}