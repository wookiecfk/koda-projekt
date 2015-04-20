# koda-projekt

Przypominam polecenie:
* Adaptacyjny koder/dekoder Huffmana
Zrealizować adaptacyjny koder i dekoder Huffmana (pozycje [1], [2] literatury uzupełniającej do wykładu). Zaimplementowany algorytm porównać ze standardowym algorytmem Huffmana (kodowanie dwuprzebiegowe: w pierwszym wyznaczenie prawdopodobieństw symboli, w drugim właściwe kodowanie) na sztucznie wygenerowanych ciągach danych o rozkładzie równomiernym, normalnym, Laplace'a oraz wybranych obrazach testowych. Ocenić efektywność algorytmu do kodowania obrazów naturalnych. 


Ogłoszenia Duszpasterskie od Łukasza:
1. [Wykonane]
2. Ogarnięcie projektu będzie wyglądać tak: jako że wątpie żeby komukolwiek chciało się bawić w administrowanie na gicie będziemy wszyscy pushować na brancha devel/koda/master. Jeśli będzie jakiś fuckup to będziemy revertować commity. Mamy o tyle szczęście że mam wrażenie że projekt może być podzielony na 4 praktycznie niezależne części (koder dynamiczny, dekoder dynamiczny, koder statyczny, generator ciągów o odpowiednich przebiegach) więc myślę że każdy bierze jedną część i tyle. Jeśli po rozmowie z dr Buchowiczem okaże się że rzeczywiście taki jest scope naszej pracy to ja walne jakiś prosty interfejs terminalowy będący niejako 'szkieletem' inputowym i każdy z nas będzie robił swoje i podepnie to do szkieletu który będzie miał odpowiednie wyprowadzenia. Koder i dekoder dynamiczny niestety są od siebie silnie zależne więc te dwie osoby będą musiały ze sobą silnie współpracować (lub nawet jedna osoba może to zakodzić).
3. Jeśli rzeczywiście każdy z nas wezmie jedną z funkcjonalności to wtedy prawdopodobnie każdy z nas będzie miał swój własny plik w którym będzie kodził swoje funkcje. Nie widzę tutaj żadnej potrzeby obiektowości więc walił to pies robimy wszystko na funkcjach jak w C. Prosiłbym o czytelny kod oraz komentarze gdzie uznacie za stosowne :)
