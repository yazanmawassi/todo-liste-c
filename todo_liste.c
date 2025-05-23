#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TODOS 100
#define MAX_LEN 100
#define DATEI_NAME "todos.txt"

char todos[MAX_TODOS][MAX_LEN];
int todoCount = 0;

void ladeTodos() {
    FILE *datei = fopen(DATEI_NAME, "r");
    if (datei == NULL) return;

    while (fgets(todos[todoCount], MAX_LEN, datei)) {
        size_t len = strlen(todos[todoCount]);
        if (len > 0 && todos[todoCount][len-1] == '\n') {
            todos[todoCount][len-1] = '\0';
        }
        todoCount++;
    }

    fclose(datei);
}

void speichereTodos() {
    FILE *datei = fopen(DATEI_NAME, "w");
    if (datei == NULL) {
        printf("Fehler beim Speichern!\n");
        return;
    }

    for (int i = 0; i < todoCount; i++) {
        fprintf(datei, "%s\n", todos[i]);
    }

    fclose(datei);
}

void zeigeTodos() {
    printf("\n-- To-Do Liste --\n");
    if (todoCount == 0) {
        printf("Keine Aufgaben vorhanden.\n");
    } else {
        for (int i = 0; i < todoCount; i++) {
            printf("%d. %s\n", i + 1, todos[i]);
        }
    }
    printf("\n");
}

void neueTodo() {
    if (todoCount >= MAX_TODOS) {
        printf("Maximale Anzahl erreicht!\n");
        return;
    }

    printf("Neue Aufgabe: ");
    getchar();
    fgets(todos[todoCount], MAX_LEN, stdin);
    size_t len = strlen(todos[todoCount]);
    if (len > 0 && todos[todoCount][len-1] == '\n') {
        todos[todoCount][len-1] = '\0';
    }
    todoCount++;
    speichereTodos();
}

void loescheTodo() {
    int index;
    printf("Nummer der Aufgabe zum Loeschen: ");
    scanf("%d", &index);
    if (index < 1 || index > todoCount) {
        printf("Ungueltige Nummer!\n");
        return;
    }
    for (int i = index - 1; i < todoCount - 1; i++) {
        strcpy(todos[i], todos[i + 1]);
    }
    todoCount--;
    speichereTodos();
}

int main() {
    int wahl;

    ladeTodos();

    do {
        printf("----- Menue -----\n");
        printf("1. Aufgaben anzeigen\n");
        printf("2. Neue Aufgabe hinzufuegen\n");
        printf("3. Aufgabe loeschen\n");
        printf("0. Beenden\n");
        printf("Auswahl: ");
        scanf("%d", &wahl);

        switch (wahl) {
            case 1:
                zeigeTodos();
                break;
            case 2:
                neueTodo();
                break;
            case 3:
                loescheTodo();
                break;
            case 0:
                printf("Programm beendet.\n");
                break;
            default:
                printf("Ungueltige Eingabe!\n");
        }
    } while (wahl != 0);

    return 0;
}
