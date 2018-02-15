
#define STEPPIN   2
#define DIRPIN    3

#define ENCPIN1   5
#define ENCPIN2   6

volatile long long targetCounter = 0L;
volatile long long isCounter = 0L;

volatile boolean triggered = false;

unsigned long post;
int interval = 500;

void setup() {

  pinMode(STEPPIN,INPUT_PULLUP);
  pinMode(DIRPIN,INPUT_PULLUP);
  pinMode(ENCPIN1,INPUT_PULLUP);
  pinMode(ENCPIN2,INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(STEPPIN), interruptStep, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCPIN1), interruptEnc1, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCPIN2), interruptEnc2, RISING);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(post < millis()){
  Serial.println("Target: " + targetCounter); 
  Serial.println("Is: " + targetCounter);
  post = millis() + interval;
 }
}





void interruptStep(){
  if(digitalRead(DIRPIN) == HIGH){
    targetCounter++;
  }
  else{
    targetCounter--;
  }
}

void interruptEnc1(){
  if(triggered){
    isCounter++;
    triggered = false;
  }
  else{
    triggered = true;
  }
}

void interruptEnc2(){
  if(triggered){
    isCounter--;
    triggered = false;
  }
  else{
    triggered = true;
  }
}
