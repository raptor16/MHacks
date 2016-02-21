double channel0; //throttle receiver
double channel1; //rudder receiver
double x0;
double x1;
int elevator = 3;
int aileron = 9;
int throttle = 10;
int rudder = 11;
double wiie;
double wiir;
double wiia;
double wiit;

void setup() {
  // put your setup code here, to run once:

  pinMode (5, INPUT); //from receiver throttle
  pinMode (6, INPUT); //from receiver elevator
  pinMode (elevator, OUTPUT); //to HK elevator
  pinMode (aileron, OUTPUT); //to HK aileron
  pinMode (throttle, OUTPUT); //to HK throttle
  pinMode (rudder, OUTPUT); //to HK rudder
  Serial.begin (9600);
}

void loop () {
  func (2000, 2000, 2500, 2500);
}

void func (double wiirightelev,
double wiileftthrot,
double wiileftrudd,
double wiirightail) {

for (int y= 0; y<2; y++){ 
   channel0[y] = pulseIn(5, HIGH); //throttle
} 
for (int i = 0; i <2; i++){
   channel1[i] = pulseIn(6, HIGH); //elevator
}

x0 = ((channel0[1]-1290)*255/1300)-1;
x1 = ((channel1[1]-1290)*255/1300)-1;

  Serial.println(channel0[0]);
  Serial.println("  |  ");
  Serial.println(channel1[0]); 


//if some threshold for fail safe
if (abs(channel0[0]-channel0[1])>100 || abs(channel1[0]-channel1[1])>100)
{
   analogWrite (throttle, channel0[1]);
   analogWrite (rudder, channel1[1]);
}  
else
{
  wiie = ((wiirightelev-1290)*255/1300)-1; 
  wiit = ((wiileftthrot-1290)*255/1300)-1; 
  wiir = ((wiileftrudd-1290)*255/1300)-1; 
  wiia = ((wiirightail-1290)*255/1300)-1;
  
  analogWrite (elevator,wiie );
  analogWrite (throttle,wiit );  
  analogWrite (rudder, wiir); 
  analogWrite (aileron, wiia);
}
  
}
