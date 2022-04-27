#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 30;
	for (int x = span * 0.5; x < ofGetWidth(); x += span) {

		for (int y = span * 0.5; y < ofGetHeight(); y += span) {

			auto noise_value = ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.01);

			if (noise_value < 0.35) { noise_value = 0; }
			else if (noise_value < 0.6) { noise_value = ofMap(noise_value, 0.35, 0.6, 0, 1); }
			else { noise_value = 1; }

			int len = ofMap(noise_value, 0, 1, span * 0.15, span * 0.65);

			ofDrawLine(x - len, y, x + len, y);
			ofDrawLine(x, y - len, x, y + len);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}