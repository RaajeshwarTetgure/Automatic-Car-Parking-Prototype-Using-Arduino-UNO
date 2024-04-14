#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD object with address 0x27, 20 columns, and 4 rows
LiquidCrystal_I2C lcd(0x27, 20, 4);

Servo myservo;

// Define pin numbers for IR sensors and buttons
#define ir_enter  2
#define ir_back 4
#define ir_car1 5
#define ir_car2 6
#define ir_car3 7
#define ir_car4 8

// Variables to store sensor readings and flags
int S1 = 0, S2 = 0, S3 = 0, S4 = 0;
int flag1 = 0, flag2 = 0;
int slot = 4; // Total available slots initially

void setup() {
  Serial.begin(9600);

  // Set pinMode for IR sensors and buttons
  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);
  pinMode(ir_car4, INPUT);
  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);

  // Attach servo to pin 3 and set initial position
  myservo.attach(3);
  myservo.write(90);

  // Initialize LCD and display welcome message
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("   Hi Welcome To");
  lcd.setCursor(0, 1);
  lcd.print("   Spongebob's");
  lcd.setCursor(0, 2);
  lcd.print("   Parking Lot");
  delay(3500);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("   Constructed By Raajeshwar");
  lcd.setCursor(0, 2);
  lcd.print("   Prototype IOT Parking System ");
  delay(5000);
  lcd.clear();

  // Read initial sensor values and calculate available slots
  Read_Sensor();
  int total = S1 + S2 + S3 + S4;
  slot = slot - total;
}

void loop() {
  // Continuously read sensor values
  Read_Sensor();

  // Display available slots on LCD
  lcd.setCursor(0, 0);
  lcd.print(" Available Slot: ");
  lcd.print(slot);
  lcd.print("    ");

  // Display status of each parking slot
  lcd.setCursor(0, 1);
  if (S1 == 1) {
    lcd.print("S1:Full ");
  } else {
    lcd.print("S1:Empty");
  }

  lcd.setCursor(11, 1);
  if (S2 == 1) {
    lcd.print("S2:Full ");
  } else {
    lcd.print("S2:Empty");
  }

  lcd.setCursor(0, 2);
  if (S3 == 1) {
    lcd.print("S3:Full ");
  } else {
    lcd.print("S3:Empty");
  }

  lcd.setCursor(11, 2);
  if (S4 == 1) {
    lcd.print("S4:Full ");
  } else {
    lcd.print("S4:Empty");
  }

  // Check for entering vehicle and adjust slot count
  if (digitalRead(ir_enter) == 0 && flag1 == 0) {
    if (slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo.write(180);
        slot = slot - 1;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print(" Sorry Parking Full ");
      delay(1500);
    }
  }

  // Check for exiting vehicle and adjust slot count
  if (digitalRead(ir_back) == 0 && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo.write(180);
      slot = slot + 1;
    }
  }

  // Reset servo position and flags after vehicle actions
  if (flag1 == 1 && flag2 == 1) {
    delay(1000);
    myservo.write(90);
    flag1 = 0, flag2 = 0;
  }

  delay(1);
}

// Function to read sensor values
void Read_Sensor() {
  S1 = 0, S2 = 0, S3 = 0, S4 = 0;

  // Update sensor values based on IR readings
  if (digitalRead(ir_car1) == 0) {
    S1 = 1;
  }
  if (digitalRead(ir_car2) == 0) {
    S2 = 1;
  }
  if (digitalRead(ir_car3) == 0) {
    S3 = 1;
  }
  if (digitalRead(ir_car4) == 0) {
    S4 = 1;
  }
}
