# Symulator lądowania na Księżycu

Projekt w języku **C** wykorzystujący bibliotekę `windows.h`, który symuluje lądowanie statku kosmicznego na Księżycu.  
Symulacja polega na ręcznym sterowaniu silniekiem za pomocą przycisku. Wymagany jest system Windows.

## Sterowanie
- Wciśnięty przycisk **Ctrl** – stan **ON** (100% mocy silnika).  
- Brak wciśnięcia – stan **OFF** (0% mocy silnika).  

## Zakończenie lądowania
- **SUKCES** – prędkość pionowa przy zetknięciu z powierzchnią mniejsza niż `1.0 m/s`.  
- **KATASTROFA** – gdy prędkość lądowania jest większa lub równa `1.0 m/s`. 
