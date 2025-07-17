# Model View Controller Paradigma

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---

## Historie / Einordnung

Das *Model-View-Controller* Paradigma (kurz: MVC-Paradigma) hat seinen Ursprung in der Smalltalk-Programmierumgebung
und ist eine Richtlinie f�r die Architektur oberfl�chenbasierter Steuerelemente. Im
Gegensatz zur Wahrnehmung eines Steuerelements als homogene Einheit besteht eine auf dem MVC-Design
entwickelte Komponente aus den drei Einheiten *Modell*, *Ansicht* und *Controller*. Bestandteil des Entwurfsmusters 
sind auch die Kommunikationswege innerhalb dieser Architektur.

## Wesentliche Merkmale

Nach dem *Model-View-Controller* Paradigma ist eine Komponente in die folgenden drei Bestandteile zu unterteilen:

  * *Modell* (*Model*):<br/>Im Modell werden die Daten der Komponente gespeichert und Methoden zum Datenzugriff
bereitgestellt. Es informiert die Ansicht(en) �ber seinen Zustand und kann Zustands�nderungsw�nsche
vom Controller oder anderen Objekten ausf�hren.

  * *Ansicht* (*View*):<br/>Die Ansicht stellt einzelne oder alle Daten des Modells grafisch dar. Sie wei� nichts oder
nur sehr wenig �ber das Datenmodell.

  * *Controller*:<br/>Der Controller reagiert auf Benutzereingaben von Maus, Tastatur oder anderen Ereignisquellen
und veranlasst das Modell zu einer �nderung seiner Zustandsdaten.

Ein *Modell* ist ausschlie�lich f�r die Daten eines Steuerelements verantwortlich und stellt �blicherweise
Methoden bereit, die auf die Daten lesend und schreibend zugreifen k�nnen. Ein auf der MVC-Architektur
basierendes Uhr-Steuerelement w�rde beispielsweise die aktuelle Tageszeit (Stunde, Minute, Sekunde) in
geeigneten Variablen ablegen und Methoden f�r den Zugriff anbieten.

Eine *Ansicht* ist eine grafische Visualisierung des Modells. Um wieder beim Beispiel der Uhr zu bleiben: Zur
Darstellung der Uhrzeit k�nnte ein Steuerelement mit GDI-Hilfsmitteln das Ziffernblatt einer Uhr mit Stunden-
und Minutenzeiger visualisieren, siehe *Abbildung* 1. Bei anderen Modellen ist es vorstellbar, dass auf
Grund der Komplexit�t des Modells nur eine Teilmenge der Daten zur Ansicht gelangt.

<img src="clock_01.png" width="150">

*Abbildung* 1: Grafische Ansicht einer Uhrzeit.

Der Datentransfer vom Modell in Richtung Ansicht ist ausschlie�lich ereignisgesteuerter Natur: Tritt im
Modell eine �nderung der Daten ein, so ist dieses daf�r verantwortlich, ein Ereignis an alle registrierten
Ansichten zu senden. Die Ansichten sind damit von der l�stigen &ndash; und vor allem auch ineffizienten &ndash; Aufgabe
befreit, sich beim Modell in regelm��igen Abst�nden nach �nderungen des Datenbestands erkundigen
zu m�ssen.

Ein herausragendes Merkmal MVC-basierter Steuerelemente ist ihre Eigenschaft, dass typischerweise mehrere,
zum Teil g�nzlich unterschiedliche Ansichten zu einem Modell existieren. Selbst an einem so einfachen
Beispiel wie der Anzeige einer Uhrzeit l�sst sich dieses Merkmal demonstrieren: Neben einer grafischen
Ansicht wie der aus *Abbildung* 1 eignet sich auch eine digitale Darstellung (*Abbildung* 2) f�r die Visualisierung
der Uhrzeit. Das zugrunde liegende Modell der Komponente ist von den unterschiedlichen Darstellungsvarianten
seines Datenbestands v�llig entkoppelt, es verwaltet ausschlie�lich die Daten der aktuellen
Uhrzeit.

<img src="clock_02.png" width="200">

*Abbildung* 2: Eine alternative Ansicht f�r Uhrzeiten.

Ein Controller behandelt Eingaben des Benutzers und wandelt diese in entsprechende Methodenaufrufe f�r
das Modell um. Am Beispiel der Uhr betrachtet hie�e das, dass Tastatur- oder Mausereignisse in einem Steuerelement
zu verarbeiten sind, die entsprechend aufbereitet zu �nderungen am Modell f�hren. In *Abbildung* 3
erkennen wir beispielsweise ein NumericUpDown-Steuerelement, das auf der Basis einer entsprechenden
Selektion in dem links davon befindlichen Textfeld entweder die Stunden, Minuten oder Sekunden
�ndert.

<img src="clock_03.png" width="160">

