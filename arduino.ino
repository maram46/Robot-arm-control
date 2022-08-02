#include <Servo.h>

Servo wrist;
Servo hand;


double hand_angle=90;
double wrist_angle=90;


void setup() {
  Serial.begin(115200);
  hand.attach(8);
  wrist.attach(9);
  hand.write(hand_angle);
  wrist.write(wrist_angle);

}
String getValue(String data, char separator, int index){
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
 String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }
  
  String command = getValue(computerText, ' ',0);

    if (command == "right" || command == "رايت" || command == "Right" || command == "يمين") {
      hand.write(hand_angle -= 20);
    }
    if (command == "left" || command == "Left" || command == "لفت" || command == "يسار") {
     hand.write(hand_angle += 20);
    }

    if (command == "top" || command == "توب" || command == "Top" || command == "فوق") {
      wrist.write(wrist_angle -= 20);
    }

   if (command == "bottom"|| command == "بوتوم" || command == "Bottom" || command == "تحت") {
     wrist.write(wrist_angle += 20);
    }
    Serial.println(command);
  Serial.println("WORKING");
  delay(1000);
}





