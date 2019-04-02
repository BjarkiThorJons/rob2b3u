#include "robot-config.h"
void taka(){
    Motor1.spin(directionType::rev,50,velocityUnits::rpm);
    Motor2.spin(directionType::fwd,50,velocityUnits::rpm);
}
int main() {
bool s=true;
while (s) {
    Vision.takeSnapshot(SIG_7);
    if (Vision.largestObject.exists && Vision.largestObject.width>5) {
        Brain.Screen.setPenColor(vex::color::white);
        Brain.Screen.setFillColor(vex::color::blue);
        Brain.Screen.drawRectangle(0,0, 480, 240);
        Brain.Screen.setCursor(2,6);
        Brain.Screen.setFont(vex::fontType::mono40);
        Brain.Screen.print("Forward");
        if (Vision.largestObject.centerX>130 && Vision.largestObject.centerX<160){
            if (Vision.largestObject.width > 70){
                Motor2.spin(vex::directionType::fwd,7,velocityUnits::pct);
                Motor1.spin(vex::directionType::fwd,7,velocityUnits::pct);
                task::sleep(100);
                Klo.rotateTo(180,rotationUnits::deg,10,velocityUnits::pct);
                Motor2.spin(vex::directionType::rev,20,velocityUnits::pct);
                Motor1.spin(vex::directionType::fwd,20,velocityUnits::pct);
                task::sleep(1000);
                Klo.rotateTo(0,rotationUnits::deg,10,velocityUnits::pct);
                task::sleep(500);
                Motor1.stop();
                Motor2.stop();
                s=false;
            }
            else if (Vision.largestObject.centerY>140 && Vision.largestObject.centerY < 150){
                Motor2.spin(vex::directionType::rev,10,velocityUnits::pct);
                Motor1.spin(vex::directionType::fwd,10,velocityUnits::pct);
            }
            else{
                Motor2.spin(vex::directionType::rev,50,velocityUnits::pct);
                Motor1.spin(vex::directionType::fwd,50,velocityUnits::pct);
            }
        }
        //turn left
        else if(Vision.largestObject.centerX>160){
            Motor2.spin(vex::directionType::fwd,7,velocityUnits::pct);
            Motor1.spin(vex::directionType::fwd,7,velocityUnits::pct);
        }
        //turn right
        else if(Vision.largestObject.centerX<130){
            Motor2.spin(vex::directionType::rev,7,velocityUnits::pct);
            Motor1.spin(vex::directionType::rev,7,velocityUnits::pct);
        }
        
    }
    	else {
            Motor2.stop();
            Motor1.stop();
            Brain.Screen.print(":(");
        }
    task::sleep(100);
}
}
