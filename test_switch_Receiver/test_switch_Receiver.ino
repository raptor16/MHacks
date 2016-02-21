double channel;
//double channelprime;

void setup() {
  pinMode (2 , INPUT);
  Serial.begin (9600);
}

void loop(){
 
  channel = pulseIn(2, HIGH);
//  channelprime = analogRead (1);
  Serial.println(channel);
  //Serial.println(" - ");
  //Serial.println(channelprime);
}
