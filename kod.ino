const int LED[] = {2, 3, 4, 5}; // LED pins
const int BUTTON[] = {6, 7, 8, 9}; // button pins

int correctButton; // variable to store the correct button
int score = 0; // variable to store the player's score
int timeLeft = 2; // variable to store the time left in seconds

void setup() {
  Serial.begin(9600); // initialize serial communication
  for (int i = 0; i < 4; i++) {
    pinMode(LED[i], OUTPUT); // set LED pins as output
    pinMode(BUTTON[i], INPUT_PULLUP); // set button pins as input with pull-up resistor
  }
}

void loop() {
  // start the game
  correctButton = random(4); // randomly choose the correct button
  digitalWrite(LED[correctButton], HIGH); // light up the correct LED
  Serial.println("Press the button corresponding to the lit LED!");
  Serial.print("Time left: ");
  Serial.println(timeLeft);
  
  // wait for button press
  while (!digitalRead(BUTTON[correctButton])) {
    // check if time is up
    if (timeLeft <= 0) {
      gameOver();
    }
    delay(1000); // wait 1 second
    timeLeft--; // decrement timeLeft
    Serial.print("Time left: ");
    Serial.println(timeLeft);
  }

  // player pressed the correct button
  digitalWrite(LED[correctButton], LOW); // turn off the correct LED
  score++; // increment score
  Serial.print("Score: ");
  Serial.println(score);
  timeLeft = 2; // reset the timeLeft
}

void gameOver() {
  Serial.println("Time's up! Game over.");
  Serial.print("Final score: ");
  Serial.println(score);
  while (1); // stop the program
}