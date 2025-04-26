#include <NewPing.h>
int TrigPin=13;
int EchoPin=12;
int MaxDistance=200; // اعلا مسافة 2 متر
int Distance; // متغير حساب المسافة للمقارنه 
NewPing sonar(TrigPin, EchoPin, MaxDistance); // تشغيل الحساس uitar وحساب المسافة 
void setup() {
   Serial.begin(9600);
   // توصيل الاسلاك حقت L298N
   // كلها اوتبوت عشان اتحكم في المواطير
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  Distance = sonar.ping_cm(); // قياس المسافة تخزينها في المتغير distamce
    delay(50);
  Serial.println(Distance);

if(Distance>=30) // اذا المسافة اكبر من 30 كل المواطير تدور مع عقارب الساعة 
  {
    // MOTOR1
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
    //MOTOR2
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
  }

    if(Distance<30) // اذا المسافة اقل من 30 ماطور يلف عكس ماطور 
  {
    //MOTOR 1
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    // MOTOR2
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
  }

}
