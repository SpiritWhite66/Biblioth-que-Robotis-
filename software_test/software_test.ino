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
int incomingByte = 0;

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
Serial.begin(19200);

}
void loop() 
{
if (Serial.available() > 0) { // si données disponibles sur le port série
		// lit l'octet entrant
		incomingByte = Serial.read();

		// renvoie l'octet reçu
		Serial.print("Octet recu: ");
		Serial.write(incomingByte);
	}
}
