Las dos funciones se usan para armar un rango `[l, r)` usando `l = lower_bound(.., first)` y `r = upper_bound(.., last)`. Usan el comparador `a < b` por defecto
- `lower_bound` retorna un iterador al primer elemento que no se ordena antes de `value`, ie. el primer elemento mayor o igual (`x >= value`).
- `upper_bound` retorna un iterador al primer elemento que se ordena después de `value`, ie. el primer elemento mayor (`x > value`).

Por ejemplo, para los datos `1 5 7 10 11 13 14 19`
- `lower_bound(.., 10)` #math.arrow `10`, `lower_bound(.., 11)` #math.arrow `11`, `lower_bound(.., 12)` #math.arrow `13`
- `upper_bound(.., 10)` #math.arrow `11`, `upper_bound(.., 11)` #math.arrow `13`, `upper_bound(.., 12)` #math.arrow `13`

