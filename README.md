# 💶 euro - Währungsrechner-Veteran (64-Bit Modernisiert)

Ein kompaktes, hochoptimiertes C-Programm zur Währungsumrechnung. Ursprünglich als schlankes CLI-Tool konzipiert, wurde es nun fit für moderne 64-Bit-Systeme gemacht.

## ✨ Features
* **Plattformunabhängig:** Kompiliert und läuft nativ unter Windows (MINGW64/CMD) und Linux (WSL).
* **Modularen Aufbau:** Nutzt ausgelagerte String-Funktionen (`upper.c`) zur verlässlichen Verarbeitung von Währungskürzeln.
* **Intelligentes Makefile:** Erkennt automatisch die aktive Shell (erkennt MSYS2/MINGW64 über `$MSYSTEM`) und wählt die passenden Systembefehle.
* **Maximale Performance:** Vollständig gestrippte Binary (~81 KB) ohne Debug-Ballast und mit `-O2` Compiler-Optimierung.

## 🛠️ Kompilierung & Installation

Zum Kompilieren wird noch mein https://github.com/Michael2211967/mod.git benötigt:

## 📂 Empfohlene Verzeichnisstruktur

Damit der Compiler die Module findet, sollten die Repositories nebeneinander im selben Entwicklungsordner liegen:

```text
dev/
├── euro/          <-- Dieses Repository (enthält euro.c, Makefile)
└── mod/           <-- Das 'mod'-Repository (enthält upper.c)
```text

Das Tool kann über das universelle Makefile in jeder gängigen Umgebung gebaut werden:

```bash
# Projekt bereinigen
make clean

# Neu kompilieren (erzeugt automatisch eine optimierte & gestrippte Binary)
make