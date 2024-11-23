#include <stdio.h>
#include <cs50.h>

// Prototipos de funciones
int esPar(int numero);
int esImpar(int numero);
void mostrarNumerosYSuma(int inicio, int fin, int tipo);
void manejarOpciones(int inicio, int fin);

int main() {
    int inicio, fin;
    char repetir;

    do {
        // Validar rango
        do {
            printf("Ingrese el valor inicial del rango: ");
            scanf("%d", &inicio);
            printf("Ingrese el valor final del rango: ");
            scanf("%d", &fin);

            if (inicio > fin) {
                printf("Rango no válido. El valor inicial debe ser menor o igual al valor final.\n");
            }
        } while (inicio > fin);

        // Manejar opciones
        manejarOpciones(inicio, fin);

        // Preguntar si desea repetir
        printf("\n¿Desea realizar otra operación? (s/n): ");
        scanf(" %c", &repetir);

    } while (repetir == 's' || repetir == 'S');

    printf("Programa finalizado.\n");
    return 0;
}

// Función para verificar si un número es par
int esPar(int numero) {
    return numero % 2 == 0;
}

// Función para verificar si un número es impar
int esImpar(int numero) {
    return numero % 2 != 0;
}

// Función para mostrar números de un tipo específico y calcular su suma
void mostrarNumerosYSuma(int inicio, int fin, int tipo) {
    int suma = 0;

    printf("Números %s en el rango [%d, %d]: ", (tipo == 0 ? "pares" : "impares"), inicio, fin);
    for (int i = inicio; i <= fin; i++) {
        if ((tipo == 0 && esPar(i)) || (tipo == 1 && esImpar(i))) {
            printf("%d ", i);
            suma += i;
        }
    }
    printf("\nSuma de los números %s: %d\n", (tipo == 0 ? "pares" : "impares"), suma);
}

// Función para manejar las opciones y delegar tareas
void manejarOpciones(int inicio, int fin) {
    int opcion;

    printf("\nElija una opción:\n");
    printf("1. Mostrar todos los números pares y calcular su suma.\n");
    printf("2. Mostrar todos los números impares y calcular su suma.\n");
    printf("3. Mostrar números pares e impares, junto con sus respectivas sumas.\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            mostrarNumerosYSuma(inicio, fin, 0);
            break;
        case 2:
            mostrarNumerosYSuma(inicio, fin, 1);
            break;
        case 3:
            mostrarNumerosYSuma(inicio, fin, 0);
            mostrarNumerosYSuma(inicio, fin, 1);
            break;
        default:
            printf("Opción no válida. Por favor, intente de nuevo.\n");
            break;
    }
}
