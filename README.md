Proiectul a fost realizat în cadrul Facultății de Automatică Calculatoare și Electronică, la disciplina Sisteme Incorporate(SI).

Descrierea proiectului

Acest proiect constă într-un sistem de control bazat pe un potențiometru care acționează un servomotor. Valoarea citită de la potențiometru este mapată într-un unghi corespunzător, permițând controlul poziției servomotorului.
În funcție de direcția de rotație a potențiometrului, două LED-uri oferă feedback vizual:
- un LED indică rotația într-o direcție,
- celălalt LED indică rotația în direcția opusă.
Pe axul servomotorului a fost montat un capăt de șurubelniță, utilizat pentru a strânge sau desface șuruburi în funcție de poziția controlată.

Codul inițial a fost furnizat de domnul Mămuleanu și reprezintă baza proiectului, fiind utilizat în scop educațional.
Pornind de la implementarea inițială, au fost realizate următoarele modificări:

au fost adăugate două funcții noi în directorul src, cu rol în extinderea funcționalității proiectului:

1. Funcția de interpretare a semnalului de la potențiometru
Aceasta citește valoarea analogică și o transformă într-un interval corespunzător de unghiuri pentru servomotor, îmbunătățind stabilitatea și precizia controlului.

2. Funcția de control al LED-urilor în funcție de direcția de rotație
Aceasta determină sensul variației semnalului citit de la potențiometru și activează LED-ul corespunzător, oferind feedback vizual utilizatorului.

Aceste modificări adaugă interactivitate proiectului și facilitează înțelegerea comportamentului sistemului în timp real.
