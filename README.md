# Calcolo Integrali 

Il progetto fornisce il codice esibito nell'elaborato interdisciplinare di informatica - matematica. Attraverso l'uso di metodi approssimativi, basati sulla discretizzazione, è possibile calcolare il valore approssimato di integrali, dati un intervallo e una funzione integranda.

## Struttura

```
- main.cpp // File contenente il codice
- README.md // File descrittivo
```

## Funzioni

```
- f()                     // funzione che contiene la funzione integranda
- puntoCentrale()         // metodo del punto centrale
- rettangoli()            // metodo dei rettangoli
- trapezi()               // metodo dei trapezi
- cavalieriSimpson()      // metodo di cavalieri-simpson

- confronto()             // controllo dei risultati
- calcoloSingolo()        // calcolo individuale del risultato
- runApp()                // 
```

Le funzioni fondamentali che vengono usate per calcolare  l'approssimazione del valore dell'integrale sono 5. La prima, f(), contiene la funzione integranda che verrà usata per calcolare l'integrale. Le 4 seguenti sono funzioni che contengono la trascrizione in codice dei metodi descritti nell'elaborato. Ciascuno restituisce un valore finale che corrisponde al valore dell'integrale. 
La funzione confronto() ha il ruolo di stampare una tabella ordinata sul terminale. Questo è possibile attraverso l'uso della libreria <iomanip> che permette di definire delle costanti quali lo separatore e la larghezza della caselle. La stampa di risultati è poi allineata a sinistra, ciò permette l'output organizzato.
La funzione calcoloSingolo() permette invece di calcolare i valori singolarmente. Per ogni metodo verranno chiesti gli estremi di integrazione e, se il metodo lo richiede, il numero di intervalli necessari.

## Come usare
Per poter usare il programma è necessario essere in possesso di un compilatore C++. Poiché il codice non deve essere modificato in alcun modo è sufficiente compilarlo a un formato eseguibile (.exe) che potrà poi essere usato direttamente dal prompt di comandi (".\main.exe"). Caricare file eseguibili su piattaforme come GitHub o GitLab è sconsigliabile e, a volte, non concesso per motivi di sicurezza giacché tutti i file passano attraverso i server e file eseguibili potrebbero, se uno intende, provocare danni gravi.