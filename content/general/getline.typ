Si tu input no sigue un formato que puedas interpretar fácilmente (eg. no se especifica el numero de strings en una
linea), puedes en lugar leer la línea completa con `getline` y usarla con un `stringstream` como si fuese `cin`
(quizás tengas que descartar un salto de linea usando un `getline` extra):
```cpp
string l;
getline(cin, l);
// l es ahora la línea completa, incluyendo espacios (sin incluir el salto de línea)
stringstream stream(l);
// ahora puedes usar stream como cin para descomponer la línea completa
int k;
stream >> k;
string s;
stream >> s;
ll n;
stream >> n;
```

`stream.eof()` devuelve un bool que indica si ya se terminó de leer la string; lo puedes usar para leer todas las strings
de una linea:
```cpp
string l;
getline(cin, l);
int k = 0;
stringstream stream(l);
while (!stream.eof()) {
  string s;
  stream >> s;
  cout << "string " << k++ << ": " << s << endl;
}
```

Puedes tambien reutilizar el `stringstream` para otras lineas:
```cpp
string l;
getline(cin, l);
stringstream stream(l);
while (!stream.eof()) {
  // consumir los datos de la linea acá
}

getline(cin, l);
stream = stringstream(l);
while (!stream.eof()) {
  // consumir la nueva linea acá
}
```

Si estás teniendo problemas con leer líneas puede deberse a un salto de línea anterior, para ello se puede usar cin.ignore() antes del getline, en caso de que antes si supieras la cantidad de elementos a leer.