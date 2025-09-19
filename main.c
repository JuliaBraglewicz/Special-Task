#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

int main(void)
{
    // --- dane wejściowe --- //
    const double m = 2000.0; // masa statku [kg]
    double H = 500.0; // wysokość nad powierzchnią księżyca [m]
    double V = 10.0; // prędkość statku [m/s]
    const double F_c = 4500.0; // siła ciągu [N]
    const double g = 1.6; // przyspieszenie grawitacyjne [m/s^2]

    const double dt = 0.1; // krok symulacji [s]
    const unsigned long step_time = (unsigned long)(dt * 1000.0); // czas wyświetlania kolejnych stanów lądownika [ms]

    bool is_engine_on = false;

    unsigned long start_time, current_time;

    start_time = GetTickCount(); // czas startu

    while (H > 0) {
        double a = g;

        if (GetAsyncKeyState(VK_CONTROL) & 0x8000) { // sprawdza klawisz Ctrl wciśnięty
            is_engine_on = true;
            a = g - (F_c / m);
        } else {
            is_engine_on = false;
        }

        // równania ruchu
        V = V + a * dt;
        H = H - V * dt;

        if (H < 0) H = 0; // wysokość nie może być ujemna

        printf("H=%.1f m, V=%.1f m/s, %s\n", H, V, is_engine_on ? "ON" : "OFF");
        current_time = GetTickCount();

        if (current_time - start_time < step_time) { // sprawdza czas między wyświetleniami
            Sleep(step_time - (current_time - start_time));
        }

        start_time = GetTickCount();
    }

    if (V < 1.0) {
        printf("Lądowanie zakończone SUKCESEM!\n");
    } else {
        printf("Lądowanie zakończone KATASTROFĄ!\n");
    }
    return 0;
}