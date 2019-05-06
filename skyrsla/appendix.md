# Viðauki
## Video - Virkni
### https://www.youtube.com/watch?v=3GM0oCfEHBs
## Dagbækur
### Ágúst dagbók: https://github.com/BjarkiThorJons/rob2b3u/blob/master/skyrsla/dagbok_Agust.md
### Bjarki dagbók: https://github.com/BjarkiThorJons/rob2b3u/blob/master/skyrsla/dagbok_Bjakri.md
## Kóði
Hérna er kóðinn okkar
```
#include "robot-config.h"
int main() {
bool s=true;
while (s) {
    Vision.takeSnapshot(SIG_7);
    if (Vision.largestObject.exists && Vision.largestObject.width>5 && Vision.largestObject.width<100) {
        Brain.Screen.setPenColor(vex::color::white);
        Brain.Screen.setFillColor(vex::color::blue);
        Brain.Screen.drawRectangle(0,0, 480, 240);
        Brain.Screen.setCursor(2,6);
        Brain.Screen.setFont(vex::fontType::mono40);
        Brain.Screen.print("Forward");
        if (Vision.largestObject.centerX>120 && Vision.largestObject.centerX<170){
            if (Vision.largestObject.width > 70){
                Motor2.spin(vex::directionType::fwd,3,velocityUnits::pct);
                Motor1.spin(vex::directionType::fwd,3,velocityUnits::pct);
                task::sleep(100);
                Klo.rotateTo(180,rotationUnits::deg,10,velocityUnits::pct);
                Motor2.spin(vex::directionType::rev,20,velocityUnits::pct);
                Motor1.spin(vex::directionType::fwd,20,velocityUnits::pct);
                task::sleep(500);
                Klo.rotateTo(92,rotationUnits::deg,10,velocityUnits::pct);
                Motor1.stop();
                Motor2.stop();
                break;
            }
            else if (Vision.largestObject.width > 50){
                Motor2.spin(vex::directionType::rev,10,velocityUnits::pct);
                Motor1.spin(vex::directionType::fwd,10,velocityUnits::pct);
            }
            else{
                Motor2.spin(vex::directionType::rev,50,velocityUnits::pct);
                Motor1.spin(vex::directionType::fwd,50,velocityUnits::pct);
            }
        }
        //turn left
        else if(Vision.largestObject.centerX>170){
            Motor2.spin(vex::directionType::fwd,7,velocityUnits::pct);
            Motor1.spin(vex::directionType::fwd,7,velocityUnits::pct);
        }
        //turn right
        else if(Vision.largestObject.centerX<120){
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

```
