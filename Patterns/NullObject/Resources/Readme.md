# *Null Object* Entwurfsmuster

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---

## Wesentliche Merkmale

Das *Null Object Pattern* ist ein Entwurfsmuster, das sich der Thematik von Null-Referenzen annimmt.
Null-Referenzen gibt es in anderen Programmiersprachen sehr wohl, in C++ sind sie per Definition nicht existent.
Wir sprechen daher besser von so genannten *Null*-Objekten, also Objekten, die keinerlei Funktionalit�t haben.

Der Sinn des Musters besteht darin, einer Referenz ein Objekt zuzuweisen, das keine Aktionen ausf�hrt.
Dadurch wird erreicht, dass die Referenz zu jedem Zeitpunkt auf ein g�ltiges Objekt verweist,
was Behandlungen von Sonderf�llen (das Nichtvorhandensein) er�brigt.

#### Kategorie: *Behavioural Pattern*

#### Ziel / Absicht:

Objekte ohne Funktionalit�t stellen nat�rlich einen Sonderfall dar.
Sie k�nnen Sinn ergeben, wenn reale Daten - zum Beispiel in einem Testszenario - nicht verf�gbar sind,
man aber das Standardverhalten der Software trotzdem bereitstellen m�chte.
Das Null-Objekt spiegelt folglich eine "*Do-Nothing*"-Beziehung wieder.

#### Problem:

Das *Null Object* Entwurfsmuster befreit uns von der Pflicht, zur Laufzeit Abfragen bzgl. gewisser Zust�nde vornehmen zu m�ssen.
�berall im Quellcode, wo �berpr�fungen auf Nullwerte erforderlich w�ren (was in C++ bei Referenzen ohnehin nicht m�glich ist),
kommen Nullobjektklassen zum Einsatz.

#### L�sung:

Im *Null Object* Entwurfsmuster erstellen wir zun�chst eine abstrakte Klasse,
die die verschiedenen auszuf�hrenden Operationen definiert.

Davon leiten wir reale Klassen ab, die die eigentliche Funktionalit�t implementieren und schlie�lich eine Null-Objekt Klasse,
die *keine* Implementierung der Basisklasse bereitstellt. Um es anderes zu formulieren: Streng genommen stellt auch die
Null-Objekt Klasse eine Implementierung der Basisklasse dar, aber eben mit leeren Methodenr�mpfen.

Nun kann man die Null-Objekt Klasse �berall dort einsetzen, wo aus welchen Gr�nden auch immer,
eine Klasse mit einer realen
Realisierung (tempor�r) nicht anwendbar ist.


##### *Hinweis*: Abgrenzung von *Null*-Objekten zu *Mock*-Objekten

*Null*-Objekte sind nicht mit *Mock*-Objekten zu verwechseln bzw. gleichzusetzen.
Ein *Mock*-Objekt (auch als *Attrappe* bezeichnet, von englisch *to mock*: etwas vort�uschen)
ist in der Softwareentwicklung ein Objekt,
das zur Durchf�hrung von Modultests als Platzhalter f�r echte Objekte verwendet wird.

Es ist nicht immer m�glich oder erw�nscht, ein einzelnes Objekt vollkommen isoliert zu testen.
Soll die Interaktion eines Objektes mit seiner Umgebung �berpr�ft werden,
muss vor dem eigentlichen Test die Umgebung nachgebildet werden.
Das kann umst�ndlich, zeitaufw�ndig oder teilweise auch nur eingeschr�nkt
oder eigentlich �berhaupt nicht m�glich sein.

In diesen F�llen helfen *Mock*-Objekte.
*Mock*-Objekte implementieren die Schnittstellen, �ber die das zu testende Objekt auf seine Umgebung zugreift.
Sie stellen sicher, dass die erwarteten Methodenaufrufe vollst�ndig, mit den korrekten Parametern und in der erwarteten Reihenfolge durchgef�hrt werden.
Das *Mock*-Objekt liefert keine Echtdaten zur�ck, sondern vorher zum Testfall passend festgelegte Werte.
Das *Mock*-Objekt kann somit dazu verwendet werden, ein bestimmtes Verhalten nachzustellen.
Im Gegensatz zu *Null*-Objekten, die keinerlei Implementierung besitzen,
weisen *Mock*-Objekte eine Implementierung auf, die das Ziel besitzt,
dass sich das *Mock*-Objekt quasi t�uschend echt im Vergleich zum eigentlichen realen Objekt verh�lt.

#### Struktur (UML):

<img src="dp_null_object.svg" width="600">

*Abbildung* 1: Schematische Darstellung des *Null Object* Entwurfsmusters.

---

#### Conceptual Example:

[Quellcode](../ConceptualExample.cpp)

---

## Literaturhinweise:

Die Anregungen zu den Beispielen zum *Null Object Pattern* stammen aus

[Null Object Design Pattern in C++](https://iq.opengenus.org/null-object-design-pattern-cpp/)<br>(abgerufen am 15.05.2020).

und

[Dmitri Nesteruk "Design Patterns in Modern C++](https://github.com/Apress/design-patterns-in-modern-cpp)<br>(abgerufen am 14.05.2020).

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
