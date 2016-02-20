double channel[2];
int elevator = 6;
int aileron = 9;
int throttle = 11;
int rudder = 12;

void setup() {
  // put your setup code here, to run once:

  pinMode (3, INPUT); //from receiver throttle
  pinMode (5, INPUT); //from receiver elevator
  pinMode (elevator, OUTPUT); //to HK elevator
  pinMode (aileron, OUTPUT); //to HK aileron
  pinMode (throttle, OUTPUT) //to HK throttle
  pinMode (rudder, OUTPUT) //to HK rudder
  Serial.begin (9600);
}

void loop() {
//if some threshold for fail safe
 
  channel[0] = pulseIn(3, HIGH); //throttle
  channel[1] = pulseIn(5, HIGH); //elevator
 
  Serial.println(channel[0]);
  Serial.println("  |  ");
  Serial.println(channel[1]);
//else do that 
  
  //if the signal is sent for elevator
    //while loop exit when 
  digitalWrite(elevator, HIGH);
  delay (time1);
  digitalWrite (elevator, LOW);
  delay (time1);

  //if the signal is sent for throttle
  digitalWrite(elevator, HIGH);
  delay (time1);
  digitalWrite (elevator, LOW);
  delay (time1);
  
 
}
