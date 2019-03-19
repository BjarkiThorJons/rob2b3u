#include "robot-config.h"

int main() {
while (true) {
    Vision.takeSnapshot(SIG_7);
    if (Vision.largestObject.exists && Vision.largestObject.width>5) {
        Brain.Screen.setPenColor(vex::color::white);
        Brain.Screen.setFillColor(vex::color::blue);
        Brain.Screen.drawRectangle(0,0, 480, 240);
        Brain.Screen.setCursor(2,6);
        Brain.Screen.setFont(vex::fontType::mono40);
        Brain.Screen.print("Forward");
        if (Vision.largestObject.centerX>140 && Vision.largestObject.centerX<150){
            Motor2.spin(vex::directionType::rev,50,velocityUnits::pct);
            Motor1.spin(vex::directionType::fwd,50,velocityUnits::pct);
        }
        else if(Vision.largestObject.centerX>225){
            Motor2.spin(vex::directionType::fwd,7,velocityUnits::pct);
            Motor1.spin(vex::directionType::fwd,7,velocityUnits::pct);
        }
        else if(Vision.largestObject.centerX<75){
            Motor2.spin(vex::directionType::rev,7,velocityUnits::pct);
            Motor1.spin(vex::directionType::rev,7,velocityUnits::pct);
        }
        
    }
    	else {
            Motor2.stop();
            Motor1.stop();
            Brain.Screen.clearScreen();
        }
    task::sleep(100);
}
}