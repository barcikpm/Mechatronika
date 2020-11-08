//zmienne używane w programie
float a;
float b;
char dzialanie;

void setup()
{
  //otwarcie portu szeregowego
  Serial.begin(9600);
}

//funkcja powodująca oczekiwanie na wprowadzenie danych do portu
void poczekaj()
{
  while(!Serial.available())
  {
  }
}

void loop()
{

  	//odczyt pierwszej liczby
    Serial.print("Wprowadz pierwsza liczbe: ");
    poczekaj();
    a = Serial.parseFloat();
  	Serial.print(a);
  
  	//odczyt drugiej liczby
    Serial.print("\nWprowadz druga liczbe: ");
  	poczekaj();
    b = Serial.parseFloat();
  	Serial.print(b);
  
  	//odczyt typu operacji
    Serial.print("\nWprowadz dzialanie (+,-,*,/): ");
  	poczekaj();
    dzialanie = Serial.read();
  	Serial.print(dzialanie);
    
    //wykonanie włąściwego działania
    switch(dzialanie)
    {
     	case('+'):
      		Serial.print("\nWynik wynosi: ");
      		Serial.print(a+b);
    	break;
    
    	case('-'):
          Serial.print("\nWynik wynosi: ");
          Serial.print(a-b);
    	break;
    
    	case('*'):
          Serial.print("\nWynik wynosi: ");
          Serial.print(a*b);
    	break;
    
    	case('/'):
      		//uwzględnienie niedzielenia przez zero
          if(b!=0)
          {
          	Serial.print("\nWynik wynosi: ");
          	Serial.print(a/b);
          }
          else
          	Serial.print("\nNie dziel przez zero!");
          
    	break;
    
    	default:
          Serial.print("\nWybrano bledna operacje!");
    	break;
    }
   
    Serial.print("\n\n");
    
}