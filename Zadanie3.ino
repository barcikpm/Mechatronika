float odleglosc = 0; //dystans do obiektu
float e = 0; //uchyb
float pozycjaAktualna = 0; //aktualne położenie dźwigni
float u = 0; //sygnał sterujący
float K = 0.8; //współczynnik wzmocnienia
float dystans = 10; //założony dystans między dźwignią a obiektem

//konfiguracja czujnika ultradźwiękowego
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  //otwarcie portu szeregowego
  Serial.begin(9600);
}

void loop()
{
  //pomiar odleglosci z czujnika w centymetrach
  odleglosc = 0.01723 * readUltrasonicDistance(7, 7);

  e=odleglosc-dystans-pozycjaAktualna; //obliczenie uchybu
  u=e*K; //obliczenie sygnału sterującego
  pozycjaAktualna = pozycjaAktualna + u; //obliczenie pozycji dźwigni
  
  //wysłanie wyników do portu szeregowego
  Serial.print("Polozenie obiektu: ");
  Serial.println(odleglosc);
  Serial.print("Aktualna pozycja dzwigni: ");
  Serial.println(pozycjaAktualna);
  delay(1000); //oczekiwanie 1s
}