double channel;

void setup() {
  pinMode (3 , INPUT);
  Serial.begin (9600);
}

void loop(){
  channel = pulseIn (3, HIGH);
  Serial.println(channel);
}
