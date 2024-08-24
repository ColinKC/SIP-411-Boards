const byte MOTOR_A = 3;  // Motor 2 Interrupt Pin - INT 1 - Right Motor
const byte MOTOR_B = 2;  // Motor 1 Interrupt Pin - INT 0 - Left Motor
 
// Constant for steps in disk
const float stepcount = 20.00;  // 20 Slots in disk, change if different
 
// Constant for wheel diameter
const float wheeldiameter = 25.10; // Wheel diameter in millimeters, change if different
 
// Integers for pulse counters
volatile int counter_A = 0;
volatile int counter_B = 0;
 
 
// Motor A
 
int enA = 10;
int in1 = 7;
int in2 = 5;
 
// Motor B
 
int enB = 9;
int in3 = 4;
int in4 = 6;
 
 

void ISR_countA()  
{
  counter_A++;  // increment Motor A counter value
} 
 

void ISR_countB()  
{
  counter_B++;  // increment Motor B counter value
}
 
// Function to convert from centimeters to steps
int CMtoSteps(float cm) {
 
  int result; 
  float circumference = (wheeldiameter * 3.14) / 10; 
  float cm_step = circumference / stepcount;  // CM per Step
  
  float f_result = cm / cm_step;  
  result = (int) f_result; 
  
  return result;  
 
}
 

void forward(int steps, int mspeed) 
{
   counter_A = 0; 
   counter_B = 0;  
   
   // Set Motor A forward
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
 
   // Set Motor B forward
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(enA, mspeed);
    } else {
    analogWrite(enA, 0);
    }
    if (steps > counter_B) {
    analogWrite(enB, mspeed);
    } else {
    analogWrite(enB, 0);
    }
   }
    
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  counter_A = 0;  
  counter_B = 0;   
 
}
 

void back(int steps, int mspeed) 
{
   counter_A = 0;  
   counter_B = 0;  
   
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
 
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   
   
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(enA, mspeed);
    } else {
    analogWrite(enA, 0);
    }
    if (steps > counter_B) {
    analogWrite(enB, mspeed);
    } else {
    analogWrite(enB, 0);
    }
    }
    
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  counter_A = 0;  
  counter_B = 0;  
}
 

void clockwise(int steps, int mspeed) 
{
   counter_A = 0;  
   counter_B = 0;  
   
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
 
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
   
   
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(enA, mspeed);
    } else {
    analogWrite(enA, 0);
    }
    if (steps > counter_B) {
    analogWrite(enB, mspeed);
    } else {
    analogWrite(enB, 0);
    }
   }
    
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  counter_A = 0; 
  counter_B = 0; 
}
 

void counterclockwise(int steps, int mspeed) 
{
   counter_A = 0; 
   counter_B = 0; 
   
   
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   
   
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(enA, mspeed);
    } else {
    analogWrite(enA, 0);
    }
    if (steps > counter_B) {
    analogWrite(enB, mspeed);
    } else {
    analogWrite(enB, 0);
    }
  }
    
  // Stop when done
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  counter_A = 0;  
  counter_B = 0;   
 
}
 
void setup() 
{
  
  attachInterrupt(digitalPinToInterrupt (MOTOR_A), ISR_countA, RISING);  
  attachInterrupt(digitalPinToInterrupt (MOTOR_B), ISR_countB, RISING);  
  
    
  
  forward(CMtoSteps(50), 255);  
  delay(1000);  
  back(10, 255); 
  delay(1000);  
  forward(10, 150);  
  delay(1000); 
  back(CMtoSteps(25.4), 200);  
  delay(1000);  
  clockwise(20, 255);  
  delay(1000);  
  counterclockwise(60, 175);  
  delay(1000); 
  forward(1, 255);  
  
  
} 
 
 
void loop()
{
 
 
  
}
