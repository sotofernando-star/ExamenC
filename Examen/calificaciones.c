#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, i;
    int nuevos;
    int total;
    float *calificaciones;
    float suma = 0;
    float promedio;

    // Preguntar cuántos estudiantes registrar
    printf("¿Cuántos estudiantes deseas registrar? ");
    scanf("%d", &n);

    // Reservar memoria dinámica con malloc
    calificaciones = (float *)malloc(n * sizeof(float));

    // Verificar si malloc falló
    if (calificaciones == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Capturar calificaciones
    for (i = 0; i < n; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }

    // Calcular promedio inicial
    promedio = suma / n;
    printf("Promedio inicial: %.2f\n", promedio);

    // Preguntar si desea agregar más estudiantes
    printf("¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
    scanf("%d", &nuevos);

    if (nuevos > 0) {

        total = n + nuevos;

        // Ampliar memoria con realloc
        calificaciones = (float *)realloc(calificaciones, total * sizeof(float));

        // Verificar error de realloc
        if (calificaciones == NULL) {
            printf("Error al reasignar memoria.\n");
            return 1;
        }

        // Capturar nuevas calificaciones
        for (i = n; i < total; i++) {
            printf("Calificación del estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i];
        }

        n = total;
    }

    // Mostrar calificaciones
    printf("\n=== Calificaciones registradas ===\n");

    for (i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
    }

    // Calcular promedio final
    promedio = suma / n;
    printf("Promedio general: %.2f\n", promedio);

    // Liberar memoria
    free(calificaciones);

    printf("Memoria liberada correctamente.\n");

    return 0;
}