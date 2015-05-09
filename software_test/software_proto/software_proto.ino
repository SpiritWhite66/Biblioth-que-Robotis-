  const int motor_one_one = 2; //moteur 1 
  const int motor_one_two = 3; //moteur 1 
  const int motor_two_one = 4; //moteur 2
  const int motor_two_two = 5; //moteur 2
  const int motor_three_one = 6; //moteur 3 
  const int motor_three_two = 7; //moteur 3
  const int sensor_flow = 8; //capteur de courant
  const int motor_four_one = 9; //moteur 4
  const int motor_four_two = 10; // moteur 4
  const int button_one = 11; //bouton 1
  const int button_two = 12; //bouton 2
  const int button_three = 13; //bouton 3  
  byte motor_one = 0;
  byte motor_two = 0;
  char i = 0;
  long time_one;
  long time_two;
  long time_three;
  long time_one_add;
  long time_two_add;
  long time_three_add;
  char communication [] = {};
  byte access = 1;
  void setup() 
  {
    pinMode(motor_one_one, OUTPUT); 
    pinMode(motor_one_two, OUTPUT); 
    pinMode(motor_two_one, OUTPUT); 
    pinMode(motor_two_two, OUTPUT); 
    pinMode(motor_three_one, OUTPUT); 
    pinMode(motor_three_two, OUTPUT); 
    pinMode(motor_four_one, OUTPUT); 
    pinMode(motor_four_two, OUTPUT); 
    pinMode(button_one, INPUT); 
    pinMode(button_two, INPUT); 
    pinMode(button_three, INPUT); 
    pinMode(sensor_flow, INPUT); 
    Serial.begin(19200);
  }
  void loop() 
  {
    if(access == 1) {
      if(Serial.available() >48){
      while(Serial.available() > 0 && i <= 24)
    {
    communication[i] = Serial.read(); 
    i++; //on passe à l'indice suivant
    }
    
      /*****Moteur 1 *****/
      if(communication[0] == '1'){
      access = 0;
      motor_one = 1;
      time_one = (communication[6]-48)*10000+(communication[7]-48)*1000+(communication[8]-48)*100+(communication[9]-48)*10+communication[10]-48;
      time_one_add = millis()+time_one;   
      Serial.println(time_one);
      Serial.write("/");
      Serial.println(time_one_add);
      Serial.write("/");
      Serial.println("Moteur 1 Réussi");
          if(communication[3] == '0') {
            digitalWrite(motor_one_one, HIGH);
            digitalWrite(motor_one_two, LOW);
            Serial.println("Sens aiguille d'une montre");
             }
        else{
          Serial.println("Sens inverse aiguille d'une montre");
          digitalWrite(motor_one_one, LOW);
          digitalWrite(motor_one_two, HIGH);
        }
      }
      
      
      /*****Moteur 2*****/
       if(communication[1] == '1'){
         access = 0;
         motor_two = 1;
        time_two = (communication[11]-48)*10000 + (communication[12]-48)*1000 + (communication[13]-48)*100 + (communication[14]-48)*10 + communication[15]-48;
        time_two_add = millis()+time_two;   
        Serial.println(time_two);
        Serial.write("/");
        Serial.println(time_two_add);
        Serial.write("/");
        Serial.println("Moteur 2 Réussi");
        if(communication[4] == '0') {
          digitalWrite(motor_two_one, HIGH);
          digitalWrite(motor_two_two, LOW);
          Serial.println("Sens aiguille d'une montre");
        }
        else{
          Serial.println("Sens inverse aiguille d'une montre");
          digitalWrite(motor_two_one, LOW);
          digitalWrite(motor_two_two, HIGH);
        }
      }
    
    }
    }
    
    else
    {
      
      Serial.println("on attend");
      Serial.println("/");
      Serial.print(time_two_add-millis());
      Serial.print(">");
      Serial.print(time_two);
      
      if(motor_one == '1'){ //pour éteindre moteur 1 
        if((time_one_add-millis())> time_one){ Serial.println("motor 1 eteint"); motor_one == 0;} 
      }
      if(motor_two == '1'){  //pour éteindre moteur 2
        if((time_two_add-millis())> time_two){ Serial.println("motor 2 eteint"); motor_two == 0;
      }
      }
      
      /*** Moteur Pince (3) ***/
       if(communication[2] == '1' && motor_one == '0' && motor_two == '0' ){
        Serial.println("Moteur Pince (3) Réussi");
          digitalWrite(motor_four_one, HIGH); //fait tourner le pseudo vérin (avance)
          digitalWrite(motor_four_two, LOW);
          delay(1000);
          digitalWrite(motor_three_one, HIGH); //on fait tourner le moteur de la pince
          digitalWrite(motor_three_two, LOW);
      }
      if(digitalRead(sensor_flow) == 'TRUE') // Si surcharge d'intensité
      {
          digitalWrite(motor_three_one, LOW);// on éteint le moteur de la pince
          digitalWrite(motor_three_two, LOW);
          digitalWrite(motor_four_one, LOW); //fait tourner le pseudo vérin (recule)
          digitalWrite(motor_four_two, HIGH);
          delay(1000);
          digitalWrite(motor_four_two, LOW); // stop le vérin
          digitalWrite(motor_two_one, LOW); // on allume le moteur 1 et 2
          digitalWrite(motor_two_two, HIGH);
          digitalWrite(motor_one_one, LOW);
          digitalWrite(motor_one_two, HIGH);
         
      }
      
      /*** Gestion bouton poussoir sécurité ***/
      if(digitalRead(button_one) == HIGH)// retour déplacement horizontale éteint
      {
        digitalWrite(motor_one_one, LOW); 
        digitalWrite(motor_one_two, LOW);
      }
       if(digitalRead(button_two) == HIGH)// déplacement vertical côté gauche
      {
        digitalWrite(motor_two_one, LOW);
        digitalWrite(motor_two_two, LOW);
      }
       if(digitalRead(button_three) == HIGH)// déplacement vertical côté droit
      {
        digitalWrite(motor_two_one, LOW);
        digitalWrite(motor_two_two, LOW);
      }
      if(digitalRead(button_three) == HIGH && digitalRead(button_two) == HIGH)// Si les 2 sont appuyé on fait avancé pendant 27ms la pince puis relache le livre
      {
        digitalWrite(motor_one_one, HIGH); // moteur vertical (1) tourne
        digitalWrite(motor_one_two, LOW);
        delay(27);
        digitalWrite(motor_one_one, LOW); // moteur vertical (1) éteint 
        digitalWrite(motor_four_one, HIGH); //fait tourner le pseudo vérin (avance)
          digitalWrite(motor_four_two, LOW);
        digitalWrite(motor_three_one, LOW); // fait tourner le moteur 3 dans le sens inverse d'une aiguille d'une montre
        digitalWrite(motor_three_two, HIGH);
        if(digitalRead(sensor_flow) == 'TRUE')
        {
          digitalWrite(motor_three_two, LOW);// on éteint le moteur 3
          digitalWrite(motor_four_one, LOW); //fait tourner le pseudo vérin (recul)
          digitalWrite(motor_four_two, HIGH);
          digitalWrite(motor_one_one, HIGH); // moteur vertical (1) tourne sens aiguille d'une montre 
          digitalWrite(motor_one_two, LOW);
          if(digitalRead(button_three) == HIGH){
          digitalWrite(motor_one_one, LOW);
          access = 0;
          }
        }
      }
      
    }
  }

