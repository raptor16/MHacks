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
int switchd;

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
  func (2590,2590 , 2590, 1290);
}

void func (double wiirightelev,
double wiileftthrot,
double wiileftrudd,
double wiirightail) {

/*
for (int y= 0; y<2; y++){ 
   channel0[y] = pulseIn(5, HIGH); //throttle
} 
for (int i = 0; i <2; i++){
   channel1[i] = pulseIn(6, HIGH); //elevator
}
*/
channel0 = pulseIn(5, HIGH); //throttle
channel1 = pulseIn(6, HIGH); //rudder


x0 = ((channel0-1290)*255/1500)-1;
x1 = ((channel1-1290)*255/1500)-1;

  Serial.print(channel0);
  Serial.print("  |  ");
  Serial.print(x0);
  Serial.print("  |  ");
  Serial.print(channel1); 
  Serial.print("  |  ");
  Serial.println(x1);
//read switch D from transmitter
switchd = pulseIn (2, HIGH);

/*
//if some threshold for fail safe
if (abs(channel0[0]-channel0[1])>100 || abs(channel1[0]-channel1[1])>100)
{
   analogWrite (throttle, channel0[1]);
   analogWrite (rudder, channel1[1]);
}  
*/

if (switchd < 1900)
{
  analogWrite (rudder, x1);
  analogWrite (throttle, x0);
  if (channel1>=2590){
    analogWrite (rudder, 2589);}
  if (channel1<=1310){
    analogWrite (rudder, 1310);}
}
else
{
 
  wiie = (abs(wiirightelev-1290)*255/1300)-1; 
  wiit = (abs(wiileftthrot-1290)*255/1300)-1; 
  wiir = (abs(wiileftrudd-1290)*255/1300)-1; 
  wiia = (abs(wiirightail-1290)*255/1300)-1;
  
  Serial.println(wiie);
  Serial.println(wiit);
  Serial.println(wiir);
  Serial.println(wiia);
  
  //////////elev//////////
  if ( wiirightelev < 1300){
    analogWrite (elevator, 1300);}
  else 
    { if (wiirightelev > 2580)
      {analogWrite (elevator, 2575);}
  else {analogWrite (elevator,wiie );}
  }
  /////////throt///////////////////
  if ( wiileftthrot < 1300){
    analogWrite (throttle, 1300);}
  else 
    { if (wiileftthrot > 2580)
      {analogWrite (throttle, 2575);}
  else {analogWrite (throttle,wiit );}
  }
  //////rudd/////////////////
    if ( wiileftrudd < 1300){
    analogWrite (rudder, 1300);}
  else 
    { if (wiileftrudd > 2580)
      {analogWrite (rudder, 2575);}
  else {analogWrite (rudder,wiir );}
  }
  //////ail/////////////
    if ( wiirightail < 1300){
    analogWrite (aileron, 1300);}
  else 
    { if (wiirightail > 2580)
      {analogWrite (aileron, 2575);}
  else {analogWrite (aileron,wiia );}
  }
  ////////////////////////
  /*
  analogWrite (elevator,wiie )
  analogWrite (throttle,wiit );  
  analogWrite (rudder, wiir); 
  analogWrite (aileron, wiia);
*/
}
  
}
