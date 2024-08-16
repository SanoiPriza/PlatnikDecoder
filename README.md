# Dekoder Hasła

Dekoder hasła do programu płatnik

## Jak zacząć	

Zakodowane hasła trzymane są w rejestrze systemu Windows, hasło administratora w kluczu HKEY_LOCAL_MACHINE\SOFTWARE\PROKOM Software SA\Płatnik\5.01.001\Admin (aktualne hasło znajduje się w polu AdmXX o największej wartości).
Hasło może mieć maksymalnie 24 znaki.

Hasło bazy danych (ostatniej użytej) znajduje się w kluczu HKEY_LOCAL_MACHINE\SOFTWARE\PROKOM Software SA\Płatnik\5.01.001\Baza, pole Jet OLEDB:Database Password.

### Uruchamianie programu

Program został skompilowany zgodnie ze standardem ISO C++17. Aby uruchomić program, wystarczy uruchomić plik `Decoder.exe` dostępny w repozytorium.

### Kompilacja na własnym kompilatorze

W przypadku problemów z uruchomieniem programu, możesz skompilować go samodzielnie. W tym celu użyj kompilatora obsługującego standard **ISO C++17**.

Aby skompilować program, użyj następującej komendy:

```bash
g++ -std=c++17 -o decoder main.cpp
```

### Użytkowanie

1. Po uruchomieniu programu zobaczysz menu z dwoma opcjami:
   - `1. Dekodowanie` (Dekodowanie hasła)
   - `2. Wyjście` (Zakończ program)

2. Aby odszyfrować hasło, wybierz opcję `1` i wprowadź zaszyfrowane hasło, gdy zostaniesz o to poproszony.

3. Program wyświetli odszyfrowane hasło.

4. Aby zakończyć program, wybierz opcję `2`. Zostaniesz poproszony o potwierdzenie wyboru.

### Przykład

```plaintext
1. Dekodowanie
2. Wyjście
Podaj zaszyfrowane hasło: t{snoztr{npzlsrpr{nnspxllslp{qr{qswvvv
Odszyfrowane hasło: przykladoweHaslo123
```

## Licencja

Projekt jest licencjonowany na warunkach licencji MIT. Zobacz plik [LICENSE](LICENSE) po szczegóły.
