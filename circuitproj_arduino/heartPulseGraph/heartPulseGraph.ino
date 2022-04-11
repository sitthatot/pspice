bool flag = false;
bool Bool = false;
int count = 0;
long deltatime = 0;
long lasttime = 0;
long checktime = 10000;
long curtime = 0;
int i = 0;
double bpm = 0;
double time1 = 0;
double time2 = 0;
bool checktime1 = false;
bool checktime2 = false;

void setup() {
  Serial.begin(9600);

  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  bool d = !digitalRead(7);
  deltatime = millis() - lasttime;
  lasttime = millis();
  curtime += deltatime;

  if (d) {
    digitalWrite(8, HIGH);
    tone(9, 1500);
    if (!flag) {
      count++;
      flag = true;
      if (count == 1) {
        time1 = curtime;
        checktime1 = true;
      }
      if (count == 10) {
        time2 = curtime;
        checktime2 = true;
      }
   }

    if (checktime1 && checktime2) {
      bpm = 60000 / ((time2 - time1)/10);
      time1 = 0;
      time2 = 0;
      count = 0;
      checktime2 = false;
      checktime1 = false;
      curtime = 0;
    }


  }
  else {
    digitalWrite(8, LOW);
    noTone(9);
    flag = false;
  }



//    if (curtime >= checktime) {
//      bpm = count * 6;
//      count = 0;
//      curtime = 0;
//    }
  Serial.println(round(bpm));
  //   Serial.print(time1);
  //   Serial.print(" ");
  //   Serial.println(time2);
  //  Serial.write
}

//void bpmCal(bool d,long delta,bool flag){
//  curtime+=delta;
//  if(d){
//    i++;
//  }
//  if(curtime>=checktime){
//    bpm=i*15;
//    i=0;
//    curtime =0;
//  }
//}
