#include <stdio.h>
#include <stdint.h>

int main() {

  //Signed short Int
  int16_t a_16, b_16, c_16;
  //Signed long int
  int32_t a_32, b_32, c_32;
  //unsigned short int
  uint16_t a_u16, b_u16, c_u16;

  b_16 = a_16 = 22222;
  b_32 = a_32 = 22222;

  c_32 = a_32 + b_32;
  c_16 = a_16 + b_16;
  printf("a_32 + b_32 = %d + %d = %d \n\n", a_32, b_32, c_32);
  printf("a_16 + b_16 = %hd + %hd = %hd\n\n", a_16, b_16, c_16);

  a_u16 = a_16 + c_32;
  printf("a_16 + c_32 = %hd + %d = %hu\n\n", a_16, c_32, a_u16);

  a_u16 = 2222;
  b_u16 = -222;
  c_u16 = a_u16 + b_u16;
  printf("a_u16 + b_u16 = %hu(=%hd) + %hu(=%hd) = %hu(=%hd)\n\n", a_u16,
         a_u16, b_u16, b_u16, c_u16, c_u16);

  a_32 = 555;
  b_32 = 1001;
  c_16 = c_32 = a_32 * b_32;
  printf("c_16 = c_32 = a_32 * b_32\n");
  printf("%hd = %d = %d * %d\n\n", c_16, c_32, a_32, b_32);
  c_32 = c_16 = a_32 * b_32;
  printf("c_32 = c_16 = a_32 * b_32\n");
  printf("%d = %hd = %d * %d\n\n", c_32, c_16, a_32, b_32);

  return 0;
}

/* OUTPUT
./blatt02_1.exe

Addition von a_23 und b_23
%d     %d     %d
long + long = long == Addition passt in den Datentyp,  normale ausführung
a_32 + b_32 = 22222 + 22222 = 44444 

%hd    %hd      %hd
short + short = short  da alle signed sind (negative werte zugelassen) liegt das Ergebnis 44.444
auserhalb des zulässigem Wertebereich ==> es kommt zu einem Wraparound
a_16 + b_16 = 22222 + 22222 = -21092

%hd     %d     %hu
short + long = Voreichenlose Dezimalzahl, short unsigned
Es kommt zu einem Wraparound, da das ergebnis auserhalb des Wertebereiches liegt, Wraparound beginnt bei 0,
da das ergebnis keine negativen Zahlen zulässt
a_16 + c_32 = 22222 + 44444 = 1130


uInt + uInt = %hu (%hd)       %hu (%hd)      %hu (%hd)

C vertraut Userinput, spiechert also auch negative zahlen in unsigned integers. Da %hd auch negative werte ausgibt wird die negative
Zahl dem Zweierkomplement entsprechend korrekt ausgegeben (erster bit = 1 wird als negativ behandelt).
Bei %hu ist dies nicht der fall, da dieses keine negativen Zahlen zulässt wird der erste bit wie ein teil der Zahl betrachtet, somit
wird ein größerer, positiver Wert ausgegeben. Für rechenoperationen ist dies jedoch irrelevant da diese immer gleich ablaufen. Das
Endergebnis ist somit in beiden ausgaben gleich.
a_u16 + b_u16 = 2222(=2222) + 65314(=-222) = 2000(=2000)



c_16 = c_32 = a_32 * b_32

Das Produkt der Multiplikation wird c_32 zugewiesen, der Wert von c_32 wird dann c_16 zugewiesen,
c_16 ist dennoch anders, da das Produkt größer ist als eine 16 Bit Zahl, alle Bits die auserhalb
der Reichweite des datentyps liegen werden weggelassen, somit wird das Ergebnis als 32.267 angegeben.
31267 = 555555 = 555 * 1001


Hier ist c_32 gleich c_16, da das Produkt erst c_16 zugewiesen wird, (wobei die bits verloren gehen) und dann der Wert von
c_16 c_32 zugewiesen wird, somit gehen die bits die außer Reichweite liegen verloren.
c_32 = c_16 = a_32 * b_32
31267 = 31267 = 555 * 1001
*/