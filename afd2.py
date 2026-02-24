import sys

def validar(cadena):
    estado = 0

    for i, c in enumerate(cadena):

        # ESTADO 0 (inicio)
        if estado == 0:
            if c.isupper():
                estado = 1  # ID mayúscula
            elif c.islower():
                estado = 2  # posible contador++
            elif c.isdigit():
                estado = 5  # número
            else:
                return False

        # ID MAYÚSCULA
        elif estado == 1:
            if c.islower() or c.isdigit():
                estado = 1
            else:
                return False

        # ID MINÚSCULA 
        elif estado == 2:
            if c.islower():
                estado = 2
            elif c == '+':
                estado = 3
            else:
                return False

        # PRIMER +
        elif estado == 3:
            if c == '+':
                estado = 4
            else:
                return False

        #  DESPUÉS DE ++ 
        elif estado == 4:
            return False  # no debe haber más caracteres

        #  NÚMERO 
        elif estado == 5:
            if c.isdigit():
                estado = 5
            elif c == '+':
                estado = 6
            else:
                return False

        #  + ENTRE NÚMEROS 
        elif estado == 6:
            if c.isdigit():
                estado = 7
            else:
                return False

        #  SEGUNDO NÚMERO 
        elif estado == 7:
            if c.isdigit():
                estado = 7
            else:
                return False

    #  ESTADOS DE ACEPTACIÓN 
    if estado in [1, 4, 7]:
        return True
    return False


def main():
    if len(sys.argv) != 2:
        print("Uso: python programa.py entrada.txt")
        return

    with open(sys.argv[1], "r") as f:
        for num_linea, linea in enumerate(f, 1):
            cadena = linea.strip()
            if not validar(cadena):
                print(f"NO ACEPTA en línea {num_linea}")


if __name__ == "__main__":
    main()
