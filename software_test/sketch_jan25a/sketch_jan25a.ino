const int motor_one_one = 2; //moteur 1 
const int motor_one_two = 3; //moteur 1 
const int motor_two_one = 4; //moteur 2
const int motor_two_two = 5; //moteur 2
const int motor_three_one = 6; //moteur 3 
const int motor_three_two = 7; //moteur 3
const int sensor_flow = 8; //capteur de courant
const int actuator_one = 9; //controle vérin 1
const int actuator_two = 10; //controle vérin 2
long time; //temps
char motor_activate = 0;
void setup() 
{
pinMode(motor_one_one, OUTPUT); 
pinMode(motor_one_two, OUTPUT); 
pinMode(motor_two_one, OUTPUT); 
pinMode(motor_two_two, OUTPUT); 
pinMode(motor_three_one, OUTPUT); 
pinMode(motor_three_two, OUTPUT); 
pinMode(actuator_one, OUTPUT); 
pinMode(actuator_two, OUTPUT); 
pinMode(sensor_flow, INPUT); 
Serial.begin(9600);

}
void loop() 
{
byte byte_read = Serial.available(); 
if(byte_read > 0) {
motor_activate = Serial.read(); 
}
   if(motor_activate == '1' ){ //moteur 1 s'allume
  char motor_sens_one = Serial.read();
       Serial.println("Moteur 1 selectionne");
    motor_activate = '0';
   }
   

}
