#include <stdio.h>
#include <ctype.h>
#include <string.h>

int validar(char *cadena) {
    int estado = 0;
    int i;

    for (i = 0; cadena[i] != '\0'; i++) {
        char c = cadena[i];

        //  ESTADO 0 
        if (estado == 0) {
            if (isupper(c))
                estado = 1;          // ID mayúscula
            else if (islower(c))
                estado = 2;          // posible contador++
            else if (isdigit(c))
                estado = 5;          // número
            else
                return 0;
        }

        // ID MAYÚSCULA
        else if (estado == 1) {
            if (islower(c) || isdigit(c))
                estado = 1;
            else
                return 0;
        }

        // ID MINÚSCULA
        else if (estado == 2) {
            if (islower(c))
                estado = 2;
            else if (c == '+')
                estado = 3;
            else
                return 0;
        }

        // PRIMER +
        else if (estado == 3) {
            if (c == '+')
                estado = 4;
            else
                return 0;
        }

        // DESPUÉS DE ++
        else if (estado == 4) {
            return 0;  // no debe haber más caracteres
        }

        //NÚMERO 
        else if (estado == 5) {
            if (isdigit(c))
                estado = 5;
            else if (c == '+')
                estado = 6;
            else
                return 0;
        }

        //  + ENTRE NÚMEROS
        else if (estado == 6) {
            if (isdigit(c))
                estado = 7;
            else
                return 0;
        }

        // SEGUNDO NÚMERO
        else if (estado == 7) {
            if (isdigit(c))
                estado = 7;
            else
                return 0;
        }
    }

    //  ESTADOS DE ACEPTACIÓN 
    if (estado == 1 || estado == 4 || estado == 7)
        return 1;

    return 0;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./programa archivo.txt\n");
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    char linea[256];
    int num_linea = 1;

    while (fgets(linea, sizeof(linea), archivo)) {

        // quitar salto de línea
        linea[strcspn(linea, "\n")] = '\0';

        if (!validar(linea)) {
            printf("NO ACEPTA en línea %d\n", num_linea);
        }

        num_linea++;
    }

    fclose(archivo);
    return 0;
}
