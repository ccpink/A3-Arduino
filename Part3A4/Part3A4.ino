//https://osoyoo.com/wp-content/uploads/2017/08/4-digit-7-segment-display_bb.jpg
int a = 2; //a
int b = 3; //b
int c = 4; //c 
int d = 5; //d
int e = 6; //e
int f = 7; //f
int g = 8; //g 
int p = 9; //demimal

int d4 = 10; //Segments 1 - 4
int d3 = 11;
int d2 = 12;
int d1 = 13;

int number = 0;


unsigned long storeMillis = 0;
const int delay_duration = 1000;


int num_array[10][7] = { 
{ 1,1,1,1,1,1,0 },    // 0
{ 0,1,1,0,0,0,0 },    // 1
{ 1,1,0,1,1,0,1 },    // 2
{ 1,1,1,1,0,0,1 },    // 3
{ 0,1,1,0,0,1,1 },    // 4
{ 1,0,1,1,0,1,1 },    // 5
{ 1,0,1,1,1,1,1 },    // 6
{ 1,1,1,0,0,0,0 },    // 7
{ 1,1,1,1,1,1,1 },    // 8
{ 1,1,1,0,0,1,1 }};   // 9

int pinArray[]{2,3,4,5,6,7,8};

void setup()
{
  //set all the pins of the LED display as output
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);

  digitalWrite(p, HIGH);
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
}

void loop()
{
  unsigned long currentMillis = millis();
  digitalWrite(d2, HIGH);
  digitalWrite(d1, LOW);
  setNumber(number % 10);
  delay(10);
  
  if(number >= 10){
    digitalWrite(d2, LOW);
    digitalWrite(d1, HIGH);
    setNumber(number / 10);
  }
  delay(10);
  
  if (currentMillis - storeMillis > delay_duration) {
    storeMillis = currentMillis; //update and store the value of storeMillis for the next iteration
    if(number < 59){
      number++;
      }else {
        number = 0;
      }
  }

}

void setNumber(int num){
  clearNum();
  for(int i = 0; i < 7; i++)
  {
    if (num_array[num][i] == 1 ){
     digitalWrite(pinArray[i], LOW);
     
    } else {
      digitalWrite(pinArray[i], HIGH);
    }
  }
};

void clearNum(){
   for(int i = 1; i < 7; i++)
  {

     digitalWrite(pinArray[i], LOW);
  }
};
