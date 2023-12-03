#define motorF 3
#define motorB 5
#define joyX A0
#define joyY A1
#define joyBtn 10

#define DEBUG true
#define Sp Serial.print
#define Spl Serial.println

bool running = false;
bool Switch = false;
int btnSwitch[2] = {0, 0};

void mapY_t(int value, int low_bound=497, int high_bound=499)

int jx, jy, jb;
  
void setup() 
{
  pinMode(motorF, OUTPUT);
  pinMode(motorB, OUTPUT);

  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  pinMode(joyBtn, INPUT);
  digitalWrite(joyBtn, HIGH);

  if (DEBUG) Serial.begin(9600);
}

void loop() 
{
  // Input
  jx = analogRead(joyX); jy = analogRead(joyY);
  jb = digitalRead(joyBtn);

  // Push switch state
  btnSwitch[0] = btnSwitch[1]; btnSwitch[1] = jb;

  if (DEBUG)
  {
    Sp("Joy X: "); Sp(jx); Sp('\t');
    Sp("Joy Y: "); Sp(jy); Sp('\t');
    Sp("Joy Btn: "); Sp(jb); Sp('\t');
    Sp("Running: "); Sp(running); Spl();
  }

  // If button up
  if (btnSwitch[0] == HIGH && btnSwitch[1] == LOW) running == !running;

  if (running)
  {
    mapY_t(jy);
  }
  else
  {
    digitalWrite(motorF, 0);
    digitalWrite(motorB, 0);
  }
}

// Not yet to be designed
void mapX(int value, int low_bound=502, int high_bound=504)
{

}

// Not yet to be designed
void mapY(int value, int low_bound=497, int high_bound=499)
{

}

// For single-motor testing use
void mapY_t(int value, int low_bound=497, int high_bound=499)
{
  if (value < low_bound) digitalWrite(motorB, map((value-low_bound+1)*-1, 0, 496, 0, 255);
  else if (value > high_bound) digitalWrite(motorF, map((value-high_bound-1, 0, 523, 0, 255)));
  else 
  {
    digitalWrite(motorF, 0);
    digitalWrite(motorB, 0);
  }
}