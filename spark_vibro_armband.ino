int vLeft = A1;
int vRight = A2;
int vTop = A3;
int vBottom = A4;

int vAll;

int vibrateSensor(String command);

void setup() {
    Spark.function("vibrate", vibrateSensor);

    pinMode(vLeft, OUTPUT);
    pinMode(vRight, OUTPUT);
    pinMode(vTop, OUTPUT);
    pinMode(vBottom, OUTPUT);
}

void loop() {
  // nothing to do here
}

int vibrateSensor(String command)
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
    if (motor != vAll) {
      int start;
      for (start = 0; start < loops; start++) {
          digitalWrite(motor, HIGH);
          delay(150);
          digitalWrite(motor, LOW);
          delay(150);
      }
    } else if (motor == vAll) {

      int vibroArray[4]={vTop,vRight,vBottom,vLeft};

      int startAll;
      for (startAll = 0; startAll < 2; startAll++) {
        int i;
        for (i = 0; i < 4; i = i + 1) {
          int delayAll = 75;

          digitalWrite(vibroArray[i], HIGH);
          delay(delayAll);
          digitalWrite(vibroArray[i], LOW);
          delay(delayAll);
        }
      }
    }

    return 0;
}
