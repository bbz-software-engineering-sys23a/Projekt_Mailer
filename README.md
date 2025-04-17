# Projekt_Mailer

Autoren: Kai Knezevic / Peter Meier / Stephan Fankhauser

## Projektbeschreibung:

Im Rahmen dieses Projekts wird eine Software entwickelt, mit der Daten von Vereinsmitgliedern erfasst, verarbeitet und gespeichert werden können.

Die erfassten Informationen werden in einer CSV-Datei gespeichert. 
Zusätzlich bietet die Anwendung die Möglichkeit, Datensätze nach bestimmten Kriterien zu filtern und über die Kommandozeile auszugeben.

Die Software berücksichtigt verschiedene Mitgliedsarten und zugehörige Mitgliedsbeiträge.
Fehlerhafte Eingaben sollen automatisch erkannt und entsprechend behandelt werden.

Zusätzliche optionale Funktionen, wie das Generieren von E-Mails oder Druckadressen, erweitern den praktischen Nutzen der Anwendung.

## Anforderungen:
| Funktion                                                                   | Muss | Wunsch |
|----------------------------------------------------------------------------|------|--------|
| Daten erfassen                                                             | x    | -      |
| Daten in CSV-Datei speichern                                               | x    | -      |
| Daten filtern und als String mit Trennzeichen";"ausgeben                   | X    | -      |
| Falscheingaben abfangen                                                    | X    | -      |
| Mitglieder-Art zuweisen und Mitlieder-Beitrag definieren                   | X    | -      |
| Anhand des Datensatzes ein E-Mail generieren                               |      | X      |
| Anhand des ausgegebenen Adressen-Strings eine druckbare Adresse generieren | -    | X      |
                                                             



## Use Case: 
- Mitgliedsdaten erfassen und speichern
- Mitgliedsdaten Auslesen
- E-mail versenden
- 
Akteur: Vereinsmitarbeiter/in (z. B. Sekretariat)

Ziel: 
- Erfassung der Mitgliedsdaten und Speicherung in der CSV-Datei
- Abruf der Mitgliedsdaten
- (nur Erweiterung)Email versenden
  
Auslöser: 
- Ein neues Vereinsmitglied soll aufgenommen werden.
- Ein vorhandenes Mitglied kann gefiltert werden.
- (nur Erwieiterung) An ein Mitglied soll eine E-mail versendet werden

Vorbedingungen:
Die Software ist gestartet.

Ablauf einer Erfassung:
1. Der Benutzer wählt in der gegebenen Auswahl "Daten erfassen"
1. Der Benutzer des Programms gibt die persönlichen Daten des Mitglieds ein (Name, Adresse, Geburtsdatum etc.).
2. Die Mitgliedsart wird ausgewählt (z. B. aktiv, passiv, Ehrenmitglied).
3. Die Software weist automatisch den entsprechenden Mitgliedsbeitrag zu.
4. Nach Abschluss der Eingabe klickt der User auf „Speichern“.
5. Bei korrekter Eingabe wird der Datensatz in der CSV-Datei gespeichert.
6. Eine Bestätigung erscheint, dass der Datensatz erfolgreich gespeichert wurde.

Nachbedingungen:
Der neue Datensatz ist in der CSV-Datei vorhanden und korrekt formatiert.

Korrekturablauf:
Bei ungültigen Eingaben zeigt die Software eine entsprechende Fehlermeldung an, und der Benutzer kann die Eingabe korrigieren.

Ablauf einer Abfrage:
1. Der Benutzer wählt in der gegebenen Auswahl "Daten anzeigen"
2. Der Benutzer gibt ein Filterkriterium ein (Filterkriterium wird abgefragt) zur Identifikation eines bestehenden Mitglieds.
3. Die Software filtert die Mitgliederdaten entsprechend den eingegebenen Kriterien.
4. Die gefundenen Mitgliedsdaten werden dem Benutzer angezeigt.
5. (nur Erweiterung) Der Benutzer kann die angezeigten Daten bearbeiten oder weitere Aktionen ausführen (z. B. speichern, E-Mail senden).

Nachbedingungen:
Die gefilterten Mitgliedsdaten werden korrekt angezeigt.

(nur Erweiterung) Ablauf der E-Mail-Erstellung:
1. Der Benutzer wählt in der gegebenen Auswahl "Ein Mail versenden"
2. Der Benutzer wählt das Mitglied aus, an das eine E-Mail gesendet werden soll.
3. Die Software erstellt automatisch eine E-Mail, basierend auf den zugewiesenen Mitgliedsdaten (z. B. Name, Beitrag).
4. Der Benutzer hat die Möglichkeit, den E-Mail-Inhalt zu überprüfen und anzupassen.
5. Die E-Mail wird an die hinterlegte Adresse des Mitglieds versendet.
6. Eine Bestätigungsmeldung erscheint, dass die E-Mail erfolgreich versendet wurde.

Nachbedingungen:
Die E-Mail wird erfolgreich versendet und an die angegebene Adresse des Mitglieds zugestellt.

## How to Install:

Voraussetzungen:
- CLion (IDE von JetBrains)
- Compiler (z. B. GCC für Linux, MinGW für Windows oder Xcode Command Line Tools für macOS)
- Git (um Das Repository zu clonen)

Projekt herunterladen:
- Lade dir den Projektordner herunter. zip oder das Repository klonen, git clone[ https://github.com/bbz-software-engineering-sys23a/Projekt_Mailer.git
- Öffne CLion und wähle „Open Project“ → navigiere zum Ordner des Projekts und öffne ihn.


Programm ausführen:
- Warte, bis CLion das Projekt vollständig indexiert hat.
- Klicke auf Build. oder ctr.F9 (Windows)
- Starte das Programm über das Pfeil Symbol oben rechts oder über Run.
  


## Flussdiagramm:

![Flussdiagramm](/Flussdiagramm.png)

## Systemsequenzdiagramm:

![Systemsequenzdiagramm](Systemsequenzdiagramm.png)


End

