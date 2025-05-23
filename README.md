# To-Do Liste in C

Ein einfaches Konsolenprogramm zum Verwalten einer To-Do-Liste mit persistentem Speicher in einer Datei (`todos.txt`).

##  Funktionen

- Anzeigen der aktuellen Aufgaben
- Neue Aufgaben hinzufügen
- Aufgaben löschen
- Speicherung in Datei

##  Projektstruktur

```
todo_liste/
├── todo_liste.c   # Hauptprogramm
├── todos.txt      # Persistente To-Do-Liste (wird beim ersten Lauf erstellt)
└── README.md
```

##  Kompilieren und Ausführen

### Kompilieren:

```bash
gcc -o todo todo_liste.c
```

### Ausführen:

```bash
./todo
```

## Hinweis

Die Aufgaben werden automatisch in `todos.txt` gespeichert und beim Start wieder geladen.
