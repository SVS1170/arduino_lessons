#define GRBLED_PIN_R 4   // пин для канала R
#define GRBLED_PIN_G 3    // пин для канала G
#define GRBLED_PIN_B 2    // пин для канала B

int rgbled_r=0, rgbled_g=0, rgbled_b=0;

void setup(){
  //enable serial datada print
  Serial.begin(9600); 
  Serial.println("RBG LED v 0.1");
  // RGBLED
  pinMode(GRBLED_PIN_R, OUTPUT);
  pinMode(GRBLED_PIN_G, OUTPUT);
  pinMode(GRBLED_PIN_B, OUTPUT);
}

void loop(){
  // change color
  rgbled_r = (rgbled_r+1)%1024;
  rgbled_g = (rgbled_g+2)%1024;
  rgbled_b = (rgbled_b+3)%1024;
  // Output
  Z1_output_rgbled();
  delay(10);
}

void Z1_output_rgbled() {
  analogWrite(GRBLED_PIN_R, rgbled_r);
  analogWrite(GRBLED_PIN_G, rgbled_g);
  analogWrite(GRBLED_PIN_B, rgbled_b);
}
