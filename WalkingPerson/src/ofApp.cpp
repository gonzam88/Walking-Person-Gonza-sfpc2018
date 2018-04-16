#include "ofApp.h"
#include "data.h"

//--------------------------------------------------------------
void ofApp::setup(){

    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 24; j++){
            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
            frames[i][j].set(x,y,z);
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    time = ofGetElapsedTimef();
    
    matrixSize = ofMap( sin(time * 0.43), -1, 1, 5, 20);
    camRotation = ofMap( sin(time * 0.22), -1, 1, 0, TWO_PI);
    sphereThreshold = ofMap( sin(time * 0.47), -1, 1, 5, 200);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    ofPoint data3d[24];
    
    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
    }
    
    
    // end do not touch
    
    
    //    //----------------------------- 3d
    cam.begin();
    cam.enableOrtho();
    
    float radio = 1000;
    float theta = camRotation;
    float camx = radio * cos(theta);
    float camz = radio * sin(theta);
    float camy = radio * sin(theta);
    cam.setPosition( ofPoint(camx, camy, camz));
    cam.lookAt(ofPoint(0,0,0));
    
    ofSetColor(255);
    
    ofSetSphereResolution(5);
    
    for (int x = 0; x < matrixSize; x++){
        for (int y = 0; y < matrixSize; y++){
            for (int z = 0; z < matrixSize; z++){
            
                float xpos = ofMap(x, 0, matrixSize, -200, 200);
                float ypos = ofMap(y, 0, matrixSize, -200, 200);
                float zpos = ofMap(z, 0, matrixSize, -200, 200);
                ofVec3f pt(xpos,ypos,zpos);
                
                float d = pt.distance(data3d[0]);
                
                for (int i = 1; i < 24; i++){   // Loop starts at 1 because the initial
                                                // value of d is distance to array at 0
                    float tempD = pt.distance(data3d[i]);
                    if(tempD < d){
                        d = tempD;
                    }
                }
                ofDrawSphere(pt, ofMap(d, 0, sphereThreshold, 5, 0.2, true));
            }
        }
    }
  
    cam.end();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
