#define x_ac A1
#define y_ac A2

#define out1 1
#define out2 2
#define out3 3
#define out4 4

void setup() {
  pinMode(x_ac, INPUT);
  pinMode(y_ac, INPUT);

  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int input_x, input_y ;
  input_x = analogRead(x_ac);
  input_y = analogRead(y_ac);

  identificar_movimiento(input_x, input_y);

  //String pos = "X: " + String(input_x) + " Y: " + String(input_y) ;

  //Serial.println(pos);
  delay(1000);

  
  // put your main code here, to run repeatedly:

}

void identificar_movimiento(int xval, int yval)
{
  if ((xval > 490 && xval < 530) and (yval > 190 and yval < 520)) //stop
  {
    Serial.println("stop");
    digitalWrite(out1,LOW);  
    digitalWrite(out2,LOW);   
    digitalWrite(out3,LOW);   
    digitalWrite(out4,LOW);
  } 

  else 
  { 
    if (yval < 190) //forward
   {
    Serial.println("forward");
     digitalWrite(out1,HIGH);  
     digitalWrite(out2,LOW);   
     digitalWrite(out3,HIGH);  
     digitalWrite(out4,LOW);
      
    }
    if (yval < 425 and yval > 190) //backward
  {
    Serial.println("backward");
   digitalWrite(out1,LOW);   
   digitalWrite(out2,HIGH);  
   digitalWrite(out3,LOW);   
   digitalWrite(out4,HIGH);
      
    }   

    if (xval > 450 && xval < 490) //left
    {
      Serial.println("left");
      digitalWrite(out1,HIGH);  
      digitalWrite(out2,LOW);   
      digitalWrite(out3,LOW);   
      digitalWrite(out4,LOW);
     }


    if (xval > 560 && xval < 590)//right
    {
      Serial.println("right");
      digitalWrite(out1,LOW);  
      digitalWrite(out2,LOW);   
      digitalWrite(out3,HIGH);   
      digitalWrite(out4,LOW);
      
    }
  }
}
