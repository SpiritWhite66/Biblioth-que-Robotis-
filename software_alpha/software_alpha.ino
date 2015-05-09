const int motor_one_one = 2; //moteur 1 
const int motor_one_two = 3; //moteur 1 
const int motor_two_one = 4; //moteur 2
const int motor_two_two = 5; //moteur 2
const int motor_three_one = 6; //moteur 3 
const int motor_three_two = 7; //moteur 3
const int sensor_flow = 8; //capteur de courant
const int motor_one = 9; //voyant moteur 1
const int motor_two = 10; //voyant moteur 2
const int motor_three = 11; //voyant moteur 3
long time; //temps
char motor_activate = 0;
byte motor_sens_one = 0;
int byte_read2;
void setup() 
{
  pinMode(motor_one_one, OUTPUT); 
  pinMode(motor_one_two, OUTPUT); 
  pinMode(motor_two_one, OUTPUT); 
  pinMode(motor_two_two, OUTPUT); 
  pinMode(motor_three_one, OUTPUT); 
  pinMode(motor_three_two, OUTPUT); 
  pinMode(motor_one, OUTPUT); 
  pinMode(motor_two, OUTPUT); 
  pinMode(motor_three, OUTPUT); 
  pinMode(sensor_flow, INPUT); 
  Serial.begin(9600);

}
void loop() 
{
  byte byte_read = Serial.available(); 
  if(byte_read > 0) {
    motor_activate = Serial.read(); 
  }
  if(motor_activate== '1'){ //moteur 1 s'allume
    Serial.println("Moteur 1 selectionne");  
    Serial.flush();
    digitalWrite(motor_one, HIGH); 
    byte_read2 = Serial.available(); 
   while(byte_read2 > '-1' )
  {
    byte_read2 = Serial.available();
    Serial.print("En attente du sens"); 
    Serial.write(motor_sens_one);
    Serial.println();
    motor_sens_one = Serial.read();
    if(byte_read2 != -1) {Serial.print("ok");  } 
  }

    if(motor_sens_one == '1'){
      char* variable1 = "moteur 1 allumé sens inverse aiguille d'une montre";
      Serial.println(variable1);
      digitalWrite(motor_one_one, LOW); 
      digitalWrite(motor_one_two, HIGH); // tourne sens inverse aiguille d'une montre
      long motor_time_one = Serial.read();
      long time_one = motor_time_one + time;
      if(time_one - time < motor_time_one) { // on stoppe le moteur
        digitalWrite(motor_one_two,LOW); // on passe donc le pin 3 en LOW
      }       
    }
    if(motor_sens_one == '2' ){
      char* variable1 = "moteur 1 allumé sens aiguille d'une montre";
      //  Serial.println(variable1);
      digitalWrite(motor_one_one, HIGH); // tourne sans aiguille d'une montre
      digitalWrite(motor_one_two, LOW);
      long motor_time_one = Serial.read();
      long time_one = motor_time_one + time;
      if(time_one - time < motor_time_one) { // on stoppe le moteur
        digitalWrite(motor_one_one,LOW); // on passe donc le pin 2 en LOW
      }       
    }
    motor_activate = 0;
  }
  
  
  /***** Moteur 2 *****/
  
  if(motor_activate== '2'){ //moteur 2 s'allume
    Serial.println("Moteur 2 selectionne");  
    Serial.flush();
    digitalWrite(motor_two, HIGH); 
   while(byte_read != -1 )
    {
      byte_read2 = Serial.available(); 
      if(byte_read2 > 0) { motor_sens_one = Serial.read();}
          Serial.print("En attente du sens");  
          Serial.write(motor_sens_one);
          Serial.println();
    }

    if(motor_sens_one == 1){
      char* variable1 = "moteur 1 allumé sens inverse aiguille d'une montre";
      Serial.println(variable1);
      digitalWrite(motor_one_one, LOW); 
      digitalWrite(motor_one_two, HIGH); // tourne sens inverse aiguille d'une montre
      long motor_time_one = Serial.read();
      long time_one = motor_time_one + time;
      if(time_one - time < motor_time_one) { // on stoppe le moteur
        digitalWrite(motor_one_two,LOW); // on passe donc le pin 3 en LOW
      }       
    }
    if(motor_sens_one == 2 ){
      char* variable1 = "moteur 1 allumé sens aiguille d'une montre";
      //  Serial.println(variable1);
      digitalWrite(motor_one_one, HIGH); // tourne sans aiguille d'une montre
      digitalWrite(motor_one_two, LOW);
      long motor_time_one = Serial.read();
      long time_one = motor_time_one + time;
      if(time_one - time < motor_time_one) { // on stoppe le moteur
        digitalWrite(motor_one_one,LOW); // on passe donc le pin 2 en LOW
      }       
    }
    motor_activate = 0;
  }
  
  /***** Moteur 3 *****/
  
 if(motor_activate== '3'){ //moteur 1 s'allume
    Serial.println("Moteur 3 selectionne");  
    Serial.flush();
    digitalWrite(motor_three, HIGH); 
   while(byte_read != -1 )
    {
      byte_read2 = Serial.available(); 
      if(byte_read2 > 0) { motor_sens_one = Serial.read();}
          Serial.print("En attente du sens");  
          Serial.write(motor_sens_one);
          Serial.println();
    }

    if(motor_sens_one == 1){
      char* variable1 = "moteur 1 allumé sens inverse aiguille d'une montre";
      Serial.println(variable1);
      digitalWrite(motor_one_one, LOW); 
      digitalWrite(motor_one_two, HIGH); // tourne sens inverse aiguille d'une montre
      long motor_time_one = Serial.read();
      long time_one = motor_time_one + time;
      if(time_one - time < motor_time_one) { // on stoppe le moteur
        digitalWrite(motor_one_two,LOW); // on passe donc le pin 3 en LOW
      }       
    }
    if(motor_sens_one == 2 ){
      char* variable1 = "moteur 1 allumé sens aiguille d'une montre";
      //  Serial.println(variable1);
      digitalWrite(motor_one_one, HIGH); // tourne sans aiguille d'une montre
      digitalWrite(motor_one_two, LOW);
      long motor_time_one = Serial.read();
      long time_one = motor_time_one + time;
      if(time_one - time < motor_time_one) { // on stoppe le moteur
        digitalWrite(motor_one_one,LOW); // on passe donc le pin 2 en LOW
      }       
    }
    motor_activate = 0;
  }

}

