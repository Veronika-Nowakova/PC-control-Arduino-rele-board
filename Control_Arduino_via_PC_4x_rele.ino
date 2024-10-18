const int zamek = 5; // HNĚDÁ 2 ASCI 57
const int rele_1 = 2; //HNĚDÁ 1 ASCI 49
const int rele_2 = 3; //ŽLUTÁ ASCI 50
const int rele_3 = 4; //ORANŽOVÁ ASCI 51

int delka_sepnuti_1 = 1000;
int delka_sepnuti_2 = 1000;
int delka_sepnuti_3 = 1000;

long pause;
byte in;

void setup()
{
  Serial.begin(9600);
  
  pinMode(rele_1, OUTPUT);
  pinMode(rele_2, OUTPUT);
  pinMode(rele_3, OUTPUT);
  pinMode(zamek, OUTPUT);

  digitalWrite(rele_1,HIGH);
  digitalWrite(rele_2,HIGH);
  digitalWrite(rele_3,HIGH);
  digitalWrite(zamek,LOW);

  Serial.println("ZAMKNUTO START");

  in = 0;

}
 
void loop() 
{
  if (Serial.available())
  {
    in = 0;
    in = Serial.read();

    while (in==57) // Prikaz 0 Zamek
    {
      digitalWrite(zamek,HIGH);
      Serial.println("KONEC ODEMKNUTO");
      delay(500);
    }

    switch(in)
    {
      case 49: // Prikaz 1
        Serial.println("Prikaz 1");
        digitalWrite(rele_1,LOW);
        delay(delka_sepnuti_1);
        digitalWrite(rele_1,HIGH);
        Serial.println("-----------");
        delay(1000);
        break;

      case 50: // Prikaz 2
        Serial.println("Prikaz 2");
        digitalWrite(rele_2,LOW);
        delay(delka_sepnuti_2);
        digitalWrite(rele_2,HIGH);
        Serial.println("-----------");
        delay(1000);
        break;

      case 51: // Prikaz 3
        Serial.println("Prikay 3");
        digitalWrite(rele_3,LOW);
        delay(delka_sepnuti_3);
        digitalWrite(rele_3,HIGH);
        Serial.println("-----------");
        delay(1000);
        break;
    }
  }
}