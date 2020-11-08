//przypisanie nazw zmiennych dla pinów
int kier1 = 5;	//wyjście 1 do sterowania kierunkiem obrotów
int kier2 = 6;	//wyjście 2 do sterowania kierunkiem obrotów
int pwm = 7;	//wyjście do sterowania prędkością obrotów
int prawo = 11;	//sygnał z przycisku do obrotów w prawo (SW2)
int lewo = 12;	//sygnał z przycisku do obrotów w lewo (SW3)
int start = 13;	//sygnał z przycisku uruchamiającego (SW1)

//zmienne przechowujące stany przycisku uruchamiającego
bool obecnyStan = LOW;
bool poprzedniStan = LOW;
bool ponownyOdczyt = LOW;

bool uruchomiony = LOW; //informacja o urucomieniu programu przyciskiem

int zliczanie = 0; //liczba uruchomień programu

void setup()
{
  //ustawienie trybu pracy pinów
  pinMode(kier1, OUTPUT);
  pinMode(kier2, OUTPUT);
  pinMode(pwm, OUTPUT);
  pinMode(prawo, INPUT);
  pinMode(lewo, INPUT);
  pinMode(start, INPUT); 
  
  //silnik zatrzymany przy uruchamianiu programu
  digitalWrite(kier1, LOW);
  digitalWrite(kier2, LOW);
  
  //otwarcie portu szeregowego
  Serial.begin(9600);
}

void loop()
{
  //stała prędkość obrotów
  digitalWrite(pwm, HIGH);
  
  //odczytanie stanu włącznika programu
  obecnyStan = digitalRead(start);
  
  //redukcja drgań styków
  if(obecnyStan != poprzedniStan)
  {
    delay(10);  
    ponownyOdczyt = digitalRead(start);
    
    //włączenie/wyłączenie programu
    if(ponownyOdczyt == obecnyStan && obecnyStan == HIGH)
    {
     uruchomiony = !uruchomiony; 
     
      //zliczanie uruchomień i wyświetlanie liczby
      if(uruchomiony == HIGH)
      {
     	zliczanie++;
       Serial.print("Liczba uruchomien programu: ");
       Serial.print(zliczanie);
       Serial.print("\n");
      }
    }
    
    poprzedniStan = obecnyStan;
  }
     
  if(uruchomiony == HIGH)
  {
  	//obroty w lewo
 	 if(digitalRead(lewo) == HIGH)
 	 {
 	   digitalWrite(kier1, HIGH);
 	   digitalWrite(kier2, LOW);
 	 }
	  //obroty w prawo
	  else if(digitalRead(prawo) == HIGH)
  	 {
  	   digitalWrite(kier1,LOW);
  	   digitalWrite(kier2,HIGH);
 	  }
 	 //stop
  	 else
 	  {
 	    digitalWrite(kier1,LOW);
 	    digitalWrite(kier2,LOW);
 	  }
  }
}