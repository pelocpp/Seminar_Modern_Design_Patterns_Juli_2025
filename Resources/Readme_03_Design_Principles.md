# Entwurfsprinzipien (SOLID)

[Zur�ck](../Readme.md)

---


#### Grundlagen 

*Abstrakte Klassen* und *Schnittstellen* werden beide verwendet,
um Abstraktionen zu erreichen.

Einen �berblick zu abstrakten Klassen und Schnittstellen
finden Sie [hier](../Patterns/AbstractClassVsInterface/Resources/Readme.md).

---


Neben *Entwurfsmustern* gibt es in der Softwareentwicklung auch *Entwurfsprinzipien*.
Hierunter versteht man Prinzipien, die die Erzeugung wartbarer und erweiterbarer Software erm�glichen.

#### Robert Cecil Martin 

F�nf der bekanntesten dieser Prinzipien - **SOLID** - wurden von Robert Cecil Martin formuliert,
einem US-amerikanischen Softwareentwickler, IT-Berater und Schriftsteller.

Interessant sind unter anderem viele seiner Aussagen zum Altern von Software:

  * Auch Software unterliegt einem Alterungsprozess
  * Symptome des Alterungsprozesses:
    * �nderungen sind schwer einzupflegen
    * Anpassungen an ge�nderte Programmumgebungen wie z. B. Frameworks sind schwer durchzuf�hren
  * &bdquo;Software verrottet und stinkt&rdquo; (Robert C. Martin)
  * Grund: Zu viele Abh�ngigkeiten im Design
  * Starke Kopplung der Software-Komponenten f�hrt dazu, dass bei �nderungen unerw�nschte Nebeneffekte auftreten

Die Folge: Laufendes Refactoring oder komplette Neuentwicklung der Software sinnvoll!

Gute Software soll

  * erweiterbar,
  * korrekt,
  * stabil,
  * so einfach wie m�glich und
  * verst�ndlich dokumentiert sein.

sein. Um die genannten Ziele erreichen zu k�nnen, gibt es
Prinzipien und Konzepte, die beim Entwurf einzuhalten sind.
Diese kann man folgenderma�en unterteilen:

  * Prinzipien zum Entwurf von Systemen
  * Prinzipien zum Entwurf einzelner Klassen
  * Prinzipien zum Entwurf miteinander kooperierender Klassen

---

#### SOLID

Robert C. Martin - auch unter den Spitznamen &bdquo;*Uncle Bob*&rdquo; bzw. &bdquo;*that guy from ObjectMentor*&rdquo; bekannt - 
fasste eine wichtige Gruppe von Prinzipien zur
Erzeugung wartbarer und erweiterbarer Software unter dem Begriff
**SOLID** zusammen. Dieser Begriff soll andeuten, dass diese Prinzipien f�r
das Schreiben hochwertiger Software unabdingbar sind. Robert C. Martin
erkl�rte diese Prinzipien zu den wichtigsten Entwurfsprinzipien:

  * [**S**ingle Responsibility Prinzip (SRP)](../Patterns/SOLID/Resources/SingleResponsibilityPrinciple.md)
  * [**O**pen-Closed Prinzip (OCP)](../Patterns/SOLID/Resources/OpenClosedPrinciple.md)
  * [**L**iskovsches Substitutionsprinzip (LSP)](../Patterns/SOLID/Resources/LiskovSubstitutionPrinciple.md)
  * [**I**nterface Segregationsprinzip (ISP)](../Patterns/SOLID/Resources/InterfaceSegregationPrinciple.md)
  * [**D**ependency Inversion Prinzip (DIP)](../Patterns/SOLID/Resources/DependencyInversionPrinciple.md)

Im �berblick betrachtet lassen sich diese Prinzipien wie folgt zusammenfassen:

  * *Single Responsibility Prinzip*:<br/>Die Regel besagt, dass es f�r jede Klasse nur einen Grund f�r Ver�nderung geben darf &ndash; anders gesagt, jede Klasse solle nur genau eine fachliche Verantwortlichkeit abdecken.
  * *Open Closed Prinzip*:<br/>Klassen sollten sich erweitern lassen, ohne dass sich dadurch ihr Verhalten �ndert. Eine Klasse sollte also offen f�r Erweiterung, aber geschlossen hinsichtlich der �nderungen sein.
  * *Liskovsches Substitutionsprinzip*:<br/>Dass sich eine abgeleitete Klasse stets so zu verhalten habe, wie die zugrunde liegende Basisklasse, fordert das LSP. Das Ziel ist, jederzeit an Stelle der Superklasse eine Subklasse ohne semantische �nderungen verwenden zu k�nnen.
  * *Interface Segregation Prinzip*:<br/>Gro�e Interfaces sind auf mehrere kleine aufzuteilen, sodass ein Verwender nur genau jene Interfaces implementieren muss, die tats�chlich notwendig sind.
  * *Dependency Inversion Prinzip*:<br/>Abh�ngigkeiten sollten stets von konkreten zu abstrakten Modulen verlaufen, sodass konkrete Implementierungen leichter auszutauschen sind und sich voneinander entkoppeln lassen.

---

#### Weitere Entwurfsprinzipien

SOLID ist bei weitem nicht die einzige Gruppe von Prinzipien f�r den Entwurf von Software.
Um den Charakter eines einf�hrenden Textes nicht zu verlassen,
f�hre ich in tabellarischer Form - und vor allem ohne jeglichen Anspruch auf Vollst�ndigkeit -
weitere Entwurfsprinzipien aus:

| Entwurfsprinzip | Kurzbeschreibung |
|:-------|----|
| **KISS** | &bdquo;Keep it simple and stupid&rdquo; - Strebe zu einem Problem immer eine m�glichst einfache L�sung an. |
| **DRY** | &bdquo;Don't repeat yourself&rdquo; - Redundant vorhandener Quellcode ist nur aufw�ndig einheitlich zu pflegen. Bei Systemen, die dem DRY-Prinzip treu sind, brauchen �nderungen nur an einer Stelle vorgenommen zu werden. |
| **YAGNI** | &bdquo;You aren't gonna need it&rdquo; - &bdquo;Implementiere Dinge immer dann, wenn Du sie tats�chlich brauchst, niemals, wenn Du nur der Meinung bist, dass Du sie brauchst!&rdquo; |
| **Separation of Concerns** | Das &bdquo;Separation of Concerns&rdquo; (**SoC**) Prinzip ist eines der grundlegendsten Prinzipien in der Softwareentwicklung. Es ist so wichtig, dass zwei der f�nf SOLID-Prinzipien (*Single Responsibility* und *Interface Segregation*) direkte Ableitungen von diesem Konzept sind. Die Aussage des Prinzips ist einfach: Schreiben Sie Ihr Programm nicht als einen festen Block, sondern teilen Sie den Code in Bl�cke auf, die winzige Teile des Systems sind, die jeweils einen einfachen, unterschiedlichen Auftrag ausf�hren. |

Tabelle 1. Weitere Entwurfsprinzipien.

---

## Literaturhinweise


[My 5 Favorite Software Design Principles](https://dev.to/pluralsight/my-5-favorite-software-design-principles-4ech)

---

[Zur�ck](../Readme.md)

---

