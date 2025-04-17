# Projekt_Mailer

Autoren: Kai Knezevic / Peter Meier / Stephan Fankhauser

**Projektbeschreibung:**

Im Rahmen dieses Projekts wird eine Software entwickelt, mit der Daten von Vereinsmitgliedern erfasst, verarbeitet und gespeichert werden können.

Die erfassten Informationen werden in einer CSV-Datei gespeichert. 
Zusätzlich bietet die Anwendung die Möglichkeit, Datensätze nach bestimmten Kriterien zu filtern und über die Kommandozeile auszugeben.

Die Software berücksichtigt verschiedene Mitgliedsarten und zugehörige Mitgliedsbeiträge.
Fehlerhafte Eingaben sollen automatisch erkannt und entsprechend behandelt werden.

Zusätzliche optionale Funktionen, wie das Generieren von E-Mails oder Druckadressen, erweitern den praktischen Nutzen der Anwendung.

## Anforderungen
| Funktion                                                                   | Muss | Wunsch |
|----------------------------------------------------------------------------|------|--------|
| Daten erfassen                                                             | x    | -      |
| Daten in CSV-Datei speichern                                               | x    | -      |
| Daten filtern und als String mit Trennzeichen";"ausgeben                   | X    | -      |
| Falscheingaben abfangen                                                    | X    | -      |
| Mitglieder-Art zuweisen und Mitlieder-Beitrag definieren                   | X    | -      |
| Anhand des Datensatzes ein E-Mail generieren                               |      | X      |
| Anhand des ausgegebenen Adressen-Strings eine druckbare Adresse generieren | -    | X      |
| ???????                                                                    | -    | -      |

Ipsum Lorem

Use Case
Use Case: Mitgliedsdaten erfassen und speichern
Akteur: Vereinsmitarbeiter/in (z. B. Sekretariat)

Ziel: Erfassung der Mitgliedsdaten und Speicherung in der CSV-Datei
Auslöser: 
- Ein neues Vereinsmitglied soll aufgenommen werden.
- Ein vorhandenes Mitglied kann gefiltert werden.
- (nur erwieiterung) Eine Mail wird mit der Automatischen zuweisung der Mitgliedsdaten erstellt.
- 
Vorbedingungen:
Die Software ist gestartet.

Ablauf:
1. Der User ders Programms gibt die persönlichen Daten des Mitglieds ein (Name, Adresse, Geburtsdatum etc.).
2. Die Mitgliedsart wird ausgewählt (z. B. aktiv, passiv, Ehrenmitglied).
3. Die Software weist automatisch den entsprechenden Mitgliedsbeitrag zu.
4. Nach Abschluss der Eingabe klickt der/die Mitarbeiter/in auf „Speichern“.
5. Die Daten werden validiert (z. B. Pflichtfelder, richtige Formate).
6. Bei korrekter Eingabe wird der Datensatz in der CSV-Datei gespeichert.
7. Eine Bestätigung erscheint, dass der Datensatz erfolgreich gespeichert wurde.

Nachbedingungen:
Der neue Datensatz ist in der CSV-Datei vorhanden und korrekt formatiert.

Korrekturablauf:
Bei ungültigen Eingaben zeigt die Software eine entsprechende Fehlermeldung an, und der Benutzer kann die Eingabe korrigieren.