*Abbildung* 3: Ein NumericUpDown-Steuerelement kann als Controller eines Uhrzeit-Steuerelements fungieren.

*Bemerkung*:

Es gibt Steuerelemente, die auf der MVC-Architektur aufsetzen und die f�r die Ansicht(en) und den (die)
Controller eine gemeinsame Oberfl�che besitzen. Betrachten wir dieses Mal das Beispiel eines Editors wie
etwa den Notepad oder auch Microsoft Word: Zum einen wird im Hauptfenster der aktuelle Text des
Modells dargestellt (View-Funktionalit�t), zum anderen wird im selben Fenster der Text bearbeitet bzw. neu
eingegeben (Controller-Funktionalit�t). Ansicht und Controller verschmelzen damit zu einer einzigen UIKomponente,
die im MVC-Jargon auch *UI-Delegierte* (*User Interface Delegierte*) genannt wird.

Die strikte Trennung der Einheiten in der MVC-Architektur bringt eine Reihe gewichtiger Vorteile mit sich:

  * Das Modell muss sich nicht um seine grafische Repr�sentation k�mmern.
  * Es k�nnen f�r ein Modell vielerlei unterschiedliche Ansichten entwickelt werden, die die Informationen
    im Modell auf ihre spezifische Art und Weise darstellen.
  * Das konkrete Aussehen einer Ansicht kann ver�ndert werden, ohne dass am zugrunde liegenden Modell
Anpassungen vorzunehmen sind.
  * Die Trennung des Controllers von der Ansicht erm�glicht die Ber�cksichtigung unterschiedlichster Eingabeger�te
   (Maus, Tastatur, Anbindung einer Netzwerkschnittstelle oder eines Sensors, usw.).

## Kommunikationswege

In einer MVC-Komponente gibt es zwischen den drei Einheiten Modell, Ansicht und Controller folgende
Kommunikationswege (siehe dazu auch *Abbildung* 4):

  * Modell &rarr; Ansicht: Eine �nderung von Modellzust�nden f�hrt zu einer �nderung der Ansicht(en),
    wobei dies durch das Versenden eines Ereignisses ausgel�st wird.
  * Ansicht &rarr; Modell: Zum Aufbau der Ansicht ist es m�glich, dass diese direkt auf die Zustandsdaten des
    Modells zugreift &ndash; vorzugsweise nur in der Initialisierungsphase des Steuerelements.
  * Controller &rarr; Modell: Die prim�re Aufgabe des Controllers besteht darin, infolge von Benutzereingaben
    die beabsichtigten �nderungen an den Zustandsdaten des Modells vorzunehmen.
  * Modell &rarr; Controller: Als Folge einer Zustandsdaten�nderung des Modells kann es sein, dass die Oberfl�che
    des Controllers zu �ndern ist. Denken Sie beispielsweise an eine Schaltfl�che, die in Abh�ngigkeit
    vom Modell zu aktivieren oder deaktivieren ist.
  * Controller &rarr; Ansicht: Ein Controller darf neben dem Modell auch die Repr�sentation einer Ansicht
    beeinflussen, zum Beispiel durch benutzerspezifische Anpassungen wie das Einstellen eines Zeichensatzes
    oder das Setzen der Vorder- und Hintergrundfarbe. Eine �nderung des Modellzustands ist hier konzeptionell
    nicht vorgesehen.
  * Ansicht &rarr; Controller: In Abh�ngigkeit vom Zustand der Ansicht ist es denkbar, dass die Oberfl�che des Controllers ebenfalls anzupassen ist.

<img src="mvc_01.png" width="500">

*Abbildung* 4: Die Kommunikationswege im MVC-Modell k�nnen direkt oder indirekt (ereignisgesteuert) erfolgen.

## Eine Ventilsteuerung mit MVC-Architektur

Lassen Sie uns das Model-View-Controller Paradigma am Beispiel eines Ventils betrachten (siehe dazu auch
*Abbildung* 5). Ein Ventil, so wie wir es beispielsweise im Maschinenbau vorfinden, kann als Zustand entweder
&bdquo;offen&rdquo;, &bdquo;geschlossen&rdquo; oder m�glicherweise auch &bdquo;zu einem gewissen Grad ge�ffnet&rdquo; besitzen. Neben
diesem (passiven) Verhalten ist es auch m�glich, aktiv �ber das Ausl�sen von Funktionen den Zustand des
Modells zu beeinflussen, das Ventil kann (teilweise) ge�ffnet oder (teilweise) geschlossen werden

<img src="mvc_02.png" width="500">

*Abbildung* 5: Ein Ventil unter dem Aspekt des Model-View-Controller Paradigmas betrachtet.

---

#### Conceptual Example:

[Quellcode](../ConceptualExample.cpp) &ndash; Umsetzung des Ventilsteuerungs-Beispiels

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
