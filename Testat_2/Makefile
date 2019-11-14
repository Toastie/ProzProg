#
# Variablen helfen in Makefiles copy&paste zu verringern und die "Rezepte"
# uebersichtlicher zu gestalten.
#

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

# Rezept wird mit `make blatt02_1.exe` aufgerufen, Windows-Nutzer muessen vor
# `./blatt02_1.exe` ggf. das `./` entfernen.

blatt02_1.exe:
	$(CC) $(CFLAGS) -o blatt02_1.exe blatt02_1.c
	./blatt02_1.exe

blatt02_3.exe:
	$(CC) $(CFLAGS) -o blatt02_3.exe blatt02_3.c
	./blatt02_3.exe

blatt02_2.exe:
	$(CC) $(CFLAGS) -o blatt02_2.exe blatt02_2.c
	./blatt02_2.exe

p1.exe:
	$(CC) $(CFLAGS) -o p1.exe p1.c
	./p1.exe
