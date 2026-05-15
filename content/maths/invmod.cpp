/*
 *Description:* Calcula el inverso modular de $a$ mod $m$ (m primo)
  Complejidad: $O(log m)$
  Requiere: binpow
*/

template<class T>
T invmod(T a, T m) {
  return binpow(a, m-2, m);
}