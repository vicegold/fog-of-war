int vAll = A0;
int vLeft = A1;
int vRight = A2;
int vTop = A3;
int vBottom = A4;

int vibreateSensor(String command);


void setup() {
    //Spark.function("leftOn", vibrateLeft);
    //Spark.function("leftOff", vibrate_stopLeft);

    /*Spark.function("rightOn", vibrateRight);
    Spark.function("rightOff", vibrate_stopRight);

    Spark.function("bottomOn", vibrateBottom);
    Spark.function("bottomOff", vibrate_stopBottom);*/

    //Spark.function("vibrate", webCommand)
    Spark.function("vibrate", vibreateSensor);

    pinMode(vLeft, OUTPUT);
    pinMode(vRight, OUTPUT);
    pinMode(vTop, OUTPUT);
    pinMode(vBottom, OUTPUT);
}

int last = 0;

void loop() {
    analogWrite(vLeft, 160);
    delay(200);
    analogWrite(vLeft, 20);
    delay(200);
    analogWrite(vLeft, 255);
    delay(200);
}

int vibreateSensor(String command)
{
   if (command == "Left") {
        vibrate(vLeft);
    } else if (command == "Right") {
        vibrate(vRight);
    } else if (command == "Bottom") {
        vibrate(vBottom);
    } else if (command == "Top") {
        vibrate(vTop);
    } else if (command == "All") {
        vibrate(vAll);
    }

    return 0;
}

int vibrate(int motor) {
    int loops = 0;
    if (motor == vTop) {
        loops = 1;
    } else if (motor == vRight) {
        loops = 2;
    } else if (motor == vBottom) {
        loops = 3;
    } else if (motor == vLeft) {
        loops = 4;
    }
    if (motor !== vAll) {
      int start;
      for (start = 0; start < loops; start++) {
          digitalWrite(motor, HIGH);
          delay(150);
          digitalWrite(motor, LOW);
          delay(150);
      }
    } else {
      int start;
      for (start = 0; start < 2; start++) {
          digitalWrite(vTop, HIGH);
          delay(150);
          digitalWrite(vTop, LOW);
          delay(150);
          digitalWrite(vRight, HIGH);
          delay(150);
          digitalWrite(vRight, LOW);
          delay(150);
          digitalWrite(vBottom, HIGH);
          delay(150);
          digitalWrite(vBottom, LOW);
          delay(150);
          digitalWrite(vLeft, HIGH);
          delay(150);
          digitalWrite(vLeft, LOW);
          delay(150);
      }
    }

    return 0;
}
