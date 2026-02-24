# afd_sumyincr
# AFD – Python y C

Programa que implementa un Autómata Finito Determinista (AFD).

Lee un archivo `.txt` línea por línea.  
Si una línea NO cumple las reglas, imprime:

```
NO ACEPTA en línea X
```

Si cumple, no imprime nada.

---

# Reglas que acepta

## 1) ID con mayúscula

Expresión regular:

```
[A-Z][a-z0-9]*
```

Debe:
- Empezar con mayúscula.
- Seguir con minúsculas o números.

✔ Acepta:
```
A
Acdcdq2
Z9
```

❌ No acepta:
```
a123
121ABC
```

---

## 2) ID minúscula con incremento

Debe:
- Empezar con minúscula.
- Tener solo minúsculas.
- Terminar obligatoriamente en ++

✔ Acepta:
```
contador++
waa++
x++
```

❌ No acepta:
```
contador
++
9++
A++
```

---

## 3) Suma de números

Formato:

```
[0-9]+ + [0-9]+
```

✔ Acepta:
```
12+4
9+8
100+25
```

❌ No acepta:
```
12+
+12
9++
12+4+5
```

---

# 📂 Formato del archivo

Cada línea debe contener una sola expresión.

Ejemplo `entrada.txt`:

```
Acdcdq2
contador++
12+4
++
9++
```

---

# ▶ Ejecutar en Python

```
python3 programa.py entrada.txt
```

---

# ▶ Ejecutar en C

Compilar:

```
gcc afd2.c -o afd
```

Ejecutar:

```
./afd2 entrada.txt
```

---

# 🎯 Resumen

El programa acepta únicamente:

- ID que empiece con mayúscula  
- ID minúscula que termine en ++  
- Suma válida número+número  

Cualquier otra cosa → NO ACEPTA
