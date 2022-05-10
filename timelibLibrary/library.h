struct Date {
    int day;
    int month;
    int year;
};

/** Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1. */
int day_of_the_year(struct Date date);

/** Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde. */
struct Date input_date();

/** Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben. */
int is_leapyear(int year);

/** Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt. */
int get_days_for_month(int month, int year);

/** Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
wie alle Daten nach dem 31.12.2400. */
int exists_date(struct Date date);

/** Die Funktion gibt den Wochentag für ein bestimmtes Datum an.
 * Mithilfe der Formel w = (d + [2,6 * m - 0,2] + y + [y/4] + [c/4] - 2c mod 7
 * d = Tagesdatum
 * m = Monat, wobei März 1 ist und Februar 12
 * y = Die beiden letzten Stellen der Jahreszahl, bei den Monaten Januar und Februar die letzten Stellen des Vorjahres
 * c = Die beiden ersten Stellen der Jahreszahl, bei den Monaten Januar und Februar die ersten Stellen des Vorjahres
*/
int weekday_for_the_date(int day, int month, int year);

/** Die Funktion printed den Wochentag, anhand der Nummer */
void print_weekday(int weekday);

/** Muss noch überarbeitet werden. */
int get_weekday_for_first_day_of_year(int year);

/** Muss noch überarbeitet werden. */
int get_calender_week(int dayOfTheYear, int year);
